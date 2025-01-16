#include <stdio.h>
#include <stdbool.h>

// macros
#define NEW_LINE printf("\n");
#define PI_GRECO 3.14159265358
#define DEBUG_PRINT(x) printf("[DEBUG] - ");\
        printf("%s", x);\
        printf("\n");

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
    
    // fine prima lezione

    bool b = true;

    printf("my bool value %d", b);

        NEW_LINE;

    int i = 10;

    printf("my integer value %d", i);

    // new_line è stato definito all'inizio con #define
        NEW_LINE;

    float f = 10.0;

    printf("inserisci un numero reale: ");

    // & serve per rifarsi dell'indirizzo della f vale per tutti i tipi di dato
    scanf("%f", &f);

    NEW_LINE;

    printf("il mio float è %f", f);

    NEW_LINE;

    //printf("inserisci il raggio: ");

    //scanf("%f", &f);

    NEW_LINE;

    printf("il mio float è %f", f);

    NEW_LINE;

    printf("=== AREA DEL CERCHIO ===");
    NEW_LINE;
    printf("INSERISCI IL RAGGIO: ");
    scanf("%f", &f);
    NEW_LINE;

    float AREA = f * f * PI_GRECO;
    // stesso modo per scrivere l'area f = f * f * PI_GRECO

    printf("L'area del cerchio è %f", AREA);

    NEW_LINE;

    float funny = (f + f - PI_GRECO) / 10.0;

    printf("Calcolo con tutti gli operatori matematici è %f", funny);


    NEW_LINE;
    NEW_LINE;

    DEBUG_PRINT("Programma terminato");
    return 0;
}
