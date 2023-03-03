#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 9
#define BLOCK_SIZE 3

void shuffle(int pInt[9], int i);

void printGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int isValid(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int num) {
    // Check if num already exists in the same row or column
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }

    // Check if num already exists in the same block
    int blockRowStart = row - row % BLOCK_SIZE;
    int blockColStart = col - col % BLOCK_SIZE;
    for (int i = blockRowStart; i < blockRowStart + BLOCK_SIZE; i++) {
        for (int j = blockColStart; j < blockColStart + BLOCK_SIZE; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int fillGrid(int grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    if (row == GRID_SIZE - 1 && col == GRID_SIZE) {
        return 1;
    }

    if (col == GRID_SIZE) {
        row++;
        col = 0;
    }

    if (grid[row][col] > 0) {
        return fillGrid(grid, row, col + 1);
    }

    int nums[GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++) {
        nums[i] = i + 1;
    }
    shuffle(nums, GRID_SIZE);

    for (int i = 0; i < GRID_SIZE; i++) {
        int num = nums[i];
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            if (fillGrid(grid, row, col + 1)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }

    return 0;
}

void shuffle(int pInt[9], int i) {

}

int solveGrid(int grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    if (row == GRID_SIZE - 1 && col == GRID_SIZE) {
        return 1;
    }

    if (col == GRID_SIZE) {
        row++;
        col = 0;
    }

    if (grid[row][col] > 0) {
        return solveGrid(grid, row, col + 1);
    }

    for (int num = 1; num <= GRID_SIZE; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveGrid(grid, row, col + 1)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}