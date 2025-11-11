#include <stdio.h>

int factorial(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }
    return res;
}


int main()
{
    int number = 0;
    scanf("%d", &number);
    printf("%d\n", factorial(number));
    
    return 0;
}
