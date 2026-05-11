/*
 * Concrete test suite derived from KLEE symbolic execution.
 * Source symbolic test: test_size_correctness.c
 * Property: size=0 on fresh table; increments on new key; unchanged on duplicate
 *
 * Each test_N() function replays the API call sequence with the concrete
 * values assigned by KLEE for that execution path.
 *
 * Build:
 *   clang -I../../TreeTable -fprofile-instr-generate -fcoverage-mapping \
 *         test_size_correctness.c ../../TreeTable/treetable.c -o test_size_correctness
 * Run:
 *   ./test_size_correctness
 */

#include <assert.h>
#include <stdio.h>
#include "treetable.h"

/* test_1: k1=-2130706432, k2=0
 * Checks: size=0 on fresh table; increments on new key; unchanged on duplicate. */
static void test_1(void)
{
    int k1=-2130706432, k2=0;
    int v1=1, v2=2, v1b=99;
    TreeTable *t; treetable_new(&t);
    assert(treetable_size(t)==0);
    treetable_add(t, &k1, &v1); assert(balanced(t)&&sorted(t));
    assert(treetable_size(t)==1);
    treetable_add(t, &k2, &v2); assert(balanced(t)&&sorted(t));
    assert(treetable_size(t)==2);
    treetable_add(t, &k1, &v1b); assert(balanced(t)&&sorted(t));
    assert(treetable_size(t)==2);
    treetable_destroy(t);
}

/* test_2: k1=16777216, k2=0
 * Checks: size=0 on fresh table; increments on new key; unchanged on duplicate. */
static void test_2(void)
{
    int k1=16777216, k2=0;
    int v1=1, v2=2, v1b=99;
    TreeTable *t; treetable_new(&t);
    assert(treetable_size(t)==0);
    treetable_add(t, &k1, &v1); assert(balanced(t)&&sorted(t));
    assert(treetable_size(t)==1);
    treetable_add(t, &k2, &v2); assert(balanced(t)&&sorted(t));
    assert(treetable_size(t)==2);
    treetable_add(t, &k1, &v1b); assert(balanced(t)&&sorted(t));
    assert(treetable_size(t)==2);
    treetable_destroy(t);
}

int main(void)
{
    test_1(); printf("test_1 passed\n");
    test_2(); printf("test_2 passed\n");
    printf("All 2 tests passed.\n");
    return 0;
}
