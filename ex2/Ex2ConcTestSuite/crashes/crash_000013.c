/*
 * crash_000013.c
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

    /* step 0: treetable_add(key=268566529, val=-191561728) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 268566529; *v = -191561728;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 1: treetable_add(key=58623, val=200) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 58623; *v = 200;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 2: treetable_add(key=-735488, val=16056096) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -735488; *v = 16056096;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 3: treetable_add(key=15138816, val=-142540929) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 15138816; *v = -142540929;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 4: treetable_get(key=-469762303) */
    { int k = -469762303; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 5: treetable_add(key=14619423, val=50298625) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 14619423; *v = 50298625;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 6: treetable_add(key=1376128, val=248) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 1376128; *v = 248;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 7: treetable_add(key=128, val=13107200) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 128; *v = 13107200;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }

    treetable_destroy(t);
    return 0;
}
