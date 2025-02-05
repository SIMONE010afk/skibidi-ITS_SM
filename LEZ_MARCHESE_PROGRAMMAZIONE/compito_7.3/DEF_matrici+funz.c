#include <stdio.h>
#include "DEF_matrici.h"

int sumMatrix(int matrix[SIZE][SIZE], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            sum += matrix[i][j];
    return sum;
}

float averageDiagonal(int matrix[SIZE][SIZE], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += matrix[i][i];
    return (float)sum / size;
}

int countEvenNumbers(int matrix[SIZE][SIZE], int size) {
    int count = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (matrix[i][j] % 2 == 0)
                count++;
    return count;
}

int countOddNumbers(int matrix[SIZE][SIZE], int size) {
    int count = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (matrix[i][j] % 2 != 0)
                count++;
    return count;
}

int findMax(int matrix[SIZE][SIZE], int size) {
    int max = matrix[0][0];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (matrix[i][j] > max)
                max = matrix[i][j];
    return max;
}

int findMin(int matrix[SIZE][SIZE], int size) {
    int min = matrix[0][0];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (matrix[i][j] < min)
                min = matrix[i][j];
    return min;
}

void rowSums(int matrix[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = 0; j < size; j++)
            sum += matrix[i][j];
        printf("Somma riga %d: %d\n", i, sum);
    }
}

void columnSums(int matrix[SIZE][SIZE], int size) {
    for (int j = 0; j < size; j++) {
        int sum = 0;
        for (int i = 0; i < size; i++)
            sum += matrix[i][j];
        printf("Somma colonna %d: %d\n", j, sum);
    }
}

int isSymmetric(int matrix[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (matrix[i][j] != matrix[j][i])
                return 0;
    return 1;
}
