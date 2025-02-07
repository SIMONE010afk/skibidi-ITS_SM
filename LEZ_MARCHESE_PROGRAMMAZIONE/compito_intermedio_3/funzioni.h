#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// Funzione per scegliere una parola casuale
void choose_random_word(char word[], char words[][20], int word_count) {
    int random_index = rand() % word_count;
    strcpy(word, words[random_index]);
}

// Funzione per stampare lo stato attuale della parola
void print_word_state(char word[], char hidden_word[]) {
    for (int i = 0; i < strlen(word); i++) {
        printf("%c ", hidden_word[i]);
    }
    printf("\n");
}
// Funzione per verificare se un carattere è già stato indovinato
int already_guessed(char guessed[], int guessed_count, char guess) {
    for (int i = 0; i < guessed_count; i++) {
        if (guessed[i] == guess) {
            return 1;  // La lettera è già stata provata
        }
    }
    return 0;  // La lettera non è stata provata
}