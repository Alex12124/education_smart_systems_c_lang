#include <stdio.h>

int compression(int a[], int b[], int N)
{
    int left = 0;
    int right = 0;
    int b_sz = 0;

    if (N <= 0)
        return b_sz;

    if (a[0] == 1)
    {
        b[b_sz] = 0;
        b_sz++;
    }
    

    for (right = 0; right < N - 1; right++)
    {
        if (a[right + 1] != a[right])
        {
            b[b_sz] = right - left + 1;
            b_sz++;
            left = right + 1;
        }
    }
    b[b_sz] = right - left + 1;
    b_sz++;

    return b_sz;
}


int main() {
    int res[17] = {0};
    int arr[17] = {1,1,1,0,0,0,0,0,0,0};
    int sz = compression(arr, res, 10);
    printf("%d\n", sz);
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", res[i]);
    }
    

    return 0;
}
