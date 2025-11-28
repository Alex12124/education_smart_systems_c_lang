#include <stdio.h>
#include <limits.h>

enum {ARR_SIZE = 10};


void int_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_array_by_last_digit(int *arr, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz - i - 1; j++)
        {
            if ((arr[j] % 10) > (arr[j + 1] % 10))
            {
                int_swap(arr + j + 1, arr + j);
            }
        }
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
    sort_array_by_last_digit(arr, ARR_SIZE);
    print_array(arr, ARR_SIZE);

    return 0;
}
