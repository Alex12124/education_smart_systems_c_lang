#include <stdio.h>

int max_of_two(int a, int b)
{
    return a > b ? a : b;
}

int max_find(int max)
{
    int number = 0;
    scanf("%d", &number);
    if (number == 0) {
        return max;
    }

    return max_find(max_of_two(number, max));
}

int main(void) {
    int number = 0;
    scanf("%d", &number);
    if (number == 0) {
        printf("%d\n", 0);
        return 0;
    }
    printf("%d\n", max_find(number));
        
       
    return 0;
}