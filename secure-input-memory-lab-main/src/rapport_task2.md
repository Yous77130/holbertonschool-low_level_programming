# Task 2 — Unsafe Input & Buffer Overflow Analysis

## Author
Yous77130 — Holberton School — Mars 2026

## File analyzed
user_input.c — function read_username()

## 1. Stack-allocated buffer identified
- Variable : char buffer[32]
- Location : stack (local variable)
- Exact size : 32 bytes (31 chars + 1 null terminator)

## 2. How input is read
- Function used : scanf("%s", buffer)
- No width limit specified in the format string
- scanf stops at whitespace but NOT at buffer boundary

## 3. Overflow condition (numeric)
- buffer capacity : 32 bytes
- maximum safe input : 31 characters
- overflow occurs when : input length > 31 characters
- overflow amount example : 40 chars input = 9 bytes written beyond buffer

## 4. Does heap allocation protect against overflow?
NO.
malloc(strlen(buffer) + 1) is called AFTER scanf.
The stack buffer is already corrupted before malloc executes.
strlen(buffer) will also read beyond valid memory if buffer is not null-terminated.

## 5. Missing invariants
- No maximum input length enforced before reading
- No null termination guarantee when buffer overflows
- scanf("%s") has no built-in bounds checking

## 6. Hardening plan (not implemented yet)
- Replace scanf("%s", buffer) with scanf("%31s", buffer)
- This limits input to 31 characters + automatic null terminator
- Invariant enforced : input_size <= buffer_size - 1

## 7. CERT references
- STR31-C : buffer[32] must include space for null terminator
- FIO42-C : scanf without width limit causes buffer overflow
- ARR30-C : writing beyond buffer[32] is out-of-bounds
