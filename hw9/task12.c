#include <limits.h>

void int_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void change_max_min(int size, int a[])
{
    int min_index = 0;
    int max_index = 0;
    int minimum = INT_MAX;
    int maximum = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (a[i] > maximum)
        {
            maximum = a[i];
            max_index = i;
        }
        if (a[i] < minimum)
        {
            minimum = a[i];
            min_index = i;
        }
    }
    int_swap(a + min_index, a + max_index);
}
