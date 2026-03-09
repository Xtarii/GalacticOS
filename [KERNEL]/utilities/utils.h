#ifndef GALACTIC_UTILS_H
#define GALACTIC_UTILS_H

/**
 * Value representing a true state
 */
#define true 1
/**
 * Value representing a false state
 */
#define false 0

/**
 * Null value
 */
#define null 0

/**
 * Kernel boolean type
 */
typedef int kbool;



/**
 * Copies `n` bytes from `src` to `dest`.
 */
void kmemcpy(void *src, void *dest, int bytes);

/**
 * Counts the length of the number
 *
 * This counts how many characters the number
 * would contain if it was a string.
 *
 * This will ignore the `-` sign if the
 * number is negative.
 *
 * @return The character array size of the number
 */
int numlen(int n);

/**
 * Converts int to Ascii
 */
void itoa(int n, char *buffer);

#endif // GALACTIC_UTILS_H
