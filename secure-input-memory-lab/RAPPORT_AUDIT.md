# Rapport d'Audit - Task 0

## 1. Analyse du code source
- Fichier : src/user_input.c
- Fonction : read_username
- Vulnérabilité trouvée : Buffer Overflow (Dépassement de tampon).
- Raison : La fonction scanf("%s", buffer) n'impose aucune limite de taille. Le buffer ne peut contenir que 32 caractères.

## 2. Tests de validation (Baseline)
- Test 1 (Entrée "test") : Le programme fonctionne.
- Test 2 (Entrée "A" répétée 50 fois) : Le programme plante (Segmentation fault).

## 3. Conclusion
Le programme présente une faille critique de sécurité mémoire. Il doit être corrigé en limitant la saisie utilisateur.
