#include <stdio.h>


void print_k_times(int k)
{
    int count = 0;
    for (int i = 1;; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (count >= k) {
                return;
            }
            printf("%d ", i);
            count++;
        }
    }
}


int main(void)
{
    int number = 0;
    scanf("%d", &number);
    print_k_times(number);
    return 0;
}
