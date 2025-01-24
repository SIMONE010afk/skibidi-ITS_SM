/*
Scrivere un programma in C che:

legga un numero intero positivo N dall'utente e stampi un triangolo di numeri con N righe
per tutti i cicli utilizzare il for
controllare che l'input inserito dall'utente sia positivo; in caso contrario, richiedi di reinserire il valore
*/

#include <stdio.h>

#define NEW_LINE printf("\n");

int main() {

    int N;

// ask  the user to insert a positive number
    do {
        printf("Inserisci un numero intero positivo: ");
        scanf("%d", &N);
        if (N <= 0) {
            printf("Il numero deve essere positivo. Riprova.\n");
        }
    } while (N <= 0);

// print the tree of numbers
    for (int i = 1; i <= N; i++ ){ // cycle for the lines

        for (int j =1; j <= i; j++) { //cycle for the numbers in each line
            printf("%d", j);
        }
    NEW_LINE;
    }


    NEW_LINE;
    NEW_LINE;
    return 0;
}