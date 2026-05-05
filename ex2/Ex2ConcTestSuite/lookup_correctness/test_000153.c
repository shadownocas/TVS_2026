/*
 * test_000153.c
 *
 * Group    : lookup_correctness
 * Property : LOOKUP CORRECTNESS — treetable_get / treetable_get_first_key / treetable_get_greater_than return correct results for inserted keys
 *
 * Derived from minimised corpus file: ex2/Ex2Harness/minimized_corpus/id:000153,src:000081,time:152141,op:flip2,pos:36
 * Total decoded steps: 10
 *
 * Compile (from ex2/Ex2ConcTestSuite/lookup_correctness/):
 *   gcc -g -fsanitize=address -o test_000153 test_000153.c  *       ../../../TreeTable/treetable.c -I ../../../TreeTable/
 * Run:
 *   ./test_000153
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

    /* step 0: treetable_get_greater_than(key=65798659) */
    { int k = 65798659; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 1: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 2: treetable_get_greater_than(key=50544131) */
    { int k = 50544131; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 3: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 4: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 5: treetable_get_greater_than(key=66519555) */
    { int k = 66519555; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 6: treetable_get_greater_than(key=2) */
    { int k = 2; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 7: treetable_get_greater_than(key=419446794) */
    { int k = 419446794; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 8: treetable_add(key=-939464701, val=14614528) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -939464701; *v = 14614528;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 9: treetable_add(key=62783488, val=587202561) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 62783488; *v = 587202561;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
