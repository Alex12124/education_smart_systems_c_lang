#include <stdio.h>

enum {ARR_SIZE = 5};

float avg_diagonal(int *matrix, int sz)
{
    int sum = 0;
    for (int i = 0; i < sz; i++)
    {
        sum += matrix[i * sz + i];
    }
    return (1.0 * sum) / sz;
}

int main() {
    int arr[ARR_SIZE][ARR_SIZE];
    int count = 0;
    for (int i = 0; i < ARR_SIZE; i++)
    {
        for (int j = 0; j < ARR_SIZE; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    float avg = avg_diagonal((int *)arr, ARR_SIZE);
    for (int i = 0; i < ARR_SIZE; i++)
    {
        for (int j = 0; j < ARR_SIZE; j++)
        {
            if (arr[i][j] > avg)
            {
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
