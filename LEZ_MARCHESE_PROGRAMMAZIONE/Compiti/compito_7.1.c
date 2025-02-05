/*
Scrivere un programma in C che:

chieda all'utente due numeri interi e un'operazione da eseguire (+, -, *, /); il programma deve definire e usare quattro funzioni separate per ciascuna operazione matematica:
int add(int, int) → somma due numeri
int sub(int, int) → sottrae due numeri
int mul(int, int) → moltiplica due numeri
float divi(int, int) → divide due numeri (gestendo il caso di divisione per zero)
dopo aver preso in input i numeri e l'operazione, il programma deve chiamare la funzione corrispondente e stampare il risultato
il programma deve essere organizzato per scrivere il codice relativo alle funzioni su file separati dal main 
il programma deve presentare un menù iniziale con le seguenti opzioni (da visualizzare più volte per ripetere le operazioni):
1. Addizione (+)
2. Sottrazione (-)
3. Moltiplicazione (*)
4. Divisione (/)
5. Esci
Scegli un'operazione (1-5):
*/

#include <stdio.h>
#include <stdlib.h>
#include "compito_7.1_operazioni.h"

#define NEW_LINE printf("\n");

int main() {

    int scelta, num1, num2;
    float risultato;

    do {
        // Mostra il menu
        printf("\n--- MENU ---\n");
        printf("1. Addizione (+)\n");
        printf("2. Sottrazione (-)\n");
        printf("3. Moltiplicazione (*)\n");
        printf("4. Divisione (/)\n");
        printf("5. Esci\n");
        printf("Scegli un'operazione (1-5): ");
        scanf("%d", &scelta);

        if (scelta >= 1 && scelta <= 4) {
            // Chiede i numeri all'utente
            printf("Inserisci il primo numero: ");
            scanf("%d", &num1);
            printf("Inserisci il secondo numero: ");
            scanf("%d", &num2);
        }

                // Esegue l'operazione scelta
        switch (scelta) {
            case 1:
                risultato = add(num1, num2);
                printf("Risultato: %d + %d = %.2f\n", num1, num2, risultato);
                break;
            case 2:
                risultato = sub(num1, num2);
                printf("Risultato: %d - %d = %.2f\n", num1, num2, risultato);
                break;
            case 3:
                risultato = mul(num1, num2);
                printf("Risultato: %d * %d = %.2f\n", num1, num2, risultato);
                break;
            case 4:
                risultato = divi(num1, num2);
                printf("Risultato: %d / %d = %.2f\n", num1, num2, risultato);
                break;
            case 5:
                printf("Uscita dal programma.\n");
                break;
            default:
                printf("Scelta non valida! Riprova.\n");
        }

    } while (scelta != 5);


    NEW_LINE;
    NEW_LINE;
    return 0;
}