#!/usr/bin/env bash
set -euo pipefail

# run_coverage.sh — compile and run all concrete tests with clang
# Produces ex2/Ex2CodeCoverage.txt

cd "$(dirname "$0")/../.." || exit 1

OUTDIR=ex2/coverage_data
rm -rf "$OUTDIR"
mkdir -p "$OUTDIR"
rm -f ex2/Ex2CodeCoverage.txt

echo "[+] Compiling tests with coverage flags..."
count=0
for f in $(find ex2/Ex2ConcTestSuite -type f -name '*.c'); do
    base=$(basename "$f" .c)
    outbin="$OUTDIR/${base}.bin"
    if clang -g -fprofile-instr-generate -fcoverage-mapping "$f" TreeTable/treetable.c -I TreeTable/ -o "$outbin"; then
        count=$((count+1))
    else
        echo "  [!] Compile failed for $f -- skipping" >&2
    fi
done

echo "[+] Compiled $count tests."

if [ $count -eq 0 ]; then
    echo "No test .c files found under ex2/Ex2ConcTestSuite" >&2
    exit 1
fi

echo "[+] Running tests to collect profiles..."
for b in "$OUTDIR"/*.bin; do
    echo "  -> Running $b"
    LLVM_PROFILE_FILE="$OUTDIR/cov_%p.profraw" "$b" || true
done

echo "[+] Merging profiles..."
llvm-profdata merge -sparse "$OUTDIR"/cov_*.profraw -o "$OUTDIR"/coverage.profdata

# Use one of the compiled binaries as the instrumented executable for llvm-cov
exe=$(ls "$OUTDIR"/*.bin | head -n1)

echo "[+] Generating report into ex2/Ex2CodeCoverage.txt..."
llvm-cov show "$exe" -instr-profile="$OUTDIR"/coverage.profdata TreeTable/treetable.c > ex2/Ex2CodeCoverage.txt

echo "[+] Done. Report saved to ex2/Ex2CodeCoverage.txt"
