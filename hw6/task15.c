#include <stdio.h>

int grow_up(int number)
{
    int flag = 1;
    int old = 10;
    while (number > 0)
    {
        if (number % 10 >= old)
        {
            flag = 0;
            break;
        }
        old = number % 10;
        number /= 10;
    }
    return flag;
}

int main(void) {
    int number;
    scanf("%d", &number);
    if (grow_up(number))
    {
        printf("YES\n");
    } else
    {
        printf("NO\n");
    }
    return 0;
}