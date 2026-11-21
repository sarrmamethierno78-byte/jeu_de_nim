\# Jeu de Nim en langage C



\## Présentation



Ce projet consiste à développer le jeu de Nim en langage C. Il propose deux modes de jeu : un mode deux joueurs et un mode joueur contre ordinateur.



L'objectif est de prendre des allumettes à tour de rôle jusqu'à ce qu'il n'en reste plus. Le joueur qui prend les dernières allumettes gagne.



\## Règles du jeu



\- La partie commence avec un tas de 16 ou 21 allumettes selon le mode.

\- Chaque joueur peut retirer entre 1 et 4 allumettes par tour.

\- Il est interdit de retirer plus d'allumettes qu'il n'en reste.

\- Le joueur qui retire les dernières allumettes remporte la partie.



\## Modes de jeu



\### 1. Deux joueurs



Deux joueurs s'affrontent sur le même ordinateur. Ils jouent chacun leur tour jusqu'à la fin de la partie.



\*\*Fichier :\*\* `jeu\_de\_nim.c`



\### 2. Joueur contre ordinateur



Le joueur affronte l'ordinateur.



L'ordinateur utilise une stratégie basée sur les multiples de 5 : il cherche à laisser à son adversaire un nombre d'allumettes multiple de 5. Lorsque ce n'est pas possible, il choisit un coup aléatoire.



\*\*Fichier :\*\* `jeu\_de\_nim\_contre\_ordinateur.c`



\## Compilation et exécution



Le projet nécessite un compilateur C, comme GCC.



Chaque mode doit être compilé séparément.



\*\*Mode deux joueurs :\*\*



```bash

gcc -Wall -Wextra -std=c11 jeu\_de\_nim.c -o jeu\_de\_nim

./jeu\_de\_nim

```



\*\*Mode contre ordinateur :\*\*



```bash

gcc -Wall -Wextra -std=c11 jeu\_de\_nim\_contre\_ordinateur.c -o jeu\_de\_nim\_ordinateur

./jeu\_de\_nim\_ordinateur

```



Sous Windows PowerShell, remplacer l'exécution par `./nom\_du\_programme.exe` (par exemple `.\\jeu\_de\_nim.exe`).



\## Technologies utilisées



\- Langage C

\- Bibliothèque standard C (`stdio.h`, `stdlib.h`)



\## Compétences travaillées



\- Décomposition d'un programme en fonctions

\- Conditions et boucles

\- Gestion des entrées utilisateur

\- Génération de nombres pseudo-aléatoires

\- Implémentation d'une stratégie de jeu



