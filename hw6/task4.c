#include <stdio.h>

int func(int x)
{
    if (x >= -2 && x < 2)
    {
        return x * x;
    } else if (x >= 2)
    {
        return x * x + 4 * x + 5; 
    } else {
        return 4;
    }
}

int func_max(int x, int y) {
    return x > y ? x: y;
}

int main(void) {
    int a = 0;
    int max = 0;

    scanf("%d", &a);

    while (a != 0)
    {
        max = func_max(max, func(a));
        scanf("%d", &a);
    }
    printf("%d\n", max);
    
    
    
    return 0;
}
