/**
 * Prints a string to the video memory
 */
void print(const char*);



void main() {
    // char *video_memory = (char*)0xb8000;
    // *video_memory = 'X';


    print("Hello, world!");
}



void print(const char *str) {
    char *video_memory = (char*)0xb8000;
    for(int i = 0; str[i]; i++) {
        video_memory[i] = str[i];
    }
}
