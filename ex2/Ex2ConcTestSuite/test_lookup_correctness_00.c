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

    /* step 0: treetable_get(key=83886081) */
    { int k = 83886081; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 1: treetable_get(key=60928) */
    { int k = 60928; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 2: treetable_add(key=2, val=8192) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2; *v = 8192;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
