#include <stdio.h>

int main(void) {
    int a = 0;
    int sum = 0;
    scanf("%d", &a);
    sum += a % 10;
    sum += (a / 10) % 10;
    sum += (a / 100) % 10;
    printf("%d\n", sum);

    return 0;
}
