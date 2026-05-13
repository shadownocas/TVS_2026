/*
 * Symbolic test: test_contains_key.c
 *
 * Property: Correctness of membership testing.
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

    int v1 = 7, v1b = 77;

    assert(!treetable_contains_key(t, &k1));
    assert(!treetable_contains_key(t, &k2));

    treetable_add(t, &k1, &v1);
    assert(balanced(t) && sorted(t));

    assert(treetable_contains_key(t, &k1));

    assert(!treetable_contains_key(t, &k2));

    treetable_add(t, &k1, &v1b);
    assert(treetable_contains_key(t, &k1));

    assert(balanced(t) && sorted(t));

    return 0;
}
