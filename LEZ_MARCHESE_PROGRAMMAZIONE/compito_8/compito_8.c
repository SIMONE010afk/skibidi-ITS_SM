#include <stdio.h>
#include <string.h>
#include <ctype.h>

void analyze_word(char word[]) {
    static int total_words = 0;
    static int total_vowels = 0;
    static int total_consonants = 0;
    static int total_length = 0;
    
    int vowels = 0, consonants = 0, length = 0;
    
    for (int i = 0; word[i] != '\0'; i++) {
        if (isalpha(word[i])) {
            length++;
            char lower = tolower(word[i]);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    
    total_words++;
    total_vowels += vowels;
    total_consonants += consonants;
    total_length += length;
    
    printf("Parola: %s\n", word);
    printf("Vocali: %d, Consonanti: %d\n", vowels, consonants);
    printf("Parole processate: %d\n", total_words);
    printf("Totale vocali: %d, Totale consonanti: %d\n", total_vowels, total_consonants);
    printf("Lunghezza media parole: %.2f\n", (float)total_length / total_words);
    printf("-------------------------------------\n");
}

int main() {
    char word[100];
    
    printf("Inserisci parole (digita STOP per terminare):\n");
    while (1) {
        scanf("%s", word);
        if (strcmp(word, "STOP") == 0) {
            break;
        }
        analyze_word(word);
    }
    
    printf("Programma terminato.\n");
    return 0;
}
