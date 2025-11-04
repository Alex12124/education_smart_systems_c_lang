#include <stdio.h>


int sum_of_digits(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}


int prod_of_digits(int number)
{
    int prod = 1;
    while (number > 0)
    {
        prod *= number % 10;
        number /= 10;
    }
    return prod;
}


int main()
{
    int number = 0;
    scanf("%d", &number);

    for (int i = 10; i <= number; i++)
    {
        if (prod_of_digits(i) == sum_of_digits(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
