## Evidence extracted

### Valgrind snippet
==431910== Invalid read of size 1
==431910==    at 0x484F226: strlen (vgpreload_memcheck)
==431910==    by 0x1092EA: main (main.c:31)
==431910==  Address 0x4a778c0 is 0 bytes inside a block of size 10 free'd
==431910==    at 0x484988F: free (vgpreload_memcheck)
==431910==    by 0x1093CA: session_destroy (session.c:33)
==431910==    by 0x1092CF: main (main.c:29)

### Source
session_destroy() frees session->user at session.c:33
main() reads username at main.c:31 via printf

### Trigger
Any input — reproducible with normal input "Yous77130"
