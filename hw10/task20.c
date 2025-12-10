#include <stdio.h>
#include <string.h>

enum {ARR_SIZE = 1001, ENGLISH_SYMBOLS = 26};

int is_palindrom(char *str)
{
    char dest[ARR_SIZE];
    int dest_sz = 0;
    int spaces = 0;
    int sz = strlen(str);
    int symbols_count[ENGLISH_SYMBOLS] = {0};
    for (int i = 0; i < sz; i++)
    {
        if (str[i] == ' ')
        {
            spaces++;
            continue;
        }
        symbols_count[str[i] - 'a']++;
    }

    int first_even_count = 1;
    char symbol_in_middle;
    for (int i = 0; i < ENGLISH_SYMBOLS; i++)
    {
        if (first_even_count && symbols_count[i] % 2 == 1)
        {
            symbol_in_middle = i + 'a';
            first_even_count = 0;
        }
        
        if (symbols_count[i] / 2 > 0)
        {
            for (int j = 0; j < symbols_count[i] / 2; j++)
            {
                dest[dest_sz] = i + 'a';
                dest_sz++;
            }
        }
    }
    if (first_even_count == 0)
    {
        dest[dest_sz] = symbol_in_middle;    
        dest_sz += dest_sz + 1;
    } else {
        dest_sz *= 2;
    }
    for (int i = 0; i < dest_sz / 2; i++)
    {
        dest[dest_sz - i - 1] = dest[i];
    }
    dest[dest_sz] = '\0';
    return dest_sz + spaces == sz;

}

int main() {
    int sz = 0;
    char str[ARR_SIZE];
    
    FILE* read_file = fopen("input.txt", "r");
    if (read_file == NULL) {
        fprintf(stderr, "Cannot open read file\n");
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
    int flag = is_palindrom(str);
    if (flag)
    {
        printf("YES\n");
    } else
    {
        printf("NO\n");
    }
    
    fclose(read_file);
    return 0;
}
