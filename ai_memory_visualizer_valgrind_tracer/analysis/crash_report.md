# Crash Report — crash_example.c

## 1. Program Description
```c
int main(void)
{
    int *ptr;

    ptr = NULL;
    printf("Value: %d\n", *ptr);
    return (0);
}
```

## 2. Crash Confirmation
```
Signal: SIGSEGV (signal 11)
Valgrind: Invalid read of size 4
Address: 0x0 is not stack'd, malloc'd or (recently) free'd
Line: crash_example.c:13
```

---

## 3. Root Cause Analysis

### Type de memoire impliquee
Ni stack, ni heap.
ptr contient l'adresse 0x0 (NULL) qui est une zone memoire
intentionnellement invalide et non mappee par le systeme d'exploitation.

### Chaine causale complete

**Etape 1 — Declaration du pointeur**
```
STACK
+------------------+
| main frame       |
|  ptr = ???       |  <- valeur non initialisee
+------------------+
```

**Etape 2 — ptr = NULL**
```
STACK
+------------------+
| main frame       |
|  ptr = 0x0      |  <- pointe vers adresse invalide
+------------------+
```

**Etape 3 — *ptr (dereferencement)**
```
Le programme tente de lire 4 bytes a l'adresse 0x0
0x0 n'est pas mappee en memoire
Le systeme d'exploitation envoie SIGSEGV
Le programme est termine immediatement
```

### Pourquoi 0x0 est invalide ?
- L'adresse 0x0 est reservee par le systeme d'exploitation
- Aucun processus ne peut lire ou ecrire a cette adresse
- C'est une protection intentionnelle pour detecter les NULL dereferences
- Toute tentative d'acces declenche SIGSEGV

### Categorie de comportement indefini
**NULL pointer dereference**
Defini dans le standard C comme comportement indefini.
Le resultat peut etre : crash, valeur incorrecte, ou comportement aleatoire.
Dans ce cas : crash deterministe car 0x0 n'est jamais mappee.

---

## 4. AI Evaluation

### Suggestion AI #1 — "Le pointeur n'est pas initialise"
**PARTIELLEMENT INCORRECT.**
Le pointeur EST initialise — a NULL.
Le probleme n'est pas l'absence d'initialisation,
mais le dereferencement d'une adresse invalide.
Un pointeur non initialise serait un bug different
(valeur aleatoire, comportement moins predictible).

### Suggestion AI #2 — "Il faut allouer de la memoire avec malloc"
**CORRECT comme solution, mais incomplet comme explication.**
La vraie cause est le dereferencement de NULL,
pas l'absence de malloc.
On pourrait aussi corriger en pointant ptr vers une variable existante :
int x = 42; ptr = &x;

### Suggestion AI #3 — "Le crash est impredictible"
**FAUX.**
Ce crash est 100% deterministe.
A chaque execution, ptr = 0x0 et *ptr = SIGSEGV.
Il n'y a aucune aleatoire dans ce comportement.

---

## 5. Suggested Fix (optionnel)

### Option A — Utiliser malloc
```c
ptr = malloc(sizeof(int));
if (ptr == NULL)
    return (1);
*ptr = 42;
printf("Value: %d\n", *ptr);
free(ptr);
```

### Option B — Pointer vers variable locale
```c
int value = 42;
ptr = &value;
printf("Value: %d\n", *ptr);
```

### Pourquoi verifier NULL apres malloc ?
malloc peut retourner NULL si la memoire est insuffisante.
Dereferencer ce NULL produirait exactement le meme crash.

---

## 6. Summary

| Element | Detail |
|---------|--------|
| Type de crash | NULL pointer dereference |
| Signal | SIGSEGV (signal 11) |
| Adresse invalide | 0x0 |
| Ligne | crash_example.c:13 |
| Memoire impliquee | Ni stack ni heap — adresse non mappee |
| Comportement | Indefini mais deterministe |
| Valgrind | Invalid read of size 4 |
