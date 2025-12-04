int count_between(int from, int to, int size, int a[])
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (from <= a[i] && a[i] <= to)
        {
            count++;
        }
    }
    return count;
}