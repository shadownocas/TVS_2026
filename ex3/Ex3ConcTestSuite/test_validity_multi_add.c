/*
 * Concrete test suite derived from: test_validity_multi_add.c
 * Property: Validity preservation after multiple insertions, including
 *           a duplicate key update, in both ascending and descending order.
 *
 *   (A) Keys inserted in ascending order — forces right-heavy growth and
 *       left-rotations inside rebalance_after_insert (R-R cases).
 *   (B) Keys inserted in descending order — forces left-heavy growth and
 *       right-rotations (L-L cases).
 *
 * Generated from KLEE ktest files:
 *   test000001.ktest :
 *     a1=0, a2=16777216, a3=33554432, a4=33554560, a5=33570816
 *     b1=0, b2=16777216, b3=33554432, b4=33554560, b5=33570816
 */

#include <assert.h>
#include "treetable.h"

int main(void)
{
    /* ---- Table A: ascending insertion ---- */
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

    /* duplicate/update: re-insert middle key with a different value */
    treetable_add(ta, &a3, &vdup_a);
    assert(balanced(ta) && sorted(ta));



    /* ---- Table B: descending insertion ---- */
    int b1 = 0;
    int b2 = 16777216;
    int b3 = 33554432;
    int b4 = 33554560;
    int b5 = 33570816;
    int vb = 2, vdup_b = 88;

    TreeTable *tb;
    treetable_new(&tb);

    /* insert in descending value order: b5, b4, b3, b2, b1 */
    treetable_add(tb, &b5, &vb); assert(balanced(tb) && sorted(tb));
    treetable_add(tb, &b4, &vb); assert(balanced(tb) && sorted(tb));
    treetable_add(tb, &b3, &vb); assert(balanced(tb) && sorted(tb));
    treetable_add(tb, &b2, &vb); assert(balanced(tb) && sorted(tb));
    treetable_add(tb, &b1, &vb); assert(balanced(tb) && sorted(tb));

    /* duplicate/update: re-insert middle key with a different value */
    treetable_add(tb, &b3, &vdup_b);
    assert(balanced(tb) && sorted(tb));


    return 0;
}
