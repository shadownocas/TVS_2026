/*
 * Concrete test suite derived from: test_rebalance_rl_zigzag.c
 * Property: Validity preservation after a Right-Left zigzag insertion.
 * Generated from KLEE ktest files:
 *   test000001.ktest : k_lo=0, k_mid=128, k_hi=16384
 */
#include <assert.h>
#include <stdlib.h>
#include "treetable.h"

int main(void)
{
    int *k_lo  = malloc(sizeof(int)); *k_lo  = 0;
    int *k_mid = malloc(sizeof(int)); *k_mid = 128;
    int *k_hi  = malloc(sizeof(int)); *k_hi  = 16384;
    int *v1    = malloc(sizeof(int)); *v1    = 1;
    int *v2    = malloc(sizeof(int)); *v2    = 2;
    int *v3    = malloc(sizeof(int)); *v3    = 3;

    TreeTable *t;
    treetable_new(&t);

    treetable_add(t, k_lo,  v1); assert(balanced(t) && sorted(t));
    treetable_add(t, k_hi,  v2); assert(balanced(t) && sorted(t));
    treetable_add(t, k_mid, v3); assert(balanced(t) && sorted(t));

    treetable_destroy(t);
    return 0;
}
