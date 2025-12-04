void int_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int sum_between_ab(int from, int to, int size, int a[])
{
    if (from > to)
    {
        int_swap(&from, &to);
    }
    
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (from <= a[i] && a[i] <= to)
        {
            sum += a[i];
        }
    }
    return sum;
}