/*
 * Property: get_greater_than correctness and monotonicity.
 *
 * (a) For a key absent from the table, get_greater_than must return
 *     CC_ERR_KEY_NOT_FOUND (NULL from get_tree_node_by_key).
 * (b) For the maximum key in the table (no successor), get_greater_than
 *     must return CC_ERR_KEY_NOT_FOUND (get_successor_node returns
 *     sentinel → treated as NULL).
 *     NOTE: KLEE detects a bug here — see Ex3BugReport.txt.
 * (c) For a key that has a successor in its right subtree, get_greater_than
 *     must return CC_OK and the result must be strictly greater than the
 *     queried key (right-subtree branch of get_successor_node).
 * (d) For a key whose successor is an ancestor (parent-walk branch of
 *     get_successor_node), get_greater_than must still return the correct,
 *     strictly-greater key.
 *
 * Functions exercised: treetable_add (ascending and descending insertion),
 *                      treetable_get_greater_than (absent-key, no-successor,
 *                      right-subtree-successor, parent-walk-successor paths),
 *                      get_successor_node (both internal branches).
 */

#include <klee/klee.h>
#include <assert.h>
#include <limits.h>
#include "treetable.h"

int main(void)
{
    /* --- symbolic inputs: four distinct keys in strict ascending order --- */
    int k1, k2, k3, k4;
    klee_make_symbolic(&k1, sizeof(k1), "k1");
    klee_make_symbolic(&k2, sizeof(k2), "k2");
    klee_make_symbolic(&k3, sizeof(k3), "k3");
    klee_make_symbolic(&k4, sizeof(k4), "k4");

    klee_assume(k1 > INT_MIN);
    klee_assume(k1 < INT_MAX);
    klee_assume(k2 > INT_MIN);
    klee_assume(k2 < INT_MAX);
    klee_assume(k3 > INT_MIN);
    klee_assume(k3 < INT_MAX);
    klee_assume(k4 > INT_MIN);
    klee_assume(k4 < INT_MAX);
    klee_assume(k1 < k2);
    klee_assume(k2 < k3);
    klee_assume(k3 < k4);

    /* a key guaranteed absent */
    int absent;
    klee_make_symbolic(&absent, sizeof(absent), "absent");
    klee_assume(absent > INT_MIN);
    klee_assume(absent < INT_MAX);
    klee_assume(absent != k1);
    klee_assume(absent != k2);
    klee_assume(absent != k3);
    klee_assume(absent != k4);

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
    assert(treetable_get_greater_than(ta, &absent, &out) == CC_ERR_KEY_NOT_FOUND);

    /* (b) maximum key has no successor — BUG DETECTED:
     * KLEE reports assertion failure here. get_successor_node returns
     * the sentinel node (non-NULL) instead of NULL for the max key,
     * causing get_greater_than to return CC_OK with garbage data.
     * See Ex3BugReport.txt for full analysis. */
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

    /* (b) on table B: same bug applies */
    out = NULL;
    assert(treetable_get_greater_than(tb, &k4, &out) == CC_ERR_KEY_NOT_FOUND);

    return 0;
}