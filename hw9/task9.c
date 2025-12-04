#include <stdio.h>
#include <limits.h>

void int_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_negmax_last(int size, int a[])
{
    int neg_max = INT_MIN;
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (a[i] < 0 && a[i] > neg_max)
        {
            neg_max = a[i];
            index = i;
        }    
    }
    if (index == -1)
    {
        return;
    }
    int_swap(a + index, a + size - 1);
}



int main()
{
    int arr[] = {1,-2,-3,-4,5,6,7,8,9,10};
    swap_negmax_last(10, arr);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
