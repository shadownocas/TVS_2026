/*
 * Symbolic test: test_validity_multi_add.c
 *
 * Property: Validity preservation after multiple insertions.
 */

#include <klee/klee.h>
#include <assert.h>
#include <limits.h>
#include "treetable.h"

int main(void)
{
    int a1, a2, a3, a4, a5;
    klee_make_symbolic(&a1, sizeof(a1), "a1");
    klee_make_symbolic(&a2, sizeof(a2), "a2");
    klee_make_symbolic(&a3, sizeof(a3), "a3");
    klee_make_symbolic(&a4, sizeof(a4), "a4");
    klee_make_symbolic(&a5, sizeof(a5), "a5");

    klee_assume(a1 > INT_MIN);
    klee_assume(a1 < INT_MAX);
    klee_assume(a2 > INT_MIN);
    klee_assume(a2 < INT_MAX);
    klee_assume(a3 > INT_MIN);
    klee_assume(a3 < INT_MAX);
    klee_assume(a4 > INT_MIN);
    klee_assume(a4 < INT_MAX);
    klee_assume(a5 > INT_MIN);
    klee_assume(a5 < INT_MAX);
    klee_assume(a1 < a2);
    klee_assume(a2 < a3);
    klee_assume(a3 < a4);
    klee_assume(a4 < a5);

    int va=1, vdup_a=99;

    TreeTable *ta;
    treetable_new(&ta);

    treetable_add(ta, &a1, &va); assert(balanced(ta) && sorted(ta));
    treetable_add(ta, &a2, &va); assert(balanced(ta) && sorted(ta));
    treetable_add(ta, &a3, &va); assert(balanced(ta) && sorted(ta));
    treetable_add(ta, &a4, &va); assert(balanced(ta) && sorted(ta));
    treetable_add(ta, &a5, &va); assert(balanced(ta) && sorted(ta));

    treetable_add(ta, &a3, &vdup_a);
    assert(balanced(ta) && sorted(ta));

    int b1, b2, b3, b4, b5;
    klee_make_symbolic(&b1, sizeof(b1), "b1");
    klee_make_symbolic(&b2, sizeof(b2), "b2");
    klee_make_symbolic(&b3, sizeof(b3), "b3");
    klee_make_symbolic(&b4, sizeof(b4), "b4");
    klee_make_symbolic(&b5, sizeof(b5), "b5");

    klee_assume(b1 > INT_MIN);
    klee_assume(b1 < INT_MAX);
    klee_assume(b2 > INT_MIN);
    klee_assume(b2 < INT_MAX);
    klee_assume(b3 > INT_MIN);
    klee_assume(b3 < INT_MAX);
    klee_assume(b4 > INT_MIN);
    klee_assume(b4 < INT_MAX);
    klee_assume(b5 > INT_MIN);
    klee_assume(b5 < INT_MAX);
    klee_assume(b1 < b2);
    klee_assume(b2 < b3);
    klee_assume(b3 < b4);
    klee_assume(b4 < b5);

    int vb=2, vdup_b=88;

    TreeTable *tb;
    treetable_new(&tb);

    treetable_add(tb, &b5, &vb); assert(balanced(tb) && sorted(tb));
    treetable_add(tb, &b4, &vb); assert(balanced(tb) && sorted(tb));
    treetable_add(tb, &b3, &vb); assert(balanced(tb) && sorted(tb));
    treetable_add(tb, &b2, &vb); assert(balanced(tb) && sorted(tb));
    treetable_add(tb, &b1, &vb); assert(balanced(tb) && sorted(tb));

    treetable_add(tb, &b3, &vdup_b);
    assert(balanced(tb) && sorted(tb));

    return 0;
}
