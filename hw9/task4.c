#include <stdio.h>
#include <unistd.h>

enum {ARR_SIZE = 10};

int is_digit(char c)
{
    return c >= '0' && c <= '9';
}

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

void print_digit(char s[])
{
    int i = 0;
    int digit_count_arr[ARR_SIZE] = {0};
    while (s[i] != '\0')
    {
        if (is_digit(s[i]))
        {
            digit_count_arr[char_to_digit(s[i])]++;
        }
        i++;
    }
    print_result(digit_count_arr, ARR_SIZE);
}

int main() {
    char str[1000 + 1];
    int read_bytes = read(fileno(stdin), str, 1000);
    if (read_bytes < 0)
    {
        return -1;
    }
    str[read_bytes] = '\0';
    print_digit(str);
    return 0;
}
