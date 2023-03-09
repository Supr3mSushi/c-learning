#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Fonction generer() qui génére un tableau aléatoire de 4 chiffres parmis 6 variables

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


// Fonction afficher() qui affiche les chiffre s en lettres

void afficher(int tab[6]) {
    char P, B, M, Y, O, G;
    char tab_char [6] = {P = 1, B = 2, M = 3, Y = 4, O = 5, G = 6};



}



// Fonction saisir() qui saisir qui





// Fonction rangeminator() qui range





int main(){
    srand(time(NULL));
    int tab[4];
    generer(tab);
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

