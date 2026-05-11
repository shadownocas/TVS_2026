/*
 * Property: Lookup correctness.
 *
 * (a) After inserting key k with value v, treetable_get(t, k) must
 *     return CC_OK and the retrieved value must equal v.
 * (b) For a key that was never inserted, treetable_get must return
 *     CC_ERR_KEY_NOT_FOUND — tested on an empty table and on a populated
 *     one (exercises both the size==0 early-exit and the do-while search
 *     loop in get_tree_node_by_key).
 * (c) After updating k1 with a new value, treetable_get must return the
 *     updated value, not the original.
 * (d) Read-only operations (treetable_get) must not mutate the table size.
 *
 * Three keys k1 < k2 < k3 are used so that get_tree_node_by_key's
 * do-while loop must walk at least two levels of the tree when searching
 * for k3, covering the multi-step traversal path.
 *
 * Functions exercised: treetable_add (new-key and update paths),
 *                      treetable_get (empty-table, found, not-found,
 *                      multi-level-search paths),
 *                      treetable_size (read-only mutation guard).
 */

#include <klee/klee.h>
#include <assert.h>
#include <limits.h>
#include "treetable.h"

int main(void)
{
    /* --- symbolic inputs: three distinct keys in ascending order --- */
    int k1, k2, k3;
    klee_make_symbolic(&k1, sizeof(k1), "k1");
    klee_make_symbolic(&k2, sizeof(k2), "k2");
    klee_make_symbolic(&k3, sizeof(k3), "k3");

    klee_assume(k1 > INT_MIN);
    klee_assume(k1 < INT_MAX);
    klee_assume(k2 > INT_MIN);
    klee_assume(k2 < INT_MAX);
    klee_assume(k3 > INT_MIN);
    klee_assume(k3 < INT_MAX);
    klee_assume(k1 < k2);
    klee_assume(k2 < k3);

    /* an absent key guaranteed different from all three */
    int absent;
    klee_make_symbolic(&absent, sizeof(absent), "absent");
    klee_assume(absent > INT_MIN);
    klee_assume(absent < INT_MAX);
    klee_assume(absent != k1);
    klee_assume(absent != k2);
    klee_assume(absent != k3);

    /* --- set up --- */
    TreeTable *t;
    treetable_new(&t);

    int v1 = 10, v2 = 20, v3 = 30, v1_new = 99;
    void *out = NULL;

    /* (b) empty table — size==0 early-exit path in get_tree_node_by_key */
    assert(treetable_get(t, &k1, &out) == CC_ERR_KEY_NOT_FOUND);

    treetable_add(t, &k1, &v1);
    treetable_add(t, &k2, &v2);
    treetable_add(t, &k3, &v3);
    assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 3);

    /* (a) all three keys must be found with correct values */
    out = NULL;
    assert(treetable_get(t, &k1, &out) == CC_OK);
    assert(out == &v1);

    out = NULL;
    assert(treetable_get(t, &k2, &out) == CC_OK);
    assert(out == &v2);

    /* k3 requires walking at least two levels in get_tree_node_by_key */
    out = NULL;
    assert(treetable_get(t, &k3, &out) == CC_OK);
    assert(out == &v3);

    /* (b) absent key on a populated table — do-while loop exhausts tree */
    out = NULL;
    assert(treetable_get(t, &absent, &out) == CC_ERR_KEY_NOT_FOUND);

    /* (d) size must be unchanged after read-only get calls */
    assert(treetable_size(t) == 3);

    /* (c) after update, get returns the new value */
    treetable_add(t, &k1, &v1_new);
    assert(balanced(t) && sorted(t));
    out = NULL;
    assert(treetable_get(t, &k1, &out) == CC_OK);
    assert(out == &v1_new);

    /* size must still be 3 after an update (not a new key) */
    assert(treetable_size(t) == 3);

    /* --- tear down --- */
    /* treetable_destroy removed for KLEE */
    return 0;
}
