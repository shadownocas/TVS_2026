/*
 * Property: monotonicity of get_greater_than
 *
 * For a key absent from the table, must return CC_ERR_KEY_NOT_FOUND.
 * For the maximum key (no successor), must return CC_ERR_KEY_NOT_FOUND.
 * For a key with a successor in its right subtree, must return CC_OK
 * and a value strictly greater than the queried key. For a key whose
 * successor is an ancestor, must still return the correct strictly-greater key.
 *
 * NOTE: Running this test will trigger an assertion failure at the
 *       "BUG-001" assertion below.
 */

#include <assert.h>
#include "treetable.h"

int main(void)
{
    int k1 = 1;
    int k2 = 256;
    int k3 = 65536;
    int k4 = 16777216;
    int absent = 0;

    int v1=1, v2=2, v3=3, v4=4;
    void *out = NULL;

    TreeTable *ta;
    treetable_new(&ta);
    treetable_add(ta, &k1, &v1);
    treetable_add(ta, &k2, &v2);
    treetable_add(ta, &k3, &v3);
    treetable_add(ta, &k4, &v4);
    assert(balanced(ta) && sorted(ta));

    out = NULL;
    assert(treetable_get_greater_than(ta, &absent, &out) == CC_ERR_KEY_NOT_FOUND);

    /* BUG-001: maximum key has no successor — should return
     * CC_ERR_KEY_NOT_FOUND but returns CC_OK with sentinel garbage. */
    out = NULL;
    assert(treetable_get_greater_than(ta, &k4, &out) == CC_ERR_KEY_NOT_FOUND);

    out = NULL;
    assert(treetable_get_greater_than(ta, &k1, &out) == CC_OK);
    assert(*(int *)out > k1);

    out = NULL;
    assert(treetable_get_greater_than(ta, &k2, &out) == CC_OK);
    assert(*(int *)out > k2);

    TreeTable *tb;
    treetable_new(&tb);
    treetable_add(tb, &k4, &v4);
    treetable_add(tb, &k3, &v3);
    treetable_add(tb, &k2, &v2);
    treetable_add(tb, &k1, &v1);
    assert(balanced(tb) && sorted(tb));

    out = NULL;
    assert(treetable_get_greater_than(tb, &k1, &out) == CC_OK);
    assert(*(int *)out > k1);

    out = NULL;
    assert(treetable_get_greater_than(tb, &k2, &out) == CC_OK);
    assert(*(int *)out > k2);

    out = NULL;
    assert(treetable_get_greater_than(tb, &k4, &out) == CC_ERR_KEY_NOT_FOUND);



    return 0;
}
