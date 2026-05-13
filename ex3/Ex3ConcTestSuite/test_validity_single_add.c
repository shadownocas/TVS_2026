/*
 * Concrete test suite derived from: test_validity_single_add.c
 * Property: Validity preservation after single zigzag insertion.
 *
 * Inserting keys in the order k3, k1, k2 (with k1 < k2 < k3) forces
 * a Left-Right double rotation inside rebalance_after_insert. The tree
 * must remain a valid, balanced BST after this zigzag (L-R) case.
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
