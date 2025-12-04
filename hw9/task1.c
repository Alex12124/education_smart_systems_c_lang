void swap_ints(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_array(int size, int a[])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap_ints(a + j, a + j + 1);
            }
        }
    }
}