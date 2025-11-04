#include <stdio.h>

int power(int number, int degree) {
    int res = number;
    for (int i = 1; i < degree; ++i) {
        res *= number;
    }
    return res;
}

int main() {
    int a, b= 0;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; ++i) {
        printf("%d ", power(i, 2));
    }
    return 0;
}
