#include <stdio.h>
#include "DEF_matrici.h"

#define NEW_LINE printf("\n");

int main() {
    int matrix[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    printf("Somma totale: %d\n", sumMatrix(matrix, SIZE));
    printf("Media diagonale: %.2f\n", averageDiagonal(matrix, SIZE));
    printf("Numeri pari: %d\n", countEvenNumbers(matrix, SIZE));
    printf("Numeri dispari: %d\n", countOddNumbers(matrix, SIZE));
    printf("Massimo: %d\n", findMax(matrix, SIZE));
    printf("Minimo: %d\n", findMin(matrix, SIZE));

    rowSums(matrix, SIZE);
    columnSums(matrix, SIZE);

    if (isSymmetric(matrix, SIZE))
        printf("La matrice è simmetrica.\n");
    else
        printf("La matrice NON è simmetrica.\n");

    NEW_LINE;
    NEW_LINE;
    return 0;
}
