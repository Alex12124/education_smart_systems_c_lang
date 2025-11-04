#include <stdio.h>

void print_fibo(int n) {
    if (n <= 0) {
        return;
    }
    if (n == 1) {
        printf("1\n");
        return;
    }
    int first = 1;
    int second = 1;
    printf("%d %d ", first, second);
    for (int i = 0; i < n - 2; i++) {
        int next = first + second;
        first = second;
        second = next;
        printf("%d ", next);
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    print_fibo(n);
    
    return 0;
}