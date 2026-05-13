/*
 * Symbolic test: test_get_correctness.c
 *
 * Property: Correctness of lookup.
 */
 * for k3, covering the multi-step traversal path.
 *
 * Functions exercised: treetable_add (new-key and update paths),
 *                      treetable_get (empty-table, found, not-found,
 *                      multi-level-search paths),
 *                      treetable_size (read-only mutation guard).
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

    int absent;
    klee_make_symbolic(&absent, sizeof(absent), "absent");
    klee_assume(absent > INT_MIN);
    klee_assume(absent < INT_MAX);
    klee_assume(absent != k1);
    klee_assume(absent != k2);
    klee_assume(absent != k3);

    TreeTable *t;
    treetable_new(&t);

    int v1 = 10, v2 = 20, v3 = 30, v1_new = 99;
    void *out = NULL;

    assert(treetable_get(t, &k1, &out) == CC_ERR_KEY_NOT_FOUND);

    treetable_add(t, &k1, &v1);
    treetable_add(t, &k2, &v2);
    treetable_add(t, &k3, &v3);
    assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 3);

    out = NULL;
    assert(treetable_get(t, &k1, &out) == CC_OK);
    assert(out == &v1);

    out = NULL;
    assert(treetable_get(t, &k2, &out) == CC_OK);
    assert(out == &v2);

    out = NULL;
    assert(treetable_get(t, &k3, &out) == CC_OK);
    assert(out == &v3);

    out = NULL;
    assert(treetable_get(t, &absent, &out) == CC_ERR_KEY_NOT_FOUND);

    assert(treetable_size(t) == 3);

    treetable_add(t, &k1, &v1_new);
    assert(balanced(t) && sorted(t));
    out = NULL;
    assert(treetable_get(t, &k1, &out) == CC_OK);
    assert(out == &v1_new);

    assert(treetable_size(t) == 3);

    return 0;
}
