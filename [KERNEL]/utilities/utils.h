#ifndef GALACTIC_UTILS
#define GALACTIC_UTILS

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
 * Copies `n` bytes from `src` to `dest`.
 */
void kmemcpy(void *src, void *dest, int bytes);

#endif // GALACTIC_UTILS
