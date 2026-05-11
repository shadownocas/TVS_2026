/*
 * Concrete test suite derived from KLEE symbolic execution.
 * Source symbolic test: test_validity_zigzag_insert.c
 * Property: balanced+sorted after zigzag insertion (covers L-R and R-L rotations)
 *
 * Each test_N() function replays the API call sequence with the concrete
 * values assigned by KLEE for that execution path.
 *
 * Build:
 *   clang -I../../TreeTable -fprofile-instr-generate -fcoverage-mapping \
 *         test_validity_zigzag_insert.c ../../TreeTable/treetable.c -o test_validity_zigzag_insert
 * Run:
 *   ./test_validity_zigzag_insert
 */

#include <assert.h>
#include <stdio.h>
#include "treetable.h"

/* test_1: k1=0, k2=0, k3=0, k4=0, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_1(void)
{
    int k1=0,k2=0,k3=0,k4=0,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_2: k1=16777216, k2=0, k3=0, k4=0, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_2(void)
{
    int k1=16777216,k2=0,k3=0,k4=0,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_3: k1=16777216, k2=50331648, k3=0, k4=0, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_3(void)
{
    int k1=16777216,k2=50331648,k3=0,k4=0,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_4: k1=-2147483640, k2=-2147483642, k3=-1879048175, k4=-1928591359, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_4(void)
{
    int k1=-2147483640,k2=-2147483642,k3=-1879048175,k4=-1928591359,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_5: k1=-1358954496, k2=0, k3=-536870912, k4=-687900745, k5=16777216
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_5(void)
{
    int k1=-1358954496,k2=0,k3=-536870912,k4=-687900745,k5=16777216;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_6: k1=-2130706432, k2=16777408, k3=16777216, k4=0, k5=16777375
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_6(void)
{
    int k1=-2130706432,k2=16777408,k3=16777216,k4=0,k5=16777375;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_7: k1=-2140141551, k2=-2139095040, k3=-2139095039, k4=-2147481582, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_7(void)
{
    int k1=-2140141551,k2=-2139095040,k3=-2139095039,k4=-2147481582,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_8: k1=520093696, k2=671088640, k3=536870912, k4=0, k5=939524096
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_8(void)
{
    int k1=520093696,k2=671088640,k3=536870912,k4=0,k5=939524096;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_9: k1=-1073741822, k2=276861015, k3=-1056964608, k4=-2139095040, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_9(void)
{
    int k1=-1073741822,k2=276861015,k3=-1056964608,k4=-2139095040,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_10: k1=-2147483640, k2=-2147483646, k3=-1879044095, k4=-2147483642, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_10(void)
{
    int k1=-2147483640,k2=-2147483646,k3=-1879044095,k4=-2147483642,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_11: k1=-1342123456, k2=-1409286144, k3=-1326399995, k4=-50331648, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_11(void)
{
    int k1=-1342123456,k2=-1409286144,k3=-1326399995,k4=-50331648,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_12: k1=-2144335587, k2=-2139095040, k3=-2139095039, k4=-2143285758, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_12(void)
{
    int k1=-2144335587,k2=-2139095040,k3=-2139095039,k4=-2143285758,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_13: k1=-2147421957, k2=-2130706432, k3=-1862270976, k4=-1912602624, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_13(void)
{
    int k1=-2147421957,k2=-2130706432,k3=-1862270976,k4=-1912602624,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_14: k1=-2131976834, k2=-2130706432, k3=-1876951040, k4=-16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_14(void)
{
    int k1=-2131976834,k2=-2130706432,k3=-1876951040,k4=-16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_15: k1=-1895763717, k2=-1895825408, k3=-1862270976, k4=-1912602624, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_15(void)
{
    int k1=-1895763717,k2=-1895825408,k3=-1862270976,k4=-1912602624,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_16: k1=-2147422089, k2=33554432, k3=-2130706432, k4=0, k5=16777216
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_16(void)
{
    int k1=-2147422089,k2=33554432,k3=-2130706432,k4=0,k5=16777216;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_17: k1=-2130706349, k2=-1946157056, k3=-1879048191, k4=285212672, k5=268435456
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_17(void)
{
    int k1=-2130706349,k2=-1946157056,k3=-1879048191,k4=285212672,k5=268435456;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_18: k1=-2139095040, k2=-2147422085, k3=-2130706432, k4=16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_18(void)
{
    int k1=-2139095040,k2=-2147422085,k3=-2130706432,k4=16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_19: k1=-1879027543, k2=-1073680129, k3=-1862270976, k4=0, k5=-1056964608
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_19(void)
{
    int k1=-1879027543,k2=-1073680129,k3=-1862270976,k4=0,k5=-1056964608;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_20: k1=50331840, k2=50331896, k3=33554432, k4=16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_20(void)
{
    int k1=50331840,k2=50331896,k3=33554432,k4=16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_21: k1=1644167168, k2=1308622848, k3=1627389952, k4=0, k5=232
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_21(void)
{
    int k1=1644167168,k2=1308622848,k3=1627389952,k4=0,k5=232;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_22: k1=-2147483627, k2=33554432, k3=-2147483584, k4=16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_22(void)
{
    int k1=-2147483627,k2=33554432,k3=-2147483584,k4=16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_23: k1=15767422, k2=16777216, k3=65536, k4=-16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_23(void)
{
    int k1=15767422,k2=16777216,k3=65536,k4=-16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_24: k1=273679296, k2=-1878915952, k3=-1862270976, k4=0, k5=-1895825408
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_24(void)
{
    int k1=273679296,k2=-1878915952,k3=-1862270976,k4=0,k5=-1895825408;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_25: k1=33554432, k2=-301989888, k3=16777408, k4=16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_25(void)
{
    int k1=33554432,k2=-301989888,k3=16777408,k4=16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_26: k1=33554432, k2=-16777216, k3=128, k4=16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_26(void)
{
    int k1=33554432,k2=-16777216,k3=128,k4=16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_27: k1=50353166, k2=16793602, k3=12544, k4=110, k5=-2141176064
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_27(void)
{
    int k1=50353166,k2=16793602,k3=12544,k4=110,k5=-2141176064;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_28: k1=33554432, k2=16777216, k3=14680064, k4=-50331648, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_28(void)
{
    int k1=33554432,k2=16777216,k3=14680064,k4=-50331648,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_29: k1=16777216, k2=-16777216, k3=8388608, k4=33554432, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_29(void)
{
    int k1=16777216,k2=-16777216,k3=8388608,k4=33554432,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_30: k1=-33554432, k2=16777217, k3=0, k4=1090519072, k5=1107167168
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_30(void)
{
    int k1=-33554432,k2=16777217,k3=0,k4=1090519072,k5=1107167168;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_31: k1=-1073741823, k2=-2132123649, k3=-2130706432, k4=0, k5=-2134900738
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_31(void)
{
    int k1=-1073741823,k2=-2132123649,k3=-2130706432,k4=0,k5=-2134900738;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_32: k1=-2147422051, k2=16657, k3=-2130673648, k4=-2130673616, k5=32768
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_32(void)
{
    int k1=-2147422051,k2=16657,k3=-2130673648,k4=-2130673616,k5=32768;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_33: k1=16777376, k2=31522750, k3=65536, k4=16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_33(void)
{
    int k1=16777376,k2=31522750,k3=65536,k4=16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_34: k1=-2147458882, k2=1040187392, k3=-2130706432, k4=1090519040, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_34(void)
{
    int k1=-2147458882,k2=1040187392,k3=-2130706432,k4=1090519040,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_35: k1=2293760, k2=2162623, k3=65536, k4=16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_35(void)
{
    int k1=2293760,k2=2162623,k3=65536,k4=16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_36: k1=50331648, k2=0, k3=33554432, k4=64, k5=16777216
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_36(void)
{
    int k1=50331648,k2=0,k3=33554432,k4=64,k5=16777216;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_37: k1=33554432, k2=16777280, k3=16777216, k4=16777408, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_37(void)
{
    int k1=33554432,k2=16777280,k3=16777216,k4=16777408,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_38: k1=33554688, k2=2, k3=16777216, k4=-2147483264, k5=256
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_38(void)
{
    int k1=33554688,k2=2,k3=16777216,k4=-2147483264,k5=256;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_39: k1=33554432, k2=1048576, k3=16777216, k4=20, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_39(void)
{
    int k1=33554432,k2=1048576,k3=16777216,k4=20,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_40: k1=33554432, k2=-1258291201, k3=16777216, k4=0, k5=-2147483520
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_40(void)
{
    int k1=33554432,k2=-1258291201,k3=16777216,k4=0,k5=-2147483520;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_41: k1=50331648, k2=33554432, k3=128, k4=16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_41(void)
{
    int k1=50331648,k2=33554432,k3=128,k4=16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_42: k1=16777344, k2=50331648, k3=16777216, k4=16777408, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_42(void)
{
    int k1=16777344,k2=50331648,k3=16777216,k4=16777408,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_43: k1=33554432, k2=33554560, k3=16777216, k4=50331776, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_43(void)
{
    int k1=33554432,k2=33554560,k3=16777216,k4=50331776,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_44: k1=33554432, k2=16777216, k3=-2132738049, k4=-33554432, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_44(void)
{
    int k1=33554432,k2=16777216,k3=-2132738049,k4=-33554432,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_45: k1=50331648, k2=16777216, k3=0, k4=-33554432, k5=252
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_45(void)
{
    int k1=50331648,k2=16777216,k3=0,k4=-33554432,k5=252;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_46: k1=-33554432, k2=0, k3=-2147418112, k4=-2130706434, k5=16777216
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_46(void)
{
    int k1=-33554432,k2=0,k3=-2147418112,k4=-2130706434,k5=16777216;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_47: k1=65536, k2=168191, k3=-1879048191, k4=-1895825408, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_47(void)
{
    int k1=65536,k2=168191,k3=-1879048191,k4=-1895825408,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_48: k1=2061487854, k2=-33554176, k3=-2147481599, k4=-2147481600, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_48(void)
{
    int k1=2061487854,k2=-33554176,k3=-2147481599,k4=-2147481600,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_49: k1=33554432, k2=1090519296, k3=16777216, k4=0, k5=1107296500
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_49(void)
{
    int k1=33554432,k2=1090519296,k3=16777216,k4=0,k5=1107296500;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_50: k1=61695, k2=16777216, k3=-2130706432, k4=0, k5=256
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_50(void)
{
    int k1=61695,k2=16777216,k3=-2130706432,k4=0,k5=256;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_51: k1=16777280, k2=33554432, k3=16777216, k4=0, k5=16777408
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_51(void)
{
    int k1=16777280,k2=33554432,k3=16777216,k4=0,k5=16777408;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_52: k1=14745341, k2=-2130706432, k3=-1593835520, k4=-16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_52(void)
{
    int k1=14745341,k2=-2130706432,k3=-1593835520,k4=-16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_53: k1=-2129657864, k2=-2139095040, k3=-2139095039, k4=-2130706432, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_53(void)
{
    int k1=-2129657864,k2=-2139095040,k3=-2139095039,k4=-2130706432,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_54: k1=-1601171403, k2=-2130706432, k3=-1610547200, k4=-33554432, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_54(void)
{
    int k1=-1601171403,k2=-2130706432,k3=-1610547200,k4=-33554432,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_55: k1=-1056964608, k2=-1073741824, k3=7383981, k4=-33554432, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_55(void)
{
    int k1=-1056964608,k2=-1073741824,k3=7383981,k4=-33554432,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_56: k1=16464, k2=8421, k3=-2130689982, k4=16793680, k5=16640
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_56(void)
{
    int k1=16464,k2=8421,k3=-2130689982,k4=16793680,k5=16640;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_57: k1=50331648, k2=16777216, k3=0, k4=536870914, k5=553648256
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_57(void)
{
    int k1=50331648,k2=16777216,k3=0,k4=536870914,k5=553648256;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_58: k1=33554432, k2=0, k3=-2097152000, k4=16777216, k5=192
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_58(void)
{
    int k1=33554432,k2=0,k3=-2097152000,k4=16777216,k5=192;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_59: k1=-18808949, k2=-16777216, k3=13659769, k4=-33554432, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_59(void)
{
    int k1=-18808949,k2=-16777216,k3=13659769,k4=-33554432,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_60: k1=1, k2=0, k3=-2145386495, k4=-2146369533, k5=2097152
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_60(void)
{
    int k1=1,k2=0,k3=-2145386495,k4=-2146369533,k5=2097152;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_61: k1=65536, k2=61695, k3=-2130706432, k4=16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_61(void)
{
    int k1=65536,k2=61695,k3=-2130706432,k4=16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_62: k1=-33554432, k2=50331648, k3=33553781, k4=16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_62(void)
{
    int k1=-33554432,k2=50331648,k3=33553781,k4=16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_63: k1=-2130706432, k2=16777216, k3=-2131730441, k4=-50331648, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_63(void)
{
    int k1=-2130706432,k2=16777216,k3=-2131730441,k4=-50331648,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_64: k1=-2130706432, k2=-2147483632, k3=-2143164442, k4=16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_64(void)
{
    int k1=-2130706432,k2=-2147483632,k3=-2143164442,k4=16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_65: k1=33566229, k2=-33554368, k3=-2147482624, k4=50356224, k5=16777216
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_65(void)
{
    int k1=33566229,k2=-33554368,k3=-2147482624,k4=50356224,k5=16777216;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_66: k1=4229, k2=33554432, k3=-2130706432, k4=0, k5=16777216
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_66(void)
{
    int k1=4229,k2=33554432,k3=-2130706432,k4=0,k5=16777216;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_67: k1=-1073741824, k2=-2147442946, k3=-2130706432, k4=0, k5=-1610596619
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_67(void)
{
    int k1=-1073741824,k2=-2147442946,k3=-2130706432,k4=0,k5=-1610596619;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_68: k1=-1073741824, k2=-1073741820, k3=-1610612736, k4=0, k5=-1073741819
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_68(void)
{
    int k1=-1073741824,k2=-1073741820,k3=-1610612736,k4=0,k5=-1073741819;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_69: k1=33554432, k2=-1128272897, k3=-1073741824, k4=16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_69(void)
{
    int k1=33554432,k2=-1128272897,k3=-1073741824,k4=16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_70: k1=-33554432, k2=33554432, k3=16777216, k4=0, k5=192
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_70(void)
{
    int k1=-33554432,k2=33554432,k3=16777216,k4=0,k5=192;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_71: k1=16777216, k2=23129835, k3=33619968, k4=50331648, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_71(void)
{
    int k1=16777216,k2=23129835,k3=33619968,k4=50331648,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_72: k1=16777440, k2=16838911, k3=-2130706432, k4=16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_72(void)
{
    int k1=16777440,k2=16838911,k3=-2130706432,k4=16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_73: k1=94, k2=88, k3=33554432, k4=16785408, k5=8192
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_73(void)
{
    int k1=94,k2=88,k3=33554432,k4=16785408,k5=8192;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_74: k1=22, k2=33554454, k3=16777238, k4=4, k5=512
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_74(void)
{
    int k1=22,k2=33554454,k3=16777238,k4=4,k5=512;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_75: k1=14691765, k2=1593835520, k3=1627389952, k4=-33554432, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_75(void)
{
    int k1=14691765,k2=1593835520,k3=1627389952,k4=-33554432,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_76: k1=-2142200075, k2=1040187392, k3=1090519040, k4=-16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_76(void)
{
    int k1=-2142200075,k2=1040187392,k3=1090519040,k4=-16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_77: k1=-1002755, k2=1040187392, k3=1090519040, k4=-16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_77(void)
{
    int k1=-1002755,k2=1040187392,k3=1090519040,k4=-16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_78: k1=-2147423745, k2=-2146435072, k3=-2130706432, k4=0, k5=-2143281152
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_78(void)
{
    int k1=-2147423745,k2=-2146435072,k3=-2130706432,k4=0,k5=-2143281152;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_79: k1=16777440, k2=16777468, k3=50331648, k4=16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_79(void)
{
    int k1=16777440,k2=16777468,k3=50331648,k4=16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_80: k1=-16777216, k2=16777216, k3=0, k4=-1358954496, k5=-1329856512
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_80(void)
{
    int k1=-16777216,k2=16777216,k3=0,k4=-1358954496,k5=-1329856512;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_81: k1=-33554432, k2=0, k3=16777344, k4=16777343, k5=16777216
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_81(void)
{
    int k1=-33554432,k2=0,k3=16777344,k4=16777343,k5=16777216;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_82: k1=-2130706432, k2=-2147479551, k3=16777216, k4=0, k5=-2146955264
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_82(void)
{
    int k1=-2130706432,k2=-2147479551,k3=16777216,k4=0,k5=-2146955264;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_83: k1=8388660, k2=6352831, k3=8486912, k4=25198592, k5=8392704
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_83(void)
{
    int k1=8388660,k2=6352831,k3=8486912,k4=25198592,k5=8392704;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_84: k1=1048576, k2=33554432, k3=17825792, k4=1048768, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_84(void)
{
    int k1=1048576,k2=33554432,k3=17825792,k4=1048768,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_85: k1=33554432, k2=50331648, k3=33554616, k4=16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_85(void)
{
    int k1=33554432,k2=50331648,k3=33554616,k4=16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_86: k1=-33554432, k2=1073741824, k3=1082654720, k4=1090519040, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_86(void)
{
    int k1=-33554432,k2=1073741824,k3=1082654720,k4=1090519040,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_87: k1=65536, k2=104, k3=33554432, k4=16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_87(void)
{
    int k1=65536,k2=104,k3=33554432,k4=16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_88: k1=503320576, k2=16777216, k3=553648128, k4=0, k5=255
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_88(void)
{
    int k1=503320576,k2=16777216,k3=553648128,k4=0,k5=255;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_89: k1=33554432, k2=0, k3=33554560, k4=50331900, k5=16777216
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_89(void)
{
    int k1=33554432,k2=0,k3=33554560,k4=50331900,k5=16777216;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_90: k1=33554432, k2=0, k3=50331648, k4=16777216, k5=64
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_90(void)
{
    int k1=33554432,k2=0,k3=50331648,k4=16777216,k5=64;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_91: k1=-2134455419, k2=-2134900736, k3=-2130706432, k4=0, k5=-2139095040
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_91(void)
{
    int k1=-2134455419,k2=-2134900736,k3=-2130706432,k4=0,k5=-2139095040;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_92: k1=-16777216, k2=-2147483520, k3=16777216, k4=-1073741696, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_92(void)
{
    int k1=-16777216,k2=-2147483520,k3=16777216,k4=-1073741696,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_93: k1=-1073741824, k2=-16777216, k3=-1610612736, k4=0, k5=14745599
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_93(void)
{
    int k1=-1073741824,k2=-16777216,k3=-1610612736,k4=0,k5=14745599;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_94: k1=57591, k2=50331648, k3=-2130706432, k4=16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_94(void)
{
    int k1=57591,k2=50331648,k3=-2130706432,k4=16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_95: k1=57385, k2=-2147483520, k3=-2130706432, k4=-2139095040, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_95(void)
{
    int k1=57385,k2=-2147483520,k3=-2130706432,k4=-2139095040,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_96: k1=1048579, k2=30588, k3=-2129655808, k4=-33554432, k5=1050624
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_96(void)
{
    int k1=1048579,k2=30588,k3=-2129655808,k4=-33554432,k5=1050624;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_97: k1=33554432, k2=192, k3=16777216, k4=0, k5=16777272
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_97(void)
{
    int k1=33554432,k2=192,k3=16777216,k4=0,k5=16777272;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_98: k1=1, k2=50332160, k3=-2130705920, k4=16777728, k5=512
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_98(void)
{
    int k1=1,k2=50332160,k3=-2130705920,k4=16777728,k5=512;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_99: k1=167833825, k2=1, k3=-2129657856, k4=-32505856, k5=1048576
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_99(void)
{
    int k1=167833825,k2=1,k3=-2129657856,k4=-32505856,k5=1048576;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_100: k1=-16777216, k2=-16777088, k3=16777216, k4=-16777119, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_100(void)
{
    int k1=-16777216,k2=-16777088,k3=16777216,k4=-16777119,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_101: k1=33554432, k2=0, k3=-2130706432, k4=252, k5=16777216
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_101(void)
{
    int k1=33554432,k2=0,k3=-2130706432,k4=252,k5=16777216;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_102: k1=196610, k2=417814, k3=-2130247680, k4=393354, k5=458752
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_102(void)
{
    int k1=196610,k2=417814,k3=-2130247680,k4=393354,k5=458752;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_103: k1=-2045181440, k2=-2143289216, k3=-2130706432, k4=-2139095040, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_103(void)
{
    int k1=-2045181440,k2=-2143289216,k3=-2130706432,k4=-2139095040,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_104: k1=-50331648, k2=16777216, k3=1073741824, k4=22083579, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_104(void)
{
    int k1=-50331648,k2=16777216,k3=1073741824,k4=22083579,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_105: k1=-1069547519, k2=-1877979046, k3=-2143158240, k4=-1794113536, k5=1078067200
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_105(void)
{
    int k1=-1069547519,k2=-1877979046,k3=-2143158240,k4=-1794113536,k5=1078067200;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_106: k1=1073803517, k2=2, k3=-2130706432, k4=788529152, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_106(void)
{
    int k1=1073803517,k2=2,k3=-2130706432,k4=788529152,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_107: k1=-2097152000, k2=20569, k3=-2130706432, k4=16777216, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_107(void)
{
    int k1=-2097152000,k2=20569,k3=-2130706432,k4=16777216,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_108: k1=-587374602, k2=-2147483640, k3=-2147483639, k4=-2147483647, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_108(void)
{
    int k1=-587374602,k2=-2147483640,k3=-2147483639,k4=-2147483647,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_109: k1=503316480, k2=16777216, k3=553648128, k4=0, k5=503316536
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_109(void)
{
    int k1=503316480,k2=16777216,k3=553648128,k4=0,k5=503316536;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_110: k1=65536, k2=90277, k3=-2130706432, k4=16842752, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_110(void)
{
    int k1=65536,k2=90277,k3=-2130706432,k4=16842752,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_111: k1=-2130706432, k2=-33554432, k3=16777216, k4=0, k5=2104
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_111(void)
{
    int k1=-2130706432,k2=-33554432,k3=16777216,k4=0,k5=2104;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_112: k1=33554433, k2=50396240, k3=41943040, k4=50333201, k5=16777216
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_112(void)
{
    int k1=33554433,k2=50396240,k3=41943040,k4=50333201,k5=16777216;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_113: k1=33554432, k2=144, k3=-2130706432, k4=0, k5=-2130706328
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_113(void)
{
    int k1=33554432,k2=144,k3=-2130706432,k4=0,k5=-2130706328;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_114: k1=-50331648, k2=16777408, k3=16777216, k4=16777343, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_114(void)
{
    int k1=-50331648,k2=16777408,k3=16777216,k4=16777343,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_115: k1=1753220858, k2=1233141982, k3=1880136072, k4=1744830482, k5=1744896512
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_115(void)
{
    int k1=1753220858,k2=1233141982,k3=1880136072,k4=1744830482,k5=1744896512;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_116: k1=1040187393, k2=1056964608, k3=1090522368, k4=1058111744, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_116(void)
{
    int k1=1040187393,k2=1056964608,k3=1090522368,k4=1058111744,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_117: k1=-33542144, k2=16777216, k3=4096, k4=33554433, k5=1
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_117(void)
{
    int k1=-33542144,k2=16777216,k3=4096,k4=33554433,k5=1;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_118: k1=-2139090928, k2=16777216, k3=729813008, k4=0, k5=-2130706431
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_118(void)
{
    int k1=-2139090928,k2=16777216,k3=729813008,k4=0,k5=-2130706431;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_119: k1=1040187392, k2=1342177280, k3=1090522368, k4=1611759872, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_119(void)
{
    int k1=1040187392,k2=1342177280,k3=1090522368,k4=1611759872,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_120: k1=1040187392, k2=16777216, k3=1090519040, k4=1146880, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_120(void)
{
    int k1=1040187392,k2=16777216,k3=1090519040,k4=1146880,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_121: k1=33588155, k2=50396224, k3=234881024, k4=50365373, k5=16777216
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_121(void)
{
    int k1=33588155,k2=50396224,k3=234881024,k4=50365373,k5=16777216;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_122: k1=1040187392, k2=-50331648, k3=1090519040, k4=-2129166336, k5=0
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_122(void)
{
    int k1=1040187392,k2=-50331648,k3=1090519040,k4=-2129166336,k5=0;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

/* test_123: k1=503320576, k2=-1621098594, k3=553648128, k4=0, k5=-2147483647
 * Checks: balanced+sorted after zigzag insertion (exercises L-R and R-L rotations). */
