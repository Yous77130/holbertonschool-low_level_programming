# Rapport Audit - Task 1

## Détection Valgrind
- **Erreur :** Invalid write (Heap Buffer Overflow)
- **Fichier :** user_input.c:13 (read_username)
- **Stats :** 42 erreurs détectées avec une entrée longue.

## Règles CERT Violées
- **MEM35-C :** Allocation de mémoire insuffisante.
- **EXP33-C :** Lecture de mémoire non initialisée suite à la corruption.

## Analyse
L'erreur est "input-dependent". Le programme échoue uniquement quand l'entrée utilisateur dépasse la taille du buffer alloué dynamiquement, corrompant les structures adjacentes du tas (heap).
