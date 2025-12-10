#include <stdio.h>
#include <string.h>

enum {ARR_SIZE = 1001};


int main() {
    int sz = 0;
    int count = 0;
    char str[ARR_SIZE];
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

    while (1)
    {
        int n = fscanf(read_file, "%1000s", str);
        if (n <= 0)
        {
            break;
        }
        if (str[strlen(str) - 1] == 'a')
        {
            count++;
        }
    }
    fprintf(write_file, "%d\n", count);
    fclose(read_file);
    fclose(write_file);
    return 0;
}
