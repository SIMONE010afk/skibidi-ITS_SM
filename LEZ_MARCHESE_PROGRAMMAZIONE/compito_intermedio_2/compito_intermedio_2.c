#include "funzioni.h"

/*used to quicker go to a new line, 
i used it in the end to put some space from the default messages*/
#define NEW_LINE printf("\n"); 

int main() {
    char words[SIZE][MAX_LEN] = {"elephant", "42trees", "Anna", "oasis", "civic", "mango", "Galaxy"};
    char words_mine[SIZE][MAX_LEN] = {"GIB", "simo", "zocca", "maledettoes4", "ire", "eli", "citchatting"};
    int scelta;

    do {
        printf("VUOI USARE LE PAROLE SCELTE DAL PROF (1) O QUELLE SCELTE DA ME (2)?");
        scanf("%d", &scelta);
    } while (scelta != 1 && scelta != 2);


    if (scelta == 1) { //default words
        count_vowel_start(words);
        count_strings_with_numbers(words);
        find_longest_and_shortest(words);
        count_palindromes(words);
        count_total_characters(words);
        print_original_order(words);
        print_reverse_order(words);
        print_reverse_order_with_reversed_strings(words);
    } else if (scelta == 2) { //my words
        count_vowel_start(words_mine);
        count_strings_with_numbers(words_mine);
        find_longest_and_shortest(words_mine);
        count_palindromes(words_mine);
        count_total_characters(words_mine);
        print_original_order(words_mine);
        print_reverse_order(words_mine);
        print_reverse_order_with_reversed_strings(words_mine);
    }
/*
    count_vowel_start(words);
    count_strings_with_numbers(words);
    find_longest_and_shortest(words);
    count_palindromes(words);
    count_total_characters(words);
    print_original_order(words);
    print_reverse_order(words);
    print_reverse_order_with_reversed_strings(words);
*/
    NEW_LINE;
    NEW_LINE;
    
    return 0;
}