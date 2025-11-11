#include <stdio.h>

static void swap_ints(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

static void reverse_int_array(int* arr, int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        swap_ints(arr+i, arr+size-i-1);
    }
    return;
}

int converting_number_system(int n, int p, int* arr)
{
    if (n == 0) {
        arr[0] = -1;
        return 0;
    }
    int size = 0;
    while (n > 0)
    {
        arr[size] = n % p;
        n /= p;
        size++;
    }
    arr[size] = -1;
    reverse_int_array(arr, size);
    return size;
}

int main(void)
{
    int p;
    int number = 0;
    int arr[20];

    scanf("%d %d", &number, &p);
    int size = converting_number_system(number, p, arr);
    if (size == 0) {
        printf("%d", 0);
        return 0;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
    
    

    return 0;
}
