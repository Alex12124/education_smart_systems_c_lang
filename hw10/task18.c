#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum {ARR_SIZE = 1001};

void super_trim(char *str)
{
    int sz = strlen(str);
    int after_first_delete_pos = 0;
    for (int i = 0; i < sz; i++)
    {
        if (str[i] != ' ')
            break;
        
        after_first_delete_pos++;
    }
    int new_sz = sz - after_first_delete_pos;
    
    if (new_sz == 0)
        return;
    if (after_first_delete_pos > 0)
    {
        memcpy(str, str + after_first_delete_pos, new_sz);
        str[new_sz] = '\0';
    }
    
    
    int right = 0;
    for (int left = 0; left < new_sz; left++)
    {
        if (str[left] == ' ')
        {
            right = left + 1;
            while (right < sz && str[right] == ' ')
                right++;

            if (right == sz)
            {
                str[left + 1] = '\0';
                return;
            }
            if (right - left > 1)
            {
                memcpy(str + left + 1, str + right, sz - right + 1);
                new_sz = strlen(str);
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
    super_trim(str);
    fprintf(write_file, "%s\n", str);
    fclose(read_file);
    fclose(write_file);
    return 0;
}
