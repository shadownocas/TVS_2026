/*
 * Symbolic test: test_get_greater_than_exact.c
 *
 * Property: Immediate-successor precision of get_greater_than.
 */

#include <klee/klee.h>
#include <assert.h>
#include <limits.h>
#include "treetable.h"

int main(void)
{
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

    TreeTable *t;
    treetable_new(&t);

    int v1=1, v2=2, v3=3;
    treetable_add(t, &k1, &v1);
    treetable_add(t, &k2, &v2);
    treetable_add(t, &k3, &v3);
    assert(balanced(t) && sorted(t));

    void *out = NULL;

    assert(treetable_get_greater_than(t, &k1, &out) == CC_OK);
    assert(*(int *)out == k2);

    out = NULL;
    assert(treetable_get_greater_than(t, &k2, &out) == CC_OK);
    assert(*(int *)out == k3);

    return 0;
}
