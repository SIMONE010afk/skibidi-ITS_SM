/*
Scrivere un programma in C che:

Chieda all'utente di inserire 10 numeri interi e li memorizzi in un array.
Calcoli e stampi:
La somma di tutti i numeri positivi presenti nell’array.
La somma di tutti i numeri negativi presenti nell’array.
Il valore massimo e il valore minimo dell'array.
Il numero di elementi pari e il numero di elementi dispari presenti nell'array.
Stampi un messaggio se tutti i numeri inseriti sono positivi o tutti negativi.
Stampi un messaggio se almeno un numero è multiplo di 5
*/

#include <stdio.h>
#include <stdlib.h>


#define NEW_LINE printf("\n");

int main() {

    int array[10];
    int sommaPositivi = 0, sommaNegativi = 0;
    int max, min;
    int pari = 0, dispari = 0;
    int tuttiPositivi = 1, tuttiNegativi = 1;
    int multiploDi5 = 0;

    printf("Dovrai inserire 10 numeri\n");

//La somma di tutti i numeri positivi presenti nell’array.
//La somma di tutti i numeri negativi presenti nell’array.
//Il valore massimo e il valore minimo dell'array.
//Il numero di elementi pari e il numero di elementi dispari presenti nell'array.

    for (int i = 0; i < 10; i++){
            printf("inserisci il numero %d: ", i + 1);
            scanf("%d", &array[i]);
    }

    for (int i = 0; i < 10; i++){
        if (array[i] > 0){
            sommaPositivi += array[i];
            tuttiNegativi = 0;
        } else if (array[i] < 0){
            sommaNegativi += array[i];
            tuttiPositivi = 0;
        }

        if (array[i] > max) {
            max = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        } 

        if (array[i] % 2 == 0){
            pari++;
        } else {
            dispari++;
        }

        if (array[i] % 5 == 0)
            multiploDi5 ++;
    }

// Stampa i risultati
    printf("\nSomma dei numeri positivi: %d\n", sommaPositivi);
    printf("Somma dei numeri negativi: %d\n", sommaNegativi);
    printf("Valore massimo: %d\n", max);
    printf("Valore minimo: %d\n", min);
    printf("Numero di numeri pari: %d\n", pari);
    printf("Numero di numeri dispari: %d\n", dispari);

    if (tuttiPositivi) {
        printf("Tutti i numeri sono positivi.\n");
    } else if (tuttiNegativi) {
        printf("Tutti i numeri sono negativi.\n");
    }

    if (multiploDi5) {
        printf("Almeno un numero è multiplo di 5.\n");
    }


    NEW_LINE;
    NEW_LINE;
    return 0;
}