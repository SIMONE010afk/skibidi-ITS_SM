/*
Scrivere un programma in linguaggio C che deve:

definire questo array di 6 stringhe inizializzato staticamente
char strings[6][50] = {"Anna", "banana", "apple", "A1pha", "racecar", "123"};
utilizzare funzioni separate per ogni analisi richiesta
il programma deve essere organizzato per scrivere il codice relativo alle funzioni su file separati dal main
stampare:
quante stringhe iniziano con 'A' o 'a'.
quante stringhe contengono almeno un numero (0-9).
la stringa più lunga e la stringa più corta.
il numero di stringhe palindrome
le stringhe palindrome
le stringhe ordinate in modo crescente in base alla lunghezza
stampare un messaggio speciale se:
tutte le stringhe sono più lunghe di 5 caratteri.
tutte le stringhe contengono almeno una vocale (a, e, i, o, u maiuscole o minuscole).
*/

#include <stdio.h>
#include "compito_7.2.h"


int main() {
    char strings[SIZE][MAX_LEN] = {"Anna", "banana", "apple", "A1pha", "racecar", "123"};

    // Conta stringhe che iniziano con 'A' o 'a'
    printf("Stringhe che iniziano con 'A' o 'a': %d\n", count_strings_starting_with_A_or_a(strings, SIZE));

    // Conta stringhe con almeno un numero
    printf("Stringhe contenenti numeri: %d\n", count_strings_with_numbers(strings, SIZE));

    // Trova la stringa più lunga e la più corta
    char longest[MAX_LEN], shortest[MAX_LEN];
    find_longest_and_shortest(strings, SIZE, longest, shortest);
    printf("Stringa più lunga: %s\n", longest);
    printf("Stringa più corta: %s\n", shortest);

    // Conta e stampa stringhe palindrome
    printf("Stringhe palindrome: %d\n", count_palindromes(strings, SIZE));

    char palindromes[SIZE][MAX_LEN];
    int palindrome_count;
    get_palindromes(strings, SIZE, palindromes, &palindrome_count);
    for (int i = 0; i < palindrome_count; i++) {
        printf("- %s\n", palindromes[i]);
    }

    // Ordina e stampa le stringhe per lunghezza
    sort_strings_by_length(strings, SIZE);
    printf("Stringhe ordinate per lunghezza:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("- %s\n", strings[i]);
    }

    // Messaggi speciali
    if (all_strings_longer_than_five(strings, SIZE)) {
        printf("Tutte le stringhe sono più lunghe di 5 caratteri!\n");
    }
    if (all_strings_have_vowel(strings, SIZE)) {
        printf("Tutte le stringhe contengono almeno una vocale!\n");
    }

    return 0;
}


