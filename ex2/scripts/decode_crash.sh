#!/usr/bin/env bash
# decode_crash.sh — Decoder for AFL++ binary harness crash files.
#
# Location: ex2/scripts/decode_crash.sh
#
# Usage (run from project root):
#   ./ex2/scripts/decode_crash.sh <crash_file>
#   ./ex2/scripts/decode_crash.sh ex2/Ex2Harness/outputs/crashes/id:000015,...

RESET="\033[0m"
GREEN="\033[32m"
BLUE="\033[34m"
YELLOW="\033[33m"
RED="\033[31m"
GRAY="\033[90m"
BOLD="\033[1m"

if [ -z "$1" ]; then
    echo "Usage: $0 <crash_file>"
    exit 1
fi

FILE="$1"

if [ ! -f "$FILE" ]; then
    echo -e "${RED}Error: file not found: $FILE${RESET}"
    exit 1
fi

# Read file as hex string (one byte per token)
HEXDUMP=$(xxd -p "$FILE" | tr -d '\n' | sed 's/../& /g')
read -r -a BYTES <<< "$HEXDUMP"

TOTAL=${#BYTES[@]}
echo -e "${BOLD}File:${RESET} $FILE"
echo -e "${BOLD}Size:${RESET} $TOTAL bytes"
echo -e "${GRAY}------------------------------------------------------------${RESET}"

cur=0
step=0

read_int32() {
    local idx=$1
    if (( idx + 4 > TOTAL )); then
        READ_VAL=""
        return 1
    fi
    local b0=$(( 16#${BYTES[$idx]} ))
    local b1=$(( 16#${BYTES[$((idx+1))]} ))
    local b2=$(( 16#${BYTES[$((idx+2))]} ))
    local b3=$(( 16#${BYTES[$((idx+3))]} ))
    local uval=$(( b0 | (b1 << 8) | (b2 << 16) | (b3 << 24) ))
    if (( uval >= 2147483648 )); then
        READ_VAL=$(( uval - 4294967296 ))
    else
        READ_VAL=$uval
    fi
    return 0
}

while (( cur < TOTAL )); do
    op_hex="${BYTES[$cur]}"
    op=$(( 16#$op_hex ))
    offset=$cur
    (( cur++ ))
    (( step++ ))

    if (( op == 0x00 )); then
        read_int32 $cur
        if [ $? -ne 0 ]; then
            echo -e "${RED}[+${offset}] Step ${step}: ADD — truncated (no key bytes)${RESET}"
            break
        fi
        key=$READ_VAL
        (( cur += 4 ))
        read_int32 $cur
        if [ $? -ne 0 ]; then
            echo -e "${RED}[+${offset}] Step ${step}: ADD key=${key} — truncated (no value bytes)${RESET}"
            break
        fi
        val=$READ_VAL
        (( cur += 4 ))
        echo -e "${GRAY}[+${offset}]${RESET} ${GREEN}ADD${RESET}          key=${BOLD}${key}${RESET}  val=${BOLD}${val}${RESET}   → assert(balanced && sorted)"

    elif (( op == 0x01 )); then
        read_int32 $cur
        if [ $? -ne 0 ]; then
            echo -e "${RED}[+${offset}] Step ${step}: GET — truncated (no key bytes)${RESET}"
            break
        fi
        key=$READ_VAL
        (( cur += 4 ))
        echo -e "${GRAY}[+${offset}]${RESET} ${BLUE}GET${RESET}          key=${BOLD}${key}${RESET}"

    elif (( op == 0x02 )); then
        echo -e "${GRAY}[+${offset}]${RESET} ${YELLOW}FIRST_KEY${RESET}"

    elif (( op == 0x03 )); then
        read_int32 $cur
        if [ $? -ne 0 ]; then
            echo -e "${RED}[+${offset}] Step ${step}: GREATER_THAN — truncated (no key bytes)${RESET}"
            break
        fi
        key=$READ_VAL
        (( cur += 4 ))
        echo -e "${GRAY}[+${offset}]${RESET} ${RED}GREATER_THAN${RESET} key=${BOLD}${key}${RESET}"

    else
        echo -e "${GRAY}[+${offset}] UNKNOWN opcode 0x${op_hex} — skipped${RESET}"
    fi
done

echo -e "${GRAY}------------------------------------------------------------${RESET}"
echo "End of input. ${step} command(s) decoded."