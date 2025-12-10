#include <stdio.h>
#include <string.h>
enum { ARR_SIZE = 10001 };

int is_lowercase_letter(char c)
{
    return 'a' <= c && c <= 'z';
}

int is_uppercase_letter(char c)
{
    return 'A' <= c && c <= 'Z';
}

int main() {
    int lowercase_count = 0;
    int uppercase_count = 0;
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
        if (is_lowercase_letter(str[i]))
        {
            lowercase_count++;
        }
        if (is_uppercase_letter(str[i]))
        {
            uppercase_count++;
        }
    }
    fprintf(write_file, "%d %d\n", lowercase_count, uppercase_count);
    fclose(read_file);
    fclose(write_file);
    return 0;
}
