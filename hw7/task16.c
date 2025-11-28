#include <stdio.h>


int is2pow(int n)
{
    if (n == 1)
    {
        return 1;
    }
    
    return (n % 2 == 0) && is2pow(n / 2);
}

int main(void) {
    int number;
    scanf("%d", &number);
    if (is2pow(number))
    {
        printf("YES\n");
    } else
    {
        printf("NO\n");
    }
    

    return 0;
}