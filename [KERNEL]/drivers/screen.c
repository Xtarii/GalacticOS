#include "screen.h"
#include "ports.h"
#include "../utilities/utils.h"

// ==========================
// Private method ( decl )
// ==========================

int get_offset(int, int);
int get_cursor_offset();
void set_cursor_offset(int);
int get_offset_col(int);
int get_offset_row(int);

int scroll_if_needed(int);



// ==========================
// Public kernel API methods
// ==========================

void clear() {
    int size = MAX_COLS * MAX_ROWS;
    unsigned char *screen = (unsigned char*)VIDEO_ADDRESS;

    for(int i = 0; i < size; i++) {
        screen[i * 2] = ' ';
        screen[i * 2 + 1] = WHITE_ON_BLACK;
    }

    set_cursor_offset(get_offset(0, 0));
}

int kput_char(char c, int col, int row, int attribute) {
    unsigned char *video = (unsigned char*)VIDEO_ADDRESS;
    if(!attribute) attribute = WHITE_ON_BLACK;

    if(col >= MAX_COLS || row >= MAX_ROWS) {
        col = MAX_COLS - 1;
        row = MAX_ROWS - 1;
        return kput_char('E', col, row, RED_ON_WHITE);
    }

    int offset;
    if(col >= 0 && row >= 0) offset = get_offset(col, row);
    else offset = get_cursor_offset();

    if(c == '\n') {
        row = get_offset_row(offset);
        offset = get_offset(0, row + 1);
    }else {
        video[offset] = c;
        video[offset + 1] = attribute;
        offset += 2;
    }

    offset -= scroll_if_needed(offset);
    set_cursor_offset(offset);
    return offset;
}

void kprint_at(const char *str, int col, int row) {
    int offset;
    if(col >= 0 && row >= 0) {
        offset = get_offset(col, row);
    } else {
        offset = get_cursor_offset();
        col = get_offset_col(offset);
        row = get_offset_row(offset);
    }

    while(*str) {
        offset = kput_char(*str, col, row, WHITE_ON_BLACK);
        col = get_offset_col(offset);
        row = get_offset_row(offset);
        str++;
    }
}

void kprint(const char *str) {
    kprint_at(str, -1, -1);
}



// ==========================
// Private kernel API methods
// ==========================

int scroll_if_needed(int scroll) {
    if(scroll < MAX_ROWS * MAX_COLS * 2) return 0;

    for(int i = 0; i < MAX_ROWS; i++) {
        int sa = get_offset(0, i) + VIDEO_ADDRESS;
        void *src = (void*)((long)get_offset(0, i)) + VIDEO_ADDRESS;
        void *dst = (void*)((long)get_offset(0, i - 1)) + VIDEO_ADDRESS;
        kmemcpy(src, dst, MAX_COLS * 2);
    }

    char *last = (char *)((long)get_offset(0, MAX_ROWS - 1)) + VIDEO_ADDRESS;
    for(int i = 0; i < MAX_COLS * 2; i++) last[i] = 0;

    return 2 * MAX_COLS;
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





int get_offset(int col, int row) { return 2 * (row * MAX_COLS + col); }
int get_offset_row(int offset) { return offset / (2 * MAX_COLS); }
int get_offset_col(int offset) {
    return (offset - (get_offset_row(offset) * 2 * MAX_COLS)) / 2;
}
