/*
 * Concrete test suite derived from KLEE symbolic execution.
 * Source symbolic test: test_contains_key.c
 * Property: contains_key true after insert, false for absent, true after update
 *
 * Each test_N() function replays the API call sequence with the concrete
 * values assigned by KLEE for that execution path.
 *
 * Build:
 *   clang -I../../TreeTable -fprofile-instr-generate -fcoverage-mapping \
 *         test_contains_key.c ../../TreeTable/treetable.c -o test_contains_key
 * Run:
 *   ./test_contains_key
 */

#include <assert.h>
#include <stdio.h>
#include "treetable.h"

/* test_1: k1=-2130706432, k2=0
 * Checks: contains_key true after insert, false for absent key,
 *         still true after update. */
static void test_1(void)
{
    int k1 = -2130706432, k2 = 0;
    int v1 = 7, v1b = 77;
    TreeTable *t;
    treetable_new(&t);
    assert(!treetable_contains_key(t, &k1));
    assert(!treetable_contains_key(t, &k2));
    treetable_add(t, &k1, &v1);
    assert(balanced(t) && sorted(t));
    assert(treetable_contains_key(t, &k1));
    assert(!treetable_contains_key(t, &k2));
    treetable_add(t, &k1, &v1b);
    assert(treetable_contains_key(t, &k1));
    assert(balanced(t) && sorted(t));
    treetable_destroy(t);
}

/* test_2: k1=16777216, k2=0
 * Checks: contains_key true after insert, false for absent key,
 *         still true after update. */
static void test_2(void)
{
    int k1 = 16777216, k2 = 0;
    int v1 = 7, v1b = 77;
    TreeTable *t;
    treetable_new(&t);
    assert(!treetable_contains_key(t, &k1));
    assert(!treetable_contains_key(t, &k2));
    treetable_add(t, &k1, &v1);
    assert(balanced(t) && sorted(t));
    assert(treetable_contains_key(t, &k1));
    assert(!treetable_contains_key(t, &k2));
    treetable_add(t, &k1, &v1b);
    assert(treetable_contains_key(t, &k1));
    assert(balanced(t) && sorted(t));
    treetable_destroy(t);
}

int main(void)
{
    test_1(); printf("test_1 passed\n");
    test_2(); printf("test_2 passed\n");
    printf("All 2 tests passed.\n");
    return 0;
}
