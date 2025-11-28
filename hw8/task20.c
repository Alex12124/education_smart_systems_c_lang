#include <stdio.h>

void int_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_int_array(int* arr, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz - 1 - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int_swap(arr + j, arr + j + 1);
            }
        }
    }
}

int get_array_from_number(int* arr, int n)
{
    int sz = 0;
    while (n > 0)
    {
        arr[sz] = n % 10;
        sz++;
        n /= 10;
    }
    
    return sz;
}

void print_number_from_array(int *arr, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}


int main() {
    int arr[10];
    int n;
    scanf("%d", &n);
    int sz = get_array_from_number(arr, n);
    sort_int_array(arr, sz);
    print_number_from_array(arr, sz);
    return 0;
}
