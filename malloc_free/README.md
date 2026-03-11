# 0x0a. C - malloc, free

Ce projet est une introduction à l'allocation dynamique de mémoire en langage C. 
Il couvre l'utilisation des fonctions `malloc` et `free` pour gérer la mémoire 
sur le tas (heap) au lieu de la pile (stack).

## Objectifs
- Comprendre la différence entre l'allocation automatique et dynamique.
- Utiliser `malloc` pour réserver de la mémoire pendant l'exécution.
- Utiliser `free` pour libérer la mémoire et éviter les fuites (memory leaks).
- Apprendre à utiliser `valgrind` pour valider l'intégrité de la mémoire.

## Exigences techniques
- Compilation avec `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`.
- Respect strict du style **Betty**.
- Interdiction d'utiliser des fonctions standards comme `printf`.
