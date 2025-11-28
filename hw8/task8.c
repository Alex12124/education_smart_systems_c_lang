#include <stdio.h>
#include <limits.h>

enum {ARR_SIZE = 12};

void int_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void inverse_array(int *arr, int sz)
{
    for (int i = 0; i < sz / 2; i++)
    {
        int_swap(arr + i, arr + sz - i - 1);
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



int main() {
    int arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", arr + i);
    }
    inverse_array(arr, ARR_SIZE / 3);
    inverse_array(arr + ARR_SIZE / 3, ARR_SIZE / 3);
    inverse_array(arr + 2 * (ARR_SIZE / 3), ARR_SIZE / 3);
    print_array(arr, ARR_SIZE);

    return 0;
}
