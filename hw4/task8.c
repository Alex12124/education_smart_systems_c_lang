#include <stdio.h>

int get_max(int a, int b) {
    return a > b ? a : b;
}

int get_min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int a, b, c = 0;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", get_max(get_max(a, b), c));
    return 0;
}
