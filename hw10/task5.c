#include <stdio.h>
#include <string.h>

enum {ARR_SIZE = 1001};



int main() {
    int sz = 0;
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
    for (int c = fgetc(read_file); c != EOF; c = fgetc(read_file))
    {
        if (c == '\n')
        {
            break;
        }
        
        str[sz] = c; 
        sz++;
    }
    str[sz] = '\0';

    for (int i = 0; i < sz; i++)
    {
        if (str[i] == 'b' || str[i] == 'B')
        {
            str[i]--;
        }
        else if (str[i] == 'a' || str[i] == 'A')
        {
            str[i]++;
        }
        
    }
    fprintf(write_file, "%s", str);
    fclose(read_file);
    fclose(write_file);
    return 0;
}
