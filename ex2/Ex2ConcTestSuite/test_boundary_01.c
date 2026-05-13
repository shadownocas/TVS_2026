/*
 * Property: correctness with boundary conditions
 *
 * Operations on empty tables, with edge-case keys (negative, zero, large values),
 * and boundary conditions must all be handled correctly. All invariants (balance,
 * sorted order) must be preserved.
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
