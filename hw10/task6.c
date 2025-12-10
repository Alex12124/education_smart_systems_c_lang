#include <stdio.h>
#include <string.h>
enum { ARR_SIZE = 1001 };

int is_palindrom(char *str)
{
    int sz = strlen(str);
    for (int i = 0; i < sz / 2; i++)
    {
        if (str[i] != str[sz - i - 1])
        {
            return 0;
        }
        
    }
    return 1;
}

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

    fscanf(read_file, "%1000s", str);
    if (is_palindrom(str))
    {
        fprintf(write_file, "YES\n");
    } else
    {
        fprintf(write_file, "NO\n");
    }
    fclose(read_file);
    fclose(write_file);
    return 0;
}
