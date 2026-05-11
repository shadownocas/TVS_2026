/*
 * Concrete test suite derived from: test_contains_key.c
 * Property: contains_key correctness.
 *   (a) A key that has been inserted must be found by treetable_contains_key.
 *   (b) A key that has never been inserted must NOT be found.
 *   (c) After a duplicate/update insert, the key is still found
 *       (update must not remove the node).
 *
 * Generated from KLEE ktest files:
 *   test000001.ktest : k1=-2130706432, k2=0
 *   test000002.ktest : k1=16777216,    k2=0
 */

#include <assert.h>
#include "treetable.h"

static void test_case_1(void)
{
    /* KLEE test000001: k1=-2130706432, k2=0 */
    int k1 = -2130706432;
    int k2 = 0;
    int v1 = 7, v1b = 77;

    TreeTable *t;
    treetable_new(&t);

    /* (b) before any insert, neither key is present */
    assert(!treetable_contains_key(t, &k1));
    assert(!treetable_contains_key(t, &k2));

    treetable_add(t, &k1, &v1);
    assert(balanced(t) && sorted(t));

    /* (a) k1 is now present */
    assert(treetable_contains_key(t, &k1));

    /* (b) k2 was never inserted */
    assert(!treetable_contains_key(t, &k2));

    /* (c) update does not remove k1 */
    treetable_add(t, &k1, &v1b);
    assert(treetable_contains_key(t, &k1));

    assert(balanced(t) && sorted(t));


}

static void test_case_2(void)
{
    /* KLEE test000002: k1=16777216, k2=0 */
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
