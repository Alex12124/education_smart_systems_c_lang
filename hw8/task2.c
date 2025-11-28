#include <stdio.h>

enum {ARR_SIZE = 5};


int int_min(int a, int b)
{
    return a < b ? a : b;
}

int find_min(int *arr, int sz)
{
    int res = 0x7FFFFFFF;
    for (int i = 0; i < sz; i++)
    {
        res = int_min(res, arr[i]);
    }
    return res;
}

int main()
{
    int arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", arr + i);
    }
    printf("%d\n", find_min(arr, ARR_SIZE));
    return 0;
}
