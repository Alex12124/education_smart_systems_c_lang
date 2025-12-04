#include <stdio.h>
#include <limits.h>

enum {ARR_SIZE = 10};

int max_int(int a, int b)
{
    return a > b ? a : b;
}

int find_max_array(int size, int a[])
{
    if (size <= 0)
    {
        return -1;
    }
    int maximum = a[0];
    for (int i = 1; i < size; i++)
    {
        maximum = max_int(maximum, a[i]);
    }
    return maximum;
}


int main() {
    int arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", arr + i);
    }
    printf("%d\n", sum_positive_elements(arr, ARR_SIZE));

    
    return 0;
}
