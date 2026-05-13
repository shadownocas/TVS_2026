/*
 * Property: validity and lookup correctness under interleaved operations
 *
 * The tree must remain valid (balanced and sorted) while simultaneously checking
 * that lookup operations return correct results. All invariants must hold under
 * mixed sequences of add and lookup operations.
 *
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

    /* step 0: treetable_get_greater_than(key=33554691) */
    { int k = 33554691; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 1: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 2: treetable_add(key=66519555, val=-419495677) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 66519555; *v = -419495677;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 3: treetable_add(key=32514, val=50591490) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 32514; *v = 50591490;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 4: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 5: treetable_add(key=50529027, val=50529059) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 50529027; *v = 50529059;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 6: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 7: treetable_get_greater_than(key=-150863101) */
    { int k = -150863101; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 8: treetable_add(key=50529027, val=-402455678) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 50529027; *v = -402455678;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 9: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 10: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 11: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 12: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 13: treetable_get_greater_than(key=33751811) */
    { int k = 33751811; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 14: treetable_get_greater_than(key=50332171) */
    { int k = 50332171; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 15: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 16: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 17: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 18: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 19: treetable_get_greater_than(key=-436207101) */
    { int k = -436207101; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 20: treetable_add(key=2162944, val=-402407911) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2162944; *v = -402407911;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
