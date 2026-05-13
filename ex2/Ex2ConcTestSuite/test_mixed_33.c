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

    /* step 0: treetable_add(key=-261631, val=65536) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -261631; *v = 65536;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 1: treetable_add(key=66519040, val=771) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 66519040; *v = 771;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 2: treetable_add(key=-261631, val=2) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -261631; *v = 2;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 3: treetable_add(key=587399936, val=35) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 587399936; *v = 35;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 4: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 5: treetable_get_greater_than(key=13959939) */
    { int k = 13959939; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 6: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 7: treetable_get_greater_than(key=8323843) */
    { int k = 8323843; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 8: treetable_add(key=50529024, val=3) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 50529024; *v = 3;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 9: treetable_add(key=587399936, val=35) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 587399936; *v = 35;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 10: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 11: treetable_get_greater_than(key=64291587) */
    { int k = 64291587; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 12: treetable_get_greater_than(key=1073742825) */
    { int k = 1073742825; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 13: treetable_add(key=50529026, val=50529224) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 50529026; *v = 50529224;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 14: treetable_get_greater_than(key=51839747) */
    { int k = 51839747; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 15: treetable_get_greater_than(key=33608963) */
    { int k = 33608963; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 16: treetable_get_greater_than(key=13107971) */
    { int k = 13107971; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 17: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 18: treetable_add(key=2130758403, val=8388352) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2130758403; *v = 8388352;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 19: treetable_add(key=65536771, val=50528256) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 65536771; *v = 50528256;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 20: treetable_add(key=33609024, val=-939392253) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 33609024; *v = -939392253;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 21: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 22: treetable_add(key=50529027, val=50529027) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 50529027; *v = 50529027;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 23: treetable_get_greater_than(key=-16637483) */
    { int k = -16637483; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 24: treetable_get_greater_than(key=52495107) */
    { int k = 52495107; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 25: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 26: treetable_get_greater_than(key=50528768) */
    { int k = 50528768; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 27: treetable_get_greater_than(key=50528456) */
    { int k = 50528456; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 28: treetable_get_greater_than(key=140800) */
    { int k = 140800; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 29: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 30: treetable_get_greater_than(key=-721222909) */
    { int k = -721222909; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 31: treetable_add(key=50529026, val=-8453941) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 50529026; *v = -8453941;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 32: treetable_add(key=50547456, val=-385678589) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 50547456; *v = -385678589;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 33: treetable_get_greater_than(key=13983744) */
    { int k = 13983744; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 34: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 35: treetable_get_greater_than(key=63439619) */
    { int k = 63439619; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 36: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 37: treetable_get_greater_than(key=13959939) */
    { int k = 13959939; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 38: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 39: treetable_get_greater_than(key=50579459) */
    { int k = 50579459; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 40: treetable_get_greater_than(key=50528456) */
    { int k = 50528456; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 41: treetable_get_greater_than(key=140800) */
    { int k = 140800; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 42: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 43: treetable_get_greater_than(key=-721222909) */
    { int k = -721222909; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 44: treetable_add(key=50529026, val=-8453941) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 50529026; *v = -8453941;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 45: treetable_add(key=50547456, val=-385678589) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 50547456; *v = -385678589;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 46: treetable_get_greater_than(key=13983744) */
    { int k = 13983744; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 47: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 48: treetable_get_greater_than(key=63439619) */
    { int k = 63439619; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 49: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 50: treetable_get_greater_than(key=13959939) */
    { int k = 13959939; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 51: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 52: treetable_get_greater_than(key=33605635) */
    { int k = 33605635; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 53: treetable_add(key=2130758403, val=8388352) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2130758403; *v = 8388352;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 54: treetable_add(key=65536771, val=16843008) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 65536771; *v = 16843008;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 55: treetable_get(key=16836865) */
    { int k = 16836865; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 56: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 57: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 58: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 59: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 60: treetable_get(key=50397441) */
    { int k = 50397441; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 61: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 62: treetable_get_greater_than(key=50529027) */
    { int k = 50529027; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 63: treetable_get_greater_than(key=455475203) */
    { int k = 455475203; void *out = NULL; treetable_get_greater_than(t, &k, &out); }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
