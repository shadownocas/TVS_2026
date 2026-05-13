/*
 * Symbolic test: test_rebalance_rl_zigzag.c
 *
 * Property: Validity preservation after a Right-Left zigzag insertion.
 */
 * Minimal trigger: insert k_lo < k_hi, then insert k_mid with
 * k_lo < k_mid < k_hi. After inserting k_hi as a right child of k_lo,
 * k_mid is inserted as a left child of k_hi — forming the RL shape.
 *
 * Insertion order: k_lo, k_hi, k_mid  (i.e. low, high, then middle).
 *
 * Functions exercised: treetable_add, rebalance_after_insert (RL branch,
 *                      lines 379-381), rotate_right (called on line 381).
 */

#include <klee/klee.h>
#include <assert.h>
#include <limits.h>
#include "treetable.h"

int main(void)
{
    int k_lo, k_mid, k_hi;
    klee_make_symbolic(&k_lo,  sizeof(k_lo),  "k_lo");
    klee_make_symbolic(&k_mid, sizeof(k_mid), "k_mid");
    klee_make_symbolic(&k_hi,  sizeof(k_hi),  "k_hi");

    klee_assume(k_lo  > INT_MIN);
    klee_assume(k_lo  < INT_MAX);
    klee_assume(k_mid > INT_MIN);
    klee_assume(k_mid < INT_MAX);
    klee_assume(k_hi  > INT_MIN);
    klee_assume(k_hi  < INT_MAX);
    klee_assume(k_lo < k_mid);
    klee_assume(k_mid < k_hi);

    int v = 1;

    TreeTable *t;
    treetable_new(&t);

    treetable_add(t, &k_lo, &v);
    assert(balanced(t) && sorted(t));

    treetable_add(t, &k_hi, &v);
    assert(balanced(t) && sorted(t));

    treetable_add(t, &k_mid, &v);
    assert(balanced(t) && sorted(t));

    return 0;
}
