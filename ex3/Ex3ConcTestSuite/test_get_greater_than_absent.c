/*
 * Concrete test suite derived from: test_get_greater_than_absent.c
 * Property: get_greater_than returns CC_ERR_KEY_NOT_FOUND for any key
 * that was never inserted into the table.
 *
 * For any absent key, get_tree_node_by_key returns NULL, making n == NULL
 * and the guard (n && s) false, reaching line 231 (CC_ERR_KEY_NOT_FOUND).
 *
 * Generated from KLEE ktest files:
 *   test000001.ktest : k1=-2147483391, k2=0,           absent=-2147483520
 *   test000002.ktest : k1=65536,       k2=0,           absent=16777216
 *   test000003.ktest : k1=33554432,    k2=16777216,    absent=0
 *   test000004.ktest : k1=0,           k2=50331648,    absent=16777216
 *   test000005.ktest : k1=0,           k2=16777216,    absent=16809984
 *   test000006.ktest : k1=0,           k2=-2135900168, absent=-16777216
 */

#include <assert.h>
#include "treetable.h"

int main(void)
{
    void *out = NULL;

    {
        int k1 = -2147483391, k2 = 0, absent = -2147483520, v = 1;
        TreeTable *t; treetable_new(&t);
        treetable_add(t, &k1, &v);
        treetable_add(t, &k2, &v);
        assert(balanced(t) && sorted(t));
        out = NULL;
        assert(treetable_get_greater_than(t, &absent, &out) == CC_ERR_KEY_NOT_FOUND);
    }

    {
        int k1 = 65536, k2 = 0, absent = 16777216, v = 1;
        TreeTable *t; treetable_new(&t);
        treetable_add(t, &k1, &v);
        treetable_add(t, &k2, &v);
        assert(balanced(t) && sorted(t));
        out = NULL;
        assert(treetable_get_greater_than(t, &absent, &out) == CC_ERR_KEY_NOT_FOUND);
    }

    {
        int k1 = 33554432, k2 = 16777216, absent = 0, v = 1;
        TreeTable *t; treetable_new(&t);
        treetable_add(t, &k1, &v);
        treetable_add(t, &k2, &v);
        assert(balanced(t) && sorted(t));
        out = NULL;
        assert(treetable_get_greater_than(t, &absent, &out) == CC_ERR_KEY_NOT_FOUND);
    }

    {
        int k1 = 0, k2 = 50331648, absent = 16777216, v = 1;
        TreeTable *t; treetable_new(&t);
        treetable_add(t, &k1, &v);
        treetable_add(t, &k2, &v);
        assert(balanced(t) && sorted(t));
        out = NULL;
        assert(treetable_get_greater_than(t, &absent, &out) == CC_ERR_KEY_NOT_FOUND);
    }

    {
        int k1 = 0, k2 = 16777216, absent = 16809984, v = 1;
        TreeTable *t; treetable_new(&t);
        treetable_add(t, &k1, &v);
        treetable_add(t, &k2, &v);
        assert(balanced(t) && sorted(t));
        out = NULL;
        assert(treetable_get_greater_than(t, &absent, &out) == CC_ERR_KEY_NOT_FOUND);
    }

    {
        int k1 = 0, k2 = -2135900168, absent = -16777216, v = 1;
        TreeTable *t; treetable_new(&t);
        treetable_add(t, &k1, &v);
        treetable_add(t, &k2, &v);
        assert(balanced(t) && sorted(t));
        out = NULL;
        assert(treetable_get_greater_than(t, &absent, &out) == CC_ERR_KEY_NOT_FOUND);
    }

    return 0;
}
