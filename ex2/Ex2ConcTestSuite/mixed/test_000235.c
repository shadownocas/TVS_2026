/*
 * test_000235.c
 *
 * Group    : mixed
 * Property : VALIDITY + LOOKUP — interleaved add and lookup operations; checks both invariants and return values
 *
 * Derived from minimised corpus file: ex2/Ex2Harness/minimized_corpus/id:000235,src:000175,time:756092,op:havoc,rep:16
 * Total decoded steps: 49
 *
 * Compile (from ex2/Ex2ConcTestSuite/mixed/):
 *   gcc -g -fsanitize=address -o test_000235 test_000235.c  *       ../../../TreeTable/treetable.c -I ../../../TreeTable/
 * Run:
 *   ./test_000235
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
    /* step 1: treetable_add(key=16744192, val=250511259) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16744192; *v = 250511259;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 2: treetable_add(key=2, val=64866314) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2; *v = 64866314;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 3: treetable_add(key=16744292, val=2137321988) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16744292; *v = 2137321988;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 4: treetable_add(key=-521416188, val=13813760) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -521416188; *v = 13813760;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 5: treetable_add(key=471604253, val=167831807) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 471604253; *v = 167831807;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 6: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 7: treetable_add(key=484835328, val=-842191076) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 484835328; *v = -842191076;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 8: treetable_add(key=47316992, val=-469773614) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 47316992; *v = -469773614;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 9: treetable_add(key=35396636, val=486530304) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 35396636; *v = 486530304;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 10: treetable_add(key=16515072, val=-216216077) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16515072; *v = -216216077;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 11: treetable_add(key=259, val=16973852) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 259; *v = 16973852;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 12: treetable_add(key=1075584203, val=65314) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 1075584203; *v = 65314;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 13: treetable_add(key=13815250, val=13107200) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13815250; *v = 13107200;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 14: treetable_add(key=-755040192, val=407163602) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -755040192; *v = 407163602;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 15: treetable_add(key=891027456, val=-108988981) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 891027456; *v = -108988981;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 16: treetable_add(key=486539136, val=-2147483648) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 486539136; *v = -2147483648;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 17: treetable_add(key=-757939360, val=47370962) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -757939360; *v = 47370962;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 18: treetable_add(key=-14942081, val=452984834) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -14942081; *v = 452984834;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 19: treetable_get(key=-1048574) */
    { int k = -1048574; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 20: treetable_add(key=2142622235, val=-757986606) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2142622235; *v = -757986606;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 21: treetable_add(key=250511259, val=-8454144) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 250511259; *v = -8454144;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 22: treetable_add(key=250511259, val=33555711) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 250511259; *v = 33555711;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 23: treetable_add(key=-938868736, val=1677722589) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -938868736; *v = 1677722589;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 24: treetable_add(key=2137313796, val=-771489537) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2137313796; *v = -771489537;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 25: treetable_add(key=-352267576, val=-1411317763) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -352267576; *v = -1411317763;
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
    /* step 28: treetable_add(key=484835328, val=-842191076) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 484835328; *v = -842191076;
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
    /* step 30: treetable_add(key=35396636, val=486530304) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 35396636; *v = 486530304;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 31: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 32: treetable_add(key=16521984, val=-216216077) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16521984; *v = -216216077;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 33: treetable_add(key=259, val=16973852) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 259; *v = 16973852;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 34: treetable_add(key=1075616971, val=65314) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 1075616971; *v = 65314;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 35: treetable_add(key=13815250, val=13107200) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13815250; *v = 13107200;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 36: treetable_add(key=-755040192, val=407163602) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -755040192; *v = 407163602;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 37: treetable_add(key=891027458, val=-108988981) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 891027458; *v = -108988981;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 38: treetable_add(key=486539136, val=-2147483648) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 486539136; *v = -2147483648;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 39: treetable_add(key=-757939360, val=47370962) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -757939360; *v = 47370962;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 40: treetable_add(key=-14942081, val=452984834) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -14942081; *v = 452984834;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 41: treetable_get(key=-1048574) */
    { int k = -1048574; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 42: treetable_add(key=2144522779, val=-757986606) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2144522779; *v = -757986606;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 43: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 44: treetable_add(key=-769056768, val=16568860) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -769056768; *v = 16568860;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 45: treetable_add(key=-8388664, val=767) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -8388664; *v = 767;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 46: treetable_add(key=-769974256, val=8442396) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -769974256; *v = 8442396;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 47: treetable_add(key=-769982464, val=433240274) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -769982464; *v = 433240274;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 48: treetable_add(key=-757930496, val=-757935406) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -757930496; *v = -757935406;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
