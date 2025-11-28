#include <stdio.h>

void print_prime_factors(int number, int factor)
{
    if (number == 1)
    {
        return;
    }
    
    if (number == factor)
    {
        printf("%d ", factor);
        return;
    }
    
    while (number % factor == 0)
    {
        printf("%d ", factor);
        number /= factor;
    }
    print_prime_factors(number, factor + 1);
}

int main(void)
{
    float number = 0;
    scanf("%f", &number);
    print_prime_factors(number, 2);
    return 0;
}
