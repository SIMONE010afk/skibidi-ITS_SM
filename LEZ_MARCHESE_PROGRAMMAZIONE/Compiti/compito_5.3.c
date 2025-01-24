/*
Scrivere un programma in C che:

chieda all'utente di inserire una sequenza di numeri interi positivi; il programma deve calcolare la somma dei numeri, il massimo numero inserito e la lunghezza della sequenza
l'input termina quando l'utente inserisce il numero 0 (lo zero non deve essere incluso nei calcoli)
se l'utente inserisce un numero negativo, il programma deve ignorarlo e chiedere un altro numero.
dopo che l'utente termina la sequenza, il programma deve stampare: la somma totale dei numeri, il numero massimo inserito, la lunghezza della sequenza (escludendo i numeri negativi e lo zero)
se l'utente non inserisce alcun numero valido prima di inserire 0, il programma deve stampare un messaggio adeguato, ad esempio: "Nessun numero valido inserito"
utilizzare il ciclo while
*/

#include <stdio.h>
#include <stdlib.h>

#define NEW_LINE printf("\n");

int main() {
    
    int x = 1, somma = 0, max = 0, cont = 0;


    while (x > 0){

    do {
    printf("Inserisci un numero (= 0 per uscire): ");
    scanf("%d", &x);

    } while (x < 0); 

    somma = somma + x;

    if (x > max)
        max = x;

    if (x != 0)
        cont ++;

    if (somma == 0)
        printf("nessun numero valido\n");
    }

    printf("la somma è: %d\nil massimo è: %d\nla lunghezza della sequenza è: %d", somma, max, cont);

    NEW_LINE;
    NEW_LINE;
    return 0;
}