#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <stdbool.h>

#define SIZE 6
#define MAX_LEN 50

void find_longest_and_shortest(char strings[][MAX_LEN], int size, char longest[], char shortest[]);
int count_palindromes(char strings[][MAX_LEN], int size);
void get_palindromes(char strings[][MAX_LEN], int size, char palindromes[][MAX_LEN], int *palindrome_count);
void sort_strings_by_length(char strings[][MAX_LEN], int size);
bool all_strings_longer_than_five(char strings[][MAX_LEN], int size);
bool all_strings_have_vowel(char strings[][MAX_LEN], int size);

#endif

