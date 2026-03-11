# Rapport Valgrind — Secure Input Memory Lab

## Auteur
Yous77130 — Holberton School — Mars 2026

## Outils utilisés
- Valgrind Memcheck 3.22.0
- gcc -std=gnu89 -Wall -Wextra -Werror -pedantic -g

## Tests effectués
- Test 1 : entrée normale (Yous77130)
- Test 2 : entrée limite (40 caractères AAAA...)

## Bug 1 — Use-after-free
- Fichier : main.c ligne 31 / session.c ligne 33
- session_destroy() libère username, puis main() le relit pour printf Goodbye
- Correction : supprimer free(session->user) dans session_destroy()

## Bug 2 — Double free
- Fichier : main.c ligne 33 / session.c ligne 33
- username est libéré deux fois
- Correction : un seul free(username) dans main() après le printf

## Bug 3 — Buffer overflow potentiel
- Fichier : user_input.c ligne 9
- scanf("%s") sans limite de taille
- Correction : scanf("%31s", buffer)

## Résumé Valgrind
ERROR SUMMARY: 13 errors from 5 contexts
All heap blocks were freed -- no leaks are possible
