#include <stdio.h>
#include <limits.h>
#include <unistd.h>

enum {
    ARR_SIZE = 10,
    STR_SIZE = 1000
};

int char_to_digit(char c)
{
    return c - '0';
}

void print_result(int* arr, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }
        printf("%d %d\n", i, arr[i]);
    }
    
}

int main() {
    char str[STR_SIZE + 1];
    int digit_count_arr[ARR_SIZE] = {0};
    int read_bytes = read(fileno(stdin), str, STR_SIZE);
    if (read_bytes < 0)
    {
        return -1;
    }
    
    for (int i = 0; i < read_bytes; i++)
    {
        digit_count_arr[char_to_digit(str[i])]++;
    }
    print_result(digit_count_arr, ARR_SIZE);    

    return 0;
}
