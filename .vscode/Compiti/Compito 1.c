#include <stdio.h>

int main()
{
    char name[50];

    char cognome[50];

    printf("inserisci il tuo nome: ");

    scanf("%s", name);

    printf("inserisci il tuo cognome: ");

    scanf("%s", cognome);

    printf("Benvenuto, %s %s !\nGrazie per aver usato il nostro programma.\nTi auguriamo Buone Feste\n*\n", name, cognome);

    return 0;
}