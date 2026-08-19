# Codexion — Fiche de travail sans IA

> Fiche de référence pour implémenter Codexion seul, à partir du sujet fourni.

## 1. Problème

Codexion simule plusieurs coders qui travaillent en parallèle.

Cycle :

```text
COMPILING → DEBUGGING → REFACTORING → COMPILING → ...
```

Pour compiler, un coder doit posséder **2 dongles simultanément**.

La simulation s'arrête :
- lorsqu'un coder burnout ;
- ou lorsque tous les coders ont atteint `number_of_compiles_required`.

## 2. Arguments

```text
number_of_coders
time_to_burnout
time_to_compile
time_to_debug
time_to_refactor
number_of_compiles_required
dongle_cooldown
scheduler
```

Le scheduler est :

```text
fifo
```

ou :

```text
edf
```

## 3. Règles essentielles

### Coders
- 1 coder = 1 `pthread`.
- Coders numérotés de `1` à `number_of_coders`.
- Coders disposés en cercle.
- Pas de communication directe entre coders.

### Dongles
- Nombre de dongles = nombre de coders.
- Un dongle entre chaque paire de coders.
- Chaque coder possède un dongle gauche et un dongle droit.
- Compiler nécessite les 2 dongles simultanément.
- Chaque dongle est protégé par un `pthread_mutex_t`.

## 4. Cycle d'un coder

```text
DEMANDE
   ↓
SCHEDULER
   ↓
obtient 2 dongles
   ↓
COMPILE
   ↓
libère les 2 dongles
   ↓
DEBUG
   ↓
REFACTOR
   ↓
nouvelle demande
```

## 5. Burnout

Un coder doit commencer une nouvelle compilation avant :

```text
last_compile_start + time_to_burnout
```

Sinon :

```text
BURNOUT
```

Au début de la simulation, la référence est le début de la simulation.

### Exemple

```text
time_to_burnout = 800 ms
dernier compile = 1000 ms
deadline = 1800 ms
```

## 6. Monitor

Le programme doit avoir un **thread monitor séparé**.

```text
MONITOR
   │
   ├── C1 → deadline
   ├── C2 → deadline
   └── C3 → deadline
```

Il surveille les deadlines de burnout et doit détecter un burnout rapidement.

## 7. Scheduler

Le scheduler décide quel coder doit obtenir ses ressources lorsqu'il y a concurrence.

```text
CODERS
   ↓
REQUESTS
   ↓
SCHEDULER
   ↓
DONGLES
```

### FIFO

First In, First Out.

Le premier arrivé est prioritaire.

```text
C1 demande à 100 ms
C2 demande à 120 ms
C3 demande à 150 ms

C1 → C2 → C3
```

Critère :

```text
request_time
```

### EDF

Earliest Deadline First.

Le coder dont la deadline est la plus proche est prioritaire.

```text
C1 → deadline 1800
C2 → deadline 1500
C3 → deadline 2100

C2 → C1 → C3
```

Deadline :

```text
last_compile_start + time_to_burnout
```

## 8. Priority Queue / Heap

Le sujet impose une priority queue basée sur une **heap**.

Heap min :

```text
             C2
            /  \
          C1    C3
         / \
       C4   C5
```

Le meilleur élément est :

```c
heap[0]
```

### Formules

Pour une heap indexée à `0` :

```text
parent(i) = (i - 1) / 2
left(i)   = 2 * i + 1
right(i)  = 2 * i + 2
```

### Opérations

```text
heap_init()
heap_push()
heap_pop()
heapify_up()
heapify_down()
heap_destroy()
```

### Push

```text
nouvel élément
      ↓
fin de heap
      ↓
heapify up
      ↓
remonter si nécessaire
```

### Pop

```text
heap[0]
   ↓
retirer
   ↓
dernier élément → racine
   ↓
heapify down
```

## 9. Structure d'une requête

Une requête représente la demande d'un coder pour obtenir ses 2 dongles.

Exemple :

```c
typedef struct s_request
{
    t_coder     *coder;
    long long   request_time;
    long long   deadline;
}   t_request;
```

Rôle :

```text
coder
  ↓
qui demande ?

request_time
  ↓
FIFO

deadline
  ↓
EDF
```

## 10. Structure du coder

