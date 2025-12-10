#include <stdio.h>


int main() {
    int number = 0;
    FILE* read_file = fopen("input.txt", "r");
    FILE* write_file = fopen("output.txt", "w");
    if (read_file == NULL) {
        fprintf(stderr, "Cannot open read file\n");
        return -1;
    }
    if (write_file == NULL) {
        fprintf(stderr, "Cannot open write file\n");
        return -1;
    }
    fscanf(read_file, "%d", &number);
    for (int i = 0; i < number; i++)
    {
        if (i % 2 == 0)
        {
            char c = 'A' + i / 2;
            fprintf(write_file, "%c", c);
        } else
        {
            int n = 2 * ((i / 2) % 4 + 1);
            fprintf(write_file, "%d", n);
        }
    }
    fprintf(write_file, "\n");
    
    fclose(read_file);
    fclose(write_file);
    
    return 0;
}
