/*
 * crash_000018.c
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

    /* step 0: treetable_add(key=1966080, val=237) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 1966080; *v = 237;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 1: treetable_get_greater_than(key=13098496) */
    { int k = 13098496; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 2: treetable_add(key=-301989888, val=200) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -301989888; *v = 200;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 3: treetable_add(key=-524288, val=33554680) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -524288; *v = 33554680;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 4: treetable_add(key=-3735552, val=59391) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -3735552; *v = 59391;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 5: treetable_get(key=163840) */
    { int k = 163840; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 6: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 7: treetable_add(key=13107200, val=-134217728) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = -134217728;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 8: treetable_add(key=512, val=51200) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 512; *v = 51200;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 9: treetable_add(key=184549888, val=51200) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 184549888; *v = 51200;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 10: treetable_add(key=2, val=200) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2; *v = 200;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 11: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 12: treetable_add(key=-808976384, val=131072) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -808976384; *v = 131072;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 13: treetable_add(key=51200, val=-134211840) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 51200; *v = -134211840;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 14: treetable_add(key=6144, val=51200) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 6144; *v = 51200;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 15: treetable_add(key=65536, val=8) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 65536; *v = 8;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 16: treetable_add(key=-958529536, val=44564715) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -958529536; *v = 44564715;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 17: treetable_add(key=13107200, val=0) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = 0;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }

    treetable_destroy(t);
    return 0;
}
