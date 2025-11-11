#include <stdio.h>

int sum_n_seq_numbers(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", sum_n_seq_numbers(n));
    return 0;
}
