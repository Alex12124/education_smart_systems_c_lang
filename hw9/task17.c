#include <stdio.h>
#include <limits.h>

enum {ARR_SIZE = 5};

int matrix_trace(int *matrix, int rows, int cols)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        sum += matrix[i * rows + i];
    }
    return sum;
}

int main() {
    int arr[ARR_SIZE][ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
    {
        for (int j = 0; j < ARR_SIZE; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("%d\n", matrix_trace((int*)arr, ARR_SIZE, ARR_SIZE));

    return 0;
}
