/*
 * Concrete test suite derived from KLEE symbolic execution.
 * Source symbolic test: test_get_correctness.c
 * Property: lookup correctness: found/not-found/update/size-read-only
 *
 * Each test_N() function replays the API call sequence with the concrete
 * values assigned by KLEE for that execution path.
 *
 * Build:
 *   clang -I../../TreeTable -fprofile-instr-generate -fcoverage-mapping \
 *         test_get_correctness.c ../../TreeTable/treetable.c -o test_get_correctness
 * Run:
 *   ./test_get_correctness
 */

#include <assert.h>
#include <stdio.h>
#include "treetable.h"

/* test_1: k1=0, k2=0, k3=0, absent=-1
 * Checks: lookup correctness, update returns new value, size unchanged by reads. */
static void test_1(void)
{
    int k1=0, k2=0, k3=0, absent=-1;
    int v1=10, v2=20, v3=30, v1_new=99;
    void *out = NULL;
    TreeTable *t;
    treetable_new(&t);
    assert(treetable_get(t, &k1, &out) == CC_ERR_KEY_NOT_FOUND);
    treetable_add(t, &k1, &v1);
    treetable_add(t, &k2, &v2);
    treetable_add(t, &k3, &v3);
    assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 3);
    out = NULL; assert(treetable_get(t, &k1, &out) == CC_OK); assert(out == &v1);
    out = NULL; assert(treetable_get(t, &k2, &out) == CC_OK); assert(out == &v2);
    out = NULL; assert(treetable_get(t, &k3, &out) == CC_OK); assert(out == &v3);
    out = NULL; assert(treetable_get(t, &absent, &out) == CC_ERR_KEY_NOT_FOUND);
    assert(treetable_size(t) == 3);
    treetable_add(t, &k1, &v1_new);
    out = NULL; assert(treetable_get(t, &k1, &out) == CC_OK); assert(out == &v1_new);
    assert(treetable_size(t) == 3);
    treetable_destroy(t);
}

/* test_2: k1=0, k2=128, k3=16384, absent=0
 * Checks: lookup correctness, update returns new value, size unchanged by reads. */
static void test_2(void)
{
    int k1=0, k2=128, k3=16384, absent=0;
    int v1=10, v2=20, v3=30, v1_new=99;
    void *out = NULL;
    TreeTable *t;
    treetable_new(&t);
    assert(treetable_get(t, &k1, &out) == CC_ERR_KEY_NOT_FOUND);
    treetable_add(t, &k1, &v1);
    treetable_add(t, &k2, &v2);
    treetable_add(t, &k3, &v3);
    assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 3);
    out = NULL; assert(treetable_get(t, &k1, &out) == CC_OK); assert(out == &v1);
    out = NULL; assert(treetable_get(t, &k2, &out) == CC_OK); assert(out == &v2);
    out = NULL; assert(treetable_get(t, &k3, &out) == CC_OK); assert(out == &v3);
    out = NULL; assert(treetable_get(t, &absent, &out) == CC_ERR_KEY_NOT_FOUND);
    assert(treetable_size(t) == 3);
    treetable_add(t, &k1, &v1_new);
    out = NULL; assert(treetable_get(t, &k1, &out) == CC_OK); assert(out == &v1_new);
    assert(treetable_size(t) == 3);
    treetable_destroy(t);
}

/* test_3: k1=-2130706432, k2=-1073741824, k3=16777216, absent=0
 * Checks: lookup correctness, update returns new value, size unchanged by reads. */
static void test_3(void)
{
    int k1=-2130706432, k2=-1073741824, k3=16777216, absent=0;
    int v1=10, v2=20, v3=30, v1_new=99;
    void *out = NULL;
    TreeTable *t;
    treetable_new(&t);
    assert(treetable_get(t, &k1, &out) == CC_ERR_KEY_NOT_FOUND);
    treetable_add(t, &k1, &v1);
    treetable_add(t, &k2, &v2);
    treetable_add(t, &k3, &v3);
    assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 3);
    out = NULL; assert(treetable_get(t, &k1, &out) == CC_OK); assert(out == &v1);
    out = NULL; assert(treetable_get(t, &k2, &out) == CC_OK); assert(out == &v2);
    out = NULL; assert(treetable_get(t, &k3, &out) == CC_OK); assert(out == &v3);
    out = NULL; assert(treetable_get(t, &absent, &out) == CC_ERR_KEY_NOT_FOUND);
    assert(treetable_size(t) == 3);
    treetable_add(t, &k1, &v1_new);
    out = NULL; assert(treetable_get(t, &k1, &out) == CC_OK); assert(out == &v1_new);
    assert(treetable_size(t) == 3);
    treetable_destroy(t);
}

