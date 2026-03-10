#ifndef STRING_H
#define STRING_H

/**
 * Converts an integer to a character string
 */
void itoa(int, char*);

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
 * @return How similar the strings are.
 */
int strcmp(const char*, const char*);

#endif // STRING_H
