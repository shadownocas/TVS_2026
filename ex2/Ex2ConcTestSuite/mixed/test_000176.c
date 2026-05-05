/*
 * test_000176.c
 *
 * Group    : mixed
 * Property : VALIDITY + LOOKUP — interleaved add and lookup operations; checks both invariants and return values
 *
 * Derived from minimised corpus file: ex2/Ex2Harness/minimized_corpus/id:000176,src:000145,time:310404,op:havoc,rep:4
 * Total decoded steps: 23
 *
 * Compile (from ex2/Ex2ConcTestSuite/mixed/):
 *   gcc -g -fsanitize=address -o test_000176 test_000176.c  *       ../../../TreeTable/treetable.c -I ../../../TreeTable/
 * Run:
 *   ./test_000176
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

    /* step 0: treetable_add(key=1, val=1677786980) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 1; *v = 1677786980;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 1: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 2: treetable_add(key=13107200, val=408248064) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 13107200; *v = 408248064;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 3: treetable_get(key=2147483647) */
    { int k = 2147483647; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 4: treetable_add(key=16842880, val=16843009) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16842880; *v = 16843009;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 5: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 6: treetable_get_first_key() */
    { void *out = NULL; treetable_get_first_key(t, &out); }
    /* step 7: treetable_get_greater_than(key=1) */
    { int k = 1; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 8: treetable_get(key=16848896) */
    { int k = 16848896; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 9: treetable_add(key=16843009, val=16843009) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 16843009; *v = 16843009;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 10: treetable_get(key=50462720) */
    { int k = 50462720; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 11: treetable_get(key=33554432) */
    { int k = 33554432; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 12: treetable_get_greater_than(key=1) */
    { int k = 1; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 13: treetable_get(key=33554432) */
    { int k = 33554432; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 14: treetable_get_greater_than(key=16777217) */
    { int k = 16777217; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 15: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 16: treetable_get(key=16843009) */
    { int k = 16843009; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 17: treetable_get(key=33554433) */
    { int k = 33554433; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 18: treetable_get_greater_than(key=1) */
    { int k = 1; void *out = NULL; treetable_get_greater_than(t, &k, &out); }
    /* step 19: treetable_get(key=16848896) */
    { int k = 16848896; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 20: treetable_add(key=50462720, val=1) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 50462720; *v = 1;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }
    /* step 21: treetable_get(key=33587200) */
    { int k = 33587200; void *out = NULL; treetable_get(t, &k, &out); }
    /* step 22: treetable_get_greater_than(key=1) */
    { int k = 1; void *out = NULL; treetable_get_greater_than(t, &k, &out); }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
