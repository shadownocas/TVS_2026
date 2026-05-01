/*
 * harness.c — AFL++ Fuzzing Harness for TreeTable
 *
 * INPUT FORMAT (text, one command per line via stdin):
 *
 *   add <key> <value>        — calls treetable_add(t, key, val)
 *   get <key>                — calls treetable_get(t, key, &out)
 *   first                    — calls treetable_get_first_key(t, &out)
 *   greater <key>            — calls treetable_get_greater_than(t, key, &out)
 *
 *   Keys and values are integers.
 *   Lines starting with '#' are ignored (comments).
 *   Any unrecognised command stops parsing.
 *
 * EXAMPLE INPUT:
 *   add 5 100
 *   add 3 200
 *   add 8 300
 *   get 3
 *   first
 *   greater 5
 *
 * COMPILATION (with AFL++):
 *   afl-clang-fast -o ex2/Ex2Harness/harness ex2/Ex2Harness/harness.c TreeTable/treetable.c -I TreeTable/
 *
 * COMPILATION (normal gcc, for local testing):
 *   gcc -g -o ex2/Ex2Harness/harness_debug ex2/Ex2Harness/harness.c TreeTable/treetable.c -I TreeTable/
 *
 * RUNNING (interactive, type commands manually):
 *   ./ex2/Ex2Harness/harness
 *
 * RUNNING (from a file):
 *   ./ex2/Ex2Harness/harness < my_commands.txt
 *
 * RUNNING (with AFL++):
 *   mkdir -p ex2/Ex2Harness/seeds
 *   printf 'add 1 100\nadd 2 200\nget 1\nfirst\ngreater 1\n' > ex2/Ex2Harness/seeds/s1
 *   afl-fuzz -i ex2/Ex2Harness/seeds -o ex2/Ex2Harness/findings -- ex2/Ex2Harness/harness
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

/* ================================================================== */
int main(void) {

    __AFL_INIT();

    static char buf[4096];

    while (__AFL_LOOP(1000)) {

        /* --- 1. Read entire stdin into buffer -------------------- */
        size_t len = fread(buf, 1, sizeof(buf) - 1, stdin);
        if (len == 0)
            continue;
        buf[len] = '\0';

        /* --- 2. Create a fresh TreeTable ------------------------- */
        TreeTable *t = NULL;
        if (treetable_new(&t) != CC_OK || t == NULL)
            continue;

        /* --- 3. Parse line by line ------------------------------- */
        char *line = buf;

        while (line && *line != '\0') {

            /* find end of line */
            char *newline = strchr(line, '\n');
            if (newline)
                *newline = '\0';

            /* skip comment lines and empty lines */
            if (*line == '#' || *line == '\0') {
                line = newline ? newline + 1 : NULL;
                continue;
            }

            char cmd[16] = {0};
            int  key, val;
            void *out = NULL;

            /* parse command word */
            if (sscanf(line, "%15s", cmd) != 1)
                goto done;

            /* ---- add <key> <val> -------------------------------- */
            if (strcmp(cmd, "add") == 0) {
                if (sscanf(line, "%*s %d %d", &key, &val) != 2)
                    goto done;

                int *k = malloc(sizeof(int));
                int *v = malloc(sizeof(int));
                if (!k || !v) { free(k); free(v); goto done; }

                *k = key;
                *v = val;

                treetable_add(t, k, v);

                /* Oracle: assert invariants after every modification */
                assert(balanced(t) && sorted(t));

            /* ---- get <key> ------------------------------------- */
            } else if (strcmp(cmd, "get") == 0) {
                if (sscanf(line, "%*s %d", &key) != 1)
                    goto done;
                treetable_get(t, &key, &out);

            /* ---- first ----------------------------------------- */
            } else if (strcmp(cmd, "first") == 0) {
                treetable_get_first_key(t, &out);

            /* ---- greater <key> --------------------------------- */
            } else if (strcmp(cmd, "greater") == 0) {
                if (sscanf(line, "%*s %d", &key) != 1)
                    goto done;
                treetable_get_greater_than(t, &key, &out);

            } else {
                /* unrecognised command — stop parsing */
                goto done;
            }

            line = newline ? newline + 1 : NULL;
        }

    done:
        /* --- 4. Destroy table — also frees all keys and values --- */
        treetable_destroy(t);
    }

    return 0;
}