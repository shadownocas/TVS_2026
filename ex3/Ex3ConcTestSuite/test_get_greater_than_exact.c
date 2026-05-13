/*
 * Concrete test suite derived from: test_get_greater_than_exact.c
 * Property: Immediate-successor precision of get_greater_than.
 *
 * get_greater_than must return the immediate successor, not just any
 * key greater than the queried one. With keys k1 < k2 < k3,
 * get_greater_than(k1) must return exactly k2, and
 * get_greater_than(k2) must return exactly k3.
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

    out = NULL;
    assert(treetable_get_greater_than(t, &k1, &out) == CC_OK);
    assert(*(int *)out == k2);

    out = NULL;
    assert(treetable_get_greater_than(t, &k2, &out) == CC_OK);
    assert(*(int *)out == k3);


    return 0;
}
