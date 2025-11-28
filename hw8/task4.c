#include <stdio.h>
#include <limits.h>

enum {ARR_SIZE = 10};

int find_2max_and_sum(int *arr, int sz)
{
    int first_max = INT_MIN;
    int first_max_index = 0;
    int second_max = INT_MIN;

    for (int i = 0; i < sz; i++)
    {
        if (arr[i] > first_max)
        {
            first_max = arr[i];
            first_max_index = i;
        }
    }
    for (int i = 0; i < sz; i++)
    {
        if (i == first_max_index)
        {
            continue;
        }
        
        if (arr[i] > second_max)
        {
            second_max = arr[i];
        }
    }

    return first_max + second_max;
}



int main() {
    int arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", arr + i);
    }
    printf("%d\n", find_2max_and_sum(arr, ARR_SIZE));

    
    return 0;
}
