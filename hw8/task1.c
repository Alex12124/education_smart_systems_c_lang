#include <stdio.h>

enum {ARR_SIZE = 5};

float calculate_avg(int *arr, int sz) {
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
    printf("%.3f\n", calculate_avg(arr, ARR_SIZE));

    
    return 0;
}
