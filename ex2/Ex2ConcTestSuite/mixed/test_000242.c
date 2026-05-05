/*
 * test_000242.c
 *
 * Group    : mixed
 * Property : VALIDITY + LOOKUP — interleaved add and lookup operations; checks both invariants and return values
 *
 * Derived from minimised corpus file: ex2/Ex2Harness/minimized_corpus/id:000242,src:000209,time:1672149,op:havoc,rep:64
 * Total decoded steps: 86
 *
 * Compile (from ex2/Ex2ConcTestSuite/mixed/):
 *   gcc -g -fsanitize=address -o test_000242 test_000242.c  *       ../../../TreeTable/treetable.c -I ../../../TreeTable/
 * Run:
 *   ./test_000242
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

    /* step 0: treetable_add(key=-50331521, val=24182984) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -50331521; *v = 24182984;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 1: treetable_add(key=8388811, val=-1593835518) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 8388811; *v = -1593835518;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 2: treetable_get_greater_than(key=0) */
    { int k = 0; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 3: treetable_add(key=-16777214, val=33563888) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -16777214; *v = 33563888;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 4: treetable_add(key=-574095341, val=-889192448) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -574095341; *v = -889192448;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 5: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 6: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 7: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 8: treetable_add(key=13107200, val=12124160) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = 12124160;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 9: treetable_add(key=8388608, val=8192) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 8388608; *v = 8192;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 10: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 11: treetable_add(key=13107200, val=2097152) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = 2097152;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 12: treetable_add(key=2, val=200) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2; *v = 200;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 13: treetable_add(key=200, val=536871040) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 200; *v = 536871040;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 14: treetable_add(key=-64256, val=-1375731707) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -64256; *v = -1375731707;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 15: treetable_add(key=2130706432, val=14524673) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2130706432; *v = 14524673;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 16: treetable_add(key=131584, val=13107200) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 131584; *v = 13107200;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 17: treetable_add(key=0, val=-1023278392) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 0; *v = -1023278392;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 18: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 19: treetable_add(key=13107200, val=12124160) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = 12124160;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 20: treetable_add(key=512, val=-21248) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 512; *v = -21248;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 21: treetable_add(key=-944963201, val=33554432) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -944963201; *v = 33554432;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 22: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 23: treetable_add(key=13107200, val=0) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = 0;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 24: treetable_add(key=268435656, val=453050331) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 268435656; *v = 453050331;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 25: treetable_add(key=33686528, val=33680898) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 33686528; *v = 33680898;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 26: treetable_add(key=33168128, val=538976258) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 33168128; *v = 538976258;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 27: treetable_add(key=538974976, val=2105376) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 538974976; *v = 2105376;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 28: treetable_add(key=547211264, val=538973216) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 547211264; *v = 538973216;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 29: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 30: treetable_add(key=13107200, val=1895876608) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = 1895876608;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 31: treetable_get(key=-2147431680) */
    { int k = -2147431680; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 32: treetable_add(key=-1593835518, val=200903) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -1593835518; *v = 200903;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 33: treetable_add(key=-262144, val=131320) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -262144; *v = 131320;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 34: treetable_add(key=2420991, val=1245186) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2420991; *v = 1245186;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 35: treetable_add(key=46858240, val=180994) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 46858240; *v = 180994;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 36: treetable_add(key=51200, val=-939476736) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 51200; *v = -939476736;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 37: treetable_add(key=8388608, val=8192) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 8388608; *v = 8192;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 38: treetable_add(key=44544, val=33685504) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 44544; *v = 33685504;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 39: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 40: treetable_add(key=13107200, val=12124160) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = 12124160;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 41: treetable_add(key=512, val=44544) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 512; *v = 44544;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 42: treetable_add(key=-1392410880, val=199) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -1392410880; *v = 199;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 43: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 44: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 45: treetable_add(key=13108224, val=0) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13108224; *v = 0;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 46: treetable_add(key=200, val=453050331) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 200; *v = 453050331;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 47: treetable_add(key=33686528, val=33680898) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 33686528; *v = 33680898;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 48: treetable_add(key=33561344, val=538976258) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 33561344; *v = 538976258;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 49: treetable_add(key=538974976, val=2105376) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 538974976; *v = 2105376;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 50: treetable_add(key=536871112, val=-586809344) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 536871112; *v = -586809344;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 51: treetable_add(key=545376256, val=538973216) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 545376256; *v = 538973216;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 52: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 53: treetable_add(key=13107200, val=1895876608) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = 1895876608;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 54: treetable_get(key=-2147431680) */
    { int k = -2147431680; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 55: treetable_add(key=-1593835518, val=200903) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -1593835518; *v = 200903;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 56: treetable_add(key=-262144, val=131320) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -262144; *v = 131320;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 57: treetable_add(key=2420991, val=538968066) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2420991; *v = 538968066;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 58: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 59: treetable_add(key=13107200, val=1895876608) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = 1895876608;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 60: treetable_get(key=-2147431680) */
    { int k = -2147431680; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 61: treetable_add(key=-1593835518, val=200903) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -1593835518; *v = 200903;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 62: treetable_add(key=-262144, val=131320) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -262144; *v = 131320;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 63: treetable_add(key=2420991, val=1245186) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2420991; *v = 1245186;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 64: treetable_add(key=46858240, val=180994) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 46858240; *v = 180994;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 65: treetable_add(key=51200, val=-939476736) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 51200; *v = -939476736;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 66: treetable_add(key=8388608, val=8192) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 8388608; *v = 8192;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 67: treetable_add(key=-872960, val=-574095341) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -872960; *v = -574095341;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 68: treetable_add(key=46858240, val=180994) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 46858240; *v = 180994;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 69: treetable_add(key=51200, val=-939476736) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 51200; *v = -939476736;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 70: treetable_add(key=8388608, val=8192) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 8388608; *v = 8192;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 71: treetable_add(key=44544, val=33685504) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 44544; *v = 33685504;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 72: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 73: treetable_add(key=13107200, val=12124160) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = 12124160;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 74: treetable_add(key=512, val=44544) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 512; *v = 44544;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 75: treetable_add(key=-1392410880, val=199) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -1392410880; *v = 199;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 76: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 77: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 78: treetable_add(key=13107200, val=0) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = 0;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 79: treetable_add(key=200, val=453050331) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 200; *v = 453050331;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 80: treetable_add(key=33683200, val=33680898) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 33683200; *v = 33680898;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 81: treetable_add(key=33561344, val=538976258) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 33561344; *v = 538976258;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 82: treetable_add(key=538974976, val=2105376) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 538974976; *v = 2105376;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 83: treetable_add(key=545376256, val=538973216) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 545376256; *v = 538973216;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 84: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 85: treetable_add(key=13107200, val=12124160) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = 12124160;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
