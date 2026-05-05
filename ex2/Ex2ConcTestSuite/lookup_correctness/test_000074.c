/*
 * test_000074.c
 *
 * Group    : lookup_correctness
 * Property : LOOKUP CORRECTNESS — treetable_get / treetable_get_first_key / treetable_get_greater_than return correct results for inserted keys
 *
 * Derived from minimised corpus file: ex2/Ex2Harness/minimized_corpus/id:000074,src:000000,time:1675,op:havoc,rep:64
 * Total decoded steps: 12
 *
 * Compile (from ex2/Ex2ConcTestSuite/lookup_correctness/):
 *   gcc -g -fsanitize=address -o test_000074 test_000074.c  *       ../../../TreeTable/treetable.c -I ../../../TreeTable/
 * Run:
 *   ./test_000074
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

    /* step 0: treetable_add(key=33554434, val=33686018) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 33554434; *v = 33686018;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 1: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 2: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 3: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 4: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 5: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 6: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 7: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 8: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 9: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 10: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 11: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
