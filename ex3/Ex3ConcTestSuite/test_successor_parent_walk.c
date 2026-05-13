/*
 * Concrete test suite derived from: test_successor_parent_walk.c
 * Property: get_successor_node parent-walk path correctness.
 * Generated from KLEE ktest files:
 *   test000001.ktest : k1=0, k2=16777216, k3=33554432, k4=33554560, k5=33570816
 */
#include <assert.h>
#include <stdlib.h>
#include "treetable.h"

int main(void)
{
    int *k1 = malloc(sizeof(int)); *k1 = 0;
    int *k2 = malloc(sizeof(int)); *k2 = 16777216;
    int *k3 = malloc(sizeof(int)); *k3 = 33554432;
    int *k4 = malloc(sizeof(int)); *k4 = 33554560;
    int *k5 = malloc(sizeof(int)); *k5 = 33570816;
    int *v1 = malloc(sizeof(int)); *v1 = 1;
    int *v2 = malloc(sizeof(int)); *v2 = 2;
    int *v3 = malloc(sizeof(int)); *v3 = 3;
    int *v4 = malloc(sizeof(int)); *v4 = 4;
    int *v5 = malloc(sizeof(int)); *v5 = 5;
    void *out = NULL;

    TreeTable *t;
    treetable_new(&t);

    treetable_add(t, k1, v1); assert(balanced(t) && sorted(t));
    treetable_add(t, k2, v2); assert(balanced(t) && sorted(t));
    treetable_add(t, k3, v3); assert(balanced(t) && sorted(t));
    treetable_add(t, k4, v4); assert(balanced(t) && sorted(t));
    treetable_add(t, k5, v5); assert(balanced(t) && sorted(t));

    out = NULL;
    assert(treetable_get_greater_than(t, k3, &out) == CC_OK);
    assert(*(int *)out == *k4);

    out = NULL;
    assert(treetable_get_greater_than(t, k1, &out) == CC_OK);
    assert(*(int *)out == *k2);

    treetable_destroy(t);
    return 0;
}
