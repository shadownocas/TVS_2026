/*
 * Concrete test suite derived from: test_get_greater_than_exact.c
 * Property: get_greater_than returns the IMMEDIATE successor, not just
 *           any key greater than the queried one.
 *
 * With keys k1 < k2 < k3, querying get_greater_than(k1) must return
 * exactly k2, and get_greater_than(k2) must return exactly k3.
 *
 * Generated from KLEE ktest files:
 *   test000001.ktest : k1=0, k2=128, k3=16384
 */

#include <assert.h>
#include "treetable.h"

int main(void)
{
    int k1 = 0;
    int k2 = 128;
    int k3 = 16384;
    int v1=1, v2=2, v3=3;
    void *out = NULL;

    TreeTable *t;
    treetable_new(&t);
    treetable_add(t, &k1, &v1);
    treetable_add(t, &k2, &v2);
    treetable_add(t, &k3, &v3);
    assert(balanced(t) && sorted(t));

    /* successor of k1 must be exactly k2, not k3 */
    out = NULL;
    assert(treetable_get_greater_than(t, &k1, &out) == CC_OK);
    assert(*(int *)out == k2);

    /* successor of k2 must be exactly k3 */
    out = NULL;
    assert(treetable_get_greater_than(t, &k2, &out) == CC_OK);
    assert(*(int *)out == k3);


    return 0;
}
