/*
 * Concrete test suite derived from: test_validity_zigzag_insert.c
 * Property: Validity preservation after a Left-Right zigzag insertion pattern.
 *
 * Insertion order k3, k1, k2 with k1 < k2 < k3 forces a Left-Right double
 * rotation inside rebalance_after_insert, exercising the zigzag (LR) case
 * of the RB-tree rebalancer.
 *
 * Generated from KLEE ktest files:
 *   test000001.ktest : k1=0, k2=486539265, k3=553648384
 */

#include <assert.h>
#include "treetable.h"

int main(void)
{
    int k1 = 0;
    int k2 = 486539265;
    int k3 = 553648384;
    int v = 1;

    TreeTable *t;
    treetable_new(&t);

    treetable_add(t, &k3, &v);
    assert(balanced(t));
    assert(sorted(t));

    treetable_add(t, &k1, &v);
    assert(balanced(t));
    assert(sorted(t));

    treetable_add(t, &k2, &v);
    assert(balanced(t));
    assert(sorted(t));


    return 0;
}