/*
 * test_000120.c
 *
 * Group    : mixed
 * Property : VALIDITY + LOOKUP — interleaved add and lookup operations; checks both invariants and return values
 *
 * Derived from minimised corpus file: ex2/Ex2Harness/minimized_corpus/id:000120,src:000000,time:19572,op:havoc,rep:4
 * Total decoded steps: 5
 *
 * Compile (from ex2/Ex2ConcTestSuite/mixed/):
 *   gcc -g -fsanitize=address -o test_000120 test_000120.c  *       ../../../TreeTable/treetable.c -I ../../../TreeTable/
 * Run:
 *   ./test_000120
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

    /* step 0: treetable_add(key=16843009, val=16843009) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16843009; *v = 16843009;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 1: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 2: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 3: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 4: treetable_get_greater_than(key=2561) */
    { int k = 2561; void *out = NULL; treetable_get_greater_than(t, &k, &out); }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
