#include <stdio.h>

int main() {
    int a, b = 0;
    scanf("%d %d", &a, &b);
    if (a > b) {
        printf("Above\n");
    } else if (a < b) {
        printf("Less\n");
    } else {
        printf("Equal\n");
    }
    
    return 0;
}