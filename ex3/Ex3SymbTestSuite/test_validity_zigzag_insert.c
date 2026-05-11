/*
 * Symbolic test: test_validity_zigzag_insert.c
 *
 * Forces an AVL Left-Right zigzag rotation and checks
 * tree validity invariants after each insertion.
 */

#include <assert.h>
#include <limits.h>

#include "klee/klee.h"
#include "treetable.h"

int main(void)
{
    int k1, k2, k3;
    int v = 1;

    klee_make_symbolic(&k1, sizeof(k1), "k1");
    klee_make_symbolic(&k2, sizeof(k2), "k2");
    klee_make_symbolic(&k3, sizeof(k3), "k3");

    /* Avoid sentinel collisions in sorted() */
    klee_assume(k1 < INT_MAX);
    klee_assume(k1 > INT_MIN);
    klee_assume(k2 > INT_MIN);
    klee_assume(k2 < INT_MAX);
    klee_assume(k3 < INT_MAX);
    klee_assume(k3 > INT_MIN);

    /* Distinct keys */
    klee_assume(k1 != k2);
    klee_assume(k2 != k3);
    klee_assume(k1 != k3);

    /*
     * Force Left-Right rotation:
     *
     * Insert order:
     *   k3, k1, k2
     *
     * Constraint:
     *   k1 < k2 < k3
     */
    klee_assume(k1 < k2);
    klee_assume(k2 < k3);

    TreeTable *t;
    treetable_new(&t);

    treetable_add(t, &k3, &v);
    assert(balanced(t));
    assert(sorted(t));

    treetable_add(t, &k1, &v);
    assert(balanced(t));
    assert(sorted(t));

    treetable_add(t, &k2, &v);
    assert(balanced(t));
    assert(sorted(t));

    return 0;
}