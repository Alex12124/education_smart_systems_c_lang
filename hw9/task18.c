#include <stdio.h>
#include <limits.h>

enum {ARR_SIZE = 10};

int int_max(int a, int b)
{
    return a > b ? a : b;
}

int find_max(int *arr, int sz)
{
    int maximum = INT_MIN; 
    for (int i = 0; i < sz; i++)
    {
        maximum = int_max(maximum, arr[i]);
    }
    return maximum;
}

int main() {
    int arr[ARR_SIZE][ARR_SIZE];
    int sum = 0;
    for (int i = 0; i < ARR_SIZE; i++)
    {
        for (int j = 0; j < ARR_SIZE; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < ARR_SIZE; i++)
    {
        sum += find_max(((int *)arr) + i * ARR_SIZE, ARR_SIZE);
    }
    printf("%d\n", sum);
    return 0;
}
