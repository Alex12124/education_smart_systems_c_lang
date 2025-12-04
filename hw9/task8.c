#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

enum {ARR_SIZE = 1000};

int int_max(int a, int b)
{
    return a > b ? a : b;
}

int int_min(int a, int b)
{
    return a < b ? a : b;
}


int identify_missing_number(int *arr, int minimum, int maximum)
{
    int res = 0;
    int sz = maximum - minimum;
    int *tmp_arr = (int*) calloc(sz + 1, sizeof(int));
    for (int i = 0; i < sz; i++)
    {
        tmp_arr[arr[i] - minimum] = 1; 
    }
    for (int i = 0; i < sz + 1; i++)
    {
        if (tmp_arr[i] == 0)
        {
            res = i + minimum;
        }  
    }
    
    free(tmp_arr);
    return res;
}

int main() {
    int arr[ARR_SIZE];
    int maximum = INT_MIN;
    int minimum = INT_MAX;

    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", arr + i);
        if (arr[i] == 0)
        {
            break;
        }
        minimum = int_min(minimum, arr[i]);
        maximum = int_max(maximum, arr[i]);
    }
    int num = identify_missing_number(arr, minimum, maximum);
    printf("%d\n", num);
    return 0;
}
