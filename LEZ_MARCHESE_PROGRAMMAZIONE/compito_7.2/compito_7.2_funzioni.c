#include "compito_7.2.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Conta quante stringhe iniziano con 'A' o 'a'
int count_strings_starting_with_A_or_a(char strings[][MAX_LEN], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (strings[i][0] == 'A' || strings[i][0] == 'a') {
            count++;
        }
    }
    return count;
}

// Conta quante stringhe contengono almeno un numero
int count_strings_with_numbers(char strings[][MAX_LEN], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; strings[i][j] != '\0'; j++) {
            if (isdigit(strings[i][j])) {
                count++;
                break;
            }
        }
    }
    return count;
}

// Trova la stringa più lunga e la più corta
void find_longest_and_shortest(char strings[][MAX_LEN], int size, char longest[], char shortest[]) {
    strcpy(longest, strings[0]);
    strcpy(shortest, strings[0]);
    
    for (int i = 1; i < size; i++) {
        if (strlen(strings[i]) > strlen(longest)) {
            strcpy(longest, strings[i]);
        }
        if (strlen(strings[i]) < strlen(shortest)) {
            strcpy(shortest, strings[i]);
        }
    }
}

// Verifica se una stringa è palindroma
bool is_palindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

// Conta quante stringhe sono palindrome
int count_palindromes(char strings[][MAX_LEN], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (is_palindrome(strings[i])) {
            count++;
        }
    }
    return count;
}

// Ottiene le stringhe palindrome
void get_palindromes(char strings[][MAX_LEN], int size, char palindromes[][MAX_LEN], int *palindrome_count) {
    *palindrome_count = 0;
    for (int i = 0; i < size; i++) {
        if (is_palindrome(strings[i])) {
            strcpy(palindromes[*palindrome_count], strings[i]);
            (*palindrome_count)++;
        }
    }
}

// Ordina le stringhe in base alla lunghezza
void sort_strings_by_length(char strings[][MAX_LEN], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strlen(strings[i]) > strlen(strings[j])) {
                char temp[MAX_LEN];
                strcpy(temp, strings[i]);
                strcpy(strings[i], strings[j]);
                strcpy(strings[j], temp);
            }
        }
    }
}

// Verifica se tutte le stringhe sono più lunghe di 5 caratteri
bool all_strings_longer_than_five(char strings[][MAX_LEN], int size) {
    for (int i = 0; i < size; i++) {
        if (strlen(strings[i]) <= 5) {
            return false;
        }
    }
    return true;
}

// Verifica se tutte le stringhe contengono almeno una vocale
bool all_strings_have_vowel(char strings[][MAX_LEN], int size) {
    char vowels[] = "aeiouAEIOU";
    for (int i = 0; i < size; i++) {
        bool has_vowel = false;
        for (int j = 0; strings[i][j] != '\0'; j++) {
            if (strchr(vowels, strings[i][j])) {
                has_vowel = true;
                break;
            }
        }
        if (!has_vowel) {
            return false;
        }
    }
    return true;
}
