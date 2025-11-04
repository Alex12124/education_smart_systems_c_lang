#include <stdio.h>


int main(void) {
    int number;
    int even_count = 0;
    do
    {
        scanf("%d", &number);
        if (number % 2 == 0 && number != 0)
        {
            even_count++;
        }
        
    } while (number != 0);
    printf("%d\n", even_count);

    return 0;
}