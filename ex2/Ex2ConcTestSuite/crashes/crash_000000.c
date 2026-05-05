/*
 * crash_000000.c
 *
 * Group    : crashes
 * Property : ASSERTION VIOLATION — balanced(t) && sorted(t) failed after
 *            treetable_add(), indicating the RB-tree invariant was broken
 *            by the sequence of insertions below.
 *
 * Signal   : SIGABRT (sig:06) — assert() called abort()
 *
 * Derived from AFL++ crash input: ex2/Ex2Harness/outputs/crashes/id:000000,sig:06,src:000000,time:11,op:flip1,pos:0
 * Total decoded steps: 5
 *
 * To reproduce (from project root):
 *   AFL_USE_ASAN=1 afl-clang-fast -g -O1 ex2/Ex2Harness/harness.c  *       TreeTable/treetable.c -I TreeTable/ -o harness_fuzz
 *   ./harness_fuzz < "ex2/Ex2Harness/outputs/crashes/id:000000,sig:06,src:000000,time:11,op:flip1,pos:0"
 *
 * Compile this test (from ex2/Ex2ConcTestSuite/crashes/):
 *   gcc -g -fsanitize=address -o crash_000000 crash_000000.c  *       ../../../TreeTable/treetable.c -I ../../../TreeTable/
 *
 * AddressSanitizer / runtime report:
 *
 * AddressSanitizer:DEADLYSIGNAL
 * =================================================================
 * ==1498970==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000020 (pc 0x0000004c7031 bp 0x7ffc8af41fb0 sp 0x7ffc8af41e70 T0)
 * ==1498970==The signal is caused by a READ memory access.
 * ==1498970==Hint: address points to the zero page.
 *     #0 0x4c7030 in tree_min /home/ines/2025_2026/STV/right/TVS_2026/TreeTable/treetable.c:396:15
 *     #1 0x4c7030 in treetable_get_first_key /home/ines/2025_2026/STV/right/TVS_2026/TreeTable/treetable.c:203:20
 *     #2 0x4c6054 in main /home/ines/2025_2026/STV/right/TVS_2026/ex2/Ex2Harness/harness.c:140:17
 *     #3 0x71eab018c082 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x24082)
 *     #4 0x41e36d in _start (/home/ines/2025_2026/STV/right/TVS_2026/harness_fuzz+0x41e36d)
 * 
 * AddressSanitizer can not provide additional info.
 * SUMMARY: AddressSanitizer: SEGV /home/ines/2025_2026/STV/right/TVS_2026/TreeTable/treetable.c:396:15 in tree_min
 * ==1498970==ABORTING
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
    /* step 1: treetable_get(key=1677721600) */
    { int k = 1677721600; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 2: treetable_add(key=33554432, val=-939524096) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 33554432; *v = -939524096;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 3: treetable_add(key=16842752, val=33554432) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16842752; *v = 33554432;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));  /* <-- crash fires here or above */
    }
    /* step 4: treetable_get_greater_than(key=1) */
    { int k = 1; void *out = NULL; treetable_get_greater_than(t, &k, &out); }

    treetable_destroy(t);
    return 0;
}
