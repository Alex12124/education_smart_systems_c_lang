#include <stdio.h>
#include <limits.h>

enum {ARR_SIZE = 12};

float calc_avg(int *arr, int sz)
{
    int sum = 0;
    for (int i = 0; i < sz; i++)
    {
        sum += arr[i];
    }
    return (1.0 * sum) / sz;
}



int main() {
    int arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", arr + i);
    }
    printf("%.2f\n", calc_avg(arr, ARR_SIZE));

    
    return 0;
}
