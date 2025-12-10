#include <stdio.h>
#include <limits.h>

enum {ARR_SIZE = 1001};


int int_max(int a, int b)
{
    return a > b ? a : b;
}

void print_longest_word(FILE* write_file, char *str, int sz)
{
    int max_len = INT_MIN;
    int max_pos = 0;
    int left = 0;
    int right = 0;
    for (; left < sz; left++)
    {
        if (str[left] != ' ')
        {
            right = left;
            for (; right < sz && str[right] != ' '; right++)
            {}
            if (right - left > max_len)
            {
                max_pos = left;
                max_len = right - left;
            }
        }
    }
    for (int i = max_pos; i < max_pos + max_len; i++)
    {
        fprintf(write_file, "%c", str[i]);
    }
    fprintf(write_file, "\n");
    
}


int main()
{
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
    print_longest_word(write_file, str, sz);
    fclose(read_file);
    fclose(write_file);
    return 0;
}
