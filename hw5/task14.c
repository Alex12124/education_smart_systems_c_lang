#include <stdio.h>



int main(void) {
    int number;
    int count = 0;
    do
    {
        scanf("%d", &number);
        count++;
    } while (number != 0);
    printf("%d\n", count - 1);

    return 0;
}