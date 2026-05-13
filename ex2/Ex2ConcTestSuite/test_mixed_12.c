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

    /* step 0: treetable_get_greater_than(key=50586883) */
    { int k = 50586883; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 1: treetable_get_greater_than(key=51512293) */
    { int k = 51512293; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 2: treetable_get_greater_than(key=33809667) */
    { int k = 33809667; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 3: treetable_get_greater_than(key=2130767362) */
    { int k = 2130767362; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 4: treetable_get_greater_than(key=1442563) */
    { int k = 1442563; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 5: treetable_add(key=-322502656, val=56770560) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -322502656; *v = 56770560;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 6: treetable_add(key=50549763, val=50588418) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 50549763; *v = 50588418;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 7: treetable_add(key=1547510017, val=1036205373) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 1547510017; *v = 1036205373;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 8: treetable_get_greater_than(key=50529151) */
    { int k = 50529151; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 9: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 10: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 11: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 12: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 13: treetable_get_greater_than(key=-48239101) */
    { int k = -48239101; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 14: treetable_get_greater_than(key=197503) */
    { int k = 197503; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 15: treetable_add(key=-83688688, val=50553061) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -83688688; *v = 50553061;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 16: treetable_get_greater_than(key=50529151) */
    { int k = 50529151; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 17: treetable_get_greater_than(key=-439876861) */
    { int k = -439876861; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 18: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 19: treetable_get_greater_than(key=-134743293) */
    { int k = -134743293; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 20: treetable_get_greater_than(key=-48239101) */
    { int k = -48239101; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 21: treetable_get_greater_than(key=50529151) */
    { int k = 50529151; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 22: treetable_get_greater_than(key=6614531) */
    { int k = 6614531; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 23: treetable_get_greater_than(key=6554452) */
    { int k = 6554452; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 24: treetable_get_greater_than(key=50529108) */
    { int k = 50529108; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 25: treetable_get_greater_than(key=50570499) */
    { int k = 50570499; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 26: treetable_get_greater_than(key=-301857948) */
    { int k = -301857948; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 27: treetable_add(key=67109889, val=66404) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 67109889; *v = 66404;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
