#include <stdio.h>
#include <limits.h>

enum {ARR_SIZE = 12};

void cycle_right_shift(int *arr, int sz, int n)
{
    n = n % sz;
    if (n <= 0)
    {
        return;
    }
    
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[sz - n + i];
    }
    for (int i = sz - 1; i >= n; i--)
    {
        arr[i] = arr[i - n];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

void print_array(int *arr, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        if (i == sz - 1)
        {
            printf("%d\n", arr[i]);
        }
        else
        {
            printf("%d ", arr[i]);
        }
    }
}


int main()
{
    int arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", arr + i);
    }
    cycle_right_shift(arr, ARR_SIZE, 4);
    print_array(arr, ARR_SIZE);
    return 0;
}
