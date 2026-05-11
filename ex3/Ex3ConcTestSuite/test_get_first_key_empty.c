/*
 * Concrete test suite derived from KLEE symbolic execution.
 * Source symbolic test: test_get_first_key_empty.c
 * Property: get_first_key on empty table returns CC_ERR_KEY_NOT_FOUND
 *
 * Each test_N() function replays the API call sequence with the concrete
 * values assigned by KLEE for that execution path.
 *
 * Build:
 *   clang -I../../TreeTable -fprofile-instr-generate -fcoverage-mapping \
 *         test_get_first_key_empty.c ../../TreeTable/treetable.c -o test_get_first_key_empty
 * Run:
 *   ./test_get_first_key_empty
 */

#include <assert.h>
#include <stdio.h>
#include "treetable.h"

/* test_1: empty table
 * Checks: get_first_key returns CC_ERR_KEY_NOT_FOUND on empty table. */
static void test_1(void)
{
    TreeTable *t; treetable_new(&t);
    void *out = NULL;
    assert(treetable_get_first_key(t, &out) == CC_ERR_KEY_NOT_FOUND);
    treetable_destroy(t);
}

int main(void)
{
    test_1(); printf("test_1 passed\n");
    printf("All 1 tests passed.\n");
    return 0;
}
