/*
 * Concrete test suite derived from: test_size_correctness.c
 * Property: Correctness of size tracking.
 *
 * A fresh table has size 0. Inserting a new key increments size by 1.
 * Inserting a duplicate key (update) must not change the size.
 */

#include <assert.h>
#include "treetable.h"

static void run_case(int k1, int k2)
{
    int v1 = 1, v2 = 2, v1b = 99;

    TreeTable *t;
    treetable_new(&t);

    assert(treetable_size(t) == 0);

    treetable_add(t, &k1, &v1);
    assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 1);

    treetable_add(t, &k2, &v2);
    assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 2);

    treetable_add(t, &k1, &v1b);
    assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 2);


}

int main(void)
{
    run_case(-2130706432, 0);
    run_case(16777216, 0);
    return 0;
}
