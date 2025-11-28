#include <stdio.h>

int sum_digits(int n)
{
    if (n == 0)
        return 0;

    return sum_digits(n / 10) + n % 10;
}


int main()
{
    int number = 0;
    scanf("%d", &number);
    printf("%d\n", sum_digits(number));
    
    return 0;
}
