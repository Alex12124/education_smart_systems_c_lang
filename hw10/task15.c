#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum {ARR_SIZE = 2001};

void replace_substr(char *str, char* template_str, char *replace_str)
{
    int left = 0;
    int sz = strlen(str);
    int replace_sz = strlen(replace_str);
    int template_sz = strlen(template_str);
    for (int right = 0; right < sz; right++)
    {
        if (str[right] == template_str[0])
        {
            left = right;
            right++;
            for (; template_sz > right - left && 
                str[right] == template_str[right - left]; right++)
            {}
            if (template_sz == right - left)
            {
                if (replace_sz < template_sz)
                {
                    memcpy(str + left, replace_str, replace_sz);
                    memcpy(str + left + replace_sz, str + left + template_sz, 
                        sz - template_sz + 1);
                } else if (replace_sz == template_sz)
                {
                    memcpy(str + left, replace_str, replace_sz);
                } else {
                    memcpy(str + left + replace_sz, str + left + template_sz,
                        sz - template_sz + 1);
                    memcpy(str + left, replace_str, replace_sz);
                }
            } else
            {
                right = left;
            } 
        }
    }
    
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

    replace_substr(str, "Cao", "Ling");
    fprintf(write_file, "%s\n", str);
    fclose(read_file);
    fclose(write_file);
    return 0;
}
