#ifndef FUNCTION_H
#define FUNCTION_H

/**
 * Marks the parameter for late usage
 *
 * Allows parameters to be used later
 * than what the compiler expects.
 */
#define LATEUSAGE(x) (void)(x)

#endif // FUNCTION_H
