#include <stdio.h>
#include <stdbool.h>

#define LAYERS 2
#define SIZE 3

// Funzione per stampare la matrice
void print_matrix(int matrix[LAYERS][SIZE][SIZE]) {
    for (int i = 0; i < LAYERS; i++) {
        printf("Layer %d:\n", i + 1);
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                printf("%d ", matrix[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Funzione per trasformare la matrice (parziale/dispari)
void transform_matrix(int matrix[LAYERS][SIZE][SIZE]) {
    for (int i = 0; i < LAYERS; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                matrix[i][j][k] = (matrix[i][j][k] % 2 == 0) ? -1 : 1;
            }
        }
    }
}

// Funzione per verificare se un layer 3x3 è un Sudoku valido
bool is_sudoku_layer_valid(int matrix[LAYERS][SIZE][SIZE], int layer_index) {
    int seen[10] = {0}; // Array per segnare numeri visti (1-9)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int value = matrix[layer_index][i][j];
            if (value < 1 || value > 9) {
                printf("Numero fuori dal range [1-9] in layer %d\n", layer_index + 1);
                return false;
            }
            if (seen[value] == 1) {
                printf("Duplicato trovato nel layer %d\n", layer_index + 1);
                return false;
            }
            seen[value] = 1;
        }
    }
    return true;
}

// Verifica riga
bool is_row_valid(int matrix[LAYERS][SIZE][SIZE], int layer_index, int row_index) {
    int seen[10] = {0};
    for (int j = 0; j < SIZE; j++) {
        int value = matrix[layer_index][row_index][j];
        if (value < 1 || value > 9 || seen[value] == 1) {
            return false;
        }
        seen[value] = 1;
    }
    return true;
}

// Verifica colonna
bool is_column_valid(int matrix[LAYERS][SIZE][SIZE], int layer_index, int col_index) {
    int seen[10] = {0};
    for (int i = 0; i < SIZE; i++) {
        int value = matrix[layer_index][i][col_index];
        if (value < 1 || value > 9 || seen[value] == 1) {
            return false;
        }
        seen[value] = 1;
    }
    return true;
}

// Funzione principale per verificare se tutta la matrice è un Sudoku valido
bool is_perfect_sudoku(int matrix[LAYERS][SIZE][SIZE]) {
    for (int i = 0; i < LAYERS; i++) {
        if (!is_sudoku_layer_valid(matrix, i)) {
            return false;
        }
    }
    for (int i = 0; i < LAYERS; i++) {
        for (int row = 0; row < SIZE; row++) {
            if (!is_row_valid(matrix, i, row)) {
                return false;
            }
        }
        for (int col = 0; col < SIZE; col++) {
            if (!is_column_valid(matrix, i, col)) {
                return false;
            }
        }
    }
    return true;
}
