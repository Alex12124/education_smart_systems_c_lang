#include <stdio.h>

int main() {
    char letter = getchar();
    char digit = getchar();
    int n = letter - 'A' + digit - '1';
    if (n % 2 == 0)
    {
        printf("BLACK\n");
    } else
    {
        printf("WHITE\n");
    }
    
    return 0;
}
