# Task 4 — Patching and Hardening

## Author
Yous77130 — Holberton School — Mars 2026

## Patches applied

### Patch 1 — user_input.c : bounded input
Before : scanf("%s", buffer);
After  : scanf("%31s", buffer);
Reason : limits input to 31 chars + null terminator = 32 bytes max

### Patch 2 — session.c : ownership fix
Before : free(session->user); free(session);
After  : free(session);
Reason : main() is the allocator of username, only main() frees it

### Patch 3 — main.c : use-after-free fix
printf Goodbye moved before session_destroy()
free(username) kept as single free after last use

## Valgrind results after patching

### Test 1 — normal input (Yous77130)
ERROR SUMMARY: 0 errors from 0 contexts
4 allocs, 4 frees — balanced

### Test 2 — boundary input (60 x A)
ERROR SUMMARY: 0 errors from 0 contexts
Input truncated to 31 chars — overflow prevented
4 allocs, 4 frees — balanced

## Conclusion
All 3 bugs eliminated :
- Stack overflow : fixed by scanf("%31s")
- Double free    : fixed by removing free(session->user)
- Use-after-free : fixed by reordering printf before session_destroy
