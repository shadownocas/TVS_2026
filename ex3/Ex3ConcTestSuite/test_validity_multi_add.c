/*
 * Concrete test suite derived from: test_validity_multi_add.c
 * Property: Validity preservation after multiple insertions.
 *
 * The tree must remain a valid, balanced BST after inserting multiple
 * keys in ascending order (forcing R-R left-rotations) and in descending
 * order (forcing L-L right-rotations), including a duplicate key update.
 */

#include <assert.h>
#include "treetable.h"

int main(void)
{
    int a1 = 0;
    int a2 = 16777216;
    int a3 = 33554432;
    int a4 = 33554560;
    int a5 = 33570816;
    int va = 1, vdup_a = 99;

    TreeTable *ta;
    treetable_new(&ta);

    treetable_add(ta, &a1, &va); assert(balanced(ta) && sorted(ta));
    treetable_add(ta, &a2, &va); assert(balanced(ta) && sorted(ta));
    treetable_add(ta, &a3, &va); assert(balanced(ta) && sorted(ta));
    treetable_add(ta, &a4, &va); assert(balanced(ta) && sorted(ta));
    treetable_add(ta, &a5, &va); assert(balanced(ta) && sorted(ta));

    treetable_add(ta, &a3, &vdup_a);
    assert(balanced(ta) && sorted(ta));



    int b1 = 0;
    int b2 = 16777216;
    int b3 = 33554432;
    int b4 = 33554560;
    int b5 = 33570816;
    int vb = 2, vdup_b = 88;

    TreeTable *tb;
    treetable_new(&tb);

    treetable_add(tb, &b5, &vb); assert(balanced(tb) && sorted(tb));
    treetable_add(tb, &b4, &vb); assert(balanced(tb) && sorted(tb));
    treetable_add(tb, &b3, &vb); assert(balanced(tb) && sorted(tb));
    treetable_add(tb, &b2, &vb); assert(balanced(tb) && sorted(tb));
    treetable_add(tb, &b1, &vb); assert(balanced(tb) && sorted(tb));

    treetable_add(tb, &b3, &vdup_b);
    assert(balanced(tb) && sorted(tb));


    return 0;
}
