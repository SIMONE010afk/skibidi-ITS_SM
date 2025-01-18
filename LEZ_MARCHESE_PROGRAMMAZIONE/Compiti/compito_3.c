#include <stdio.h>

#define SOMMA(x,y) x+y
#define SOTTRAZIONE(x,y) x-y
#define MOLTIPLICAZIONE(x,y) x * y
#define DIVISIONE(x,y) x / y
#define MODULO(x,y) x%y
#define NEW_LINE printf("\n");
#define STAMPA_NOME(nome) printf("Ciao %s\n", #nome)

int main()
{
    int x, y;

    STAMPA_NOME(Simone Torrengo);

    printf("inserisci x: ");

    scanf("%d", &x);

    printf("inserisci y: ");

    scanf("%d", &y);

    printf("La somma dei 2 numeri è %d\n", SOMMA(x,y));

    printf("La sottrazione dei 2 numeri è %d\n", SOTTRAZIONE(x,y));

    printf("La moltiplicazione dei 2 numeri è %d\n", MOLTIPLICAZIONE(x,y));

    double z = x, w = y, t;

    printf("La divisione dei 2 numeri è %.2f\n", DIVISIONE(z,w));

    printf("Il modulo dei 2 numeri è %d\n", MODULO(x,y));
    
    t = ((((SOMMA(x,y))+SOTTRAZIONE(x,y))+MOLTIPLICAZIONE(x,y))+DIVISIONE(z,w))+MODULO(x,y);

    printf("Il risultato di tutte le operazioni precedenti è %.2f\n", t);

    printf("Grazie per aver usato il nostro programma.");

    NEW_LINE;
    NEW_LINE;
    return 0;

}