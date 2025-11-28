#include <stdio.h>
#include <limits.h>

enum {ARR_SIZE = 10};


void int_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int count_element(int *arr, int sz, int element)
{
    int count = 0;
    for (int i = 0; i < sz; i++)
    {
        if (arr[i] == element)
        {
            count++;
        }
        
    }
    return count;
}


int take_elements_from_array(int*dest, int *source, int sz)
{
    int dest_sz = 0;
    for (int i = 0; i < sz; i++)
    {
        if (count_element(source, sz, source[i]) == 1)
        {
            dest[dest_sz] = source[i];
            dest_sz++;
        } 
    }
    return dest_sz;
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
    int dest[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", arr + i);
    }
    int count = take_elements_from_array(dest, arr, ARR_SIZE);
    print_array(dest, count);

    return 0;
}
