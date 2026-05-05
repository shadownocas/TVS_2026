/*
 * test_000178.c
 *
 * Group    : mixed
 * Property : VALIDITY + LOOKUP — interleaved add and lookup operations; checks both invariants and return values
 *
 * Derived from minimised corpus file: ex2/Ex2Harness/minimized_corpus/id:000178,src:000145,time:311396,op:havoc,rep:32
 * Total decoded steps: 23
 *
 * Compile (from ex2/Ex2ConcTestSuite/mixed/):
 *   gcc -g -fsanitize=address -o test_000178 test_000178.c  *       ../../../TreeTable/treetable.c -I ../../../TreeTable/
 * Run:
 *   ./test_000178
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

    /* step 0: treetable_add(key=-369032959, val=16843032) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -369032959; *v = 16843032;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 1: treetable_get(key=15517441) */
    { int k = 15517441; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 2: treetable_add(key=-255, val=-65025) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -255; *v = -65025;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 3: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 4: treetable_add(key=6604810, val=352381183) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 6604810; *v = 352381183;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 5: treetable_add(key=-16776929, val=50528500) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -16776929; *v = 50528500;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 6: treetable_get(key=16777216) */
    { int k = 16777216; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 7: treetable_add(key=-469710848, val=16843009) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -469710848; *v = 16843009;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 8: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 9: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 10: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 11: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 12: treetable_get(key=-16711423) */
    { int k = -16711423; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 13: treetable_get(key=60615) */
    { int k = 60615; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 14: treetable_get(key=16843263) */
    { int k = 16843263; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 15: treetable_get(key=25231105) */
    { int k = 25231105; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 16: treetable_get(key=16843026) */
    { int k = 16843026; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 17: treetable_get(key=50462720) */
    { int k = 50462720; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 18: treetable_get(key=16842752) */
    { int k = 16842752; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 19: treetable_get(key=-16711423) */
    { int k = -16711423; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 20: treetable_get(key=16847361) */
    { int k = 16847361; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 21: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 22: treetable_get(key=16843249) */
    { int k = 16843249; void *out = NULL; treetable_get(t, &k, &out); }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
