#include <stdio.h>

int main(void) {
    int a;
    int digit = -1;
    int flag = 0;
    scanf("%d", &a);
    while (a > 0) {
        if (digit == a % 10) {
            flag = 1;
            break;
        }
        digit = a % 10;
        a /= 10;
    }
    if (flag) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    

    return 0;
}