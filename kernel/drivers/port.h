#ifndef _GALACTIC_PORT
#define _GALACTIC_PORT

/**
 * Reads byte input from port
 *
 * @return Byte value
 */
unsigned char pbin(unsigned short);

/**
 * Writes byte to port
 */
void pbout(unsigned short, unsigned char);



/**
 * Reads word input from port
 *
 * @return Word value
 */
unsigned short pwin(unsigned short);

/**
 * Writes word to port
 */
void pwout(unsigned short, unsigned short);

#endif // _GALACTIC_PORT
