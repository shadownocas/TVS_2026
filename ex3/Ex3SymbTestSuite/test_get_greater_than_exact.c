/*
 * Property: get_greater_than returns the IMMEDIATE successor, not just
 *           any key greater than the queried one.
 *
 * With keys k1 < k2 < k3 in the table, querying get_greater_than(k1)
 * must return exactly k2 (the next key in sorted order), NOT k3.
 * Similarly, querying get_greater_than(k2) must return exactly k3.
 *
 * This distinguishes a correct successor implementation from a naive one
 * that might return any larger key. It exercises the in-order traversal
 * logic inside get_successor_node more precisely than
 * test_get_greater_than.c, which only checks strict-greater-than.
 *
 * Functions exercised: treetable_add, treetable_get_greater_than,
 *                      get_successor_node (exact successor value check).
 */

#include <klee/klee.h>
#include <assert.h>
#include <limits.h>
#include "treetable.h"

int main(void)
{
    /* --- symbolic inputs: three distinct keys in strict ascending order --- */
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

    /* --- set up --- */
    TreeTable *t;
    treetable_new(&t);

    int v1=1, v2=2, v3=3;
    treetable_add(t, &k1, &v1);
    treetable_add(t, &k2, &v2);
    treetable_add(t, &k3, &v3);
    assert(balanced(t) && sorted(t));

    void *out = NULL;

    /* successor of k1 must be exactly k2, not k3 */
    assert(treetable_get_greater_than(t, &k1, &out) == CC_OK);
    assert(*(int *)out == k2);

    /* successor of k2 must be exactly k3 */
    out = NULL;
    assert(treetable_get_greater_than(t, &k2, &out) == CC_OK);
    assert(*(int *)out == k3);

    /* --- tear down --- */
    /* treetable_destroy removed for KLEE */
    return 0;
}
