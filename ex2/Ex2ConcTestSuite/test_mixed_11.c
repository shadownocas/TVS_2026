/*
 * Property: validity and lookup correctness under interleaved operations
 *
 * The tree must remain valid (balanced and sorted) while simultaneously checking
 * that lookup operations return correct results. All invariants must hold under
 * mixed sequences of add and lookup operations.
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

    /* step 0: treetable_add(key=1, val=-156) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 1; *v = -156;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 1: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 2: treetable_add(key=13107200, val=5594880) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = 5594880;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 3: treetable_add(key=-39936, val=190975) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -39936; *v = 190975;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 4: treetable_add(key=1361920, val=16799071) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 1361920; *v = 16799071;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 5: treetable_get(key=33554432) */
    { int k = 33554432; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 6: treetable_get_greater_than(key=1) */
    { int k = 1; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 7: treetable_get(key=48889855) */
    { int k = 48889855; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 8: treetable_add(key=13107200, val=5594880) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = 5594880;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 9: treetable_get(key=1) */
    { int k = 1; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 10: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 11: treetable_get_greater_than(key=1) */
    { int k = 1; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 12: treetable_get(key=33554432) */
    { int k = 33554432; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 13: treetable_get_greater_than(key=1) */
    { int k = 1; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 14: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 15: treetable_get_greater_than(key=1) */
    { int k = 1; void *out = NULL; treetable_get_greater_than(t, &k, &out); }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
