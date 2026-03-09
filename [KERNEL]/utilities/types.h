#ifndef GALACTIC_TYPES_H
#define GALACTIC_TYPES_H

/**
 * Unsigned 32 bit integer
 */
typedef unsigned int uint32_t;
/**
 * Signed 32 bit integer
 */
typedef signed int int32_t;

/**
 * Unsigned 16 bit integer
 */
typedef unsigned short int uint16_t;
/**
 * Signed 16 bit integer
 */
typedef signed short int int16_t;

/**
 * Unsigned 8 bit integer
 */
typedef unsigned char uint8_t;
/**
 * Signed 8 bit integer
 */
typedef signed char int8_t;



/**
 * Low 16 bit for address
 */
#define LOW_16(address) (uint16_t)((address) & 0xFFFF)
/**
 * High 16 bit for address
 */
#define HIGH_16(address) (uint16_t)(((address) >> 16) & 0xFFFF)

#endif // GALACTIC_TYPES_H
