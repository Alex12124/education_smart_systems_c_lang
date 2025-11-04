#include <stdio.h>

int power(int number, int degree) {
    int res = number;
    for (int i = 1; i < degree; ++i) {
        res *= number;
    }
    return res;
}

int main() {
    int a, b, sum = 0;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; ++i) {
        sum += power(i, 2);    
    }
    printf("%d\n", sum);
    return 0;
}