/*
Scrivere un programma in C che:

Definisca questa matrice 3x4 di numeri in virgola mobile (float) e la inizializzi staticamente nel codice:
 

  1.5  −6.8   10.0
 −3.2   7.1  −11.3
  4.0  −8.4   12.6
  5.5   9.9  −13.7

Calcoli e stampi:
La somma di tutti i numeri positivi presenti nella matrice.
La somma di tutti i numeri negativi presenti nella matrice.
Il valore massimo e il valore minimo della matrice.
Il numero di elementi pari e il numero di elementi dispari (considerando solo la parte intera del numero).
Stampi un messaggio se tutti i numeri nella matrice sono positivi o tutti negativi.
Stampi un messaggio se almeno un numero è multiplo di 5 (considerando solo la parte intera del numero).
*/

#include <stdio.h>
#include <stdlib.h>


#define NEW_LINE printf("\n");

int main() {

    float somma = 0, matrix[4][3] ={{1.5,-6.8,10.0},{-3.2,7.1,-11.3},{4.0,-8.4,12.6},{5.5,9.9,-13.7}};

    float sommaPositivi = 0, sommaNegativi = 0;
    float max, min;
    int pari = 0, dispari = 0;
    int tuttiPositivi = 1, tuttiNegativi = 1;
    int multiploDi5 = 0;

//La somma di tutti i numeri positivi presenti nell’array.
//La somma di tutti i numeri negativi presenti nell’array.
//Il valore massimo e il valore minimo dell'array.
//Il numero di elementi pari e il numero di elementi dispari presenti nell'array.

for (int i = 0; i < 4; i++ )
    for (int j = 0; j < 3; j++){
        if (matrix[i][j] > 0){
            sommaPositivi += matrix[i][j];
            tuttiNegativi = 0;
        } else if (matrix[i][j] < 0){
            sommaNegativi += matrix[i][j];
            tuttiPositivi = 0;
        }

        if (matrix[i][j] > max) {
            max = matrix[i][j];
        }
        if (matrix[i][j] < min) {
            min = matrix[i][j];
        } 

int valore_int = (int) matrix[i][j];

        if (valore_int % 2 == 0){
            pari++;
        } else {
            dispari++;
        }

        if (valore_int % 5 == 0)
            multiploDi5 ++;
    }

// Stampa i risultati
    printf("\nSomma dei numeri positivi: %.2f\n", sommaPositivi);
    printf("Somma dei numeri negativi: %.2f\n", sommaNegativi);
    printf("Valore massimo: %.2f\n", max);
    printf("Valore minimo: %.2f\n", min);
    printf("Numero di numeri pari: %d\n", pari);
    printf("Numero di numeri dispari: %d\n", dispari);


    NEW_LINE;
    NEW_LINE;
    return 0;
}