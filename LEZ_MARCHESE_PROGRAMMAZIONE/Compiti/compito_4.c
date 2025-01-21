/*Scrivere un programma in C che:

Legga da tastiera il giorno della settimana (come stringa) e la spesa effettuata in quel giorno.
Usi una macro per calcolare l'IVA (22%) sulla spesa.
Usi una struttura di controllo if-else per distinguere i giorni feriali da quelli festivi.
Stampi il totale delle spese con e senza IVA, specificando se il giorno è feriale o festivo.
*/

#include <stdio.h>
#include <string.h>

//define for iva
#define IVA(x) ((x) * 0.22)
#define NEW_LINE printf("\n");

int main() {

/*giorno will be used to do the strcmp 
with festivo later */   
    char giorno[20];
    float spesa, spesa_con_iva, iva;

// array di puntatori di stringhe costante 
    const char *festivi[] = {"domenica", "sabato"};
    int is_festivo = 0;

//printf for the day of the week
    printf("Inserisci il giorno della settimana: ");
    scanf("%s", giorno);

        NEW_LINE;

//printf for the expence
    printf("Inserisci la spesa effettuata in %s: ", giorno);
    scanf("%f", &spesa);

        NEW_LINE;

// calculating IVA and total cost plus iva
    iva = IVA(spesa);
    spesa_con_iva = spesa + iva;

// check if the day is festivo
// for check the array festivi[], checking all of the elemnts
// strcmp compare giorno and festivo
// if it gives 0 it means that the 2 strings are equals
    for (int i = 0; i < 2; i++) {
        if (strcmp(giorno, festivi[i]) == 0) {
            is_festivo = 1;
            break;
        }
    }

// ciclo di print per giorno festivo se no feriale
    if (is_festivo) {
        printf("Il giorno %s è festivo.\n", giorno);
    } else {
        printf("Il giorno %s è feriale.\n", giorno);
    }

// print della spesa, iva e spesa totale
    printf("Spesa senza IVA: %.2f\n", spesa);
    printf("IVA (22%%): %.2f\n", iva);
    printf("Totale spesa con IVA: %.2f\n", spesa_con_iva);

    NEW_LINE;
    NEW_LINE;
    return 0;
}