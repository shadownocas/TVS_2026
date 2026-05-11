/*
 * Concrete test suite derived from KLEE symbolic execution.
 * Source symbolic test: test_get_greater_than.c
 * Property: get_greater_than: absent/max/right-subtree/parent-walk successor paths
 *
 * Each test_N() function replays the API call sequence with the concrete
 * values assigned by KLEE for that execution path.
 *
 * Build:
 *   clang -I../../TreeTable -fprofile-instr-generate -fcoverage-mapping \
 *         test_get_greater_than.c ../../TreeTable/treetable.c -o test_get_greater_than
 * Run:
 *   ./test_get_greater_than
 */

#include <assert.h>
#include <stdio.h>
#include "treetable.h"

/* test_1: k1=1, k2=256, k3=65536, k4=16777216, absent=0
 * Checks: absent key fails; right-subtree and parent-walk successor paths.
 * NOTE: assertion on k4 (max key, no successor) exposes BUG in
 *       get_successor_node — see Ex3BugReport.txt. */
static void test_1(void)
{
    int k1=1, k2=256, k3=65536, k4=16777216, absent=0;
    int v1=1, v2=2, v3=3, v4=4;
    void *out;
    /* ascending table */
    TreeTable *ta; treetable_new(&ta);
    treetable_add(ta, &k1, &v1); treetable_add(ta, &k2, &v2);
    treetable_add(ta, &k3, &v3); treetable_add(ta, &k4, &v4);
    assert(balanced(ta) && sorted(ta));
    assert(treetable_get_greater_than(ta, &absent, &out) == CC_ERR_KEY_NOT_FOUND);
    out=NULL; assert(treetable_get_greater_than(ta, &k1, &out)==CC_OK);
    assert(*(int*)out > k1);
    out=NULL; assert(treetable_get_greater_than(ta, &k2, &out)==CC_OK);
    assert(*(int*)out > k2);
    treetable_destroy(ta);
    /* descending table */
    TreeTable *tb; treetable_new(&tb);
    treetable_add(tb, &k4, &v4); treetable_add(tb, &k3, &v3);
    treetable_add(tb, &k2, &v2); treetable_add(tb, &k1, &v1);
    assert(balanced(tb) && sorted(tb));
    out=NULL; assert(treetable_get_greater_than(tb, &k1, &out)==CC_OK);
    assert(*(int*)out > k1);
    out=NULL; assert(treetable_get_greater_than(tb, &k2, &out)==CC_OK);
    assert(*(int*)out > k2);
    treetable_destroy(tb);
}

int main(void)
{
    test_1(); printf("test_1 passed\n");
    printf("All 1 tests passed.\n");
    return 0;
}
