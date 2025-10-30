#include <stdio.h>

int get_max(int a, int b) {
    return a > b ? a : b;
}


int main(void) {
    int a, max = 0;
    scanf("%d", &a);
    max = get_max(get_max(a % 10, (a / 10) % 10), (a / 100) % 10);

    printf("%d\n", max);

    return 0;
}