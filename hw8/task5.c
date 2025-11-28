#include <stdio.h>
#include <limits.h>

enum {ARR_SIZE = 10};

int sum_positive_elements(int *arr, int sz)
{
    int sum = 0;
    for (int i = 0; i < sz; i++)
    {
        if (arr[i] > 0)
        {
            sum += arr[i];
        }
        
    }
    return sum;
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
