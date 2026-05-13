/*
 * Symbolic test: test_get_greater_than.c
 *
 * Property: Monotonicity of get_greater_than.
 */

#include <klee/klee.h>
#include <assert.h>
#include <limits.h>
#include "treetable.h"

int main(void)
{
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

    TreeTable *ta;
    treetable_new(&ta);
    treetable_add(ta, &k1, &v1);
    treetable_add(ta, &k2, &v2);
    treetable_add(ta, &k3, &v3);
    treetable_add(ta, &k4, &v4);
    assert(balanced(ta) && sorted(ta));

    assert(treetable_get_greater_than(ta, &absent, &out) == CC_ERR_KEY_NOT_FOUND);

    /* (b) maximum key has no successor — BUG DETECTED:
     * KLEE reports assertion failure here. get_successor_node returns
     * the sentinel node (non-NULL) instead of NULL for the max key,
     * causing get_greater_than to return CC_OK with garbage data. */
    out = NULL;
    assert(treetable_get_greater_than(ta, &k4, &out) == CC_ERR_KEY_NOT_FOUND);

    out = NULL;
    assert(treetable_get_greater_than(ta, &k1, &out) == CC_OK);
    assert(*(int *)out > k1);

    out = NULL;
    assert(treetable_get_greater_than(ta, &k2, &out) == CC_OK);
    assert(*(int *)out > k2);

    TreeTable *tb;
    treetable_new(&tb);
    treetable_add(tb, &k4, &v4);
    treetable_add(tb, &k3, &v3);
    treetable_add(tb, &k2, &v2);
    treetable_add(tb, &k1, &v1);
    assert(balanced(tb) && sorted(tb));

    out = NULL;
    assert(treetable_get_greater_than(tb, &k1, &out) == CC_OK);
    assert(*(int *)out > k1);

    out = NULL;
    assert(treetable_get_greater_than(tb, &k2, &out) == CC_OK);
    assert(*(int *)out > k2);

    out = NULL;
    assert(treetable_get_greater_than(tb, &k4, &out) == CC_ERR_KEY_NOT_FOUND);

    return 0;
}