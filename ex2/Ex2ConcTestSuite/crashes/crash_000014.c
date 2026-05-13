/*
 * crash_000014.c
 *
 * Group    : crashes
 * Property : ASSERTION VIOLATION — balanced(t) && sorted(t) failed after
 *            treetable_add(), indicating the RB-tree invariant was broken
 *            by the sequence of insertions below.
 *
 * Signal   : SIGABRT (sig:06) — assert() called abort()
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

    /* step 0: treetable_add(key=1, val=256) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 1; *v = 256;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 1: treetable_add(key=100, val=512) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 100; *v = 512;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 2: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 3: treetable_add(key=13107200, val=-939524096) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = -939524096;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 4: treetable_add(key=16842752, val=33554432) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16842752; *v = 33554432;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 5: treetable_get_greater_than(key=6553601) */
    { int k = 6553601; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 6: treetable_add(key=131072, val=13107200) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 131072; *v = 13107200;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 7: treetable_add(key=65792, val=50462720) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 65792; *v = 50462720;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }

    treetable_destroy(t);
    return 0;
}
