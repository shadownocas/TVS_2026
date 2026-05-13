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

    /* step 0: treetable_add(key=2130706558, val=2140864767) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2130706558; *v = 2140864767;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 1: treetable_add(key=2, val=64866314) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2; *v = 64866314;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 2: treetable_add(key=16744292, val=-756297212) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16744292; *v = -756297212;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 3: treetable_add(key=-352267576, val=-1411317763) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -352267576; *v = -1411317763;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 4: treetable_add(key=471610909, val=167831807) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 471610909; *v = 167831807;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 5: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 6: treetable_add(key=482869248, val=-842191076) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 482869248; *v = -842191076;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 7: treetable_add(key=47316992, val=1124061906) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 47316992; *v = 1124061906;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 8: treetable_add(key=35396636, val=469762048) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 35396636; *v = 469762048;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 9: treetable_add(key=16515072, val=-216216077) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16515072; *v = -216216077;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 10: treetable_add(key=259, val=605821980) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 259; *v = 605821980;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 11: treetable_add(key=1075584203, val=65314) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 1075584203; *v = 65314;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 12: treetable_add(key=-757936686, val=407163602) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -757936686; *v = 407163602;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 13: treetable_add(key=891027458, val=-108988981) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 891027458; *v = -108988981;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 14: treetable_add(key=486539136, val=-2147483648) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 486539136; *v = -2147483648;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 15: treetable_add(key=-757939360, val=47370962) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -757939360; *v = 47370962;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 16: treetable_add(key=-14942081, val=452984834) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -14942081; *v = 452984834;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 17: treetable_get(key=-1048574) */
    { int k = -1048574; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 18: treetable_add(key=2144522779, val=-757986606) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2144522779; *v = -757986606;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 19: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 20: treetable_add(key=-769974272, val=16568860) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -769974272; *v = 16568860;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 21: treetable_add(key=-757989344, val=35684380) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -757989344; *v = 35684380;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 22: treetable_add(key=-16777016, val=-754974849) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -16777016; *v = -754974849;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 23: treetable_add(key=-757923849, val=47370962) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -757923849; *v = 47370962;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 24: treetable_add(key=-3670016, val=-939458689) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -3670016; *v = -939458689;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 25: treetable_add(key=-520094229, val=-842150485) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -520094229; *v = -842150485;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 26: treetable_add(key=471604253, val=167831807) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 471604253; *v = 167831807;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 27: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 28: treetable_add(key=482869248, val=-842191076) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 482869248; *v = -842191076;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 29: treetable_add(key=47316992, val=-469773614) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 47316992; *v = -469773614;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 30: treetable_add(key=35396636, val=469762048) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 35396636; *v = 469762048;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 31: treetable_add(key=16515072, val=-216216077) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16515072; *v = -216216077;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 32: treetable_get(key=66304) */
    { int k = 66304; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 33: treetable_add(key=605821980, val=1840156) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 605821980; *v = 1840156;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 34: treetable_add(key=-841875456, val=-757935406) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -841875456; *v = -757935406;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 35: treetable_add(key=891027458, val=-108988981) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 891027458; *v = -108988981;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 36: treetable_add(key=486539136, val=-2147483648) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 486539136; *v = -2147483648;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 37: treetable_add(key=-757939360, val=47370962) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -757939360; *v = 47370962;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 38: treetable_add(key=-14942081, val=452984834) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -14942081; *v = 452984834;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 39: treetable_get(key=-1048574) */
    { int k = -1048574; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 40: treetable_add(key=2144522779, val=-757986606) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2144522779; *v = -757986606;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 41: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 42: treetable_add(key=-769974272, val=16568860) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -769974272; *v = 16568860;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 43: treetable_add(key=-769982464, val=433240274) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -769982464; *v = 433240274;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 44: treetable_add(key=-757930496, val=-757935406) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -757930496; *v = -757935406;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 45: treetable_add(key=196352, val=-523829248) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 196352; *v = -523829248;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
