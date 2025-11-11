#include <stdio.h>

int sum_of_digits_is_even(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum % 2 == 0;
}



int main(void)
{
    int number;
    scanf("%d", &number);
    if (sum_of_digits_is_even(number))
    {
        printf("YES\n");
    } else
    {
        printf("NO\n");
    }
    return 0;
}