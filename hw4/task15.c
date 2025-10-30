#include <stdio.h>

int get_max(int a, int b) {
    return a > b ? a : b;
}


int main(void) {
    int x1, y1, x2, y2 = 0;
    float k, b;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    k = (y2 - (float)y1) / (x2 - x1);
    b = (y1 + y2 - k * (x1 + x2)) / 2;
    printf("%.2f %.2f\n", k, b);

    return 0;
}
