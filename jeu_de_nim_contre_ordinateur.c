
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Renvoie le numéro de l'autre joueur.
// Si le joueur actuel est le 1, renvoie 2, et inversement.
int autre_joueur(int x){
    if (x==1){
        return 2;
    }
    return 1;
}

// Affiche le nombre d'allumettes restantes
// sous forme de barres verticales.
void affiche_allumettes(int x){
    printf("Il reste %d allumettes :",x);
    for (int i=0;i<x;i++){
        printf("|");
    }
    printf("\n");
}

// Demande à l'utilisateur de saisir un entier
// correspondant au nombre d'allumettes à retirer
// Et Verifie si le joueur a saisi un chiffre.


int recupere_entier(){
    int x;
    int resultat;

    printf("Choisissez un nombre d'allumettes a retirer : ");

    resultat = scanf("%d",&x);

    while(resultat != 1){
        printf("Veuillez saisir un entier valide !\n");

        // Vide le buffer jusqu'au prochain retour à la ligne.
        while(getchar() != '\n');

        printf("Choisissez un nombre d'allumettes à retirer : ");
        resultat = scanf("%d",&x);
    }

    return x;
}


// Vérifie si le nombre choisi est autorisé :
// il doit être compris entre 1 et 4
// et ne doit pas dépasser le nombre d'allumettes restantes.
int nombre_valide(int x,int total){
    if(x >= 1 && x <= 4 && x <= total){
        return 1;
    }
    return 0;
}

// Demande un nombre d'allumettes valide.
// Tant que la saisie ne respecte pas les règles,
// le joueur doit recommencer.
int recupere_nombre_valide_allumettes(int total){
    int x = recupere_entier();
    while(!nombre_valide(x,total)){
		printf("veuillez rester en dessous du total et choisir un chiffre entre 1 et 4 ");
		x = recupere_entier();
	}
    
    return x;
}

// Génère un entier aléatoire compris entre debut et fin inclus.
// rand() % (fin-debut+1) permet de déterminer l'intervalle,
// puis on ajoute debut pour obtenir la bonne plage de valeurs.
int entier_aleatoire(int debut,int fin){
    int x=rand()%(fin-debut+1)+debut;
    return x;
}

// Détermine le nombre d'allumettes que l'ordinateur doit retirer.
// L'objectif est de laisser à l'adversaire un multiple de 5.
// Si le nombre restant est déjà un multiple de 5,
// l'ordinateur choisit un nombre aléatoire entre 1 et 4.
int coup_ordinateur(int n){

    // Si le nombre d'allumettes est compris entre 1 et 4,
    // l'ordinateur les retire toutes.
    if((n==1)||(n==2)||(n==3)||(n==4)){
        return n;
    }

    // Si n est un multiple de 5, l'ordinateur choisit
    // un coup aléatoire entre 1 et 4.
    if(n % 5 == 0){
        return entier_aleatoire(1 , 4);
    }

    // Sinon, l'ordinateur cherche le nombre à retirer
    // pour laisser un multiple de 5.
    if (n % 5 != 0){
        if ((n - 1) % 5 == 0){
            return 1;
        }
        if ((n - 2) % 5 == 0){
            return 2;
        }
        if ((n - 3) % 5 == 0){
            return 3;
        }
        if ((n - 4) % 5 == 0){
            return 4;
        }
    }

    // Coup de secours si aucun des cas précédents ne s'applique.
    return 1;
}

// Gère une partie entre le joueur humain et l'ordinateur.
// Le joueur humain commence.
// La variable z indique qui vient de jouer :
// 1 pour le joueur humain et 2 pour l'ordinateur.
void partie (int n){
    printf("**DEBUT DU JEU DE NIM**\n");
    printf("Chaque joueur doit prendre à chaque tour 1, 2, 3 ou 4 allumettes. Celui qui ne peut plus prendre d'allumettes perd !\n");
    printf("aujourd'hui vous jouerez contre l'ordinateur\n");

    int z = 0;
    int x;

    while (n != 0){

        // Tour du joueur humain.
        printf("A votre tour !\n");
        affiche_allumettes(n);
        z = 1;

        // On retire du total le nombre d'allumettes choisi.
        n = n - recupere_nombre_valide_allumettes(n);

        // Si le joueur a pris les dernières allumettes,
        // la partie s'arrête immédiatement.
        if (n == 0){
            break;
        }

        // Tour de l'ordinateur.
        printf("il reste %d allumettes\n",n);
        printf ("au tour de l'ordinateur\n");
        affiche_allumettes(n);

        // L'ordinateur choisit son coup.
        x = coup_ordinateur(n);
        printf("L'ordinateur a retire %d allumettes\n",x);

        z = 2;

        // On retire du total le nombre d'allumettes choisi
        // par l'ordinateur.
        n = n - x;
    }

    // Détermine le résultat de la partie.
    // Si le joueur humain a joué en dernier, il gagne.
    // Si l'ordinateur a joué en dernier, le joueur perd.
    if (z == 1){
        printf("gagne");
    }
    else if (z == 2){
        printf("perdu");
    }
}


int main() {
	srand(time(NULL));
    // Lance une partie avec 21 allumettes.
    // Affiche ensuite la valeur renvoyée par la fonction partie().
    partie (21);

    return EXIT_SUCCESS;
}
