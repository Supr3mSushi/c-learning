#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
Gen (réponse du mastermind) --> [1,2,3,4] (il prend des chiffres de 1 à 6 au hasard)
Afficher (passer le tableau dedans) --> donne un tableau avec des lettres à la place des chiffres (ex: B = 1, A =2, etc)
Saisir --> prend 4 valeurs entrées par l'utilisateur qui sont mises dans un tableau après être transformé ( B =1, A = 2)
Rangement --> prend deux paramètres (tab, x) ->  le tableau[0,1,1,2] (0 -> ., 1-> W, 2->R)
*/


// Fonction generer()

void generer(int tab[4]) {
    bool deja_utilise[6] = {false}; // initialisation du tableau de booléens
    int i, n;

    for (i = 0; i < 4; i++) {
        do {
            n = rand() % 6 + 1; // génère un nombre aléatoire entre 1 et 6
        } while (deja_utilise[n - 1]); // continue à générer des nombres jusqu'à ce qu'un nombre non utilisé soit trouvé

        deja_utilise[n - 1] = true; // marque le nombre comme utilisé
        tab[i] = n; // ajoute le nombre au tableau
    }

    for (i = 0; i < 4; i++) {
        printf("%d ", tab[i]); // affiche les nombres générés
    }

    printf("\n");
}


// Fonction afficher()

void afficher(int tab[4]){
    for(int i = 0; i < 4; i++){
        switch(tab[i]){
            case 1:
                printf("P ");
                break;
            case 2:
                printf("B ");
                break;
            case 3:
                printf("M ");
                break;
            case 4:
                printf("Y ");
                break;
            case 5:
                printf("O ");
                break;
            case 6:
                printf("G ");
                break;
        }
    }
    printf("\n");
}



// Fonction saisir()
void saisir(int tab[4]){
    int i;
    for(i = 0; i < 4; i++){
        printf("Entrez une couleur : ");
        scanf("%d", &tab[i]);
    }
}

// Fonction rangeminator()





int main(){
    srand(time(NULL));
    int tab[4];
    generer(tab);
    afficher(tab);
    /*printf("A vous de jouer !");
    printf("Voici les couleurs disponibles : \n");
    printf("1 = P, 2 = B, 3 = M, 4 = Y, 5 = O, 6 = G \n");
    printf("-------------------------------");
    printf("\n");
    printf("Voici les couleurs que vous avez choisi : \n");
    printf("1 = P, 2 = B, 3 = M, 4 = Y, 5 = O, 6 = G \n");
    printf("-------------------------------");
    printf("\n");*/

    system("pause");
    return 0;


}

