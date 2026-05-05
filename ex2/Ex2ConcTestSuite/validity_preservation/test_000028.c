/*
 * test_000028.c
 *
 * Group    : validity_preservation
 * Property : VALIDITY PRESERVATION — tree remains balanced() and sorted() after every treetable_add()
 *
 * Derived from minimised corpus file: ex2/Ex2Harness/minimized_corpus/id:000028,src:000000,time:683,op:havoc,rep:2
 * Total decoded steps: 1
 *
 * Compile (from ex2/Ex2ConcTestSuite/validity_preservation/):
 *   gcc -g -fsanitize=address -o test_000028 test_000028.c  *       ../../../TreeTable/treetable.c -I ../../../TreeTable/
 * Run:
 *   ./test_000028
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

    /* step 0: treetable_add(key=-8447, val=99) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = -8447; *v = 99;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
