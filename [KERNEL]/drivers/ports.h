#ifndef GALACTIC_PORTS
#define GALACTIC_PORTS

/**
 * Reads byte from specified port ( port byte in )
 *
 * @return Byte
 */
unsigned char pbin(unsigned short);

/**
 * Outputs byte on specifed port ( port byte out )
 */
void pbout(unsigned short, unsigned char);

/**
 * Reads word from specifed port ( port word in )
 *
 * @return Word from port in
 */
unsigned short pwin(unsigned short);

/**
 * Outputs word on specifed port ( port word out )
 */
void pwout(unsigned short, unsigned short);

#endif // GALACTIC_PORTS
