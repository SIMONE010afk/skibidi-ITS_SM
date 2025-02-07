#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>


#define SIZE 7
#define MAX_LEN 20

//1 how many strings start with a vowel
void count_vowel_start(char words[][MAX_LEN]) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        char first = tolower(words[i][0]);
        if (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') {
            count++;
        }
    }
    printf("Numero di stringhe che iniziano con una vocale: %d\n", count);
}

//2 how many strings contains at least a number
void count_strings_with_numbers(char words[][MAX_LEN]) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; words[i][j] != '\0'; j++) {
            if (isdigit(words[i][j])) {
                count++;
                break;
            }
        }
    }
    printf("Numero di stringhe con almeno un numero: %d\n", count);
}

//3 find the shortest and the longest string
void find_longest_and_shortest(char words[][MAX_LEN]) {
    int min_idx = 0, max_idx = 0;
    for (int i = 1; i < SIZE; i++) {
        if (strlen(words[i]) < strlen(words[min_idx])) {
            min_idx = i;
        }
        if (strlen(words[i]) > strlen(words[max_idx])) {
            max_idx = i;
        }
    }
    printf("Stringa piu' lunga: \"%s\"\n", words[max_idx]);
    printf("Stringa piu' corta: \"%s\"\n", words[min_idx]);
}

//4 how many are palindromes
    //check if plindrome and then count
bool is_palindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - 1 - i])) {
            return false;
        }
    }
    return true;
}


void count_palindromes(char words[][MAX_LEN]) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (is_palindrome(words[i])) {
            count++;
        }
    }
    printf("Numero di stringhe palindrome: %d\n", count);
}

//5 total number of the char in the strings
void count_total_characters(char words[][MAX_LEN]) {
    int total = 0;
    for (int i = 0; i < SIZE; i++) {
        total += strlen(words[i]);
    }
    printf("Numero totale di caratteri: %d\n", total);
}

//6 print in the corrent order and the other way
int compare(const void *a, const void *b) {
    return strlen((char *)a) - strlen((char *)b);  // Confronta le lunghezze
}

void print_original_order(char words[][MAX_LEN]) {
    //organize the words
    qsort(words, SIZE, MAX_LEN, compare);

    //print the words for lengh
    printf("Elenco delle stringhe ordinate per lunghezza:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%s\n", words[i]);
    }
}

void print_reverse_order(char words[][MAX_LEN]) {
    printf("Elenco delle stringhe in ordine inverso:\n");
    for (int i = SIZE - 1; i >= 0; i--) {
        printf("%s\n", words[i]);  // Stampa ogni parola su una nuova riga
    }
}

//7 other way plus swapping chars
void print_reverse_order_with_reversed_strings(char words[][MAX_LEN]) {
    printf("Elenco delle stringhe in ordine inverso con caratteri invertiti:\n");
    for (int i = SIZE - 1; i >= 0; i--) {
        // Stampa la parola invertita
        for (int j = strlen(words[i]) - 1; j >= 0; j--) {
            putchar(words[i][j]);  // Stampa carattere per carattere
        }
        printf("\n");  // Vai a capo dopo ogni parola invertita
    }
}