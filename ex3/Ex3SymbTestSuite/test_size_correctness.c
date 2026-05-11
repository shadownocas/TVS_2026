/*
 * Property: Size correctness.
 *
 * (a) A fresh table has size 0.
 * (b) Inserting a new key increments size by 1.
 * (c) Inserting a duplicate key (update) does NOT change the size.
 *
 * Uses two symbolic keys k1 != k2 to exercise both the new-key and the
 * update branches of treetable_add while verifying the size invariant.
 *
 * Functions exercised: treetable_add (new-key and update branches),
 *                      treetable_size
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
    klee_assume(k1 != k2);
 
    /* --- set up --- */
    TreeTable *t;
    treetable_new(&t);
 
    int v1 = 1, v2 = 2, v1b = 99;
 
    /* (a) fresh table */
    assert(treetable_size(t) == 0);
 
    /* (b) new key increases size */
    treetable_add(t, &k1, &v1); assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 1);
 
    treetable_add(t, &k2, &v2); assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 2);
 
    /* (c) duplicate key: size must stay the same */
    treetable_add(t, &k1, &v1b); assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 2);
 
    assert(balanced(t) && sorted(t));
 
    /* --- tear down --- */
    /* treetable_destroy removed for KLEE */
    return 0;
}
 