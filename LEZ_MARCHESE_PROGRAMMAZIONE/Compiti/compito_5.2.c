/*
Scrivere un programma in C che:

simuli un semplice gioco in cui l'utente deve indovinare un numero segreto
il programma genera un numero segreto casuale tra 1 e 100
l'utente ha un numero illimitato di tentativi per indovinare il numero.
dopo ogni tentativo, il programma deve fornire un suggerimento: se il numero inserito è troppo alto, il programma deve stampare: "Troppo alto! Riprova."; se il numero inserito è troppo basso, il programma deve stampare: "Troppo basso! Riprova."
se l'utente indovina, il programma stampa: "Complimenti! Hai indovinato il numero in [X] tentativi." (dove [X] è il numero di tentativi effettuati).
il programma termina solo quando l'utente indovina il numero.
usare il ciclo do while per gestire i tentativi
utilizzare la funzione rand() per generare il numero segreto casualmente
gestire i tentativi con una variabile contatore
verificare che l'input sia valido (solo numeri interi positivi)
*/

#include <stdio.h>
#include <stdlib.h>

#define NEW_LINE printf("\n");

int main() {
    
    int numeroSegreto, tentativo, tentativi = 0;

//Rand a number from 1 to 100
    srand(1); 
    numeroSegreto = rand() % 100 + 1;

    printf("Benvenuto al gioco di indovinare il numero!\n");
    printf("Ho scelto un numero tra 1 e 100. Prova a indovinarlo!\n");

    do {
        printf("Inserisci il tuo tentativo (numero intero positivo): ");
        if (scanf("%d", &tentativo) == 1 && tentativo > 0) {
            tentativi++; // tentativi auto-increase

            if (tentativo > numeroSegreto) {
                printf("Troppo alto! Riprova.\n");
            } else if (tentativo < numeroSegreto) {
                printf("Troppo basso! Riprova.\n");
            } else {
                printf("Complimenti! Hai indovinato il numero in %d tentativi.\n", tentativi);
            }
        } else {
            printf("Errore: inserisci un numero intero positivo valido.\n");
            
        }
    } while (tentativo != numeroSegreto);

    NEW_LINE;
    NEW_LINE;
    return 0;
}