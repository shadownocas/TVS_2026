/*
 * Symbolic test: test_successor_parent_walk.c
 *
 * Property: get_successor_node parent-walk path correctness.
 */

#include <klee/klee.h>
#include <assert.h>
#include <limits.h>
#include "treetable.h"

int main(void)
{
    int k1, k2, k3, k4, k5;
    klee_make_symbolic(&k1, sizeof(k1), "k1");
    klee_make_symbolic(&k2, sizeof(k2), "k2");
    klee_make_symbolic(&k3, sizeof(k3), "k3");
    klee_make_symbolic(&k4, sizeof(k4), "k4");
    klee_make_symbolic(&k5, sizeof(k5), "k5");

    klee_assume(k1 > INT_MIN);
    klee_assume(k1 < INT_MAX);
    klee_assume(k2 > INT_MIN);
    klee_assume(k2 < INT_MAX);
    klee_assume(k3 > INT_MIN);
    klee_assume(k3 < INT_MAX);
    klee_assume(k4 > INT_MIN);
    klee_assume(k4 < INT_MAX);
    klee_assume(k5 > INT_MIN);
    klee_assume(k5 < INT_MAX);
    klee_assume(k1 < k2);
    klee_assume(k2 < k3);
    klee_assume(k3 < k4);
    klee_assume(k4 < k5);

    int v = 1;
    void *out = NULL;

    TreeTable *t;
    treetable_new(&t);

    treetable_add(t, &k1, &v); assert(balanced(t) && sorted(t));
    treetable_add(t, &k2, &v); assert(balanced(t) && sorted(t));
    treetable_add(t, &k3, &v); assert(balanced(t) && sorted(t));
    treetable_add(t, &k4, &v); assert(balanced(t) && sorted(t));
    treetable_add(t, &k5, &v); assert(balanced(t) && sorted(t));

    out = NULL;
    assert(treetable_get_greater_than(t, &k3, &out) == CC_OK);
    assert(*(int *)out == k4);

    out = NULL;
    assert(treetable_get_greater_than(t, &k1, &out) == CC_OK);
    assert(*(int *)out == k2);

    return 0;
}
