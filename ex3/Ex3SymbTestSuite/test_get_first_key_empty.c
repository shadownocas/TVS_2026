/*
 * Symbolic test: test_get_first_key_empty.c
 *
 * Property: get_first_key on empty table returns CC_ERR_KEY_NOT_FOUND.
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
