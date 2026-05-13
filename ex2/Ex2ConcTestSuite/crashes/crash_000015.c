/*
 * crash_000015.c
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

    /* step 0: treetable_add(key=0, val=255) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 0; *v = 255;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 1: treetable_add(key=1062863176, val=154133) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 1062863176; *v = 154133;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 2: treetable_add(key=-1077985473, val=-1077952577) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -1077985473; *v = -1077952577;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 3: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 4: treetable_add(key=13107200, val=-1078001664) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = -1078001664;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 5: treetable_get(key=37725504) */
    { int k = 37725504; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 6: treetable_add(key=0, val=512) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 0; *v = 512;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 7: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 8: treetable_add(key=33701632, val=8388608) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 33701632; *v = 8388608;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 9: treetable_add(key=43384848, val=-939507968) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 43384848; *v = -939507968;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 10: treetable_add(key=0, val=1064065536) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 0; *v = 1064065536;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 11: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 12: treetable_add(key=20922178, val=16251904) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 20922178; *v = 16251904;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 13: treetable_add(key=926898816, val=5914687) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 926898816; *v = 5914687;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }

    treetable_destroy(t);
    return 0;
}
