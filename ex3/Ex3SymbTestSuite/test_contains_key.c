/*
 * Property: contains_key correctness.
 *
 * (a) A key that has been inserted must be found by treetable_contains_key.
 * (b) A key that has never been inserted must NOT be found.
 * (c) After a duplicate/update insert, the key is still found (regression
 *     guard: update must not remove the node).
 *
 * This test drives treetable_get (called internally by contains_key via
 * get_tree_node_by_key) along both the found and not-found paths,
 * complementing test_get_correctness.c with a boolean-result perspective.
 *
 * Functions exercised: treetable_add, treetable_get (indirectly through
 *                      treetable_contains_key → get_tree_node_by_key)
 */

#include <klee/klee.h>
#include <assert.h>
#include <limits.h>
#include "treetable.h"

int main(void)
{
    /* --- symbolic inputs --- */
    int k1, k2;
    klee_make_symbolic(&k1, sizeof(k1), "k1");
    klee_make_symbolic(&k2, sizeof(k2), "k2");

    klee_assume(k1 > INT_MIN);
    klee_assume(k1 < INT_MAX);
    klee_assume(k2 > INT_MIN);
    klee_assume(k2 < INT_MAX);
    klee_assume(k1 != k2);   /* k2 is guaranteed absent */

    /* --- set up --- */
    TreeTable *t;
    treetable_new(&t);

    int v1 = 7, v1b = 77;

    /* (b) before any insert, neither key is present */
    assert(!treetable_contains_key(t, &k1));
    assert(!treetable_contains_key(t, &k2));

    treetable_add(t, &k1, &v1);
    assert(balanced(t) && sorted(t));

    /* (a) k1 is now present */
    assert(treetable_contains_key(t, &k1));

    /* (b) k2 was never inserted */
    assert(!treetable_contains_key(t, &k2));

    /* (c) update does not remove k1 */
    treetable_add(t, &k1, &v1b);
    assert(treetable_contains_key(t, &k1));

    assert(balanced(t) && sorted(t));

    /* --- tear down --- */
    /* treetable_destroy removed for KLEE */
    return 0;
}
