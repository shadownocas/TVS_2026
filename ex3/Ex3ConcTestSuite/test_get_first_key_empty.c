/*
 * Concrete test suite derived from: test_get_first_key_empty.c
 * Property: get_first_key on empty table must return CC_ERR_KEY_NOT_FOUND.
 *
 * BUG-002 DEMONSTRATED: KLEE reports null page access at treetable.c:396
 * inside tree_min. treetable_get_first_key calls tree_min(table, table->root)
 * unconditionally. On an empty table, table->root == table->sentinel, and
 * sentinel->left is zero-initialised (NULL), so tree_min dereferences a null
 * pointer before it can return the sentinel, causing a crash instead of the
 * expected CC_ERR_KEY_NOT_FOUND.
 *
 * Generated from KLEE ktest files:
 *   test000001.ktest : (no symbolic objects — empty table, no inputs needed)
 *
 * NOTE: Running this test will CRASH due to BUG-002.
 *       It is kept here to document the bug-triggering input.
 */

#include <assert.h>
#include "treetable.h"

int main(void)
{
    TreeTable *t;
    treetable_new(&t);

    void *out = NULL;

    /* BUG-002: crashes inside tree_min — sentinel->left is NULL */
    assert(treetable_get_first_key(t, &out) == CC_ERR_KEY_NOT_FOUND);


    return 0;
}