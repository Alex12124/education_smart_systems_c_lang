#include <stdio.h>

int get_max(int a, int b) {
    return a > b ? a : b;
}

int get_min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int a, b = 0;
    scanf("%d %d", &a, &b);
    printf("%d %d\n", get_min(a, b), get_max(a, b));
    return 0;
}
