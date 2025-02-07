#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "funzioni.h"

#define MAX_TRIES 100  //max of tries
#define WORD_COUNT 6
#define MAX_GUESSES 26  

int main() {
    char words[6][20] = {"elephant", "banana", "computer", "galaxy", "puzzle", "giraffe"};
    char word[20];  // rand word
    char words_mine[6][20] = {"GIB", "simo", "zocca", "maledettoes4", "ire", "eli", "citchatting"};
    char hidden_word[20];  
    int attempts = 0;  //tries
    char guessed[MAX_GUESSES];  
    int guessed_count = 0;  

    srand(time(NULL));

    int scelta;

    // chosing who to follow
    do {
        printf("VUOI USARE LE PAROLE SCELTE DAL PROF (1) O QUELLE SCELTE DA ME (2)?");
        scanf("%d", &scelta);
    } while (scelta != 1 && scelta != 2);

    if (scelta == 1) {
    choose_random_word(word, words, 6);

    for (int i = 0; i < strlen(word); i++) {
        hidden_word[i] = '*';
    }
    hidden_word[strlen(word)] = '\0';  

    printf("Benvenuto al gioco dell'indovinello!\n");
    printf("Indovina la parola: ");

    // guess the word
    while (strcmp(word, hidden_word) != 0) {
        char guess;
        printf("\nParola attuale: ");
        print_word_state(word, hidden_word);
        printf("\nInserisci un carattere: ");
        scanf(" %c", &guess);  
        if (already_guessed(guessed, guessed_count, guess)==1) {
            printf("Hai già provato il carattere '%c'. Prova con un altro.\n", guess);
            continue;  
        }
        int found = 0;
        for (int i = 0; i < strlen(word); i++) {
            if (word[i] == guess && hidden_word[i] == '*') {
                hidden_word[i] = guess;
                found = 1;
            }
        }
        if(found==1)
        {
            printf("carattere presente nella parola bravo");
        }

        if (!found) {
            printf("Il carattere '%c' non è nella parola.\n", guess);
        }
        guessed[guessed_count] = guess;
        guessed_count++;
        attempts++;  
    }


    printf("\nCongratulazioni! Hai indovinato la parola '%s' in %d tentativi.\n", word, attempts);
    } else if (scelta == 2){


    choose_random_word(word, words_mine, 6);


    for (int i = 0; i < strlen(word); i++) {
        hidden_word[i] = '*';
    }
    hidden_word[strlen(word)] = '\0';  

    printf("Benvenuto al gioco dell'indovinello!\n");
    printf("Indovina la parola: ");


    while (strcmp(word, hidden_word) != 0) {
        char guess;
        printf("\nParola attuale: ");
        print_word_state(word, hidden_word);
        printf("\nInserisci un carattere: ");
        scanf(" %c", &guess);  
        if (already_guessed(guessed, guessed_count, guess)==1) {
            printf("Hai già provato il carattere '%c'. Prova con un altro.\n", guess);
            continue;  
        }
        int found = 0;

        for (int i = 0; i < strlen(word); i++) {
            if (word[i] == guess && hidden_word[i] == '*') {
                hidden_word[i] = guess;  
                found = 1;
            }
        }
        if(found==1)
        {
            printf("carattere presente nella parola bravo");
        }

        if (!found) {
            printf("Il carattere '%c' non è nella parola.\n", guess);
        }
        guessed[guessed_count] = guess;
        guessed_count++;
        attempts++;  
    }

    // print final tries
    printf("\nCongratulazioni! Hai indovinato la parola '%s' in %d tentativi.\n", word, attempts);
    }

    return 0;
}