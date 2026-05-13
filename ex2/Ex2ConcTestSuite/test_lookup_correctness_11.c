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

    /* step 0: treetable_add(key=67108865, val=15335267) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 67108865; *v = 15335267;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 1: treetable_add(key=16974336, val=-943054848) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16974336; *v = -943054848;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 2: treetable_add(key=32768, val=65775) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 32768; *v = 65775;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 3: treetable_add(key=285212673, val=2139029761) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 285212673; *v = 2139029761;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 4: treetable_get(key=16777473) */
    { int k = 16777473; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 5: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 6: treetable_get(key=1677721857) */
    { int k = 1677721857; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 7: treetable_add(key=16902399, val=65793) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16902399; *v = 65793;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 8: treetable_add(key=-1895751680, val=16879505) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -1895751680; *v = 16879505;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 9: treetable_get(key=16973824) */
    { int k = 16973824; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 10: treetable_add(key=536936449, val=31464448) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 536936449; *v = 31464448;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 11: treetable_get(key=-557275647) */
    { int k = -557275647; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 12: treetable_get(key=16843174) */
    { int k = 16843174; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 13: treetable_get(key=94721) */
    { int k = 94721; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 14: treetable_add(key=16843040, val=453056513) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16843040; *v = 453056513;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 15: treetable_add(key=1852730990, val=-2022805906) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 1852730990; *v = -2022805906;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 16: treetable_get(key=1050615) */
    { int k = 1050615; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 17: treetable_add(key=16843009, val=16843009) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16843009; *v = 16843009;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 18: treetable_get(key=65792) */
    { int k = 65792; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 19: treetable_get(key=0) */
    { int k = 0; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 20: treetable_add(key=-1342054400, val=16635) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -1342054400; *v = 16635;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 21: treetable_get(key=-1852863319) */
    { int k = -1852863319; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 22: treetable_get(key=17111041) */
    { int k = 17111041; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 23: treetable_add(key=66304, val=536936449) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 66304; *v = 536936449;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 24: treetable_add(key=50266240, val=-1863195136) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 50266240; *v = -1863195136;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
