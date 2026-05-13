/*
 * crash_000006.c
 *
 * Group    : crashes
 * Property : NULL DEREFERENCE — tree_min() reads through a null/near-null
 *            pointer when treetable_get_first_key() is called on an empty
 *            or structurally invalid tree.
 *
 * Signal   : SIGABRT (sig:06) — assert() called abort()
 *
 * AddressSanitizer / runtime report:
 *
 * AddressSanitizer:DEADLYSIGNAL
 * =================================================================
 * ==1499094==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000020 (pc 0x0000004c7031 bp 0x7fffd2311d80 sp 0x7fffd2311c30 T0)
 * ==1499094==The signal is caused by a READ memory access.
 * ==1499094==Hint: address points to the zero page.
 *     #0 0x4c7030 in tree_min /home/ines/2025_2026/STV/right/TVS_2026/TreeTable/treetable.c:396:15
 *     #1 0x4c7030 in treetable_get_first_key /home/ines/2025_2026/STV/right/TVS_2026/TreeTable/treetable.c:203:20
 *     #2 0x4c6054 in main /home/ines/2025_2026/STV/right/TVS_2026/ex2/Ex2Harness/harness.c:140:17
 *     #3 0x7c3736692082 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x24082)
 *     #4 0x41e36d in _start (/home/ines/2025_2026/STV/right/TVS_2026/harness_fuzz+0x41e36d)
 * 
 * AddressSanitizer can not provide additional info.
 * SUMMARY: AddressSanitizer: SEGV /home/ines/2025_2026/STV/right/TVS_2026/TreeTable/treetable.c:396:15 in tree_min
 * ==1499094==ABORTING
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

    /* step 0: treetable_get(key=1677714944) */
    { int k = 1677714944; void *out = NULL; treetable_get(t, &k, &out); }
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
    /* step 6: treetable_add(key=33688322, val=2) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 33688322; *v = 2;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 7: treetable_add(key=-1696000, val=33686123) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -1696000; *v = 33686123;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 8: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 9: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 10: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }

    treetable_destroy(t);
    return 0;
}
