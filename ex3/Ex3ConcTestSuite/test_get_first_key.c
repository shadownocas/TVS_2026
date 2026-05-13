/*
 * Concrete test suite derived from: test_get_first_key.c
 * Property: Correctness of minimum-key retrieval.
 *
 * After inserting a single key k, get_first_key must return k. After
 * inserting two distinct keys, get_first_key must return the smaller
 * one regardless of insertion order. After inserting four keys in
 * descending order, tree_min must correctly walk multiple left pointers
 * to reach the minimum.
 *
 * NOTE: The empty-table case is in test_get_first_key_empty.c because
 * it triggers a null-page-access bug (BUG-002).
 */

#include <assert.h>
#include "treetable.h"

int main(void)
{
    int k1 = 0;
    int k2 = 16777216;
    int k3 = 16777472;
    int k4 = 16793600;
    int v1=1, v2=2, v3=3, v4=4;
    void *out = NULL;

    TreeTable *t1;
    treetable_new(&t1);
    treetable_add(t1, &k1, &v1);
    assert(balanced(t1) && sorted(t1));
    out = NULL;
    assert(treetable_get_first_key(t1, &out) == CC_OK);
    assert(*(int *)out == k1);


    TreeTable *t2;
    treetable_new(&t2);
    treetable_add(t2, &k2, &v2);
    treetable_add(t2, &k1, &v1);
    assert(balanced(t2) && sorted(t2));
    out = NULL;
    assert(treetable_get_first_key(t2, &out) == CC_OK);
    assert(*(int *)out == k1);


    TreeTable *t4;
    treetable_new(&t4);
    treetable_add(t4, &k4, &v4);
    treetable_add(t4, &k3, &v3);
    treetable_add(t4, &k2, &v2);
    treetable_add(t4, &k1, &v1);
    assert(balanced(t4) && sorted(t4));
    out = NULL;
    assert(treetable_get_first_key(t4, &out) == CC_OK);
    assert(*(int *)out == k1);


    return 0;
}
