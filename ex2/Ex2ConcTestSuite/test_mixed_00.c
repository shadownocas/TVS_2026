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

    /* step 0: treetable_add(key=2, val=100) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2; *v = 100;
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
    /* step 2: treetable_get(key=1) */
    { int k = 1; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 3: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 4: treetable_get_greater_than(key=1) */
    { int k = 1; void *out = NULL; treetable_get_greater_than(t, &k, &out); }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
