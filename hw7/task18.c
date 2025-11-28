#include <stdio.h>

void print_digits_recurs(int n)
{
    if (n < 10) {
        printf("%d", n);
        return;
    }

    print_digits_recurs(n / 10);
    printf(" %d", n % 10);

}

void print_digits(int n)
{
    if (n == 0) {
        printf("0\n");
        return;
    }
    
    print_digits_recurs(n);
    printf("\n"); 
}

int main() {
    int number;
    scanf("%d", &number);
    print_digits(number);
    
    return 0;
}