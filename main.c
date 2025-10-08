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

char* get_output_string(char** table, int length) {
    char* output = malloc(sizeof(char) * (length + 1));
    for (int row = 0; row < length; row++) {
        output[row] = table[row][length - 1];
    }
    output[length] = 0;
    return output;
}


char* bwt_transform(char *input, int length) {
    char** table = get_rotation_table(input, length);
    sort_lexical_order(table, length);
    char *output = get_output_string(table, length);
    for (int i = 0; i < length; i++) {
        free(table[i]);
    }
    free(table);
    return output;
}

int main() {
    // Input MUST Include a null character
    char* input = "SIX.MIXED.PIXIES.SIFT.SIXTY.PIXIE.DUST.BOXEES&";
    int length = strlen(input);
    char* output = bwt_transform(input, length);
    printf("%s\n", output);
    free(output);
}
