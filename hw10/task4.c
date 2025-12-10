#include <stdio.h>
#include <string.h>

enum { ENGLISH_SYMBOLS = 26};

void print_same_symbols(FILE* output, char *first, char *second)
{
    int symbol_count_first[ENGLISH_SYMBOLS] = {0};
    int symbol_count_second[ENGLISH_SYMBOLS] = {0};
    for (int i = 0; i < strlen(first); i++)
    {
        symbol_count_first[first[i] - 'a']++;
    }
    for (int i = 0; i < strlen(second); i++)
    {
        symbol_count_second[second[i] - 'a']++;
    }
    for (int i = 0; i < ENGLISH_SYMBOLS; i++)
    {
        if (symbol_count_first[i] == 1 && symbol_count_second[i] == 1)
        {
            fprintf(output, "%c ", i + 'a');
        }
    }
    
}

int main() {
    int sz = 0;
    char first[101];
    char second[101];
    FILE* read_file = fopen("input.txt", "r");
    FILE* write_file = fopen("output.txt", "w");
    if (read_file == NULL) {
        fprintf(stderr, "Cannot open read file\n");
        return -1;
    }
    if (write_file == NULL) {
        fprintf(stderr, "Cannot open write file\n");
        fclose(read_file);
        return -1;
    }
    fscanf(read_file, "%100s %100s", first, second);
    print_same_symbols(write_file, first, second);

    fclose(read_file);
    fclose(write_file);
    return 0;
}
