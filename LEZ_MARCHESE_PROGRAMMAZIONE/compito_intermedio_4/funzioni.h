#include <stdio.h>
#include <stdbool.h>

#define LAYERS 2
#define ROWS 3
#define COLS 3

// Funzione per modificare la matrice sostituendo gli elementi pari con -1 e dispari con 1
void modify_matrix(int matrix[LAYERS][ROWS][COLS]) {
    for (int k = 0; k < LAYERS; k++) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                matrix[k][i][j] = (matrix[k][i][j] % 2 == 0) ? -1 : 1;
            }
        }
    }
}

// Funzione per verificare se una matrice 3x3 è un Sudoku perfetto
bool is_perfect_sudoku(int matrix[ROWS][COLS]) {
    bool seen[10] = {false}; // Indice 0 non usato (numeri validi: 1-9)
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int val = matrix[i][j];
            if (val < 1 || val > 9 || seen[val]) {
                return false; // Numero fuori intervallo o ripetuto
            }
            seen[val] = true;
        }
    }
    return true;
}