Ton projet possède déjà des éléments utiles :

```text
id
thread
next
prev
dongle
last_compile_start
compile_count / compile_done
```

La liste circulaire permet de retrouver les voisins :

```text
C1 → C2 → C3 → C4
↑              ↓
└──────────────┘
```

Ne réécris pas inutilement cette partie.

## 11. Structure du dongle

Conceptuellement :

```c
typedef struct s_dongle
{
    pthread_mutex_t lock;
    long long       cooldown_until;
}   t_dongle;
```

Le mutex protège l'accès au dongle.

`cooldown_until` indique à partir de quel moment le dongle peut être repris.

## 12. Cooldown

Après utilisation :

```text
C1 libère D1
       ↓
D1 indisponible
       ↓
COOLDOWN
       ↓
D1 disponible
```

Exemple :

```text
release = 1000 ms
cooldown = 200 ms

available_at = 1200 ms
```

Le thread du coder ne doit pas simplement dormir pendant tout le cooldown : le dongle lui-même doit rester indisponible.

## 13. Mutex

### Mutex des dongles

```text
D1 → mutex
D2 → mutex
D3 → mutex
```

Empêche plusieurs threads de modifier simultanément le même dongle.

### Mutex du scheduler

Protège :

```text
heap
queue size
requêtes
```

### Mutex d'affichage

Protège les logs afin qu'une ligne ne soit pas mélangée avec une autre.

## 14. Condition variable

Une condition variable permet à un thread d'attendre sans busy-wait.

À éviter :

```c
while (!available)
    usleep(1);
```

Préférer :

```c
pthread_cond_wait(...)
```

Lorsqu'une ressource devient disponible :

```c
pthread_cond_signal(...)
```

ou :

```c
pthread_cond_broadcast(...)
```

Le thread réveillé doit toujours **revérifier la condition**.

## 15. Les deux dongles

Un coder doit obtenir :

```text
LEFT + RIGHT
```

avant de compiler.

Il ne doit jamais compiler avec seulement un dongle.

```text
        C1
       /  \
      D1  D2
       \  /
       COMPILE
```

## 16. Deadlock

Scénario classique :

```text
C1 possède D1
C2 possède D2

C1 attend D2
C2 attend D1
```

Résultat :

```text
C1 → attend C2
C2 → attend C1
```

Pour éviter cela, l'acquisition des deux ressources doit être conçue correctement.

## 17. Starvation

La starvation signifie qu'un coder attend indéfiniment :

```text
C1
 ↓
attend
 ↓
attend
 ↓
jamais servi
```

Le scheduler doit garantir un comportement équitable, notamment sous EDF dans les cas faisables.

## 18. Logging

Format attendu :

```text
timestamp X has taken a dongle
timestamp X is compiling
timestamp X is debugging
timestamp X is refactoring
timestamp X burned out
```

Exemple :

```text
0 1 has taken a dongle
1 1 has taken a dongle
1 1 is compiling
201 1 is debugging
401 1 is refactoring
```

Protéger l'affichage avec un mutex.

## 19. Temps

Le sujet recommande :

```c
gettimeofday()
```

Pour mesurer le temps depuis le début de la simulation :

```text
elapsed =
(current.tv_sec - start.tv_sec) * 1000
+
(current.tv_usec - start.tv_usec) / 1000
```

Il faut savoir écrire une fonction du type :

```c
long long get_time_ms(void);
```

et une fonction qui retourne le temps écoulé depuis le démarrage.

## 20. Phases

Les durées sont :

```text
compile  → time_to_compile
debug    → time_to_debug
refactor → time_to_refactor
```

`usleep()` peut être utilisé pour les durées, mais attention à la précision nécessaire pour le monitor.

## 21. État global de la simulation

Éviter les variables globales.

Une structure centrale peut regrouper :

```text
t_all
 ├── arguments
 ├── coders
 ├── dongles
 ├── scheduler
 ├── start_time
 └── stop
```

Le scheduler est partagé par tous les coders, donc il doit appartenir à la simulation plutôt qu'à un coder individuel.

## 22. Architecture logique

