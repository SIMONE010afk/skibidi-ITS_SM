
#include <stdio.h>
#include <stdbool.h>

int main()
{
    char name[50];

    char cognome[50];

    printf("inserisci il tuo nome: ");

    scanf("%s", name);

    printf("inserisci il tuo cognome: ");

    scanf("%s", cognome);

    printf("Benvenuto, %s %s !\nGrazie per aver usato il nostro programma.\nTi auguriamo Buone Feste\n", name, cognome);

    printf("\n\t   *\n\t  ***\n\t *****\n\t*******\n\t  ***\n");
    
    return 0;
}
