/*
 * crash_000008.c
 *
 * Group    : crashes
 * Property : ASSERTION VIOLATION — balanced(t) && sorted(t) failed after
 *            treetable_add(), indicating the RB-tree invariant was broken
 *            by the sequence of insertions below.
 *
 * Signal   : SIGABRT (sig:06) — assert() called abort()
 *
 * Derived from AFL++ crash input: ex2/Ex2Harness/outputs/crashes/id:000008,sig:06,src:000000,time:892,op:havoc,rep:8
 * Total decoded steps: 8
 *
 * To reproduce (from project root):
 *   AFL_USE_ASAN=1 afl-clang-fast -g -O1 ex2/Ex2Harness/harness.c  *       TreeTable/treetable.c -I TreeTable/ -o harness_fuzz
 *   ./harness_fuzz < "ex2/Ex2Harness/outputs/crashes/id:000008,sig:06,src:000000,time:892,op:havoc,rep:8"
 *
 * Compile this test (from ex2/Ex2ConcTestSuite/crashes/):
 *   gcc -g -fsanitize=address -o crash_000008 crash_000008.c  *       ../../../TreeTable/treetable.c -I ../../../TreeTable/
 *
 * AddressSanitizer / runtime report:
 *
 * harness_fuzz: ex2/Ex2Harness/harness.c:128: int main(void): Assertion `balanced(t) && sorted(t)' failed.
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

    /* step 0: treetable_add(key=-100663552, val=131172) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -100663552; *v = 131172;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 1: treetable_add(key=0, val=16838912) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 0; *v = 16838912;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 2: treetable_add(key=33554432, val=-939474429) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 33554432; *v = -939474429;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 3: treetable_add(key=61440, val=12714754) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 61440; *v = 12714754;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 4: treetable_add(key=2, val=200) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2; *v = 200;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 5: treetable_add(key=16838912, val=0) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16838912; *v = 0;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 6: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 7: treetable_get_greater_than(key=194) */
    { int k = 194; void *out = NULL; treetable_get_greater_than(t, &k, &out); }

    treetable_destroy(t);
    return 0;
}
