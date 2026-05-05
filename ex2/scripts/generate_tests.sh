#!/usr/bin/env bash
# generate_tests.sh — Converts AFL++ minimised corpus and crash inputs
#                     into grouped concrete C test cases.
#
# Location: ex2/scripts/generate_tests.sh
#
# Usage (run from project root):
#   ./ex2/scripts/generate_tests.sh
#   ./ex2/scripts/generate_tests.sh [minimized_corpus_dir] [crashes_dir]
#
# Output structure:
#   ex2/Ex2ConcTestSuite/
#     validity_preservation/
#     lookup_correctness/
#     boundary/
#     mixed/
#     crashes/

set -euo pipefail

MINIMISED_DIR="${1:-ex2/Ex2Harness/minimized_corpus}"
CRASHES_DIR="${2:-ex2/Ex2Harness/outputs/crashes}"
SUITE_DIR="ex2/Ex2ConcTestSuite"
HARNESS="./harness_fuzz"

GREEN="\033[32m"
BLUE="\033[34m"
YELLOW="\033[33m"
GRAY="\033[90m"
RESET="\033[0m"

mkdir -p \
    "$SUITE_DIR/validity_preservation" \
    "$SUITE_DIR/lookup_correctness" \
    "$SUITE_DIR/boundary" \
    "$SUITE_DIR/mixed" \
    "$SUITE_DIR/crashes"

decode_file() {
    local file="$1"
    python3 - "$file" <<'PYEOF'
import sys, struct

def read_i32(data, i):
    if i + 4 > len(data):
        return None, i
    return struct.unpack_from("<i", data, i)[0], i + 4

data = open(sys.argv[1], "rb").read()
i = 0
while i < len(data):
    op = data[i]
    i += 1
    if op == 0x00:
        key, i = read_i32(data, i)
        val, i = read_i32(data, i)
        if key is None or val is None:
            break
        print(f"ADD {key} {val}")
    elif op == 0x01:
        key, i = read_i32(data, i)
        if key is None:
            break
        print(f"GET {key}")
    elif op == 0x02:
        print("FIRST")
    elif op == 0x03:
        key, i = read_i32(data, i)
        if key is None:
            break
        print(f"GREATER {key}")
PYEOF
}

infer_group() {
    local ops="$1"
    local has_add=0 has_get=0 has_first=0 has_greater=0 count=0
    while IFS= read -r line; do
        [[ -z "$line" ]] && continue
        (( count++ )) || true
        case "$line" in
            ADD*)     has_add=1 ;;
            GET*)     has_get=1 ;;
            FIRST*)   has_first=1 ;;
            GREATER*) has_greater=1 ;;
        esac
    done <<< "$ops"
    if (( count == 0 )) || (( has_add == 0 )); then echo "boundary"; return; fi
    if (( has_get == 0 && has_first == 0 && has_greater == 0 )); then echo "validity_preservation"; return; fi
    local lookup_types=$(( has_get + has_first + has_greater ))
    if (( lookup_types == 1 )); then echo "lookup_correctness"; return; fi
    echo "mixed"
}

generate_normal_c() {
    local file_id="$1" group="$2" source_file="$3" ops="$4"
    local prop_desc
    case "$group" in
        validity_preservation) prop_desc="VALIDITY PRESERVATION — tree remains balanced() and sorted() after every treetable_add()" ;;
        lookup_correctness)    prop_desc="LOOKUP CORRECTNESS — treetable_get / treetable_get_first_key / treetable_get_greater_than return correct results for inserted keys" ;;
        boundary)              prop_desc="BOUNDARY — operations on empty table or with edge-case keys (negative, zero, large values)" ;;
        mixed)                 prop_desc="VALIDITY + LOOKUP — interleaved add and lookup operations; checks both invariants and return values" ;;
    esac
    local step=0 body=""
    while IFS= read -r line; do
        [[ -z "$line" ]] && continue
        local op="${line%% *}" args="${line#* }"
        case "$op" in
            ADD)
                local key="${args%% *}" val="${args##* }"
                body+="    /* step $step: treetable_add(key=$key, val=$val) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = $key; *v = $val;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
" ;;
            GET)
                body+="    /* step $step: treetable_get(key=$args) */
    { int k = $args; void *out = NULL; treetable_get(t, &k, &out); }
" ;;
            FIRST)
                body+="    /* step $step: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
