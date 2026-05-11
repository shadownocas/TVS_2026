/*
 * Concrete test suite derived from: test_size_correctness.c
 * Property: Size correctness.
 *   (a) A fresh table has size 0.
 *   (b) Inserting a new key increments size by 1.
 *   (c) Inserting a duplicate key (update) does NOT change the size.
 *
 * Generated from KLEE ktest files:
 *   test000001.ktest : k1=-2130706432, k2=0
 *   test000002.ktest : k1=16777216,    k2=0
 */

#include <assert.h>
#include "treetable.h"

static void run_case(int k1, int k2)
{
    int v1 = 1, v2 = 2, v1b = 99;

    TreeTable *t;
    treetable_new(&t);

    /* (a) fresh table */
    assert(treetable_size(t) == 0);

    /* (b) new key increases size */
    treetable_add(t, &k1, &v1);
    assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 1);

    treetable_add(t, &k2, &v2);
    assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 2);

    /* (c) duplicate key: size must stay the same */
    treetable_add(t, &k1, &v1b);
    assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 2);


}

int main(void)
{
    /* test000001 */
    run_case(-2130706432, 0);
    /* test000002 */
    run_case(16777216, 0);
    return 0;
}
