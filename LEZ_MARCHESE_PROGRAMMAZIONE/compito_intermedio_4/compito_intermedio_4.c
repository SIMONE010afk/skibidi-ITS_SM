#include <stdio.h>
#include <stdbool.h>
#include "funzioni.h"

int main() {
    int matrix[LAYERS][ROWS][COLS] = {
        {
            {1,  4,  7},
            {2,  5,  8},
            {3,  6,  9}
        },
        {
            {1,  4,  7},
            {2,  5,  8},
            {3,  5,  9}  // Il numero 5 è ripetuto volutamente
        }
    };
    
    // Verifica Sudoku per ogni strato
    for (int k = 0; k < LAYERS; k++) {
        if (is_perfect_sudoku(matrix[k])) {
            printf("La matrice %d e' un Sudoku perfetto.\n", k + 1);
        } else {
            printf("La matrice %d NON e' un Sudoku perfetto.\n", k + 1);
        }
    }
    
    // Modifica la matrice
    modify_matrix(matrix);
    
    // Stampa la matrice modificata
    printf("Matrice modificata:\n");
    for (int k = 0; k < LAYERS; k++) {
        printf("Strato %d:\n", k + 1);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%2d ", matrix[k][i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}
