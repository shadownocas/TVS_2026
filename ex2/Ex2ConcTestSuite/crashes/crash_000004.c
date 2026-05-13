/*
 * crash_000004.c
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
 * ==1499043==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000020 (pc 0x0000004c7031 bp 0x7ffd7b3052e0 sp 0x7ffd7b305190 T0)
 * ==1499043==The signal is caused by a READ memory access.
 * ==1499043==Hint: address points to the zero page.
 *     #0 0x4c7030 in tree_min /home/ines/2025_2026/STV/right/TVS_2026/TreeTable/treetable.c:396:15
 *     #1 0x4c7030 in treetable_get_first_key /home/ines/2025_2026/STV/right/TVS_2026/TreeTable/treetable.c:203:20
 *     #2 0x4c6054 in main /home/ines/2025_2026/STV/right/TVS_2026/ex2/Ex2Harness/harness.c:140:17
 *     #3 0x74aa3ff31082 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x24082)
 *     #4 0x41e36d in _start (/home/ines/2025_2026/STV/right/TVS_2026/harness_fuzz+0x41e36d)
 * 
 * AddressSanitizer can not provide additional info.
 * SUMMARY: AddressSanitizer: SEGV /home/ines/2025_2026/STV/right/TVS_2026/TreeTable/treetable.c:396:15 in tree_min
 * ==1499043==ABORTING
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

    /* step 0: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 1: treetable_add(key=-939459600, val=36831232) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -939459600; *v = 36831232;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 2: treetable_add(key=-570431232, val=-1572856) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -570431232; *v = -1572856;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }

    treetable_destroy(t);
    return 0;
}
