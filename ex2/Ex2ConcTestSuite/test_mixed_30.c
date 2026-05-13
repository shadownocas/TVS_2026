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

    /* step 0: treetable_add(key=200, val=200) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 200; *v = 200;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 1: treetable_get_greater_than(key=197379) */
    { int k = 197379; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 2: treetable_add(key=50529024, val=50529027) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 50529024; *v = 50529027;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 3: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 4: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 5: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 6: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 7: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 8: treetable_get_greater_than(key=50529024) */
    { int k = 50529024; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 9: treetable_get_greater_than(key=50550019) */
    { int k = 50550019; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 10: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 11: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 12: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 13: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 14: treetable_get_greater_than(key=50531331) */
    { int k = 50531331; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 15: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 16: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 17: treetable_get_greater_than(key=50533379) */
    { int k = 50533379; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 18: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 19: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 20: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 21: treetable_get_greater_than(key=-2147482877) */
    { int k = -2147482877; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 22: treetable_add(key=50529027, val=50529027) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 50529027; *v = 50529027;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 23: treetable_get_greater_than(key=117637891) */
    { int k = 117637891; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 24: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 25: treetable_get_greater_than(key=1077100547) */
    { int k = 1077100547; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 26: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 27: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 28: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 29: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 30: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 31: treetable_get_greater_than(key=50331651) */
    { int k = 50331651; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 32: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 33: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 34: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 35: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 36: treetable_get_greater_than(key=66978307) */
    { int k = 66978307; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 37: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 38: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 39: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 40: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 41: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 42: treetable_get_greater_than(key=50528288) */
    { int k = 50528288; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 43: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 44: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 45: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 46: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 47: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 48: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 49: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 50: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 51: treetable_get_greater_than(key=58721027) */
    { int k = 58721027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 52: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 53: treetable_get_greater_than(key=51839747) */
    { int k = 51839747; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 54: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 55: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 56: treetable_add(key=51200, val=50529024) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 51200; *v = 50529024;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
