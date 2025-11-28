#include <stdio.h>
#include <limits.h>

enum {ARR_SIZE = 10};

typedef struct {
    int max_index;
    int max;
    int min_index;
    int min;
} MinMaxResult;

MinMaxResult min_max(int *arr, int sz)
{
    MinMaxResult res = {
        .max = INT_MIN,
        .min = INT_MAX,
        .max_index = 0,
        .min_index = 0
    };
    for (int i = 0; i < sz; i++)
    {
        if (arr[i] > res.max)
        {
            res.max = arr[i];
            res.max_index = i;
        }
        if (arr[i] < res.min)
        {
            res.min = arr[i];
            res.min_index = i;
        }        
    }
    return res;
}



int main() {
    int arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", arr + i);
    }
    MinMaxResult res = min_max(arr, ARR_SIZE);
    printf("%d %d %d %d\n", res.max_index + 1, res.max, res.min_index + 1, res.min);

    
    return 0;
}
