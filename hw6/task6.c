#include <stdio.h>

unsigned long long count_seeds(int n) {
    unsigned long long res = 1;
    return res << (n - 1);
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%llu\n", count_seeds(n));
    

    return 0;
}