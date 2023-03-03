#include <stdio.h>

// Definition de la grille de Sudoku en une matrice de 9x9
#define SIZE 9

// Affichage de la grille du sudoku
void print_grid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Vérifie si un nombre peut être placé dans une case donnée
int is_valid(int grid[SIZE][SIZE], int row, int col, int num) {

    // Vérifie si le numéro existe déjà dans la ligne
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }

    // Vérifie si le numéro existe déjà dans la colonne
    for (int i = 0; i < SIZE; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }

    // Vérifie si le numéro existe déjà dans la grille 3x3
    int start_row = (row / 3) * 3;
    int start_col = (col / 3) * 3;
    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_col; j < start_col + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }

    // Si le numéro n'existe pas déjà, il peut être placé dans la case
    return 1;
}

// Fonction récursive pour résoudre la grille de Sudoku
int solve_sudoku(int grid[SIZE][SIZE], int row, int col) {

    // Si la grille est totalement remplie le sudoku est résolu
    if (row == SIZE) {
        return 1;
    }

    // Si une ligne es totalement remplie, on passe à la ligne suivante
    if (col == SIZE) {
        return solve_sudoku(grid, row + 1, 0);
    }

    // Si une case contient déjà un nombre, on passe à la case suivante
    if (grid[row][col] != 0) {
        return solve_sudoku(grid, row, col + 1);
    }

    // On place les nombres de 1 à 9 dans la case
    for (int num = 1; num <= 9; num++) {
        if (is_valid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(grid, row, col + 1)) {
                return 1;
            }

            // Supprime le nombre si le sudoku n'est pas résolu avec le nombre actuel
            grid[row][col] = 0;
        }
    }

    // AUcun nombre fonctionne, sudoku pas resolvable
    return 0;
}

// Définition d'une grille de Sudoku à résoudre
int main() {
    int grid[SIZE][SIZE] = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    // Affichage de la grille de Sudoku initiale
    printf("Grille initiale :\n");

    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }

    // Résoudre la grille de Sudoku
    if (solve_sudoku(grid, 0, 0)) {
        // Afficher la grille de Sudoku résolue
        printf("\nGrille resolue :\n");
        print_grid(grid);
    } else {
        printf("\nLe Sudoku est irresolvable.\n");
    }

    return 0;
}
