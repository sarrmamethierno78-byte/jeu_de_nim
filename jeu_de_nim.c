
#include <stdio.h>
#include <stdlib.h>

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

// Demande au joueur de saisir un nombre d'allumettes à retirer
//Verifie si le joueur a saisi un chiffre
// et renvoie la valeur saisie.
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

// Vérifie si le nombre choisi est valide.
// Le joueur peut retirer entre 1 et 4 allumettes,
// sans dépasser le nombre d'allumettes restantes.
int nombre_valide(int x,int total){
    if(x >= 1 && x <= 4 && x <= total){
        return 1;
    }
    return 0;
}
// Demande au joueur un nombre d'allumettes valide.
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

// Gère le déroulement d'une partie de Nim.
// y représente le nombre initial d'allumettes.
// Les joueurs jouent chacun leur tour jusqu'à ce
// qu'il ne reste plus aucune allumette.
int duel(int y){
    printf("**DEBUT DU JEU DE NIM**\n");
    printf("Chaque joueur doit prendre à chaque tour 1, 2, 3 ou 4 allumettes. Celui qui ne peut plus prendre d'allumettes perd !\n");

    // z mémorise le joueur qui vient de jouer.
    // Il est initialisé à 2 pour que le joueur 1 commence.
    int z=2;

    while(y!=0){
        affiche_allumettes(y);

        // Détermine le joueur dont c'est le tour.
        printf("Au tour du joueur %d\n",autre_joueur(z));

        // Retire du total le nombre d'allumettes choisi.
        y=y-recupere_nombre_valide_allumettes(y);

        // Alterne entre les deux joueurs (1 et 2).
        z = 3-z;
    }

    // Lorsque le tas est vide, le joueur qui vient de jouer
    // a pris les dernières allumettes : l'autre joueur a perdu.
    printf("Joueur %d a perdu\n",3-z);

    // Renvoie le numéro du joueur qui a gagné.
    return z;
}

int main() {
   // Lance une partie avec 16 allumettes
   // et affiche le numéro du joueur gagnant.
   printf("ON A UN VAINQUEUR ET C'EST LE JOUEUR NUMERO %d",duel(16));
   return EXIT_SUCCESS;
}
