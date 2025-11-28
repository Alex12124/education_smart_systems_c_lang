#include <stdio.h>


int count_ones_in_binary(int number)
{
    int count = 0;
    while (number > 0)
    {
        if (number % 2 == 1)
        {
            count++;
        }
        number >>= 1;
    }
    return count;
}

int main()
{
    int number;

    scanf("%d", &number);
    printf("%d\n", count_ones_in_binary(number));
    return 0;
}