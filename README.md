# TVS_2026
Repository to develop the TVS project :)

# 📌 Exercise 2 – Fuzzing with AFL++

This exercise focuses on testing a C implementation of a **TreeTable (Red-Black Tree)** using fuzzing techniques with AFL++.

### 🔍 Objectives

The goal is to automatically detect:
- **Memory-safety bugs** (e.g., crashes, invalid memory access)
- **Logical bugs** that violate structural properties of the tree

This is achieved by combining:
- **Coverage-guided fuzzing (AFL++)**
- **Custom invariant oracles**

### 🧠 Oracles (Correctness Checks)

Two invariant-checking functions were implemented inside `treetable.c`:

#### 1. `balanced(TreeTable* t)`
Checks whether the tree is **height-balanced**
#### 2. `sorted(TreeTable* t)`
Checks whether the tree satisfies the **Binary Search Tree property**

These functions act as **runtime assertions** during fuzzing: `assert(balanced(t) && sorted(t));`

To run the program:

- `sudo apt install afl++`
- `AFL_USE_ASAN=1 afl-clang-fast -g -O1 ex2/Ex2Harness/harness.c TreeTable/treetable.c -I TreeTable/ -o harness_fuzz` (this to compile)
- `afl-fuzz -i seeds -o ex2/Ex2Harness/outputs -m none -- ./harness_fuzz` (this to run)

- `afl-cmin -i ex2/Ex2Harness/outputs/queue -o minimized_corpus -m none -- ./harness_fuzz` (this for 2.4)

To replay a crash:
- `ls ex2/Ex2Harness/outputs/crashes/` Then choose one like: `ex2/Ex2Harness/outputs/crashes/id:000000,sig:11,src:000000,time:4,op:flip1,pos:0`
- `./ex2/Ex2Harness/decode_crash.sh` + crash file

If you get this problem:
-  Hmm, your system is configured to send core dump notifications to an
    external utility. This will cause issues -- FIX: `echo core | sudo tee /proc/sys/kernel/core_pattern`