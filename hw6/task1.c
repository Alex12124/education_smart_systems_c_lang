#include <stdio.h>


int abs(int number) {
    return number > 0 ? number : -number;
}

int main() {
    int a = 0;
    scanf("%d", &a);
    printf("%d\n", abs(a));
    
    return 0;
}
