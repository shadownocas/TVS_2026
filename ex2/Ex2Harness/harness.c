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
 *   Any unrecognised opcode or insufficient remaining bytes stops parsing.
 *
 * COMPILATION (with AFL++):
 *   afl-clang-fast -o ex2/Ex2Harness/harness ex2/Ex2Harness/harness.c TreeTable/treetable.c -I TreeTable/
 *
 * COMPILATION (normal gcc, for local testing):
 *   gcc -o ex2/Ex2Harness/harness ex2/Ex2Harness/harness.c TreeTable/treetable.c -I TreeTable/
 *
 * RUNNING:
 *  mkdir -p ex2/Ex2Harness/seeds
 *  printf '\x00\x01\x00\x00\x00\x02\x00\x00\x00\x01\x01\x00\x00\x00' > ex2/Ex2Harness/seeds/s1
 *  afl-fuzz -i ex2/Ex2Harness/seeds -o ex2/Ex2Harness/findings -- ex2/Ex2Harness/harness
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "treetable.h"

/* ------------------------------------------------------------------
 * __AFL_LOOP is provided by afl-clang-fast at compile time.
 * When compiled with normal gcc it is not defined, so we define it
 * here as a one-shot loop so the harness still builds and runs.
 * ------------------------------------------------------------------ */
#ifndef __AFL_LOOP
#define __AFL_LOOP(x) (({ static int __c = 0; __c++ == 0; }))
#endif

#ifndef __AFL_INIT
#define __AFL_INIT() do {} while(0)
#endif

/* ------------------------------------------------------------------
 * Safe read helpers — advance cursor, return 0 on underflow
 * ------------------------------------------------------------------ */
static int read_byte(const unsigned char *buf, size_t len,
                     size_t *cur, unsigned char *out) {
    if (*cur >= len) return 0;
    *out = buf[(*cur)++];
    return 1;
}

static int read_int(const unsigned char *buf, size_t len,
                    size_t *cur, int *out) {
    if (*cur + 4 > len) return 0;
    memcpy(out, buf + *cur, 4);
    *cur += 4;
    return 1;
}

/* ================================================================== */
int main(void) {

    __AFL_INIT();

    static unsigned char buf[4096]; // No risk of stack overflow since it doesnt live in stack

    while (__AFL_LOOP(1000)) {

        /* --- 1. Read input from stdin ---------------------------- */
        size_t len = fread(buf, 1, sizeof(buf), stdin);
        if (len == 0)
            continue;

        /* --- 2. Create a fresh TreeTable ------------------------- */
        TreeTable *t = NULL;
        if (treetable_new(&t) != CC_OK || t == NULL)
            continue;

        /* --- 3. Parse and dispatch commands ---------------------- */
        size_t cur = 0;

        while (cur < len) {

            unsigned char opcode;
            if (!read_byte(buf, len, &cur, &opcode))
                break;

            int raw_key, raw_val;
            void *out = NULL;

            switch (opcode) {

            /* ---- treetable_add ---------------------------------- */
            case 0x00:
                if (!read_int(buf, len, &cur, &raw_key)) goto done;
                if (!read_int(buf, len, &cur, &raw_val)) goto done;
                {
                    int *k = malloc(sizeof(int));
                    int *v = malloc(sizeof(int));
                    if (!k || !v) { free(k); free(v); goto done; }

                    *k = raw_key;
                    *v = raw_val;

                    treetable_add(t, k, v);

                    /* Oracle: assert invariants after every modification */
                    assert(balanced(t) && sorted(t));
                }
                break;

            /* ---- treetable_get ---------------------------------- */
            case 0x01:
                if (!read_int(buf, len, &cur, &raw_key)) goto done;
                treetable_get(t, &raw_key, &out);
                break;

            /* ---- treetable_get_first_key ------------------------ */
            case 0x02:
                treetable_get_first_key(t, &out);
                break;

            /* ---- treetable_get_greater_than --------------------- */
            case 0x03:
                if (!read_int(buf, len, &cur, &raw_key)) goto done;
                treetable_get_greater_than(t, &raw_key, &out);
                break;

            default:
                goto done;
            }
        }

    done:
        /* --- 4. Destroy table — also frees all keys and values --- */
        treetable_destroy(t);
    }

    return 0;
}