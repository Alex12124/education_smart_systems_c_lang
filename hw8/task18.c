#include <stdio.h>

enum {ARR_SIZE = 8};


void number_of_multiples(int *arr, int sz, int n)
{
    for (int i = 0; i < sz; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            if (j % (i + 2) == 0)
            {
                arr[i]++;
            }
        }
    }
}

void print_result(int *arr, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        printf("%d %d\n", i + 2, arr[i]);
    }
    
}

int main() {
    int arr[ARR_SIZE] = {0};
    int n;
    scanf("%d", &n);
    number_of_multiples(arr, ARR_SIZE, n);
    print_result(arr, ARR_SIZE);
    return 0;
}
