# Audit de Sécurité - Task 1: Analyse Mémoire

## Évidence de l'erreur (Valgrind)
Lors de l'exécution avec une entrée longue (Boundary Input), Valgrind détecte l'erreur suivante :
- **Type :** Invalid Write / Heap Buffer Overflow
- **Localisation :** user_input.c:13 (fonction read_username)
- **Résumé :** 42 erreurs provenant de 5 contextes.

## Classification CERT
Cette faille correspond à la règle **MEM35-C** : "Allocate sufficient memory for an object". Le programme alloue un buffer trop petit pour la saisie utilisateur sans vérifier la taille de l'entrée.

## Observation
Le bug est dépendant de l'entrée (input-dependent). Une entrée courte ne déclenche pas d'erreur immédiate, mais une entrée longue corrompt le tas (heap).
