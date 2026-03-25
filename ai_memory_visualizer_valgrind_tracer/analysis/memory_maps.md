# Memory Maps Analysis

## 1. stack_example.c

### Program behavior
Sum: 8

### Memory Map

#### Step 1 — main() is called
```
STACK
+------------------+
| main frame       |
|  x = 5          |
|  y = 3          |
|  sum = ???       |
+------------------+
```

#### Step 2 — add(5, 3) is called
```
STACK
+------------------+
| add frame        |
|  a = 5          |
|  b = 3          |
|  result = 8     |
+------------------+
| main frame       |
|  x = 5          |
|  y = 3          |
|  sum = ???       |
+------------------+
```

#### Step 3 — add() returns, frame destroyed
```
STACK
+------------------+
| main frame       |
|  x = 5          |
|  y = 3          |
|  sum = 8        |
+------------------+
```

### Variable lifetimes
- x, y, sum : vivent pendant toute l'execution de main()
- a, b, result : vivent uniquement pendant l'execution de add()
- Quand add() retourne, son frame est detruit

---

## 2. heap_example.c

### Program behavior
Value: 42

### Memory Map

#### Step 1 — malloc() called
```
STACK                    HEAP
+------------------+     +------------------+
| main frame       |     |                  |
|  ptr = 0x????  ------> | [sizeof(int)=4B] |
+------------------+     +------------------+
```

#### Step 2 — *ptr = 42
```
STACK                    HEAP
+------------------+     +------------------+
| main frame       |     |                  |
|  ptr = 0x????  ------> |      42          |
+------------------+     +------------------+
```

#### Step 3 — free(ptr)
```
STACK                    HEAP
+------------------+     +------------------+
| main frame       |     |                  |
|  ptr = 0x????  - - - > |   [freed]        |
+------------------+     +------------------+
```

### Variable lifetimes
- ptr (stack) : vit pendant toute l'execution de main()
- *ptr (heap) : vit de malloc() jusqu'a free()
- Apres free(), ptr pointe vers une zone invalide (dangling pointer)

---

## 3. aliasing_example.c

### Program behavior
a = 20
b = 20

### Memory Map

#### Step 1 — malloc() + *a = 10
```
STACK                    HEAP
+------------------+     +------------------+
| main frame       |     |                  |
|  a = 0x????    ------> |      10          |
|  b = NULL        |     +------------------+
+------------------+
```

#### Step 2 — b = a (aliasing !)
```
STACK                    HEAP
+------------------+     +------------------+
| main frame       |     |                  |
|  a = 0x????    ------> |      10          |
|  b = 0x????    ---/    +------------------+
+------------------+
```
IMPORTANT: a et b pointent vers la MEME zone memoire !

#### Step 3 — *b = 20
```
STACK                    HEAP
+------------------+     +------------------+
| main frame       |     |                  |
|  a = 0x????    ------> |      20          |
|  b = 0x????    ---/    +------------------+
+------------------+
```
Modifier *b modifie aussi *a car ils partagent la meme adresse !

### AI Error Example
L'IA a initialement dit que b etait une copie independante de a.
C'est FAUX. b = a copie l'ADRESSE, pas la valeur.
Les deux pointeurs partagent la meme zone heap.
C'est pourquoi *a = 20 apres *b = 20.

---

## Key Concepts

### Stack vs Heap
| Stack | Heap |
|-------|------|
| Automatique | Manuel (malloc/free) |
| Taille limitee | Taille flexible |
| Detruit a la fin de la fonction | Persiste jusqu'a free() |
| Variables locales | Allocations dynamiques |

### Pointer aliasing
Quand deux pointeurs pointent vers la meme adresse memoire,
modifier l'un modifie l'autre.
