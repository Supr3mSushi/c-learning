#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>

int main()
{
    int sudoku[9][9] = {
            {6, 2, 4, 5, 3, 9, 1, 8, 7},
            {5, 1, 9, 7, 2, 8, 6, 3, 4},
            {8, 3, 7, 6, 1, 4, 2 ,9, 5},
            {1, 4, 3, 8, 6, 5, 7, 2, 9},
            {9, 6, 8, 2, 4, 7, 3, 5, 1},
            {2, 5, 7, 4, 9, 1, 8, 6, 3},
            {3, 8, 6, 1, 5, 2, 9, 4, 7},
            {4, 9, 1, 3, 7, 6, 5, 8, 2},
            {7, 1, 2, 9, 8, 3, 4, 5, 6}
    };

    int i;

    for (i = 0; i < 9; i++) {

        printf("%d %d %d | %d %d %d | %d %d %d\n", sudoku[i][0],sudoku[i][1],sudoku[i][2],sudoku[i][3],sudoku[i][4],sudoku[i][5],sudoku[i][6],sudoku[i][7],sudoku[i][8]);

        if ( (i+1)%3 == 0) printf("---------------------\n");

    }

    return 0;
}
