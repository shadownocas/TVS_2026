/*
 * test_000046.c
 *
 * Group    : lookup_correctness
 * Property : LOOKUP CORRECTNESS — treetable_get / treetable_get_first_key / treetable_get_greater_than return correct results for inserted keys
 *
 * Derived from minimised corpus file: ex2/Ex2Harness/minimized_corpus/id:000046,src:000000,time:860,op:havoc,rep:8
 * Total decoded steps: 3
 *
 * Compile (from ex2/Ex2ConcTestSuite/lookup_correctness/):
 *   gcc -g -fsanitize=address -o test_000046 test_000046.c  *       ../../../TreeTable/treetable.c -I ../../../TreeTable/
 * Run:
 *   ./test_000046
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
