#include <stdio.h>

int main(void) {
    int a = 0;
    int mul = 1;
    scanf("%d", &a);
    mul *= a % 10;
    mul *= (a / 10) % 10;
    mul *= (a / 100) % 10;
    printf("%d\n", mul);

    return 0;
}
