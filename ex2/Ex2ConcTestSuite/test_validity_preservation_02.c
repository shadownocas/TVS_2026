/*
 * Property: preservation of validity after insertions
 *
 * The tree must remain a valid, balanced BST after insertions and updates.
 * Tree invariants (balance factors, sorted order) must be maintained through
 * rebalancing operations.
 *
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

    /* step 0: treetable_add(key=8388608, val=-335544320) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 8388608; *v = -335544320;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 1: treetable_add(key=0, val=1476395244) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 0; *v = 1476395244;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 2: treetable_add(key=369033216, val=-150994707) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 369033216; *v = -150994707;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 3: treetable_add(key=-262144, val=33605310) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -262144; *v = 33605310;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 4: treetable_add(key=13107224, val=-67108864) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107224; *v = -67108864;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 5: treetable_add(key=1572866, val=2248) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 1572866; *v = 2248;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 6: treetable_add(key=60416, val=7256) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 60416; *v = 7256;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 7: treetable_add(key=15537663, val=402653696) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 15537663; *v = 402653696;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 8: treetable_add(key=7368, val=-317325568) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 7368; *v = -317325568;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 9: treetable_add(key=-945555712, val=26) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -945555712; *v = 26;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 10: treetable_add(key=-960561156, val=402653696) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -960561156; *v = 402653696;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 11: treetable_add(key=200, val=33554682) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 200; *v = 33554682;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 12: treetable_add(key=51200, val=369033216) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 51200; *v = 369033216;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 13: treetable_add(key=-945555712, val=1566399744) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -945555712; *v = 1566399744;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 14: treetable_add(key=-656887040, val=728) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -656887040; *v = 728;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 15: treetable_add(key=1769672, val=33554655) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 1769672; *v = 33554655;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 16: treetable_add(key=51200, val=-2147483648) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 51200; *v = -2147483648;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 17: treetable_add(key=-335544320, val=236) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -335544320; *v = 236;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 18: treetable_add(key=60416, val=7256) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 60416; *v = 7256;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 19: treetable_add(key=-721420033, val=524544) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -721420033; *v = 524544;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 20: treetable_add(key=8339800, val=-8454144) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 8339800; *v = -8454144;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
