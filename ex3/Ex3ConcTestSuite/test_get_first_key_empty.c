/*
 * Concrete test suite derived from: test_get_first_key_empty.c
 * Property: Correctness of minimum-key retrieval on empty table.
 *
 * Calling get_first_key on an empty table must return
 * CC_ERR_KEY_NOT_FOUND.
 *
 * NOTE: Running this test will CRASH due to BUG-002 (crashes inside tree_min — sentinel->left is NULL).
 *       It is kept here to document the bug-triggering input.
 */

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