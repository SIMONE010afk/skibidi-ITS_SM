#include <stdio.h>
#include <stdbool.h>

#define SIZE 3  // 3x3 Sudoku (per ogni blocco)
#define LAYERS 2 // Numero di blocchi 3x3 (esempio con 2 blocchi)

// Funzione per verificare se un blocco (layer) 3x3 è un Sudoku valido
bool is_sudoku_layer_valid(int matrix[LAYERS][SIZE][SIZE], int layer_index) {
    int seen[10] = {0}; // Array per segnare numeri visti (1-9)
   
    // Controlla il blocco (layer) 3x3
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int value = matrix[layer_index][i][j];
            // Verifica se il numero è nell'intervallo valido (1-9)
            if (value < 1 || value > 9) {
                printf("Numero fuori dal range [1-9] in layer %d\n", layer_index + 1);
                return false;
            }
            // Verifica se il numero è già stato visto (duplicato)
            if (seen[value] == 1) {
                printf("Duplicato trovato nel layer %d\n", layer_index + 1);
                return false;
            }
            seen[value] = 1;  // Marca il numero come visto
        }
    }
    return true;
}

// Funzione per verificare se una riga contiene numeri unici
bool is_row_valid(int matrix[LAYERS][SIZE][SIZE], int layer_index, int row_index) {
    int seen[10] = {0}; // Array per segnare numeri visti (1-9)
    for (int j = 0; j < SIZE; j++) {
        int value = matrix[layer_index][row_index][j];
        // Verifica se il numero è nell'intervallo valido (1-9)
        if (value < 1 || value > 9) {
            return false;
        }
        // Verifica se il numero è già stato visto (duplicato)
        if (seen[value] == 1) {
            return false;
        }
        seen[value] = 1;  // Marca il numero come visto
    }
    return true;
}

// Funzione per verificare se una colonna contiene numeri unici
bool is_column_valid(int matrix[LAYERS][SIZE][SIZE], int layer_index, int col_index) {
    int seen[10] = {0}; // Array per segnare numeri visti (1-9)
    for (int i = 0; i < SIZE; i++) {
        int value = matrix[layer_index][i][col_index];
        // Verifica se il numero è nell'intervallo valido (1-9)
        if (value < 1 || value > 9) {
            return false;
        }
        // Verifica se il numero è già stato visto (duplicato)
        if (seen[value] == 1) {
            return false;
        }
        seen[value] = 1;  // Marca il numero come visto
    }
    return true;
}

// Funzione per verificare se la matrice è un Sudoku valido
bool is_sudoku_valid(int matrix[LAYERS][SIZE][SIZE]) {
    // Verifica ogni blocco (layer)
    for (int i = 0; i < LAYERS; i++) {
        if (!is_sudoku_layer_valid(matrix, i)) {
            return false; // Se un layer non è valido, restituisci false
        }
    }

    // Verifica ogni riga e colonna di ogni layer
    for (int i = 0; i < LAYERS; i++) {
        for (int row = 0; row < SIZE; row++) {
            if (!is_row_valid(matrix, i, row)) {
                printf("Riga %d nel layer %d non è valida\n", row + 1, i + 1);
                return false; // Se una riga non è valida, restituisci false
            }
        }

        for (int col = 0; col < SIZE; col++) {
            if (!is_column_valid(matrix, i, col)) {
                printf("Colonna %d nel layer %d non è valida\n", col + 1, i + 1);
                return false; // Se una colonna non è valida, restituisci false
            }
        }
    }
    return true; // Se tutti i controlli sono passati, è un Sudoku valido
}

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