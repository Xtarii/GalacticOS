#ifndef GALACTIC_SCREEN_H
#define GALACTIC_SCREEN_H

/**
 * Video address pointer
 */
#define VIDEO_ADDRESS 0xb8000
/**
 * Screen max rows
 */
#define MAX_ROWS 25
/**
 * Max columns
 */
#define MAX_COLS 80



/**
 * White text on black background
 */
#define WHITE_ON_BLACK 0x0f
/**
 * Red text on white background
 */
#define RED_ON_WHITE 0xf4



/**
 * Screen control ( I/O port )
 */
#define REG_SCREEN_CTRL 0x3d4
/**
 * Screen data ( I/O port )
 */
#define REG_SCREEN_DATA 0x3d5



/**
 * Clears the screen buffer
 */
void clear();

/**
 * Puts character on kernel screen at position
 *
 * @return The new cursor offset
 */
int kput_char(char c, int col, int row, int attribute);



/**
 * Prints message to kernel screen at position.
 * Column / Row position.
 */
void kprint_at(const char*, int, int);

/**
 * Prints string to kernel screen
 */
void kprint(const char*);

#endif // GALACTIC_SCREEN_H
