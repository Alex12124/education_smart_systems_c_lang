#include <stdio.h>

int is_digit(char c)
{
    return c >= '0' && c <= '9';
}

int main() {
    int count = 0;
    for (char c = getchar(); c != '.'; c = getchar())
    {
        if (is_digit(c))
        {
            count++;
        }
    }
    printf("%d\n", count);
    
    return 0;
}