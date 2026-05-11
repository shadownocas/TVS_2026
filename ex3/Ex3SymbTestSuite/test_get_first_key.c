/*
 * Property: get_first_key correctness.
 *
 * (b) After inserting a single key k, get_first_key must return k.
 * (c) After inserting two distinct keys k1 and k2, get_first_key must
 *     return the smaller one regardless of insertion order.
 * (d) After inserting four keys in descending order, the minimum key k1
 *     ends up as a deep left leaf, requiring tree_min to walk multiple
 *     left-child pointers.
 *
 * NOTE: empty-table case (a) is in test_get_first_key_empty.c because
 * it triggers BUG-002 — see Ex3BugReport.txt.
 *
 * Functions exercised: treetable_add, treetable_get_first_key,
 *                      tree_min (single-step and multi-step left walks).
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

    int v1=1, v2=2, v3=3, v4=4;
    void *out = NULL;

    /* ---- (b) single key ---- */
    TreeTable *t1;
    treetable_new(&t1);
    treetable_add(t1, &k1, &v1);
    assert(balanced(t1) && sorted(t1));
    out = NULL;
    assert(treetable_get_first_key(t1, &out) == CC_OK);
    assert(*(int *)out == k1);

    /* ---- (c) two keys: first key must be the minimum ---- */
    TreeTable *t2;
    treetable_new(&t2);
    treetable_add(t2, &k2, &v2);
    treetable_add(t2, &k1, &v1);
    assert(balanced(t2) && sorted(t2));
    out = NULL;
    assert(treetable_get_first_key(t2, &out) == CC_OK);
    assert(*(int *)out == k1);

    /* ---- (d) four keys descending: min is a deep left leaf ---- */
    TreeTable *t4;
    treetable_new(&t4);
    treetable_add(t4, &k4, &v4);
    treetable_add(t4, &k3, &v3);
    treetable_add(t4, &k2, &v2);
    treetable_add(t4, &k1, &v1);
    assert(balanced(t4) && sorted(t4));
    out = NULL;
    assert(treetable_get_first_key(t4, &out) == CC_OK);
    assert(*(int *)out == k1);

    return 0;
}
