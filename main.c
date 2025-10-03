#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

char** get_rotation_table(char* input, int length) {
    char **result = malloc(sizeof(char*) * length);
    for (int row = 0; row < length; row++) {
        char* row_string = malloc(sizeof(char) * length);
        for (int col = 0; col < length; col++) {
            row_string[col] = input[((row + col) % length)];
        }
        result[row] = row_string;
    }

    return result;
}

// Lexicographically compares two strings.
int cmp_lex(const void* a, const void* b) {  
    // First, void pointers a and b (which are meant to be strings) 
    // are casted into string pointers (char**). Then, their string 
    // values are obtained with *(char**)a and *(char**)b and are
    // passed as arguments to strcmp.

    return strcmp(*(char**)a, *(char**)b); 
} 

// Sorts the given table lexicographically.
void sort_lexical_order(char** table, int length) {
    qsort(table, length, sizeof(char*), cmp_lex);
}

int main() {
    // Input MUST Include a null character
    char* input = "BANANA&";
    char** table = get_rotation_table(input, 7);

    sort_lexical_order(table, 7);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%c", table[i][j]);
        }
        free(table[i]);
        printf("\n");
    }
    free(table);
}

void bwt_transform() {
    
}