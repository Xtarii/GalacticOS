#include "screen.h"
#include "ports.h"

// ==========================
// Private method ( decl )
// ==========================

int get_offset(int, int);
int get_cursor_offset();
void set_cursor_offset(int);
int get_offset_col(int);
int get_offset_row(int);

int print_char(char, int, int, int);



// ==========================
// Public kernel API methods
// ==========================

void kprint_at(char *str, int col, int row) {
    int offset;
    if(col >= 0 && row >= 0) {
        offset = get_offset(col, row);
    } else {
        offset = get_cursor_offset();
        col = get_offset_col(offset);
        row = get_offset_row(offset);
    }

    do {
        offset = print_char(*str, col, row, WHITE_ON_BLACK);
        col = get_offset_col(offset);
        row = get_offset_row(offset);
    }while(*str++);
}

void kprint(char *str) {
    kprint_at(str, -1, -1);
}

void clear() {
    int size = MAX_COLS * MAX_ROWS;
    char *screen = (char *)VIDEO_ADDRESS;

    for(int i = 0; i < size; i++) {
        screen[i * 2] = ' ';
        screen[i * 2 + 1] = WHITE_ON_BLACK;
    }

    set_cursor_offset(get_offset(0, 0));
}



// ==========================
// Private kernel API methods
// ==========================

int print_char(char c, int col, int row, int attribute) {
    unsigned char *vidmem = (unsigned char*) VIDEO_ADDRESS;
    if(!attribute) attribute = WHITE_ON_BLACK;

    if(col >= MAX_COLS || row >= MAX_ROWS) {
        vidmem[2 * (MAX_COLS) * (MAX_ROWS) - 2] = 'E';
        vidmem[2 * (MAX_COLS) * (MAX_ROWS) - 1] = RED_ON_WHITE;
        return get_offset(col, row);
    }

    int offset;
    if(col >= 0 && row >= 0) offset = get_offset(col, row);
    else offset = get_cursor_offset();

    if(c == '\n') {
        row = get_offset_row(offset);
        offset = get_offset(0, row + 1);
    }else {
        vidmem[offset] = c;
        vidmem[offset + 1] = attribute;
        offset += 2;
    }

    set_cursor_offset(offset);
    return offset;
}

int get_cursor_offset() {
    pbout(REG_SCREEN_CTRL, 14);
    int offset = pbin(REG_SCREEN_DATA) << 8;
    pbout(REG_SCREEN_CTRL, 15);
    offset += pbin(REG_SCREEN_DATA);
    return offset * 2;
}

void set_cursor_offset(int offset) {
    offset /= 2;
    pbout(REG_SCREEN_CTRL, 14);
    pbout(REG_SCREEN_DATA, (unsigned char)(offset >> 8));
    pbout(REG_SCREEN_CTRL, 15);
    pbout(REG_SCREEN_DATA, (unsigned char)(offset & 0xff));
}

int get_offset(int col, int row) { return 2 * (row * MAX_ROWS + col); }
int get_offset_col(int offset) { return offset / (2 * MAX_COLS); }
int get_offset_row(int offset) {
    return (offset - (get_offset_row(offset) * 2 * MAX_COLS)) / 2;
}
