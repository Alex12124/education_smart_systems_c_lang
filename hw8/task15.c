#include <stdio.h>

enum {ARR_SIZE = 10};


int get_positive_array(int*dest, int *source, int sz)
{
    int dest_sz = 0;
    for (int i = 0; i < sz; i++)
    {
        if (source[i] > 0)
        {
            dest[dest_sz] = source[i];
            dest_sz++;
        }
        
    }
    return dest_sz;
}

int get_negative_array(int*dest, int *source, int sz)
{
    int dest_sz = 0;
    for (int i = 0; i < sz; i++)
    {
        if (source[i] < 0)
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
            printf("%d", arr[i]);
        }
        else
        {
            printf("%d ", arr[i]);
        }
    }
}



int main() {
    int arr[ARR_SIZE];
    int positive_arr[ARR_SIZE];
    int negative_arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", arr + i);
    }
    int count = get_positive_array(positive_arr, arr, ARR_SIZE);
    print_array(positive_arr, count);
    printf(" ");
    count = get_negative_array(negative_arr, arr, ARR_SIZE);
    print_array(negative_arr, count);
    printf("\n");
    return 0;
}
