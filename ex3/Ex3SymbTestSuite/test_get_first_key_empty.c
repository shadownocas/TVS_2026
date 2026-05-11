/*
 * Property: get_first_key on empty table returns CC_ERR_KEY_NOT_FOUND.
 *
 * BUG-002 DETECTED: KLEE reports null page access at treetable.c:396
 * (inside tree_min). treetable_get_first_key calls tree_min on the root
 * without checking if the table is empty first. On an empty table,
 * root == sentinel and tree_min walks sentinel->left causing a null
 * page access. See Ex3BugReport.txt for full analysis.
 */

#include <klee/klee.h>
#include <assert.h>
#include "treetable.h"

int main(void)
{
    TreeTable *t;
    treetable_new(&t);
    void *out = NULL;
    assert(treetable_get_first_key(t, &out) == CC_ERR_KEY_NOT_FOUND);
    return 0;
}
