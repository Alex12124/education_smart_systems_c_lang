#include <stdio.h>

void int_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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
    for (int i = 0; i < sz / 2; i++)
    {
        int_swap(arr + i, arr + sz - i - 1);
    }
    
    return sz;
}

void print_array(int *arr, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        if (i == sz - 1)
        {
            printf("%d\n", arr[i]);
        }
        else
        {
            printf("%d ", arr[i]);
        }
    }
}


int main() {
    int arr[10];
    int n;
    scanf("%d", &n);
    int sz = get_array_from_number(arr, n);
    print_array(arr, sz);
    return 0;
}
