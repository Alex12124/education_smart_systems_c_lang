#include <stdio.h>

int is_prime(int n, int delitel)
{
    if (n == 1)
    {
        return 0;
    }
    if (delitel * delitel > n)
    {
        return 1;
    }
    
    if (n % delitel == 0)
    {
        return 0;
    }
    
    return is_prime(n, delitel + 1);
}

int main()
{
    int number;
    scanf("%d", &number);
    if (is_prime(number, 2))
    {
        printf("YES\n");
    } else
    {
        printf("NO\n");
    }
    return 0;
}