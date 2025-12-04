#include <limits.h>

int int_max(int a, int b)
{
    return a > b ? a : b;
}

int int_abs(int a)
{
    return a > 0 ? a : -a;
}

int count_bigger_abs(int n, int a[])
{
    int count = 0;
    int maximum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maximum = int_max(maximum, a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (int_abs(a[i]) > maximum)
        {
            count++;
        }
    }
    return count;
}