/* test_4: k1=256, k2=65536, k3=16777216, absent=0
 * Checks: lookup correctness, update returns new value, size unchanged by reads. */
static void test_4(void)
{
    int k1=256, k2=65536, k3=16777216, absent=0;
    int v1=10, v2=20, v3=30, v1_new=99;
    void *out = NULL;
    TreeTable *t;
    treetable_new(&t);
    assert(treetable_get(t, &k1, &out) == CC_ERR_KEY_NOT_FOUND);
    treetable_add(t, &k1, &v1);
    treetable_add(t, &k2, &v2);
    treetable_add(t, &k3, &v3);
    assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 3);
    out = NULL; assert(treetable_get(t, &k1, &out) == CC_OK); assert(out == &v1);
    out = NULL; assert(treetable_get(t, &k2, &out) == CC_OK); assert(out == &v2);
    out = NULL; assert(treetable_get(t, &k3, &out) == CC_OK); assert(out == &v3);
    out = NULL; assert(treetable_get(t, &absent, &out) == CC_ERR_KEY_NOT_FOUND);
    assert(treetable_size(t) == 3);
    treetable_add(t, &k1, &v1_new);
    out = NULL; assert(treetable_get(t, &k1, &out) == CC_OK); assert(out == &v1_new);
    assert(treetable_size(t) == 3);
    treetable_destroy(t);
}

/* test_5: k1=0, k2=65536, k3=65537, absent=16777216
 * Checks: lookup correctness, update returns new value, size unchanged by reads. */
static void test_5(void)
{
    int k1=0, k2=65536, k3=65537, absent=16777216;
    int v1=10, v2=20, v3=30, v1_new=99;
    void *out = NULL;
    TreeTable *t;
    treetable_new(&t);
    assert(treetable_get(t, &k1, &out) == CC_ERR_KEY_NOT_FOUND);
    treetable_add(t, &k1, &v1);
    treetable_add(t, &k2, &v2);
    treetable_add(t, &k3, &v3);
    assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 3);
    out = NULL; assert(treetable_get(t, &k1, &out) == CC_OK); assert(out == &v1);
    out = NULL; assert(treetable_get(t, &k2, &out) == CC_OK); assert(out == &v2);
    out = NULL; assert(treetable_get(t, &k3, &out) == CC_OK); assert(out == &v3);
    out = NULL; assert(treetable_get(t, &absent, &out) == CC_ERR_KEY_NOT_FOUND);
    assert(treetable_size(t) == 3);
    treetable_add(t, &k1, &v1_new);
    out = NULL; assert(treetable_get(t, &k1, &out) == CC_OK); assert(out == &v1_new);
    assert(treetable_size(t) == 3);
    treetable_destroy(t);
}

/* test_6: k1=0, k2=33554432, k3=33554560, absent=16777216
 * Checks: lookup correctness, update returns new value, size unchanged by reads. */
static void test_6(void)
{
    int k1=0, k2=33554432, k3=33554560, absent=16777216;
    int v1=10, v2=20, v3=30, v1_new=99;
    void *out = NULL;
    TreeTable *t;
    treetable_new(&t);
    assert(treetable_get(t, &k1, &out) == CC_ERR_KEY_NOT_FOUND);
    treetable_add(t, &k1, &v1);
    treetable_add(t, &k2, &v2);
    treetable_add(t, &k3, &v3);
    assert(balanced(t) && sorted(t));
    assert(treetable_size(t) == 3);
    out = NULL; assert(treetable_get(t, &k1, &out) == CC_OK); assert(out == &v1);
    out = NULL; assert(treetable_get(t, &k2, &out) == CC_OK); assert(out == &v2);
    out = NULL; assert(treetable_get(t, &k3, &out) == CC_OK); assert(out == &v3);
    out = NULL; assert(treetable_get(t, &absent, &out) == CC_ERR_KEY_NOT_FOUND);
    assert(treetable_size(t) == 3);
    treetable_add(t, &k1, &v1_new);
    out = NULL; assert(treetable_get(t, &k1, &out) == CC_OK); assert(out == &v1_new);
    assert(treetable_size(t) == 3);
    treetable_destroy(t);
}

int main(void)
{
    test_1(); printf("test_1 passed\n");
    test_2(); printf("test_2 passed\n");
    test_3(); printf("test_3 passed\n");
    test_4(); printf("test_4 passed\n");
    test_5(); printf("test_5 passed\n");
    test_6(); printf("test_6 passed\n");
    printf("All 6 tests passed.\n");
    return 0;
}
