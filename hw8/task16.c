#include <stdio.h>
#include <limits.h>

enum {ARR_SIZE = 10};

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


int get_element_with_max_count(int *source, int sz)
{
    int max_count = 0;
    int max_count_idx = 0;
    for (int i = 0; i < sz; i++)
    {
        int count = count_element(source, sz, source[i]);

        if (count > max_count)
        {
            max_count = count;
            max_count_idx = i; 
        } 
    }
    return source[max_count_idx];
}



int main() {
    int arr[ARR_SIZE];
    int dest[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", arr + i);
    }
    int element = get_element_with_max_count(arr, ARR_SIZE);
    printf("%d\n", element);

    return 0;
}
