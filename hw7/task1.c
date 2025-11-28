#include <stdio.h>


void print_numbers(int n) {
    if (n < 1)
        return;

    print_numbers(n - 1);
    printf("%d ", n);
}

int main() {
    int a = 0;
    scanf("%d", &a);
    print_numbers(a);
    
    return 0;
}
