/*
 * Concrete test suite derived from KLEE symbolic execution.
 * Source symbolic test: test_get_greater_than_exact.c
 * Property: get_greater_than returns IMMEDIATE successor, not just any larger key
 *
 * Each test_N() function replays the API call sequence with the concrete
 * values assigned by KLEE for that execution path.
 *
 * Build:
 *   clang -I../../TreeTable -fprofile-instr-generate -fcoverage-mapping \
 *         test_get_greater_than_exact.c ../../TreeTable/treetable.c -o test_get_greater_than_exact
 * Run:
 *   ./test_get_greater_than_exact
 */

#include <assert.h>
#include <stdio.h>
#include "treetable.h"

/* test_1: k1=0, k2=128, k3=16384
 * Checks: get_greater_than returns IMMEDIATE successor, not just any larger key. */
static void test_1(void)
{
    int k1=0, k2=128, k3=16384;
    int v1=1, v2=2, v3=3;
    void *out;
    TreeTable *t; treetable_new(&t);
    treetable_add(t, &k1, &v1); treetable_add(t, &k2, &v2); treetable_add(t, &k3, &v3);
    assert(balanced(t) && sorted(t));
    out=NULL; assert(treetable_get_greater_than(t, &k1, &out)==CC_OK);
    assert(*(int*)out == k2);
    out=NULL; assert(treetable_get_greater_than(t, &k2, &out)==CC_OK);
    assert(*(int*)out == k3);
    treetable_destroy(t);
}

int main(void)
{
    test_1(); printf("test_1 passed\n");
    printf("All 1 tests passed.\n");
    return 0;
}
