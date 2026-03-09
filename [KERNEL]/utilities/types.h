#ifndef GALACTIC_TYPES_H
#define GALACTIC_TYPES_H

/**
 * Unsigned 32 bit integer
 */
typedef unsigned int uint32;
/**
 * Signed 32 bit integer
 */
typedef signed int int32;

/**
 * Unsigned 16 bit integer
 */
typedef unsigned short int uint16;
/**
 * Signed 16 bit integer
 */
typedef signed short int int16;

/**
 * Unsigned 8 bit integer
 */
typedef unsigned char uint8;
/**
 * Signed 8 bit integer
 */
typedef signed char int8;



/**
 * Low 16 bit for address
 */
#define LOW_16(address) (uint16)((address) & 0xFFFF)
/**
 * High 16 bit for address
 */
#define HIGH_16(address) (uint16)(((address) >> 16) & 0xFFFF)

#endif // GALACTIC_TYPES_H
