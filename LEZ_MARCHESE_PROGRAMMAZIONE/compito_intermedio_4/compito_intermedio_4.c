#include <stdio.h>
#include <stdbool.h>
#include "funzioni.h"

int main() {
    int matrix[2][3][3] = {
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

    printf("Matrice originale:\n");
    print_matrix(matrix);

    // Controllo Sudoku PRIMA della trasformazione
    for (int i = 0; i < 2; i++) {
        if (is_perfect_sudoku(matrix)) {
            printf("\nLa matrice %d è un Sudoku perfetto.\n", i + 1);
        } else {
            printf("\nLa matrice %d non è un Sudoku perfetto.\n", i + 1);
        }
    }

    transform_matrix(matrix);
    printf("\nDopo sostituzione pari/dispari:\n");
    print_matrix(matrix);

    return 0;
}
