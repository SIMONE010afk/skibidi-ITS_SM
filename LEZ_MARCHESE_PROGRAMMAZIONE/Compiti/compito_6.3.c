/*
Scrivere un programma in C che:

Definisca questo array di 6 stringhe inizializzato staticamente:
 
 {"apple", "banana", "123hello", "Aardvark", "racecar", "world"}
      

Analizzi le stringhe e stampi:
Quante stringhe iniziano con la lettera 'A' o 'a'.
Quante stringhe contengono almeno un numero (0-9).
La stringa più lunga e la stringa più corta.
Il numero di stringhe palindrome (uguali se lette al contrario).
Stampi un messaggio se tutte le stringhe sono lunghe più di 5 caratteri o se tutte le stringhe contengono almeno una vocale.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NEW_LINE printf("\n");

int main() {

    char *array[6][20] = {"apple", "banana", "123hello", "Aardvark", "racecar", "world"};

    int contA = 0, conta = 0, contn = 0;
    int max = 0, min = 0, countPalindromes = 0;
    int maxL = 0, minL = 20;
    char *longestStr = array[0], *shortestStr = array[0];

for (int i = 0; i < 6; i++){
    if (array[i][0] == 'A')
        contA++;
    if (array[i][0] == 'a')
        conta++;

// Controllo se è una parola palindroma
    int len = strlen(array[i]);
    int isPalindrome = 1;

    for (int j = 0; j < len / 2; j++) {
        if (array[i][j] != array[i][len - j - 1]) {
            isPalindrome = 0;
            break;
        }
    }
        if (isPalindrome) {
            countPalindromes++;
        }

    for (int j = 0; array[i][j] != '\0'; j++){
        if (isdigit(array[i][j])){
            contn++;
            break;
        }
    }

// Controllo la stringa più lunga e la più corta
    if (strlen(array[i]) > strlen(longestStr)) {
            longestStr = array[i];
        }
    if (strlen(array[i]) < strlen(shortestStr)) {
            shortestStr = array[i];
        }
}

    max++;

// Stampa i risultati
    printf("Le stringhe che iniziano con 'A' sono: %d\n", contA);
    printf("Le stringhe che iniziano con 'a' sono: %d\n", conta);
    printf("Le stringhe che contengono un numero sono: %d\n", contn);
    printf("La stringa più lunga è: %d\n che corrisponde a: ", max);



    NEW_LINE;
    NEW_LINE;
    return 0;
}