/*
 * Property: preservation of validity after insertions
 *
 * The tree must remain a valid, balanced BST after insertions and updates.
 * Tree invariants (balance factors, sorted order) must be maintained through
 * rebalancing operations.
 *
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
