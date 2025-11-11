#include <stdio.h>

int middle(int a, int b) {
    return (b - a) / 2 + a;
}

int main() {
    int a, b, sum = 0;
    scanf("%d %d", &a, &b);
    printf("%d\n", middle(a, b));
}