# Task 3 — Dangling Pointers & Memory Lifetime Analysis

## Author
Yous77130 — Holberton School — Mars 2026

## 1. Dynamic allocations identified

### Allocation 1 — username
- Function : read_username() in user_input.c line 13
- malloc(strlen(buffer) + 1)
- Returned to : main() via username pointer

### Allocation 2 — session
- Function : session_create() in session.c line 8
- malloc(sizeof(session_t))
- Returned to : main() via session pointer

## 2. Pointer propagation

username (main) → passed to session_create()
               → stored as session->user
               → session->user and username point to SAME memory block

## 3. Ownership analysis

### Who owns username?
- read_username() allocates it → ownership transferred to main()
- main() passes it to session_create() → session->user points to it
- session_destroy() calls free(session->user) → assumes ownership
- main() calls free(username) → also assumes ownership
- RESULT: ownership is implicit and ambiguous → double free

### Who owns session?
- session_create() allocates it → ownership transferred to main()
- session_destroy() frees it → correct, single owner ✅

## 4. Bugs identified

### Bug 1 — Double free (MEM31-C)
session_destroy() frees session->user (session.c:33)
main() frees username (main.c:33)
Same memory block freed twice → undefined behavior

### Bug 2 — Use-after-free (MEM30-C)
session_destroy() frees username at main.c:29
printf("Goodbye %s", username) reads freed memory at main.c:31
Pointer is dangling — memory no longer valid

### Bug 3 — Implicit ownership transfer (MEM34-C)
session_create() receives username but does not document
whether it takes ownership or borrows the pointer
session_destroy() assumes ownership without explicit contract

## 5. Lifetime analysis

username lifetime should be : from read_username() to after printf Goodbye
username actual lifetime is  : freed too early inside session_destroy()
Result : dangling pointer between line 29 and 33 in main.c

## 6. Ownership fix plan (not implemented yet)
- session_destroy() must NOT free session->user
- Only main() frees username, after the last use
- Ownership rule : allocator is the sole owner and freer

## 7. CERT references
- MEM30-C : use-after-free in main.c line 31
- MEM31-C : double free of username
- MEM34-C : session_destroy() frees memory it does not own
