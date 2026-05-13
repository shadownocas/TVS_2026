/*
 * Symbolic test: test_get_greater_than_absent.c
 *
 * Property: get_greater_than returns CC_ERR_KEY_NOT_FOUND for any key
 * that was never inserted into the table.
 */
#include <klee/klee.h>
#include <assert.h>
#include <limits.h>
#include "treetable.h"

int main(void)
{
    int k1, k2, absent;
    klee_make_symbolic(&k1,     sizeof(k1),     "k1");
    klee_make_symbolic(&k2,     sizeof(k2),     "k2");
    klee_make_symbolic(&absent, sizeof(absent), "absent");

    klee_assume(k1 > INT_MIN); klee_assume(k1 < INT_MAX);
    klee_assume(k2 > INT_MIN); klee_assume(k2 < INT_MAX);
    klee_assume(absent > INT_MIN); klee_assume(absent < INT_MAX);
    klee_assume(k1 != k2);
    klee_assume(absent != k1);
    klee_assume(absent != k2);

    int v = 1;
    void *out = NULL;

    TreeTable *t;
    treetable_new(&t);
    treetable_add(t, &k1, &v);
    treetable_add(t, &k2, &v);
    assert(balanced(t) && sorted(t));

    assert(treetable_get_greater_than(t, &absent, &out) == CC_ERR_KEY_NOT_FOUND);

    return 0;
}
