#include <stdio.h>

int power(int number, int degree) {
    if (degree == 0) {
        return 1;
    }
    int res = number;
    for (int i = 1; i < degree; ++i) {
        res *= number;
    }
    return res;
}

int main() {
    int a, b= 0;
    scanf("%d %d", &a, &b);
    printf("%d\n", power(a, b));

    return 0;
}
