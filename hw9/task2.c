#include "string.h"
#include "stdlib.h"


void sort_even_odd(int n, int a[])
{
    int* even_arr = (int*) malloc(sizeof(int) * n);
    int even_arr_sz = 0;
    int* odd_arr = (int*) malloc(sizeof(int) * n);
    int odd_arr_sz = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            even_arr[even_arr_sz] = a[i];
            even_arr_sz++;
        } else
        {
            odd_arr[odd_arr_sz] = a[i];
            odd_arr_sz++;
        }
    }
    memcpy(a, even_arr, sizeof(int) * even_arr_sz);
    memcpy(a + even_arr_sz, odd_arr, sizeof(int) * odd_arr_sz);
    free(even_arr);
    free(odd_arr);
}
