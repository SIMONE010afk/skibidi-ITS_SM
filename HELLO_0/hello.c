// #include fa l'inclusione di tutte le funzioni per input e output
/*per commentare posso
usare anche questo modo*/

#include <stdio.h>

// int ritorna un valore intero, se ritorna a zero va tutto bene

int main() 
{
    // \n serve per spaziare dal messaggio sul terminale
    printf("hello world!!\n");

    // variable of 32 chars
    char name[32];

    // ask for a name 
    printf("Enter a name: ");

    // scanf read the input of the user
    // elenco cosa voglio leggere e cos'è che legge quindi caratteri (%s) = stringa  

    scanf("%s", name);

    // print the message with the name entered
    // \t = tabulazione
    printf("\n HEllo \t %s \n", name );



    return 0;
}