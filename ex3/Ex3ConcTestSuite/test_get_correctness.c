/*
 * Concrete test suite derived from: test_get_correctness.c
 * Property: Correctness of lookup.
 *
 * After inserting key k with value v, treetable_get must return CC_OK
 * and the retrieved value must equal v. For a key never inserted,
 * treetable_get must return CC_ERR_KEY_NOT_FOUND. After updating k1
 * with a new value, treetable_get must return the updated value.
 */

#include <assert.h>
#include "treetable.h"

static void run_case(int k1, int k2, int k3, int absent)
{
    int v1 = 10, v2 = 20, v3 = 30, v1_new = 99;
    void *out = NULL;

    TreeTable *t;
    treetable_new(&t);

    assert(treetable_get(t, &k1, &out) == CC_ERR_KEY_NOT_FOUND);

    treetable_add(t, &k1, &v1);
    treetable_add(t, &k2, &v2);
    treetable_add(t, &k3, &v3);
    assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 3);

    out = NULL;
    assert(treetable_get(t, &k1, &out) == CC_OK);
    assert(out == &v1);

    out = NULL;
    assert(treetable_get(t, &k2, &out) == CC_OK);
    assert(out == &v2);

    out = NULL;
    assert(treetable_get(t, &k3, &out) == CC_OK);
    assert(out == &v3);

    out = NULL;
    assert(treetable_get(t, &absent, &out) == CC_ERR_KEY_NOT_FOUND);

    assert(treetable_size(t) == 3);

    treetable_add(t, &k1, &v1_new);
    assert(balanced(t) && sorted(t));
    out = NULL;
    assert(treetable_get(t, &k1, &out) == CC_OK);
    assert(out == &v1_new);

    assert(treetable_size(t) == 3);


}

int main(void)
{
    run_case(-2130706432, -1073741824, 16777216, 0);
    run_case(256, 65536, 16777216, 0);
    run_case(0, 65536, 65537, 16777216);
    run_case(0, 33554432, 33554560, 16777216);

    return 0;
}
