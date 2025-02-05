#include <stdio.h>

/*
#define SOTTRAZIONE(x,y) x-y
#define MOLTIPLICAZIONE(x,y) x * y
#define DIVISIONE(x,y) x / y
#define MODULO(x,y) x%y
#define NEW_LINE printf("\n");
#define STAMPA_NOME(nome) printf("Ciao %s\n", #nome)
*/

#include "compito_3.h"

int main()
{
    int x, y;

// print the name
    STAMPA_NOME(Simone Torrengo);

// insert first value
    printf("inserisci x: ");

    scanf("%d", &x);

// insert second value
    printf("inserisci y: ");

    scanf("%d", &y);

// sum, substraction, multiplication
    printf("La somma dei 2 numeri è %d\n", SOMMA(x,y));

    printf("La sottrazione dei 2 numeri è %d\n", SOTTRAZIONE(x,y));

    printf("La moltiplicazione dei 2 numeri è %d\n", MOLTIPLICAZIONE(x,y));

/* define new variables as the division needs double and only 2 numbers after the comma,
 plus create a new variable for all the operations together*/
    double z = x, w = y, t;

// division, modulus
    printf("La divisione dei 2 numeri è %.2f\n", DIVISIONE(z,w));

    printf("Il modulo dei 2 numeri è %d\n", MODULO(x,y));
    
    t = ((((SOMMA(x,y))+SOTTRAZIONE(x,y))+MOLTIPLICAZIONE(x,y))+DIVISIONE(z,w))+MODULO(x,y);

// print the result
    printf("Il risultato di tutte le operazioni precedenti è %.2f\n", t);

    printf("Grazie per aver usato il nostro programma.");

    NEW_LINE;
    NEW_LINE;
    NEW_LINE;
    
    return 0;

}