#ifndef STRING_H
#define STRING_H

/**
 * Converts an integer to a character string
 */
void itoa(int, char*);

/**
 * Converts hex to a character string
 */
void htoa(int, char*);

/**
 * Reverse string
 */
void reverse(char*);

/**
 * Gets the length of the string
 *
 * @return String length
 */
int strlen(const char*);

/**
 * Compares two strings with each other
 *
 * This is `0` if the strings are equal.
 * `Negative` if `b` is greater than `a`
 * otherwise `positive`.
 *
 * @return How similar the strings are.
 */
int strcmp(const char* a, const char* b);

#endif // STRING_H
