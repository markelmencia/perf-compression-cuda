#include <stdio.h>
#include <stdlib.h>

char* get_rotation_table(char* input, int length) {
    char *result = malloc(sizeof(char) * (length * length));
    for (int row = 0; row < length; row++) {
        for (int col = 0; col < length; col++) {
            result[col + (row * length)] = input[((row + col) % length)];
        }
    }
    return result;
}

int main() {
    // Input MUST Include a null character
    char* input = "BANANA";
    char* teburu = get_rotation_table(input, 7);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%c", teburu[j + (i * 7)]);
        }
        printf("\n");
    }
}

void bwt_transform() {
    
}