```text
                         t_all
                           │
             ┌─────────────┼─────────────┐
             │             │             │
          CODERS        SCHEDULER      MONITOR
             │             │             │
       ┌─────┼─────┐       │             │
       ↓     ↓     ↓       HEAP        burnout
      C1    C2    C3        │
             │              │
             └──────┬───────┘
                    ↓
                 DONGLES
```

Flux d'une demande :

```text
coder
  ↓
crée une request
  ↓
ajoute dans heap
  ↓
attend son tour
  ↓
scheduler l'autorise
  ↓
obtient les 2 dongles
  ↓
compile
  ↓
libère les dongles
  ↓
cooldown
  ↓
debug
  ↓
refactor
```

## 23. Fonctions à savoir écrire

### Heap

```text
heap_init()
heap_push()
heap_pop()
heapify_up()
heapify_down()
heap_destroy()
```

### Scheduler

```text
request_priority()
scheduler_add()
scheduler_next()
scheduler_remove()
```

### Synchronisation

```text
pthread_mutex_lock()
pthread_mutex_unlock()

pthread_cond_wait()
pthread_cond_signal()
pthread_cond_broadcast()
```

### Threads

```text
pthread_create()
pthread_join()
```

### Temps

```text
gettimeofday()
```

## 24. Ordre recommandé d'implémentation

Ne développe pas tout en même temps.

```text
1. Parser les arguments
        ↓
2. Créer les coders
        ↓
3. Créer les dongles
        ↓
4. Faire fonctionner les threads
        ↓
5. Faire compile/debug/refactor
        ↓
6. Ajouter les mutex des dongles
        ↓
7. Éliminer les deadlocks
        ↓
8. Implémenter la heap
        ↓
9. Implémenter FIFO
        ↓
10. Implémenter EDF
        ↓
11. Brancher le scheduler sur la prise des dongles
        ↓
12. Ajouter le cooldown
        ↓
13. Ajouter/corriger le monitor
        ↓
14. Gérer proprement l'arrêt
        ↓
15. Tester starvation/deadlock
        ↓
16. Vérifier les leaks
        ↓
17. Norm + Makefile
```

## 25. Checklist finale

```text
[ ] Chaque coder possède son pthread
[ ] Les coders sont disposés circulairement
[ ] N coders = N dongles
[ ] Chaque dongle possède son mutex
[ ] Une compilation nécessite 2 dongles
[ ] Les 2 dongles sont obtenus simultanément
[ ] Le cooldown est respecté
[ ] FIFO fonctionne
[ ] EDF fonctionne
[ ] Une priority queue / heap est utilisée
[ ] Les demandes sont correctement ordonnées
[ ] Pas de deadlock
[ ] Pas de starvation dans les cas faisables
[ ] Monitor séparé
[ ] Burnout détecté rapidement
[ ] Simulation s'arrête correctement
[ ] Logs protégés par mutex
[ ] Les lignes ne sont pas mélangées
[ ] Tous les threads sont join
[ ] Mutex/cond détruits
[ ] Allocations libérées
[ ] Pas de variable globale
[ ] Makefile avec -Wall -Wextra -Werror -pthread
[ ] Norm respectée
```

## 26. Les concepts à maîtriser

Les 6 notions essentielles :

```text
pthread
   +
mutex
   +
condition variable
   +
heap / priority queue
   +
FIFO / EDF
   +
gestion du temps
```

Puis viennent :

```text
        SYNCHRONISATION
               │
        ┌──────┴──────┐
        ↓             ↓
     scheduler      dongles
        │             │
      FIFO/EDF      mutex
        │             │
        └──────┬──────┘
               ↓
             CODER
               │
          compile/debug/
             refactor
               │
               ↓
            MONITOR
               │
             burnout
```

## 27. Règle de travail

Ne cherche pas à mémoriser tout le projet.

Pour chaque morceau de code, sois capable de répondre à :

1. **Quelle ressource est partagée ?**
2. **Qui peut la modifier ?**
3. **Quel mutex la protège ?**
4. **Quand un thread doit-il attendre ?**
5. **Qu'est-ce qui le réveille ?**
6. **Comment le scheduler choisit-il le prochain coder ?**
7. **Comment le programme détecte-t-il le burnout ?**
8. **Comment la simulation s'arrête-t-elle ?**

Si tu peux répondre à ces questions, tu comprends réellement l'architecture de Codexion.
