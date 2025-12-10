#include <stdio.h>
#include <stdlib.h>

enum {ARR_SIZE = 1001};

int count_symbol(char *str, int sz, char c)
{
    int count = 0;
    for (int i = 0; i < sz; i++)
    {
        if (c == str[i])
        {
            count++;
        }
    }
    return count;
}

int filter_str(char *dest, char *str, int sz)
{
    int dest_sz = 0;
    for (int i = 0; i < sz; i++)
    {
        if (str[i] == ' ')
        {
            continue;
        }
        if (count_symbol(dest, dest_sz, str[i]) > 0)
        {
            continue;
        }
        dest[dest_sz] = str[i];
        dest_sz++;
        dest[dest_sz] = '\0';
    }
    return dest_sz;
}


int main()
{
    int lowercase_count = 0;
    int uppercase_count = 0;
    int sz = 0;
    char str[ARR_SIZE];
    char res[ARR_SIZE];
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
    int res_sz = filter_str(res, str, sz);
    fprintf(write_file, "%s\n", res);
    fclose(read_file);
    fclose(write_file);
    return 0;
}
