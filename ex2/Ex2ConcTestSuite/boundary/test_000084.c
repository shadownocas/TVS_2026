/*
 * test_000084.c
 *
 * Group    : boundary
 * Property : BOUNDARY — operations on empty table or with edge-case keys (negative, zero, large values)
 *
 * Derived from minimised corpus file: ex2/Ex2Harness/minimized_corpus/id:000084,src:000000,time:2271,op:havoc,rep:8
 * Total decoded steps: 3
 *
 * Compile (from ex2/Ex2ConcTestSuite/boundary/):
 *   gcc -g -fsanitize=address -o test_000084 test_000084.c  *       ../../../TreeTable/treetable.c -I ../../../TreeTable/
 * Run:
 *   ./test_000084
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

    /* step 0: treetable_get(key=33554432) */
    { int k = 33554432; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 1: treetable_get(key=-402524952) */
    { int k = -402524952; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 2: treetable_get(key=589824) */
    { int k = 589824; void *out = NULL; treetable_get(t, &k, &out); }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
