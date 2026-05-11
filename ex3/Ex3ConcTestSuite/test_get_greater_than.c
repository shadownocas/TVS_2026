/*
 * Concrete test suite derived from: test_get_greater_than.c
 * Property: get_greater_than correctness and monotonicity.
 *   (a) For a key absent from the table, must return CC_ERR_KEY_NOT_FOUND.
 *   (b) For the maximum key (no successor), must return CC_ERR_KEY_NOT_FOUND.
 *   (c) For a key with a successor in its right subtree, must return CC_OK
 *       and the result must be strictly greater than the queried key.
 *   (d) For a key whose successor is an ancestor (parent-walk branch),
 *       must still return the correct strictly-greater key.
 *
 * BUG-001 DEMONSTRATED: Assertion at (b) fails.
 * get_successor_node returns the sentinel node (a non-NULL pointer) instead
 * of NULL when querying the maximum key. The guard `if (n && s)` in
 * treetable_get_greater_than therefore always passes, causing it to return
 * CC_OK with sentinel->key (garbage) instead of CC_ERR_KEY_NOT_FOUND.
 *
 * Generated from KLEE ktest files:
 *   test000001.ktest : k1=1, k2=256, k3=65536, k4=16777216, absent=0
 *
 * NOTE: Running this test will trigger an assertion failure at the
 *       "BUG-001" assertion below due to BUG-001.
 */

#include <assert.h>
#include "treetable.h"

int main(void)
{
    int k1 = 1;
    int k2 = 256;
    int k3 = 65536;
    int k4 = 16777216;
    int absent = 0;   /* absent != k1,k2,k3,k4 and 0 < 1 so not in table */

    int v1=1, v2=2, v3=3, v4=4;
    void *out = NULL;

    /* ---- Table A: ascending insertion (right-subtree successor path) ---- */
    TreeTable *ta;
    treetable_new(&ta);
    treetable_add(ta, &k1, &v1);
    treetable_add(ta, &k2, &v2);
    treetable_add(ta, &k3, &v3);
    treetable_add(ta, &k4, &v4);
    assert(balanced(ta) && sorted(ta));

    /* (a) absent key */
    out = NULL;
    assert(treetable_get_greater_than(ta, &absent, &out) == CC_ERR_KEY_NOT_FOUND);

    /* (b) BUG-001: maximum key has no successor — should return
     * CC_ERR_KEY_NOT_FOUND but returns CC_OK with sentinel garbage. */
    out = NULL;
    assert(treetable_get_greater_than(ta, &k4, &out) == CC_ERR_KEY_NOT_FOUND);

    /* (c) right-subtree successor */
    out = NULL;
    assert(treetable_get_greater_than(ta, &k1, &out) == CC_OK);
    assert(*(int *)out > k1);

    out = NULL;
    assert(treetable_get_greater_than(ta, &k2, &out) == CC_OK);
    assert(*(int *)out > k2);

    /* ---- Table B: descending insertion (parent-walk successor path) ---- */
    TreeTable *tb;
    treetable_new(&tb);
    treetable_add(tb, &k4, &v4);
    treetable_add(tb, &k3, &v3);
    treetable_add(tb, &k2, &v2);
    treetable_add(tb, &k1, &v1);
    assert(balanced(tb) && sorted(tb));

    /* (d) parent-walk successor */
    out = NULL;
    assert(treetable_get_greater_than(tb, &k1, &out) == CC_OK);
    assert(*(int *)out > k1);

    out = NULL;
    assert(treetable_get_greater_than(tb, &k2, &out) == CC_OK);
    assert(*(int *)out > k2);

    /* (b) same bug on table B */
    out = NULL;
    assert(treetable_get_greater_than(tb, &k4, &out) == CC_ERR_KEY_NOT_FOUND);



    return 0;
}
