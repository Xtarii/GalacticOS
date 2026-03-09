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
 * Converts int to Ascii
 */
void itoa(int n, char *buffer);

#endif // GALACTIC_UTILS_H
