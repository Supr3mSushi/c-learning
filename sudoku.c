#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
Pour l'exercice vous aurez besoin de generer des entiers aléatoire : rand() renvoit un entier aléatoire.
il s'utilise : rand() % NOMBREMAX + 1
Pour un entier aléatoire entre 0 et 1 il faut donc faire rand() %2
voir dans la methode main.
*/

/*
Ecrire la fonction generer(), elle prend en paramètre la grille et renvoie le nombre d'éléments non nuls
*/

void generer(int grid[9][9]) {
    int ligne, colonne;
    int nombreNonNuls = 0;

    for (ligne = 0; ligne < 9; ligne++) {
        for (colonne = 0; colonne < 9; colonne++) {
            if (grid[ligne][colonne] != 0) {
                nombreNonNuls++;
            }
        }
    }

    for(ligne = 0;ligne < 9; ++ligne) {
        for(colonne = 0; colonne < 9; ++colonne) printf("%d ", grid[ligne][colonne]); printf("\n");
    }

    printf("Nombre d'elements non nuls : %d\n", nombreNonNuls);
}

// Ce lien vous sera utile : https://www.geeksforgeeks.org/pass-2d-array-parameter-c/


/*
Écrire une fonction saisir() qui demande à l’utilisateur de saisir au clavier les indices i et j et la valeur v à placer à l’emplacement (i,j).
La fonction doit vérifier la validité des indices et de la valeur.
Si la case n’est pas occupée, la valeur doit être placée dans la grille. remplissage est alors incrémentée
*/

void saisir(int grid[9][9]) {
    int i, j, v;
    int REGION_SIZE = 3;

    printf("|-------|-------|-------|\n");
    for (int i = 0; i < 9; i++) {
        printf("| ");
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
            if ((j+1) % REGION_SIZE == 0 && j != 9){
                printf("| ");
            }
            if ((j+1) % REGION_SIZE == 0 && j!= 9){
                printf("");
            }
        }
        printf("\n");
        if ((i+1) % REGION_SIZE == 0 && i != 9) {
            printf("|-------|-------|-------|\n");
        }
    }

    printf("Which Lines (0-8) : \n");
    scanf("%d", &i);
    printf("Which Column (0-8) : \n");
    scanf("%d", &j);
    printf("Which Value (1-9) : \n");
    scanf("%d", &v);

    if(i < 0 || i > 8 || j < 0 || j > 8 || v < 1 || v > 9) {
        printf("Erreur ! Mauvaises valeurs.\n");
    }
    else {
        if(grid[i][j] == 0) {
            grid[i][j] = v;
        } else {
            printf("Erreur ! Cette case est déjà prise. Veuillez en choisir un autre\n");
        }
    }
}

/*
Écrire la fonction verifierLigneColonne() qui prend en paramètre un numéro et un sens (HORIZ ou VERT)
qui vérifie que la ligne ou la colonne (suivant les cas) numéro est bien remplie.
On pourra utiliser un tableau intermédiaire pour vérifier cela. La fonction retournera 1 si tout s’est bien passé, 0 sinon.
 Les constantes HORIZ de valeur 0 et VERT de valeur 1 sont à définir.
*/

int verifierLigneColonne(int grid[9][9], int value, int sens) {
    int i;
    int array[9];
    if(sens == 0) {
        for(i = 0; i < 9; i++) {
            array[i] = grid[i][value];
        }
    } else if(sens == 1) {
        for(i = 0; i < 9; i++) {
            array[i] = grid[value][i];
        }
    }

    int sum = 0;
    for(i = 0; i < 9; i++) {
        sum += array[i];
    }

    if(sum == 45) {
        return 0;
    } else {
        return 1;
    }
}

/*
Écrire la fonction verifierRegion() qui prend en paramètre deux indices k et l qui correspondent à la région (k,l)
et qui renvoie 1 si la région est correctement remplie, 0 sinon.
*/

int verifierRegion(int grid[9][9], int k, int l) {
    int i, j;
    int array[9];
    int index = 0;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            array[index] = grid[i + k][j + l];
            index++;
        }
    }

    int sum = 0;
    for(i = 0; i < 9; i++) {
        sum += array[i];
    }

    if(sum == 45) {
        return 0;
    } else {
        return 1;
    }
}

/*
Écrire la fonction verifierGrille() qui renvoie 1 si la grille est correctement remplie et 0 sinon
*/

int verifierGrille(int grid[9][9]) {
    bool region = false;
    bool ligne = false;
    bool colonne = false;
    for (int i = 3; i < 9; i += 3) {
        for(int j = 3; j < 9; j += 3) {
            if (verifierRegion(grid, i, j) == 0) {
                region = true;
            }
        }
    }

    for(int i = 0; i < 9; i++) {
        if(verifierLigneColonne(grid, i, 0) == 0) {
            ligne = true;
        }
        if(verifierLigneColonne(grid, i, 1) == 0) {
            colonne = true;
        }
    }
    if (region && ligne && colonne) {
        return 0;
    } else {
        return 1;
    }
}

/*
Écrire le programme principal, en supposant que la seule condition d’arrêt est la réussite du sudoku (ce test ne devra être fait que si nécessaire)
 */

int main(){
    // Ne pas toucher le code entre les commentaires
    srand(time(NULL));
    int i, j;
    int solution[9][9];
    printf("RESOLUTION DU SUDOKU");
    printf("\n");
    printf("--------------------------------");
    printf("\n");
    for(j=0;j<9; ++j) {
        for(i=0; i<9; ++i) solution[j][i] = (i + j*3 +j /3) % 9 +1 ;
    }

    int num_to_remove  = 30;
    while (num_to_remove > 0) {
        int row = rand() % 9;
        int col = rand() % 9;
        if (solution[row][col] != 0) {
            solution[row][col] = 0;
            num_to_remove--;
        }
    }

    generer(solution);

    printf("-------------------------------");
    printf("\n");
    // Toucher le code entre les commentaires

    int valid = 1;
    while(valid == 1) {
        saisir(solution);
        generer(solution);
        valid = verifierGrille(solution);
    }

    printf("Mazel tov, vous avez terminé le sudoku\n");

    // Ne pas toucher au code ci dessous
    system("pause");
    return 0;
}

