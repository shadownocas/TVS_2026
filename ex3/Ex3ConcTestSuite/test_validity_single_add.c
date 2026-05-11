/*
 * Concrete test suite derived from KLEE symbolic execution.
 * Source symbolic test: test_validity_single_add.c
 * Property: balanced+sorted after a single insertion
 *
 * Each test_N() function replays the API call sequence with the concrete
 * values assigned by KLEE for that execution path.
 *
 * Build:
 *   clang -I../../TreeTable -fprofile-instr-generate -fcoverage-mapping \
 *         test_validity_single_add.c ../../TreeTable/treetable.c -o test_validity_single_add
 * Run:
 *   ./test_validity_single_add
 */

#include <assert.h>
#include <stdio.h>
#include "treetable.h" 

/* test_1: k=0
 * Checks: balanced+sorted after a single insertion. */
static void test_1(void)
{
    int k=0, v=42;
    TreeTable *t; treetable_new(&t);
    treetable_add(t, &k, &v);
    assert(balanced(t) && sorted(t));
    treetable_destroy(t);
}

int main(void)
{
    test_1(); printf("test_1 passed\n");
    printf("All 1 tests passed.\n");
    return 0;
}
