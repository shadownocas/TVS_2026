/*
 * Property: correctness of lookup operations
 *
 * After inserting key k with value v, treetable_get / treetable_get_first_key /
 * treetable_get_greater_than must return correct results. For keys never inserted,
 * these functions must return error codes. Lookups must not mutate table structure
 * or state.
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
    /* step 1: treetable_add(key=67161344, val=32272) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 67161344; *v = 32272;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 2: treetable_add(key=250511259, val=-853547265) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 250511259; *v = -853547265;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 3: treetable_add(key=-149946368, val=1755043) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -149946368; *v = 1755043;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 4: treetable_add(key=488243456, val=50878) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 488243456; *v = 50878;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 5: treetable_add(key=13107264, val=1441536) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107264; *v = 1441536;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 6: treetable_add(key=205, val=-1024) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 205; *v = -1024;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 7: treetable_add(key=-945555712, val=26) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -945555712; *v = 26;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 8: treetable_add(key=-960619011, val=1073741824) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -960619011; *v = 1073741824;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 9: treetable_add(key=16777416, val=-8454136) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16777416; *v = -8454136;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 10: treetable_add(key=262144, val=449291255) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 262144; *v = 449291255;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 11: treetable_add(key=-67108864, val=13022463) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -67108864; *v = 13022463;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 12: treetable_add(key=-484835328, val=469762560) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -484835328; *v = 469762560;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 13: treetable_add(key=-926365449, val=-926365496) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -926365449; *v = -926365496;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 14: treetable_add(key=436273152, val=13024797) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 436273152; *v = 13024797;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 15: treetable_add(key=-939507712, val=369033216) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -939507712; *v = 369033216;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 16: treetable_add(key=16515072, val=52480) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16515072; *v = 52480;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 17: treetable_add(key=-1024, val=53269) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -1024; *v = 53269;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 18: treetable_add(key=-50331648, val=13024768) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -50331648; *v = 13024768;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 19: treetable_add(key=-939507712, val=134283264) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -939507712; *v = 134283264;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 20: treetable_add(key=-1105723521, val=198) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -1105723521; *v = 198;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 21: treetable_add(key=449291255, val=0) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 449291255; *v = 0;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 22: treetable_add(key=436207616, val=131299) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 436207616; *v = 131299;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 23: treetable_add(key=449291255, val=205) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 449291255; *v = 205;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 24: treetable_add(key=13041660, val=4194304) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13041660; *v = 4194304;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 25: treetable_add(key=524780, val=1507840) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 524780; *v = 1507840;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 26: treetable_add(key=200, val=-853883136) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 200; *v = -853883136;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 27: treetable_add(key=-262144, val=198) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -262144; *v = 198;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 28: treetable_add(key=16777416, val=33554440) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16777416; *v = 33554440;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 29: treetable_add(key=-926365496, val=-926365496) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -926365496; *v = -926365496;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 30: treetable_add(key=-926416126, val=-926365496) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -926416126; *v = -926365496;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 31: treetable_add(key=200, val=-317325568) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 200; *v = -317325568;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 32: treetable_add(key=65535, val=-1291845632) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 65535; *v = -1291845632;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 33: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 34: treetable_add(key=13107200, val=67108891) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = 67108891;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 35: treetable_add(key=5890, val=200) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 5890; *v = 200;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 36: treetable_add(key=13047295, val=436258816) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13047295; *v = 436258816;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 37: treetable_add(key=-67108864, val=2162893) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -67108864; *v = 2162893;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 38: treetable_add(key=-67101568, val=50943) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -67101568; *v = 50943;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 39: treetable_add(key=13107264, val=524544) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107264; *v = 524544;
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
    /* step 41: treetable_add(key=-18016769, val=250) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -18016769; *v = 250;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 42: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 43: treetable_add(key=-721420051, val=524544) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -721420051; *v = 524544;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 44: treetable_add(key=8339800, val=-16777216) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 8339800; *v = -16777216;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 45: treetable_add(key=-947652864, val=-1291845632) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -947652864; *v = -1291845632;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 46: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 47: treetable_add(key=13108224, val=67108891) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13108224; *v = 67108891;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
