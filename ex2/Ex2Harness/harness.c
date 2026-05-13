/*
 * harness.c — AFL++ Fuzzing Harness for TreeTable
 *
 * INPUT FORMAT (binary, read from stdin):
 *
 *   A flat sequence of commands. Each command begins with a 1-byte opcode,
 *   followed by command-specific payload:
 *
 *   [0x00] treetable_add(t, key, val)
 *     Payload: 4 bytes (int key) + 4 bytes (int value) = 8 bytes
 *     Total:   9 bytes
 *     Oracle:  assert(balanced(t) && sorted(t)) after call
 *
 *   [0x01] treetable_get(t, key, &out)
 *     Payload: 4 bytes (int key)
 *     Total:   5 bytes
 *     Oracle:  none (read-only)
 *
 *   [0x02] treetable_get_first_key(t, &out)
 *     Payload: none
 *     Total:   1 byte
 *     Oracle:  none (read-only)
 *
 *   [0x03] treetable_get_greater_than(t, key, &out)
 *     Payload: 4 bytes (int key)
 *     Total:   5 bytes
 *     Oracle:  none (read-only)
 *
 * MEMORY MODEL
 * ============
 * Keys and values for treetable_add are heap-allocated. Every pointer is
 * tracked in a local allocs[] array. treetable_destroy frees all k/v pairs
 * that were successfully inserted. The remaining loop at done: frees any
 * that were allocated but never handed to the table (e.g. on failed add or
 * early goto done). Read-only operations use stack variables — the tree
 * never stores those pointers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include "treetable.h"

#ifndef __AFL_LOOP
#define __AFL_LOOP(x) (({ static int __c = 0; __c++ == 0; }))
#endif

#ifndef __AFL_INIT
#define __AFL_INIT() \
    do               \
    {                \
    } while (0)
#endif

#define MAX_INPUT 4096

static uint8_t input_buf[MAX_INPUT];
static size_t input_len;
static size_t input_pos;

static int read_bytes(void *dst, size_t n)
{
    if (input_pos + n > input_len)
        return 0;
    memcpy(dst, input_buf + input_pos, n);
    input_pos += n;
    return 1;
}

int main(void)
{
    __AFL_INIT();

    while (__AFL_LOOP(1000))
    {

        input_len = fread(input_buf, 1, MAX_INPUT, stdin);
        input_pos = 0;

        TreeTable *t = NULL;
        if (treetable_new(&t) != CC_OK || t == NULL)
            continue;

        void *allocs[512];
        int nallocs = 0;

        uint8_t op;

        while (read_bytes(&op, 1))
        {

            switch (op)
            {

            case 0x00:
            {
                int *k = malloc(sizeof(int));
                int *v = malloc(sizeof(int));
                if (!k || !v)
                {
                    free(k);
                    free(v);
                    goto done;
                }

                allocs[nallocs++] = k;
                allocs[nallocs++] = v;

                if (!read_bytes(k, sizeof(int)))
                    goto done;
                if (!read_bytes(v, sizeof(int)))
                    goto done;

                if (treetable_add(t, k, v) == CC_OK)
                {
                    nallocs -= 2;

                    assert(balanced(t) && sorted(t));
                }
                break;
            }

            case 0x01:
            {
                int key;
                if (!read_bytes(&key, sizeof(int)))
                    goto done;

                void *out = NULL;
                treetable_get(t, &key, &out);
                break;
            }

            case 0x02:
            {
                void *out = NULL;
                treetable_get_first_key(t, &out);
                break;
            }

            case 0x03:
            {
                int key;
                if (!read_bytes(&key, sizeof(int)))
                    goto done;

                void *out = NULL;
                treetable_get_greater_than(t, &key, &out);
                break;
            }

            default:
                break;
            }
        }

    done:
        treetable_destroy(t);

        for (int i = 0; i < nallocs; i++)
            free(allocs[i]);
    }

    return 0;
}