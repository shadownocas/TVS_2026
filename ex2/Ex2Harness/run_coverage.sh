#!/bin/bash

# Move to project root (important if script is run from anywhere)
cd "$(dirname "$0")/../.." || exit 1

# Clean old data
rm -f ex2/Ex2Harness/*.profraw
rm -f ex2/Ex2Harness/*.profdata
rm -f Ex2HarnessCoverage.txt

echo "[+] Compiling with coverage..."

clang -fprofile-instr-generate -fcoverage-mapping \
    ex2/Ex2Harness/harness.c TreeTable/treetable.c \
    -I TreeTable/ -o ex2/Ex2Harness/harness_cov

echo "[+] Running tests..."

for f in ex2/Ex2Harness/tests_coverage/*.txt; do
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
    TreeTable/treetable.c > Ex2HarnessCoverage.txt

echo "[+] Done."
echo "📄 Coverage report: Ex2HarnessCoverage.txt"