# Valgrind Analysis

## 1. heap_example.c

### Valgrind Output
```
HEAP SUMMARY:
  in use at exit: 0 bytes in 0 blocks
  total heap usage: 2 allocs, 2 frees, 1,028 bytes allocated
ERROR SUMMARY: 0 errors from 0 contexts
```

### Analysis
**Resultat : PROPRE - 0 erreurs**

- malloc() alloue 4 bytes pour un int
- *ptr = 42 ecrit correctement dans la zone allouee
- free(ptr) libere correctement la memoire
- La memoire est entierement liberee a la sortie

**Conclusion :** Gestion memoire correcte. Pas de fuite, pas d'acces invalide.

---

## 2. aliasing_example.c

### Valgrind Output
```
HEAP SUMMARY:
  in use at exit: 0 bytes in 0 blocks
  total heap usage: 2 allocs, 2 frees, 1,028 bytes allocated
ERROR SUMMARY: 0 errors from 0 contexts
```

### Analysis
**Resultat : PROPRE - 0 erreurs**

- malloc() alloue 4 bytes, pointe par 'a'
- b = a : les deux pointeurs partagent la meme adresse heap
- *b = 20 : modifie la valeur via l'alias b
- free(a) libere la memoire une seule fois

**Point important sur l'aliasing :**
Meme si a et b pointent vers la meme zone, free() n'est appele qu'une fois.
Si on avait fait free(a) ET free(b), Valgrind aurait detecte un double-free.

### AI Error Example
L'IA a suggere que free(b) etait necessaire apres free(a).
C'est FAUX et DANGEREUX.
Puisque b = a (meme adresse), free(b) apres free(a) = double-free.
Un double-free est un comportement indefini qui peut corrompre la memoire.

---

## 3. crash_example.c

### Valgrind Output
```
Invalid read of size 4
   at 0x109161: main (crash_example.c:13)
 Address 0x0 is not stack'd, malloc'd or (recently) free'd

Process terminating with signal 11 (SIGSEGV)
ERROR SUMMARY: 1 errors from 1 contexts
```

### Analysis
**Resultat : CRASH - Segmentation Fault**

**Type d'erreur :** Invalid read (lecture invalide)

**Cause precise :**
```c
int *ptr;
ptr = NULL;          /* ptr pointe vers l'adresse 0x0 */
printf("%d", *ptr);  /* CRASH : lecture a l'adresse 0x0 */
```

**Chaine causale complete :**
1. ptr est initialise a NULL (adresse 0x0)
2. 0x0 n'est pas une zone memoire valide (ni stack, ni heap)
3. *ptr tente de lire 4 bytes a l'adresse 0x0
4. Le systeme d'exploitation detecte l'acces illegal
5. Signal SIGSEGV envoye → Segmentation fault

**Terminologie correcte :**
- Type : NULL pointer dereference
- Valgrind : "Invalid read of size 4"
- OS : SIGSEGV (signal 11)

**Lifetime violation :**
ptr n'a jamais pointe vers une zone memoire valide.
Il n'existe aucune allocation a dereferencer.

---

## Summary Table

| Programme | Erreurs | Type | Description |
|-----------|---------|------|-------------|
| heap_example | 0 | - | Gestion memoire correcte |
| aliasing_example | 0 | - | Aliasing correct, free unique |
| crash_example | 1 | Invalid read | NULL pointer dereference |

## Key Terminology

| Terme | Definition |
|-------|-----------|
| Invalid read | Lecture d'une zone memoire non allouee |
| Memory leak | Memoire allouee mais jamais liberee |
| Double-free | free() appele deux fois sur la meme adresse |
| Use-after-free | Acces a une zone apres free() |
| NULL dereference | Dereferencement d'un pointeur NULL |
| SIGSEGV | Signal systeme = acces memoire illegal |
