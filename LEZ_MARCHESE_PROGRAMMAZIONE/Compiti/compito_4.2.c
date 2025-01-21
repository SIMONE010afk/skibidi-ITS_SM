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
#include <time.h>

//define or comment these #define to apply/disable the funciots
#define CALCOLO_PENALE
#define DEBUG

//macro to calculate the fine (10%) if u pay late 
#define CALCOLA_PENALE(x) ((x) * 0.10)

int calcola_differenza_giorni(int anno1, int mese1, int giorno1, int anno2, int mese2, int giorno2);

//expence of the month
#define SOGLIA 1000.0

#define NEW_LINE printf("\n");

int main() {

    float elettricita, acqua, gas, internet;
    float totale = 0.0, penale = 0.0;

//calculating dates of payment
    int giorno_pagamento, mese_pagamento, anno_pagamento;
    int giorno_dovuto, mese_dovuto, anno_dovuto;
    int giorni_di_ritardo;

// Input expences
    printf("Inserisci la spesa per l'elettricità: ");
    scanf("%f", &elettricita);
    printf("Inserisci la spesa per l'acqua: ");
    scanf("%f", &acqua);
    printf("Inserisci la spesa per il gas: ");
    scanf("%f", &gas);
    printf("Inserisci la spesa per internet: ");
    scanf("%f", &internet);

//Clculating the total amount
    totale = elettricita + acqua + gas + internet;

// Input the actual date
    printf("Inserisci la data del pagamento (gg mm aaaa): ");
    scanf("%d %d %d", &giorno_pagamento, &mese_pagamento, &anno_pagamento);

// Input when the dead line is/was
    printf("Inserisci la data di scadenza del pagamento (gg mm aaaa): ");
    scanf("%d %d %d", &giorno_dovuto, &mese_dovuto, &anno_dovuto);

    NEW_LINE;

//Calculating the difference of the dates
    giorni_di_ritardo = calcola_differenza_giorni(
        anno_dovuto, mese_dovuto, giorno_dovuto,
        anno_pagamento, mese_pagamento, giorno_pagamento
    );

// If there is a delay calculate the fine
    #ifdef CALCOLO_PENALE
    if (giorni_di_ritardo > 0) {
        penale = CALCOLA_PENALE(totale);
        printf("Pagamento in ritardo di %d giorni. \nPenale calcolata: %.2f\n", giorni_di_ritardo, penale);
    } else {
        printf("Pagamento effettuato in tempo. Nessuna penale applicata.\n");
    }
    #else
    printf("Calcolo della penale disabilitato.\n");
    #endif

//Checking the total amount (with or without the fine)
    float totale_finale = totale + penale;

//Check if the total expences exceeds the SOGLIA
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

//Which is the actual input that is too high
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

//Summary of the expences
    printf("\n--- Riepilogo finale ---\n");
    printf("Elettricità: %.2f\n", elettricita);
    printf("Acqua: %.2f\n", acqua);
    printf("Gas: %.2f\n", gas);
    printf("Internet: %.2f\n", internet);
    #ifdef CALCOLO_PENALE
    printf("Penale: %.2f\n", penale);
    #endif
    printf("Totale: %.2f\n", totale_finale);


    NEW_LINE;
    NEW_LINE;
    return 0;
}

//Function to calculate the difference in days between 2 dates
int calcola_differenza_giorni(int anno1, int mese1, int giorno1, int anno2, int mese2, int giorno2) {
    struct tm data1 = {0}, data2 = {0};
    time_t t1, t2;

//Input your dates
    data1.tm_year = anno1 - 1900; // tm_year is the year from 1900
    data1.tm_mon = mese1 - 1;     // tm_mon goes from 0 to 11
    data1.tm_mday = giorno1;

    data2.tm_year = anno2 - 1900;
    data2.tm_mon = mese2 - 1;
    data2.tm_mday = giorno2;

//Convert the date in epoch time
    t1 = mktime(&data1);
    t2 = mktime(&data2);

//Calculating the difference in seconds and transform it into days
    return (int)difftime(t2, t1) / (60 * 60 * 24);
}