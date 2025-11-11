#include <stdio.h>


int is_digit(char c)
{
    return c >= '0' && c <= '9';
}

int digit_to_num(char c)
{
    return (int)(c - '0');
}

int main() {
    int sum = 0;
    for (char c = getchar(); c != '.'; c = getchar())
    {
        if (is_digit(c))
        {
            sum += digit_to_num(c);
        }
    }
    printf("%d\n", sum);

    return 0;
}