static void test_123(void)
{
    int k1=503320576,k2=-1621098594,k3=553648128,k4=0,k5=-2147483647;
    int v=1;
    TreeTable *t; treetable_new(&t);
    treetable_add(t,&k3,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k5,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k1,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k4,&v); assert(balanced(t)&&sorted(t));
    treetable_add(t,&k2,&v); assert(balanced(t)&&sorted(t));

}

int main(void)
{
    test_1(); printf("test_1 passed\n");
    test_2(); printf("test_2 passed\n");
    test_3(); printf("test_3 passed\n");
    test_4(); printf("test_4 passed\n");
    test_5(); printf("test_5 passed\n");
    test_6(); printf("test_6 passed\n");
    test_7(); printf("test_7 passed\n");
    test_8(); printf("test_8 passed\n");
    test_9(); printf("test_9 passed\n");
    test_10(); printf("test_10 passed\n");
    test_11(); printf("test_11 passed\n");
    test_12(); printf("test_12 passed\n");
    test_13(); printf("test_13 passed\n");
    test_14(); printf("test_14 passed\n");
    test_15(); printf("test_15 passed\n");
    test_16(); printf("test_16 passed\n");
    test_17(); printf("test_17 passed\n");
    test_18(); printf("test_18 passed\n");
    test_19(); printf("test_19 passed\n");
    test_20(); printf("test_20 passed\n");
    test_21(); printf("test_21 passed\n");
    test_22(); printf("test_22 passed\n");
    test_23(); printf("test_23 passed\n");
    test_24(); printf("test_24 passed\n");
    test_25(); printf("test_25 passed\n");
    test_26(); printf("test_26 passed\n");
    test_27(); printf("test_27 passed\n");
    test_28(); printf("test_28 passed\n");
    test_29(); printf("test_29 passed\n");
    test_30(); printf("test_30 passed\n");
    test_31(); printf("test_31 passed\n");
    test_32(); printf("test_32 passed\n");
    test_33(); printf("test_33 passed\n");
    test_34(); printf("test_34 passed\n");
    test_35(); printf("test_35 passed\n");
    test_36(); printf("test_36 passed\n");
    test_37(); printf("test_37 passed\n");
    test_38(); printf("test_38 passed\n");
    test_39(); printf("test_39 passed\n");
    test_40(); printf("test_40 passed\n");
    test_41(); printf("test_41 passed\n");
    test_42(); printf("test_42 passed\n");
    test_43(); printf("test_43 passed\n");
    test_44(); printf("test_44 passed\n");
    test_45(); printf("test_45 passed\n");
    test_46(); printf("test_46 passed\n");
    test_47(); printf("test_47 passed\n");
    test_48(); printf("test_48 passed\n");
    test_49(); printf("test_49 passed\n");
    test_50(); printf("test_50 passed\n");
    test_51(); printf("test_51 passed\n");
    test_52(); printf("test_52 passed\n");
    test_53(); printf("test_53 passed\n");
    test_54(); printf("test_54 passed\n");
    test_55(); printf("test_55 passed\n");
    test_56(); printf("test_56 passed\n");
    test_57(); printf("test_57 passed\n");
    test_58(); printf("test_58 passed\n");
    test_59(); printf("test_59 passed\n");
    test_60(); printf("test_60 passed\n");
    test_61(); printf("test_61 passed\n");
    test_62(); printf("test_62 passed\n");
    test_63(); printf("test_63 passed\n");
    test_64(); printf("test_64 passed\n");
    test_65(); printf("test_65 passed\n");
    test_66(); printf("test_66 passed\n");
    test_67(); printf("test_67 passed\n");
    test_68(); printf("test_68 passed\n");
    test_69(); printf("test_69 passed\n");
    test_70(); printf("test_70 passed\n");
    test_71(); printf("test_71 passed\n");
    test_72(); printf("test_72 passed\n");
    test_73(); printf("test_73 passed\n");
    test_74(); printf("test_74 passed\n");
    test_75(); printf("test_75 passed\n");
    test_76(); printf("test_76 passed\n");
    test_77(); printf("test_77 passed\n");
    test_78(); printf("test_78 passed\n");
    test_79(); printf("test_79 passed\n");
    test_80(); printf("test_80 passed\n");
    test_81(); printf("test_81 passed\n");
    test_82(); printf("test_82 passed\n");
    test_83(); printf("test_83 passed\n");
    test_84(); printf("test_84 passed\n");
    test_85(); printf("test_85 passed\n");
    test_86(); printf("test_86 passed\n");
    test_87(); printf("test_87 passed\n");
    test_88(); printf("test_88 passed\n");
    test_89(); printf("test_89 passed\n");
    test_90(); printf("test_90 passed\n");
    test_91(); printf("test_91 passed\n");
    test_92(); printf("test_92 passed\n");
    test_93(); printf("test_93 passed\n");
    test_94(); printf("test_94 passed\n");
    test_95(); printf("test_95 passed\n");
    test_96(); printf("test_96 passed\n");
    test_97(); printf("test_97 passed\n");
    test_98(); printf("test_98 passed\n");
    test_99(); printf("test_99 passed\n");
    test_100(); printf("test_100 passed\n");
    test_101(); printf("test_101 passed\n");
    test_102(); printf("test_102 passed\n");
    test_103(); printf("test_103 passed\n");
    test_104(); printf("test_104 passed\n");
    test_105(); printf("test_105 passed\n");
    test_106(); printf("test_106 passed\n");
    test_107(); printf("test_107 passed\n");
    test_108(); printf("test_108 passed\n");
    test_109(); printf("test_109 passed\n");
    test_110(); printf("test_110 passed\n");
    test_111(); printf("test_111 passed\n");
    test_112(); printf("test_112 passed\n");
    test_113(); printf("test_113 passed\n");
    test_114(); printf("test_114 passed\n");
    test_115(); printf("test_115 passed\n");
    test_116(); printf("test_116 passed\n");
    test_117(); printf("test_117 passed\n");
    test_118(); printf("test_118 passed\n");
    test_119(); printf("test_119 passed\n");
    test_120(); printf("test_120 passed\n");
    test_121(); printf("test_121 passed\n");
    test_122(); printf("test_122 passed\n");
    test_123(); printf("test_123 passed\n");
    printf("All 123 tests passed.\n");
    return 0;
}
