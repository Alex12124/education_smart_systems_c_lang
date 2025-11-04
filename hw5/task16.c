#include <stdio.h>


int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    while (a != 0 && b != 0)
    {
        if (a < b)
        {
            b = b % a;
        } else
        {
            a = a % b;
        }
    }
    printf("%d\n", a + b);

    return 0;
}