#include <stdio.h>
#include "operazioni_funz.h" //to include the file where i wrote the functions

/*used to quicker go to a new line, 
i used it in the end to put some space from the default messages*/
#define NEW_LINE printf("\n");  

int main() {

    int choice, num1, num2;
    int numbers[] = {2, 4, 6, 8, 10};
    int size = sizeof(numbers) / sizeof(numbers[0]);


    while (1) {

        //showing the menu to the user
        printf("\nScegli un'operazione:\n");
        printf("1. Addizione (+)\n");
        printf("2. Sottrazione (-)\n");
        printf("3. Moltiplicazione (*)\n");
        printf("4. Divisione (/)\n");
        printf("5. Modulo (%%)\n");
        printf("6. Potenza (^)\n");
        printf("7. Test di tutte le funzioni\n");
        printf("8. Esci\n");
        printf("Opzione (1-8): ");
        scanf("%d", &choice);

        //exit choice
        if (choice == 8) {
            printf("Uscita dal programma.\n");
            break;
        }

        //the user can now chose if to use his numbers or default ones using sub_choice declared later
        if (choice == 7) {
        int sub_choice;
        printf("\nVuoi usare: \n1. I numeri predefiniti che sono {2, 4, 6, 8, 10}\n2. Due numeri a scelta\nOpzione (1-2): ");
        scanf("%d", &sub_choice);
            
        if (sub_choice == 1) { //default numbers 
            test_all_operations(numbers, size);
        } else if (sub_choice == 2) { //his numbers
            printf("Inserisci due numeri: ");
            scanf("%d %d", &num1, &num2);
            int custom_numbers[] = {num1, num2};
            test_all_operations(custom_numbers, 2);
        } else {
            printf("Scelta non valida. Ritorno al menu principale.\n");
        }
            continue;
        }

        switch (choice) {
            case 1: //add
                printf("Inserisci due numeri: ");
                scanf("%d %d", &num1, &num2);
                printf("%d + %d = %d\n", num1, num2, add(num1, num2));
                break;
            case 2: //sub
                printf("Inserisci due numeri: ");
                scanf("%d %d", &num1, &num2);
                printf("%d - %d = %d\n", num1, num2, sub(num1, num2));
                break;
            case 3: //mul
                printf("Inserisci due numeri: ");
                scanf("%d %d", &num1, &num2);
                printf("%d * %d = %d\n", num1, num2, mul(num1, num2));
                break;
            case 4: //divi
                printf("Inserisci due numeri: ");
                scanf("%d %d", &num1, &num2);
                printf("%d / %d = %.2f\n", num1, num2, divi(num1, num2));
                break;
            case 5: //mod
                printf("Inserisci due numeri: ");
                scanf("%d %d", &num1, &num2);
                printf("%d %% %d = %d\n", num1, num2, mod(num1, num2));
                break;
            case 6: //power
                printf("Inserisci due numeri: ");
                scanf("%d %d", &num1, &num2);
                printf("%d ^ %d = %d\n", num1, num2, power(num1, num2));
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }
    }

    NEW_LINE;
    NEW_LINE;
    return 0;
}
