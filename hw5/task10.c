#include <stdio.h>



int main()
{
    int number;
    int digit = 10;
    int flag = 1;
    scanf("%d", &number);
    while (number)
    {
        if (number % 10 >= digit)
        {
            flag = 0;
            break;
        }
        digit = number % 10;

        number /= 10;
    }
    if (flag) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}