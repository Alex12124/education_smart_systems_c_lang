#include <stdio.h>


int main() {
    char str[101];
    int sz = 0;
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
    for (int c = fgetc(read_file); c != EOF; c = fgetc(read_file))
    {
        if (c == '\n')
        {
            continue;
        }
        
        str[sz] = c;
        sz++;
    }
    str[sz] = '\0';
    fprintf(write_file, "%s, %s, %s %d", str, str, str, sz);
    fclose(read_file);
    fclose(write_file);
    
    return 0;
}
