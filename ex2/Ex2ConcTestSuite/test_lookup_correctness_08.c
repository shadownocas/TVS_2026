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

    /* step 0: treetable_get_greater_than(key=65539) */
    { int k = 65539; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 1: treetable_add(key=50529027, val=54395651) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 50529027; *v = 54395651;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 2: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 3: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 4: treetable_get_greater_than(key=1895957251) */
    { int k = 1895957251; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 5: treetable_get_greater_than(key=515) */
    { int k = 515; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 6: treetable_get_greater_than(key=65830659) */
    { int k = 65830659; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 7: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 8: treetable_get_greater_than(key=50544131) */
    { int k = 50544131; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 9: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 10: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 11: treetable_get_greater_than(key=7406083) */
    { int k = 7406083; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 12: treetable_add(key=419446794, val=15205120) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 419446794; *v = 15205120;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 13: treetable_add(key=1677778688, val=-1107296256) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 1677778688; *v = -1107296256;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 14: treetable_get_greater_than(key=587202561) */
    { int k = 587202561; void *out = NULL; treetable_get_greater_than(t, &k, &out); }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
