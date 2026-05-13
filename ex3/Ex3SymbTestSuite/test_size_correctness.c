/*
 * Symbolic test: test_size_correctness.c
 *
 * Property: Correctness of size tracking.
 */
 
#include <klee/klee.h>
#include <assert.h>
#include <limits.h>
#include "treetable.h"
 
int main(void)
{
    int k1, k2;
    klee_make_symbolic(&k1, sizeof(k1), "k1");
    klee_make_symbolic(&k2, sizeof(k2), "k2");
 
    klee_assume(k1 > INT_MIN);
    klee_assume(k1 < INT_MAX);
    klee_assume(k2 > INT_MIN);
    klee_assume(k2 < INT_MAX);
    klee_assume(k1 != k2);
 
    TreeTable *t;
    treetable_new(&t);
 
    int v1 = 1, v2 = 2, v1b = 99;
 
    assert(treetable_size(t) == 0);
 
    treetable_add(t, &k1, &v1); assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 1);
 
    treetable_add(t, &k2, &v2); assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 2);
 
    treetable_add(t, &k1, &v1b); assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 2);
 
    assert(balanced(t) && sorted(t));

    return 0;
}
 