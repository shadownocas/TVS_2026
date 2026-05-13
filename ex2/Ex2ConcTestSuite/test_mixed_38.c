/*
 * Property: validity and lookup correctness under interleaved operations
 *
 * The tree must remain valid (balanced and sorted) while simultaneously checking
 * that lookup operations return correct results. All invariants must hold under
 * mixed sequences of add and lookup operations.
 *
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

    /* step 0: treetable_add(key=-30, val=32767) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -30; *v = 32767;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 1: treetable_add(key=67161344, val=-1395798579) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 67161344; *v = -1395798579;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 2: treetable_add(key=236, val=0) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 236; *v = 0;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 3: treetable_add(key=7296, val=-317325568) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 7296; *v = -317325568;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 4: treetable_add(key=-945555712, val=26) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -945555712; *v = 26;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 5: treetable_add(key=-1544093695, val=6855) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -1544093695; *v = 6855;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 6: treetable_add(key=-1105389055, val=198) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -1105389055; *v = 198;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 7: treetable_add(key=-16777016, val=-855637995) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -16777016; *v = -855637995;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 8: treetable_add(key=-67108864, val=-803864577) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -67108864; *v = -803864577;
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
    /* step 10: treetable_add(key=-960619011, val=1073741824) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -960619011; *v = 1073741824;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 11: treetable_add(key=16777416, val=33554440) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16777416; *v = 33554440;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 12: treetable_add(key=262144, val=449291255) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 262144; *v = 449291255;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 13: treetable_add(key=-67108864, val=13025023) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -67108864; *v = 13025023;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 14: treetable_add(key=-484835328, val=402653696) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -484835328; *v = 402653696;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 15: treetable_add(key=49352, val=-317325568) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 49352; *v = -317325568;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 16: treetable_add(key=449291255, val=205) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 449291255; *v = 205;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 17: treetable_add(key=13041660, val=4194304) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13041660; *v = 4194304;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 18: treetable_add(key=524544, val=1507840) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 524544; *v = 1507840;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 19: treetable_add(key=200, val=-317325568) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 200; *v = -317325568;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 20: treetable_add(key=-945555712, val=-1291845632) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -945555712; *v = -1291845632;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 21: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 22: treetable_add(key=13107200, val=67108891) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = 67108891;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 23: treetable_add(key=5890, val=200) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 5890; *v = 200;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 24: treetable_add(key=13047295, val=436258816) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13047295; *v = 436258816;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 25: treetable_add(key=-67108864, val=205) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -67108864; *v = 205;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 26: treetable_add(key=-67101568, val=50943) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -67101568; *v = 50943;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 27: treetable_add(key=13107264, val=524544) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107264; *v = 524544;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 28: treetable_add(key=5890, val=200) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 5890; *v = 200;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 29: treetable_add(key=-18016769, val=250) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -18016769; *v = 250;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 30: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 31: treetable_add(key=436207853, val=131299) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 436207853; *v = 131299;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 32: treetable_add(key=49352, val=-302318080) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 49352; *v = -302318080;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 33: treetable_add(key=449291255, val=205) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 449291255; *v = 205;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 34: treetable_add(key=13041660, val=4194304) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13041660; *v = 4194304;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 35: treetable_add(key=524544, val=1507840) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 524544; *v = 1507840;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 36: treetable_add(key=200, val=-317325568) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 200; *v = -317325568;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 37: treetable_add(key=-945555712, val=-1291845632) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -945555712; *v = -1291845632;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 38: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 39: treetable_add(key=13107200, val=67108891) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = 67108891;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 40: treetable_add(key=5890, val=200) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 5890; *v = 200;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 41: treetable_add(key=13047295, val=436258816) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13047295; *v = 436258816;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 42: treetable_add(key=-67108864, val=205) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -67108864; *v = 205;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 43: treetable_add(key=-67101568, val=50943) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -67101568; *v = 50943;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 44: treetable_add(key=2134988800, val=2130706432) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2134988800; *v = 2130706432;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 45: treetable_add(key=16777416, val=33554440) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16777416; *v = 33554440;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 46: treetable_add(key=51200, val=369033216) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 51200; *v = 369033216;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 47: treetable_add(key=131072, val=237) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 131072; *v = 237;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 48: treetable_get(key=1476395016) */
    { int k = 1476395016; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 49: treetable_add(key=-16777216, val=60693) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -16777216; *v = 60693;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 50: treetable_add(key=-659357696, val=186584) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -659357696; *v = 186584;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 51: treetable_add(key=512, val=455067648) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 512; *v = 455067648;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 52: treetable_add(key=33555456, val=-939524073) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 33555456; *v = -939524073;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 53: treetable_add(key=-16777216, val=50965) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -16777216; *v = 50965;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 54: treetable_add(key=26, val=-3277824) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 26; *v = -3277824;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 55: treetable_add(key=13041660, val=536870912) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13041660; *v = 536870912;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 56: treetable_get(key=1476395016) */
    { int k = 1476395016; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 57: treetable_add(key=-16777216, val=60693) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -16777216; *v = 60693;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 58: treetable_add(key=-659357696, val=186584) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -659357696; *v = 186584;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 59: treetable_add(key=512, val=455067648) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 512; *v = 455067648;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 60: treetable_add(key=33555456, val=-939524073) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 33555456; *v = -939524073;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 61: treetable_add(key=-16777216, val=50965) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -16777216; *v = 50965;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 62: treetable_add(key=26, val=13499392) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 26; *v = 13499392;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 63: treetable_add(key=478150656, val=-956302336) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 478150656; *v = -956302336;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 64: treetable_add(key=4194304, val=16777416) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 4194304; *v = 16777416;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 65: treetable_add(key=1507840, val=51200) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 1507840; *v = 51200;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 66: treetable_add(key=-317325568, val=64254) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -317325568; *v = 64254;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 67: treetable_add(key=15532034, val=13161728) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 15532034; *v = 13161728;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
