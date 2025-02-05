#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#define SIZE 5

//Nota che matrix[][SIZE] è una dichiarazione valida purché size venga passato come argomento.

int sumMatrix(int matrix[SIZE][SIZE], int size);
float averageDiagonal(int matrix[SIZE][SIZE], int size);
int countEvenNumbers(int matrix[SIZE][SIZE], int size);
int countOddNumbers(int matrix[SIZE][SIZE], int size);
int findMax(int matrix[SIZE][SIZE], int size);
int findMin(int matrix[SIZE][SIZE], int size);
void rowSums(int matrix[SIZE][SIZE], int size);
void columnSums(int matrix[SIZE][SIZE], int size);
int isSymmetric(int matrix[SIZE][SIZE], int size);

#endif
