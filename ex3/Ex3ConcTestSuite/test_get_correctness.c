/*
 * Concrete test suite derived from: test_get_correctness.c
 * Property: Lookup correctness.
 *   (a) After inserting key k with value v, treetable_get must return CC_OK
 *       and the retrieved value must equal v.
 *   (b) For a key never inserted, treetable_get must return CC_ERR_KEY_NOT_FOUND
 *       (empty-table early-exit and populated-table do-while exhaustion paths).
 *   (c) After updating k1 with a new value, treetable_get must return the
 *       updated value.
 *   (d) Read-only treetable_get must not mutate the table size.
 *
 * Generated from KLEE ktest files:
 *   test000001.ktest : k1=-2130706432, k2=-1073741824, k3=16777216,  absent=0
 *   test000002.ktest : k1=256,         k2=65536,       k3=16777216,  absent=0
 *   test000003.ktest : k1=0,           k2=65536,       k3=65537,     absent=16777216
 *   test000004.ktest : k1=0,           k2=33554432,    k3=33554560,  absent=16777216
 */

#include <assert.h>
#include "treetable.h"

static void run_case(int k1, int k2, int k3, int absent)
{
    int v1 = 10, v2 = 20, v3 = 30, v1_new = 99;
    void *out = NULL;

    TreeTable *t;
    treetable_new(&t);

    /* (b) empty table — size==0 early-exit path */
    assert(treetable_get(t, &k1, &out) == CC_ERR_KEY_NOT_FOUND);

    treetable_add(t, &k1, &v1);
    treetable_add(t, &k2, &v2);
    treetable_add(t, &k3, &v3);
    assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 3);

    /* (a) all three keys found with correct values */
    out = NULL;
    assert(treetable_get(t, &k1, &out) == CC_OK);
    assert(out == &v1);

    out = NULL;
    assert(treetable_get(t, &k2, &out) == CC_OK);
    assert(out == &v2);

    out = NULL;
    assert(treetable_get(t, &k3, &out) == CC_OK);
    assert(out == &v3);

    /* (b) absent key on populated table */
    out = NULL;
    assert(treetable_get(t, &absent, &out) == CC_ERR_KEY_NOT_FOUND);

    /* (d) size unchanged after read-only calls */
    assert(treetable_size(t) == 3);

    /* (c) after update, get returns the new value */
    treetable_add(t, &k1, &v1_new);
    assert(balanced(t) && sorted(t));
    out = NULL;
    assert(treetable_get(t, &k1, &out) == CC_OK);
    assert(out == &v1_new);

    /* size stays 3 after an update (not a new key) */
    assert(treetable_size(t) == 3);


}

int main(void)
{
    /* test000001 */
    run_case(-2130706432, -1073741824, 16777216, 0);
    /* test000002 */
    run_case(256, 65536, 16777216, 0);
    /* test000003 */
    run_case(0, 65536, 65537, 16777216);
    /* test000004 */
    run_case(0, 33554432, 33554560, 16777216);

    return 0;
}
