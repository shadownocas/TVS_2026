/*
 * crash_000016.c
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
 * ==1499289==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000020 (pc 0x0000004c7031 bp 0x7ffefd64e300 sp 0x7ffefd64e1b0 T0)
 * ==1499289==The signal is caused by a READ memory access.
 * ==1499289==Hint: address points to the zero page.
 *     #0 0x4c7030 in tree_min /home/ines/2025_2026/STV/right/TVS_2026/TreeTable/treetable.c:396:15
 *     #1 0x4c7030 in treetable_get_first_key /home/ines/2025_2026/STV/right/TVS_2026/TreeTable/treetable.c:203:20
 *     #2 0x4c6054 in main /home/ines/2025_2026/STV/right/TVS_2026/ex2/Ex2Harness/harness.c:140:17
 *     #3 0x71a22844c082 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x24082)
 *     #4 0x41e36d in _start (/home/ines/2025_2026/STV/right/TVS_2026/harness_fuzz+0x41e36d)
 * 
 * AddressSanitizer can not provide additional info.
 * SUMMARY: AddressSanitizer: SEGV /home/ines/2025_2026/STV/right/TVS_2026/TreeTable/treetable.c:396:15 in tree_min
 * ==1499289==ABORTING
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

    /* step 0: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 1: treetable_get_greater_than(key=922944259) */
    { int k = 922944259; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 2: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 3: treetable_add(key=13107200, val=926351360) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = 926351360;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 4: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 5: treetable_add(key=13107200, val=352321536) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = 352321536;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }

    treetable_destroy(t);
    return 0;
}
