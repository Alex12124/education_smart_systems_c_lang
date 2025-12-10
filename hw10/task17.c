#include <stdio.h>
#include <string.h>

enum {ARR_SIZE = 1001};


void char_swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permutations_of_neighbour_elements(char *str)
{
    int right = 0;
    int sz = strlen(str);
    for (int left = 0; left < sz; left++)
    {
        if (str[left] == ' ')
        {
            continue;
        }
        right = left + 1;
        while (right < sz && str[right] == ' ')
        {
            right++;
        }
        if (right == sz)
        {
            return;
        }
        char_swap(str + left, str + right);
        left = right;
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
    permutations_of_neighbour_elements(str);
    fprintf(write_file, "%s\n", str);
    return 0;
}
