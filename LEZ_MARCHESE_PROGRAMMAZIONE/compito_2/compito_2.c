#include <stdio.h>
#include <string.h>

#define STAMPA_NOME(nome) printf("Ciao %s\n", #nome)
#define NEW_LINE printf("\n");

int main()
{


// print the name
    STAMPA_NOME(Simone Torrengo);

    char categoria[3];
    double peso, recuperabile, irrecuperabile;
    double percentualeRiciclabile;


// insert category
    printf("Inserisci la categoria del dispositivo (R1, R2, R3, R4, R5): ");
    scanf("%s", categoria);

//insert weight
    printf("Inserisci il peso del dispositivo elettronico in kg: ");
    scanf("%lf", &peso);  // Usa %lf per leggere un valore double

    NEW_LINE;

// decide the percentage of recoverable material by category
    if (strcmp(categoria, "R1") == 0) {
        percentualeRiciclabile = 0.85;
    } else if (strcmp(categoria, "R2") == 0) {
        percentualeRiciclabile = 0.75;
    } else if (strcmp(categoria, "R3") == 0) {
        percentualeRiciclabile = 0.65;
    } else if (strcmp(categoria, "R4") == 0) {
        percentualeRiciclabile = 0.50;
    } else if (strcmp(categoria, "R5") == 0) {
        percentualeRiciclabile = 0.40;
    } else {
        printf("Categoria non valida!\n");
        return 1; // Exit the program in case of failure
    }

// calculating the weights 
    recuperabile = peso * percentualeRiciclabile;
    irrecuperabile = peso - recuperabile;

// print the result
    printf("Peso Totale: %.2lf kg\n", peso);

    printf("Peso recuperabile: %.2lf kg\n", recuperabile);

    printf("Peso del materiale irrecuperabile: %.2lf kg\n", irrecuperabile);

    printf("Grazie per aver usato il nostro programma.");

    NEW_LINE;
    NEW_LINE;
    NEW_LINE;
    
    return 0;

}