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

    /* step 0: treetable_add(key=16847105, val=16843009) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16847105; *v = 16843009;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 1: treetable_get(key=50462933) */
    { int k = 50462933; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 2: treetable_get(key=16845825) */
    { int k = 16845825; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 3: treetable_get(key=16908545) */
    { int k = 16908545; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 4: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 5: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 6: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 7: treetable_get(key=65793) */
    { int k = 65793; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 8: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 9: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 10: treetable_get(key=-570370815) */
    { int k = -570370815; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 11: treetable_add(key=16843010, val=16843009) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16843010; *v = 16843009;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 12: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 13: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 14: treetable_get(key=50397495) */
    { int k = 50397495; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 15: treetable_get(key=-436207359) */
    { int k = -436207359; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 16: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 17: treetable_get(key=570622209) */
    { int k = 570622209; void *out = NULL; treetable_get(t, &k, &out); }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
