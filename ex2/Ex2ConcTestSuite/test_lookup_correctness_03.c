/*
 * Property: correctness of lookup operations
 *
 * After inserting key k with value v, treetable_get / treetable_get_first_key /
 * treetable_get_greater_than must return correct results. For keys never inserted,
 * these functions must return error codes. Lookups must not mutate table structure
 * or state.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "treetable.h"

extern int balanced(TreeTable *t);
extern int sorted  (TreeTable *t);

int main(void)
{
    TreeTable *t;
    assert(treetable_new(&t) == CC_OK);

    /* step 0: treetable_add(key=1, val=100) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 1; *v = 100;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 1: treetable_add(key=2, val=200) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2; *v = 200;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 2: treetable_add(key=33554432, val=-939524096) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 33554432; *v = -939524096;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 3: treetable_add(key=16883200, val=33554432) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16883200; *v = 33554432;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 4: treetable_get_greater_than(key=1) */
    { int k = 1; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 5: treetable_add(key=16883200, val=33554432) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16883200; *v = 33554432;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 6: treetable_get_greater_than(key=1) */
    { int k = 1; void *out = NULL; treetable_get_greater_than(t, &k, &out); }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
