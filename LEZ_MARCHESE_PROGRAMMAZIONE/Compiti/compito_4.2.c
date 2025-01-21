/*
1. Gestisca le spese mensili per elettricità, acqua, gas e internet.
2. Usi una macro per calcolare una penale del 10% per ritardi nei pagamenti.
3. Usi direttive come #ifdef e #ifndef per: abilitare o disabilitare il calcolo della penale in base a una configurazione.
4. Permettere il debug del programma stampando informazioni aggiuntive.
5. Determini se la spesa totale supera una soglia predefinita e stampi un messaggio con if-else.
6. Offra suggerimenti di risparmio utilizzando uno switch.
7. Stampi un riepilogo finale con tutte le informazioni.
*/

#include <stdio.h>

//define or comment these #define to apply/disable the funciots
#define CALCOLO_PENALE
#define DEBUG

//macro to calculate the fine (10%) if u pay late 
#define CALCOLA_PENALE(x) ((x) * 0.10)

//expence of the month
#define SOGLIA 1000.0

#define NEW_LINE printf("\n");

int main() {

    float elettricita, acqua, gas, internet;
    float totale = 0.0, penale = 0.0;

// Input delle spese
    printf("Inserisci la spesa per l'elettricità: ");
    scanf("%f", &elettricita);
    printf("Inserisci la spesa per l'acqua: ");
    scanf("%f", &acqua);
    printf("Inserisci la spesa per il gas: ");
    scanf("%f", &gas);
    printf("Inserisci la spesa per internet: ");
    scanf("%f", &internet);

// Calcolo del totale
    totale = elettricita + acqua + gas + internet;

    #ifdef CALCOLO_PENALE

// Calcolo della penale per ritardi nei pagamenti
    penale = CALCOLA_PENALE(totale);
    #ifdef DEBUG
    printf("[DEBUG] Penale calcolata: %.2f\n", penale);
    #endif
    #else
    #ifdef DEBUG
    printf("[DEBUG] Calcolo della penale disabilitato.\n");
    #endif
    #endif

// Determinazione della spesa totale (con o senza penale)
    float totale_finale = totale + penale;

//Check if the total expence exceeds the SOGLIA
    if (totale_finale > SOGLIA) {
        printf("Attenzione: La spesa totale (%.2f) supera la soglia di %.2f!\n", totale_finale, SOGLIA);
    } else {
        printf("La spesa totale (%.2f) è entro la soglia di %.2f.\n", totale_finale, SOGLIA);
    }

// Saving tips
    printf("\nSuggerimenti di risparmio:\n");
    int categoria_maggiore = 0; 
// 1=elettricità, 2=acqua, 3=gas, 4=internet
    float spesa_maggiore = 0;

    if (elettricita > spesa_maggiore) { spesa_maggiore = elettricita; categoria_maggiore = 1; }
    if (acqua > spesa_maggiore) { spesa_maggiore = acqua; categoria_maggiore = 2; }
    if (gas > spesa_maggiore) { spesa_maggiore = gas; categoria_maggiore = 3; }
    if (internet > spesa_maggiore) { spesa_maggiore = internet; categoria_maggiore = 4; }

    switch (categoria_maggiore) {
        case 1:
            printf("Riduci il consumo di elettricità.\n");
            break;
        case 2:
            printf("Risparmia acqua controllando eventuali perdite.\n");
            break;
        case 3:
            printf("Ottimizza il consumo di gas.\n");
            break;
        case 4:
            printf("Valuta un piano internet più economico.\n");
            break;
        default:
            printf("Tutte le spese sembrano equilibrate.\n");
            break;
    }

// Riepilogo finale
    printf("\n--- Riepilogo finale ---\n");
    printf("Elettricità: %.2f\n", elettricita);
    printf("Acqua: %.2f\n", acqua);
    printf("Gas: %.2f\n", gas);
    printf("Internet: %.2f\n", internet);
    #ifdef CALCOLO_PENALE
    printf("Penale: %.2f\n", penale);
    #endif
    printf("Totale (con penale, se applicabile): %.2f\n", totale_finale);


    NEW_LINE;
    NEW_LINE;
    return 0;
}