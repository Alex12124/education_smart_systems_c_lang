#include <stdio.h>

void dec_to_bin(int n)
{
    if (n == 0)
    {
        return;
    }
    
    dec_to_bin(n / 2);
    printf("%d", n % 2);
}

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    if (n == 0)
    {
        printf("%d", 0);
        return 0;
    }
    
    dec_to_bin(n);
    return 0;
}
