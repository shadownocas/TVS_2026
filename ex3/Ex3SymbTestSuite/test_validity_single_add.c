/*
 * Property: Validity preservation after a single insertion.
 *
 * For any integer key k (excluding INT_MIN and INT_MAX, which are used
 * as sentinels by the sorted() oracle), inserting k into a fresh
 * TreeTable must leave the tree both balanced and sorted.
 *
 * Functions exercised: treetable_add (new-key path, empty-tree branch)
 */
 
#include <klee/klee.h>
#include <assert.h>
#include <limits.h>
#include "treetable.h"
 
int main(void)
{
    /* --- symbolic input --- */
    int k;
    klee_make_symbolic(&k, sizeof(k), "k");
 
    /* exclude sentinel values used by sorted() internally */
    klee_assume(k > INT_MIN);
    klee_assume(k < INT_MAX);
 
    /* --- set up --- */
    TreeTable *t;
    treetable_new(&t);
 
    int v = 42; /* value is irrelevant for structural properties */
    treetable_add(t, &k, &v);
 
    /* --- property --- */
    assert(balanced(t) && sorted(t));
 
    /* --- tear down --- */
    /* treetable_destroy removed for KLEE */
    return 0;
}
