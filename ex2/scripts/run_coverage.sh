#!/usr/bin/env bash
# run_coverage.sh — Compiles harness with coverage, runs test inputs,
#                   and generates an llvm-cov report.
#
# Location: ex2/scripts/run_coverage.sh
#
# Usage (run from project root):
#   ./ex2/scripts/run_coverage.sh
#
# Test inputs should be plain text files in:
#   ex2/Ex2Harness/tests_coverage/*.txt
#
# Output:
#   ex2/Ex2HarnessCoverage.txt

# Move to project root regardless of where the script is called from
cd "$(dirname "$0")/../.." || exit 1

# Clean old data
rm -f ex2/Ex2Harness/cov_*.profraw
rm -f ex2/Ex2Harness/coverage.profdata
rm -f ex2/Ex2HarnessCoverage.txt

echo "[+] Compiling with coverage..."

clang -fprofile-instr-generate -fcoverage-mapping \
    ex2/Ex2Harness/harness.c TreeTable/treetable.c \
    -I TreeTable/ -o ex2/Ex2Harness/harness_cov

echo "[+] Running tests..."

shopt -s nullglob
test_files=(ex2/Ex2Harness/tests_coverage/*.txt)

if [ ${#test_files[@]} -eq 0 ]; then
    echo "  [!] No test files found in ex2/Ex2Harness/tests_coverage/"
    echo "      Create .txt files there with commands like: add 1 100"
    exit 1
fi

for f in "${test_files[@]}"; do
    echo "  -> Running $f"
    LLVM_PROFILE_FILE="ex2/Ex2Harness/cov_%p.profraw" \
        ./ex2/Ex2Harness/harness_cov < "$f"
done

echo "[+] Merging profiles..."

llvm-profdata merge -sparse \
    ex2/Ex2Harness/cov_*.profraw \
    -o ex2/Ex2Harness/coverage.profdata

echo "[+] Generating report..."

llvm-cov show ex2/Ex2Harness/harness_cov \
    -instr-profile=ex2/Ex2Harness/coverage.profdata \
    TreeTable/treetable.c > ex2/Ex2HarnessCoverage.txt

echo "[+] Done."
echo "Coverage report: ex2/Ex2HarnessCoverage.txt"