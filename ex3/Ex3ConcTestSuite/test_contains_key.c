/*
 * Concrete test suite derived from: test_contains_key.c
 * Property: Correctness of membership testing.
 *
 * A key that has been inserted must be found by treetable_contains_key.
 * A key that has never been inserted must not be found. After a
 * duplicate/update insert, the key must still be found.
 */

#include <assert.h>
#include "treetable.h"

static void test_case_1(void)
{
    int k1 = -2130706432;
    int k2 = 0;
    int v1 = 7, v1b = 77;

    TreeTable *t;
    treetable_new(&t);

    assert(!treetable_contains_key(t, &k1));
    assert(!treetable_contains_key(t, &k2));

    treetable_add(t, &k1, &v1);
    assert(balanced(t) && sorted(t));

    assert(treetable_contains_key(t, &k1));

    assert(!treetable_contains_key(t, &k2));

    treetable_add(t, &k1, &v1b);
    assert(treetable_contains_key(t, &k1));

    assert(balanced(t) && sorted(t));


}

static void test_case_2(void)
{
    int k1 = 16777216;
    int k2 = 0;
    int v1 = 7, v1b = 77;

    TreeTable *t;
    treetable_new(&t);

    assert(!treetable_contains_key(t, &k1));
    assert(!treetable_contains_key(t, &k2));

    treetable_add(t, &k1, &v1);
    assert(balanced(t) && sorted(t));

    assert(treetable_contains_key(t, &k1));
    assert(!treetable_contains_key(t, &k2));

    treetable_add(t, &k1, &v1b);
    assert(treetable_contains_key(t, &k1));

    assert(balanced(t) && sorted(t));


}

int main(void)
{
    test_case_1();
    test_case_2();
    return 0;
}