" ;;
            GREATER)
                body+="    /* step $step: treetable_get_greater_than(key=$args) */
    { int k = $args; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
" ;;
        esac
        (( step++ )) || true
    done <<< "$ops"

    cat <<CEOF
/*
 * test_${file_id}.c
 *
 * Group    : ${group}
 * Property : ${prop_desc}
 *
 * Derived from minimised corpus file: ${source_file}
 * Total decoded steps: ${step}
 *
 * Compile (from ex2/Ex2ConcTestSuite/${group}/):
 *   gcc -g -fsanitize=address -o test_${file_id} test_${file_id}.c \
 *       ../../../TreeTable/treetable.c -I ../../../TreeTable/
 * Run:
 *   ./test_${file_id}
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "treetable.h"

extern int balanced(TreeTable *t);
extern int sorted  (TreeTable *t);

int main(void)
{
    TreeTable *t;
    assert(treetable_new(&t) == CC_OK);

${body}
    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
CEOF
}

capture_asan() {
    local crash_path="$1"
    if [ ! -x "$HARNESS" ]; then echo "harness binary not found at $HARNESS"; return; fi
    ASAN_OPTIONS="abort_on_error=0:exitcode=0" "$HARNESS" < "$crash_path" 2>&1 || true
}

generate_crash_c() {
    local file_id="$1" source_file="$2" ops="$3" asan_report="$4"
    local step=0 body=""
    while IFS= read -r line; do
        [[ -z "$line" ]] && continue
        local op="${line%% *}" args="${line#* }"
        case "$op" in
            ADD)
                local key="${args%% *}" val="${args##* }"
                body+="    /* step $step: treetable_add(key=$key, val=$val) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = $key; *v = $val;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
" ;;
            GET)
                body+="    /* step $step: treetable_get(key=$args) */
    { int k = $args; void *out = NULL; treetable_get(t, &k, &out); }
" ;;
            FIRST)
                body+="    /* step $step: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
" ;;
            GREATER)
                body+="    /* step $step: treetable_get_greater_than(key=$args) */
    { int k = $args; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
" ;;
        esac
        (( step++ )) || true
    done <<< "$ops"

    local asan_commented
    asan_commented=$(echo "$asan_report" | head -60 | sed 's/^/ * /')

    cat <<CEOF
/*
 * crash_${file_id}.c
 *
 * Group    : crashes
 * Property : ASSERTION VIOLATION — balanced(t) && sorted(t) failed after
 *            treetable_add(), indicating the RB-tree invariant was broken
 *            by the sequence of insertions below.
 *
 * Signal   : SIGABRT (sig:06) — assert() called abort()
 *
 * Derived from AFL++ crash input: ${source_file}
 * Total decoded steps: ${step}
 *
 * To reproduce (from project root):
 *   AFL_USE_ASAN=1 afl-clang-fast -g -O1 ex2/Ex2Harness/harness.c \
 *       TreeTable/treetable.c -I TreeTable/ -o harness_fuzz
 *   ./harness_fuzz < "${source_file}"
 *
 * Compile this test (from ex2/Ex2ConcTestSuite/crashes/):
 *   gcc -g -fsanitize=address -o crash_${file_id} crash_${file_id}.c \
 *       ../../../TreeTable/treetable.c -I ../../../TreeTable/
 *
 * AddressSanitizer / runtime report:
 *
${asan_commented}
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "treetable.h"

extern int balanced(TreeTable *t);
extern int sorted  (TreeTable *t);

int main(void)
{
    TreeTable *t;
    assert(treetable_new(&t) == CC_OK);

${body}
    treetable_destroy(t);
    return 0;
}
CEOF
}

process_dir() {
    local input_dir="$1" is_crash="$2" count=0
    if [ ! -d "$input_dir" ]; then
        echo -e "${YELLOW}Warning: directory not found: $input_dir — skipping${RESET}"
        return
    fi
    local label; [ "$is_crash" = "1" ] && label="crashes" || label="corpus"
    echo -e "\n${BLUE}Processing $label: $input_dir${RESET}"

    for filepath in "$input_dir"/id:*; do
        [ -f "$filepath" ] || continue
        local filename; filename=$(basename "$filepath")
        local file_id; file_id=$(echo "$filename" | grep -oP 'id:\K[0-9]+' | head -1)
        file_id=$(printf "%06d" "$((10#$file_id))")

        local ops; ops=$(decode_file "$filepath" 2>/dev/null) || ops=""
        local op_count; op_count=$(echo "$ops" | grep -c '^\(ADD\|GET\|FIRST\|GREATER\)' 2>/dev/null || echo 0)
        echo -e "  ${GRAY}${filename:0:55}${RESET}  ${op_count} ops"

        if [ "$is_crash" = "1" ]; then
            echo -e "    ${YELLOW}Capturing ASAN report...${RESET}"
            local asan; asan=$(capture_asan "$filepath")
            generate_crash_c "$file_id" "$filepath" "$ops" "$asan" > "$SUITE_DIR/crashes/crash_${file_id}.c"
            echo -e "    ${GREEN}-> ex2/Ex2ConcTestSuite/crashes/crash_${file_id}.c${RESET}"
        else
            local group; group=$(infer_group "$ops")
            generate_normal_c "$file_id" "$group" "$filepath" "$ops" > "$SUITE_DIR/${group}/test_${file_id}.c"
            echo -e "    ${GREEN}-> ex2/Ex2ConcTestSuite/${group}/test_${file_id}.c${RESET}"
        fi
        (( count++ )) || true
    done
    echo -e "  ${GREEN}Done: $count files processed${RESET}"
}

echo -e "${BLUE}=== AFL++ Corpus -> Concrete C Test Generator ===${RESET}"
echo -e "Minimised corpus : $MINIMISED_DIR"
echo -e "Crashes          : $CRASHES_DIR"
echo -e "Output           : $SUITE_DIR/"

process_dir "$MINIMISED_DIR" "0"
process_dir "$CRASHES_DIR"   "1"

echo -e "\n${GREEN}=== Complete ===${RESET}"
echo "Output structure:"
find "$SUITE_DIR" -name "*.c" | sort | sed 's/^/  /'