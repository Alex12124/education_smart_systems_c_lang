#include <stdio.h>

void print_odd_number(int number)
{
    if (number % 2 != 0)
    {
        printf("%d ", number);
    }
    
}



int main(void)
{
    int number = -1;
    while (1)
    {
        scanf("%d", &number);
        if (number == 0)
        {
            break;
        }
        
        print_odd_number(number);
    }
    
    
    return 0;
}