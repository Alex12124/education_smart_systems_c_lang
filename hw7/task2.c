#include <stdio.h>


int sum_numbers(int n) {
    if (n < 1)
        return 0;

    return sum_numbers(n - 1) + n;
}

int main() {
    int a = 0;
    scanf("%d", &a);
    printf("%d\n", sum_numbers(a));
    
    return 0;
}
