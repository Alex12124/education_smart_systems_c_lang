#include <stdio.h>
#include <limits.h>

enum {ARR_SIZE = 30};

int int_min(int a, int b)
{
    return a < b ? a : b;
}

int int_max(int a, int b)
{
    return a > b ? a : b;
}

void print_two_minimum(int *arr, int sz)
{
    int first_min_index = 0;
    int second_min_index = 0;
    int first_min = INT_MAX;
    int second_min = INT_MAX;


    for (int i = 0; i < sz; i++)
    {
        if (arr[i] < first_min)
        {
            first_min = arr[i];
            first_min_index = i;
        }
    }
    for (int i = 0; i < sz; i++)
    {
        if (i == first_min_index) {
            continue;
        }
        if (arr[i] < second_min)
        {
            second_min = arr[i];
            second_min_index = i;
        }
    }
    printf("%d %d\n", int_min(first_min_index, second_min_index),
            int_max(first_min_index, second_min_index));
    
}


int main() {
    int arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", arr + i);
    }
    print_two_minimum(arr, ARR_SIZE);

    return 0;
}
