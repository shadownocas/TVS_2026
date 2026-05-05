/*
 * test_000032.c
 *
 * Group    : validity_preservation
 * Property : VALIDITY PRESERVATION — tree remains balanced() and sorted() after every treetable_add()
 *
 * Derived from minimised corpus file: ex2/Ex2Harness/minimized_corpus/id:000032,src:000000,time:709,op:havoc,rep:128
 * Total decoded steps: 1
 *
 * Compile (from ex2/Ex2ConcTestSuite/validity_preservation/):
 *   gcc -g -fsanitize=address -o test_000032 test_000032.c  *       ../../../TreeTable/treetable.c -I ../../../TreeTable/
 * Run:
 *   ./test_000032
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

    /* step 0: treetable_add(key=0, val=-167771960) */
    {
        int *k = malloc(sizeof(int));
        int *v = malloc(sizeof(int));
        *k = 0; *v = -167771960;
        treetable_add(t, k, v);
        assert(balanced(t) && sorted(t));
    }

    treetable_destroy(t);
    printf("PASS\n");
    return 0;
}
