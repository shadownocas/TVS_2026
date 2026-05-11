/*
 * Concrete test suite derived from KLEE symbolic execution.
 * Source symbolic test: test_validity_multi_add.c
 * Property: balanced+sorted after ascending/descending 5-key insertion + duplicate
 *
 * Each test_N() function replays the API call sequence with the concrete
 * values assigned by KLEE for that execution path.
 *
 * Build:
 *   clang -I../../TreeTable -fprofile-instr-generate -fcoverage-mapping \
 *         test_validity_multi_add.c ../../TreeTable/treetable.c -o test_validity_multi_add
 * Run:
 *   ./test_validity_multi_add
 */

#include <assert.h>
#include <stdio.h>
#include "treetable.h"

/* test_1: a=[0,16777216,33554432,33554560,33570816] b=[0,16777216,33554432,33554560,33570816]
 * Checks: balanced+sorted after ascending and descending insertion + duplicate. */
static void test_1(void)
{
    int a1=0,a2=16777216,a3=33554432,a4=33554560,a5=33570816;
    int b1=0,b2=16777216,b3=33554432,b4=33554560,b5=33570816;
    int va=1, vdup_a=99, vb=2, vdup_b=88;
    TreeTable *ta; treetable_new(&ta);
    treetable_add(ta,&a1,&va); assert(balanced(ta)&&sorted(ta));
    treetable_add(ta,&a2,&va); assert(balanced(ta)&&sorted(ta));
    treetable_add(ta,&a3,&va); assert(balanced(ta)&&sorted(ta));
    treetable_add(ta,&a4,&va); assert(balanced(ta)&&sorted(ta));
    treetable_add(ta,&a5,&va); assert(balanced(ta)&&sorted(ta));
    treetable_add(ta,&a3,&vdup_a); assert(balanced(ta)&&sorted(ta));
    treetable_destroy(ta);
    TreeTable *tb; treetable_new(&tb);
    treetable_add(tb,&b5,&vb); assert(balanced(tb)&&sorted(tb));
    treetable_add(tb,&b4,&vb); assert(balanced(tb)&&sorted(tb));
    treetable_add(tb,&b3,&vb); assert(balanced(tb)&&sorted(tb));
    treetable_add(tb,&b2,&vb); assert(balanced(tb)&&sorted(tb));
    treetable_add(tb,&b1,&vb); assert(balanced(tb)&&sorted(tb));
    treetable_add(tb,&b3,&vdup_b); assert(balanced(tb)&&sorted(tb));
    treetable_destroy(tb);
}

int main(void)
{
    test_1(); printf("test_1 passed\n");
    printf("All 1 tests passed.\n");
    return 0;
}
