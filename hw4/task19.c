#include <stdio.h>

int is_triangle(int a, int b, int c) {
    return a + b > c && a + c > b && b + c > a;
}

int main() {
    int a, b, c = 0;
    scanf("%d %d %d", &a, &b, &c);
    if (is_triangle(a, b, c)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
