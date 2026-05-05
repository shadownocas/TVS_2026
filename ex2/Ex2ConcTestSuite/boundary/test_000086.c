/*
 * test_000086.c
 *
 * Group    : boundary
 * Property : BOUNDARY — operations on empty table or with edge-case keys (negative, zero, large values)
 *
 * Derived from minimised corpus file: ex2/Ex2Harness/minimized_corpus/id:000086,src:000000,time:2283,op:havoc,rep:16
 * Total decoded steps: 8
 *
 * Compile (from ex2/Ex2ConcTestSuite/boundary/):
 *   gcc -g -fsanitize=address -o test_000086 test_000086.c  *       ../../../TreeTable/treetable.c -I ../../../TreeTable/
 * Run:
 *   ./test_000086
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

    /* step 0: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 1: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 2: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 3: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 4: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 5: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 6: treetable_get(key=1048577) */
    { int k = 1048577; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 7: treetable_get(key=259) */
    { int k = 259; void *out = NULL; treetable_get(t, &k, &out); }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
