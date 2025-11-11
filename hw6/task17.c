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

int is_happy_number(int n)
{
    return prod_of_digits(n) == sum_of_digits(n);
}


int main()
{
    int number = 0;
    scanf("%d", &number);
    if (is_happy_number(number))
    {
        printf("YES\n");
    } else 
    {
        printf("NO\n");
    }
    

    return 0;
}
