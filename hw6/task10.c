#include <stdio.h>

void print_simple(int number)
{
    for (int i = 2; number / i > 0; i++)
    {
        while (number % i == 0)
        {
            number /= i;
            printf("%d ", i);
        }
    }
}

int main()
{
    int number;
    scanf("%d", &number);
    print_simple(number);
    return 0;
}