#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <stdbool.h>

#define SIZE 6
#define MAX_LEN 50

int count_strings_starting_with_A_or_a(char strings[][MAX_LEN], int size);
int count_strings_with_numbers(char strings[][MAX_LEN], int size);
void find_longest_and_shortest(char strings[][MAX_LEN], int size, char longest[], char shortest[]);
bool is_palindrome(const char *str);
int count_palindromes(char strings[][MAX_LEN], int size);
void get_palindromes(char strings[][MAX_LEN], int size, char palindromes[][MAX_LEN], int *palindrome_count);
void sort_strings_by_length(char strings[][MAX_LEN], int size);
bool all_strings_longer_than_five(char strings[][MAX_LEN], int size);
bool all_strings_have_vowel(char strings[][MAX_LEN], int size);

#endif
