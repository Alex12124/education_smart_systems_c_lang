#include <stdio.h>

enum {ARR_SIZE = 10};

int product_of_odd_digits(int number)
{
    int res = 1;
    while (number > 0)
    {
        if ((number % 10) % 2 == 1)
        {
            res *= number % 10;
        }
        number /= 10;
    }
    return res;
}

int product_of_even_digits(int number)
{
    int res = 1;
    while (number > 0)
    {
        if ((number % 10) % 2 == 0)
        {
            res *= number % 10;
        }
        number /= 10;
    }
    return res;
}

void modify_array(int *arr, int sz, int even_modify)
{
    for (int i = 0; i < sz; i++)
    {
        if (even_modify && arr[i] % 2 == 0)
        {
            arr[i] = product_of_even_digits(arr[i]);
        }
        if (!even_modify && arr[i] % 2 == 1)
        {
            arr[i] = product_of_odd_digits(arr[i]);
        }
    }
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
    int arr[ARR_SIZE];
    int count_even = 0;
    int count_odd = 0;
    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", arr + i);
        if (arr[i] % 2 == 0)
        {
            count_even++;
        } else
        {
            count_odd++;
        }
    }
    modify_array(arr, ARR_SIZE, count_even <= count_odd);
    print_array(arr, ARR_SIZE);
    return 0;
}
