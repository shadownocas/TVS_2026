/*
 * test_000240.c
 *
 * Group    : lookup_correctness
 * Property : LOOKUP CORRECTNESS — treetable_get / treetable_get_first_key / treetable_get_greater_than return correct results for inserted keys
 *
 * Derived from minimised corpus file: ex2/Ex2Harness/minimized_corpus/id:000240,src:000190,time:891136,op:havoc,rep:64
 * Total decoded steps: 114
 *
 * Compile (from ex2/Ex2ConcTestSuite/lookup_correctness/):
 *   gcc -g -fsanitize=address -o test_000240 test_000240.c  *       ../../../TreeTable/treetable.c -I ../../../TreeTable/
 * Run:
 *   ./test_000240
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

    /* step 0: treetable_add(key=-352329215, val=545259293) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -352329215; *v = 545259293;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 1: treetable_add(key=33224, val=33555149) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 33224; *v = 33555149;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 2: treetable_add(key=14417920, val=63441379) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 14417920; *v = 63441379;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 3: treetable_add(key=64000, val=0) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 64000; *v = 0;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 4: treetable_add(key=0, val=-16718079) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 0; *v = -16718079;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 5: treetable_add(key=33685759, val=131072) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 33685759; *v = 131072;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 6: treetable_add(key=14155776, val=-686421987) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 14155776; *v = -686421987;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 7: treetable_add(key=5890, val=-65336) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 5890; *v = -65336;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 8: treetable_add(key=-384434428, val=-385934848) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -384434428; *v = -385934848;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 9: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 10: treetable_add(key=-50724864, val=-486475010) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -50724864; *v = -486475010;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 11: treetable_add(key=570485969, val=-741867520) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 570485969; *v = -741867520;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 12: treetable_add(key=522, val=-738998256) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 522; *v = -738998256;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 13: treetable_add(key=32, val=-855637995) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 32; *v = -855637995;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 14: treetable_add(key=-101580553, val=654442499) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -101580553; *v = 654442499;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 15: treetable_add(key=16384000, val=1677785600) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16384000; *v = 1677785600;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 16: treetable_add(key=-1057161216, val=20774656) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -1057161216; *v = 20774656;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 17: treetable_add(key=7167, val=514) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 7167; *v = 514;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 18: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 19: treetable_add(key=280, val=136118357) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 280; *v = 136118357;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 20: treetable_add(key=5890, val=-65336) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 5890; *v = -65336;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 21: treetable_add(key=-32178176, val=417530106) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -32178176; *v = 417530106;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 22: treetable_add(key=570485969, val=-70778880) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 570485969; *v = -70778880;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 23: treetable_add(key=-656541597, val=300973320) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -656541597; *v = 300973320;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 24: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 25: treetable_add(key=2564096, val=16384000) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2564096; *v = 16384000;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 26: treetable_add(key=325320954, val=-134217785) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 325320954; *v = -134217785;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 27: treetable_add(key=13047295, val=-419349249) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13047295; *v = -419349249;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 28: treetable_add(key=16711935, val=514) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16711935; *v = 514;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 29: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 30: treetable_add(key=24, val=216) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 24; *v = 216;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 31: treetable_add(key=-939524096, val=-12582912) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -939524096; *v = -12582912;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 32: treetable_add(key=8, val=1677721611) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 8; *v = 1677721611;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 33: treetable_add(key=354353152, val=13047273) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 354353152; *v = 13047273;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 34: treetable_add(key=67108914, val=603980000) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 67108914; *v = 603980000;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 35: treetable_add(key=-741142276, val=-1210853908) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -741142276; *v = -1210853908;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 36: treetable_add(key=522, val=-738998256) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 522; *v = -738998256;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 37: treetable_add(key=32, val=-855637995) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 32; *v = -855637995;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 38: treetable_add(key=-638451465, val=654442499) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -638451465; *v = 654442499;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 39: treetable_add(key=16384000, val=1677785600) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16384000; *v = 1677785600;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 40: treetable_add(key=-1057161216, val=20774656) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -1057161216; *v = 20774656;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 41: treetable_add(key=7167, val=514) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 7167; *v = 514;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 42: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 43: treetable_add(key=24, val=136118357) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 24; *v = 136118357;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 44: treetable_add(key=5890, val=-218693432) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 5890; *v = -218693432;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 45: treetable_add(key=-65336, val=6911) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -65336; *v = 6911;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 46: treetable_add(key=16449045, val=-571991837) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16449045; *v = -571991837;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 47: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 48: treetable_add(key=512, val=9985) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 512; *v = 9985;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 49: treetable_add(key=-100663046, val=67134464) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -100663046; *v = 67134464;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 50: treetable_add(key=13047295, val=-419349249) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13047295; *v = -419349249;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 51: treetable_add(key=16711935, val=514) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16711935; *v = 514;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 52: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 53: treetable_add(key=24, val=136118488) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 24; *v = 136118488;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 54: treetable_add(key=5890, val=-65336) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 5890; *v = -65336;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 55: treetable_add(key=-384434428, val=-385934848) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -384434428; *v = -385934848;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 56: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 57: treetable_add(key=0, val=-486539264) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 0; *v = -486539264;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 58: treetable_add(key=570485969, val=-70778880) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 570485969; *v = -70778880;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 59: treetable_add(key=-656541597, val=300973320) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -656541597; *v = 300973320;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 60: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 61: treetable_add(key=16777216, val=15269632) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16777216; *v = 15269632;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 62: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 63: treetable_add(key=-204992512, val=536925139) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -204992512; *v = 536925139;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 64: treetable_add(key=1376256, val=16698624) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 1376256; *v = 16698624;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 65: treetable_add(key=14219506, val=9986) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 14219506; *v = 9986;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 66: treetable_add(key=-100663046, val=-955030528) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -100663046; *v = -955030528;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 67: treetable_add(key=-1057161216, val=20774656) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -1057161216; *v = 20774656;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 68: treetable_add(key=7167, val=514) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 7167; *v = 514;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 69: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 70: treetable_add(key=24, val=136118357) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 24; *v = 136118357;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 71: treetable_add(key=5890, val=-65336) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 5890; *v = -65336;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 72: treetable_add(key=-32178176, val=417530106) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -32178176; *v = 417530106;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 73: treetable_add(key=570485969, val=-70778880) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 570485969; *v = -70778880;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 74: treetable_add(key=-656541597, val=-1082104) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -656541597; *v = -1082104;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 75: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 76: treetable_add(key=2556416, val=16384000) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2556416; *v = 16384000;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 77: treetable_add(key=325320946, val=-134217785) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 325320946; *v = -134217785;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 78: treetable_add(key=13047295, val=-419349249) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13047295; *v = -419349249;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 79: treetable_add(key=16711935, val=514) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16711935; *v = 514;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 80: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 81: treetable_add(key=24, val=136118488) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 24; *v = 136118488;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 82: treetable_add(key=5890, val=-65336) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 5890; *v = -65336;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 83: treetable_add(key=-382796028, val=-385934848) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -382796028; *v = -385934848;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 84: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 85: treetable_add(key=-50724864, val=-486475010) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -50724864; *v = -486475010;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 86: treetable_add(key=570485969, val=-70778880) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 570485969; *v = -70778880;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 87: treetable_add(key=-658835357, val=300973320) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -658835357; *v = 300973320;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 88: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 89: treetable_add(key=0, val=-385941503) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 0; *v = -385941503;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 90: treetable_add(key=522, val=-738998256) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 522; *v = -738998256;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 91: treetable_add(key=32, val=-855637995) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 32; *v = -855637995;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 92: treetable_add(key=-118357769, val=654442745) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -118357769; *v = 654442745;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 93: treetable_add(key=15138816, val=1677785600) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 15138816; *v = 1677785600;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 94: treetable_add(key=12647680, val=-419349249) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 12647680; *v = -419349249;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 95: treetable_add(key=7167, val=514) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 7167; *v = 514;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 96: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 97: treetable_add(key=24, val=136118357) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 24; *v = 136118357;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 98: treetable_add(key=5890, val=-65336) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 5890; *v = -65336;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 99: treetable_add(key=-32178176, val=417530106) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -32178176; *v = 417530106;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 100: treetable_add(key=570485969, val=-70778880) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 570485969; *v = -70778880;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 101: treetable_add(key=-656541597, val=300973320) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -656541597; *v = 300973320;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 102: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 103: treetable_add(key=2556416, val=16384000) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 2556416; *v = 16384000;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 104: treetable_add(key=325320946, val=-134217785) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 325320946; *v = -134217785;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 105: treetable_add(key=13047295, val=-419349249) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13047295; *v = -419349249;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 106: treetable_add(key=16711935, val=514) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16711935; *v = 514;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 107: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 108: treetable_add(key=24, val=136118488) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 24; *v = 136118488;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 109: treetable_add(key=5890, val=-65336) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 5890; *v = -65336;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 110: treetable_add(key=-384434428, val=-385934848) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -384434428; *v = -385934848;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 111: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 112: treetable_add(key=-50724864, val=-486475010) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -50724864; *v = -486475010;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 113: treetable_add(key=570485969, val=-70778880) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 570485969; *v = -70778880;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
