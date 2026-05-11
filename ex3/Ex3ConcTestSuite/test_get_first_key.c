/*
 * Concrete test suite derived from KLEE symbolic execution.
 * Source symbolic test: test_get_first_key.c
 * Property: get_first_key returns minimum across single/two/four-key tables
 *
 * Each test_N() function replays the API call sequence with the concrete
 * values assigned by KLEE for that execution path.
 *
 * Build:
 *   clang -I../../TreeTable -fprofile-instr-generate -fcoverage-mapping \
 *         test_get_first_key.c ../../TreeTable/treetable.c -o test_get_first_key
 * Run:
 *   ./test_get_first_key
 */

#include <assert.h>
#include <stdio.h>
#include "treetable.h"

/* test_1: k1=0, k2=16777216, k3=16777472, k4=16793600
 * Checks: get_first_key returns minimum across single/two/four-key tables. */
static void test_1(void)
{
    int k1=0, k2=16777216, k3=16777472, k4=16793600;
    int v1=1, v2=2, v3=3, v4=4;
    void *out;
    /* single key */
    TreeTable *t1; treetable_new(&t1);
    treetable_add(t1, &k1, &v1);
    assert(balanced(t1) && sorted(t1));
    out=NULL; assert(treetable_get_first_key(t1, &out)==CC_OK);
    assert(*(int*)out == k1);
    treetable_destroy(t1);
    /* two keys */
    TreeTable *t2; treetable_new(&t2);
    treetable_add(t2, &k2, &v2); treetable_add(t2, &k1, &v1);
    assert(balanced(t2) && sorted(t2));
    out=NULL; assert(treetable_get_first_key(t2, &out)==CC_OK);
    assert(*(int*)out == k1);
    treetable_destroy(t2);
    /* four keys descending */
    TreeTable *t4; treetable_new(&t4);
    treetable_add(t4, &k4, &v4); treetable_add(t4, &k3, &v3);
    treetable_add(t4, &k2, &v2); treetable_add(t4, &k1, &v1);
    assert(balanced(t4) && sorted(t4));
    out=NULL; assert(treetable_get_first_key(t4, &out)==CC_OK);
    assert(*(int*)out == k1);
    treetable_destroy(t4);
}

int main(void)
{
    test_1(); printf("test_1 passed\n");
    printf("All 1 tests passed.\n");
    return 0;
}
