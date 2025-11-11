#include <stdio.h>
#include <string.h>

char to_upper_symbol(char c) {
    if (c >= 'a' && c <= 'z')
    {
        c -= ('a' - 'A');
    }
    return c;
}

int main(void) {
    char c = getchar();
    while (c != '.')
    {
        putchar(to_upper_symbol(c));
        c = getchar();
    }
    printf("\n");

    return 0;
}
