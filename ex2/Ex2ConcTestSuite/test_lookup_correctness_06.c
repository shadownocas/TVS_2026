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

    /* step 0: treetable_add(key=-261631, val=2) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -261631; *v = 2;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 1: treetable_add(key=50528256, val=771) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 50528256; *v = 771;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 2: treetable_add(key=50529027, val=50529027) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 50529027; *v = 50529027;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 3: treetable_get_greater_than(key=-16645931) */
    { int k = -16645931; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 4: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 5: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 6: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 7: treetable_add(key=50529026, val=637534408) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 50529026; *v = 637534408;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
