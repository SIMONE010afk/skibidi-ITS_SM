#include "funzioni.h"

/*used to quicker go to a new line, 
i used it in the end to put some space from the default messages*/
#define NEW_LINE printf("\n"); 

int main() {
    char words[SIZE][MAX_LEN] = {"elephant", "42trees", "Anna", "oasis", "civic", "mango", "Galaxy"};
    
    count_vowel_start(words);
    count_strings_with_numbers(words);
    find_longest_and_shortest(words);
    count_palindromes(words);
    count_total_characters(words);
    print_original_order(words);
    print_reverse_order(words);
    print_reverse_order_with_reversed_strings(words);

    NEW_LINE;
    NEW_LINE;
    
    return 0;
}