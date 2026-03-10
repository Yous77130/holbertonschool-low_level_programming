## 2. Environnement de test
- **Compilation :** `gcc -g -o vulnerable_app main.c session.c user_input.c`
- **Outil :** Valgrind 3.22.0
- **Entrée normale :** "test"
- **Entrée limite :** "12345678901234567890"

## 3. Analyse des résultats (Données Valgrind)

### Faille #1 : Heap Buffer Overflow
- **Localisation :** `user_input.c`, fonction `read_username`
- **Preuve (Stack Trace) :** [Insère ici les 4-5 lignes du stack trace que Valgrind t'a données tout à l'heure]
- **Diagnostic :** Le programme alloue un espace fixe via `malloc`. L'utilisation d'une fonction de lecture non bornée entraîne un écrasement de la mémoire adjacente sur le tas.
- **Conformité CERT :** MEM35-C (Violation).

## 4. Comparaison
- **Baseline (Entrée courte) :** Le programme s'exécute sans erreur critique.
- **Limite (Entrée longue) :** 42 erreurs signalées. Cela prouve une dépendance directe entre la longueur de l'entrée et l'intégrité mémoire.

## 5. Conclusion
Le programme souffre d'un défaut de conception critique dans la gestion des entrées utilisateur. La correction nécessite une validation stricte de la longueur de chaîne avant tout `memcpy` ou `strcpy`.
