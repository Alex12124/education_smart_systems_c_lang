#include <stdio.h>


int main()
{
    int number;

    scanf("%d", &number);
    if (number == 0) {
        printf("0\n");
        return 0;
    }
    while (number)
    {
        printf("%d", number % 10);
        number /= 10;
    }
    printf("\n");
    
    return 0;
}