#include <stdio.h>


int get_max(int a, int b) {
    return a > b ? a : b;
}


int get_min(int a, int b) {
    return a < b ? a : b;
}


int main(void) {
    int number = 0;
    int min_digit = 9;
    int max_digit = 0;
    scanf("%d", &number);
    while (number)
    {
        min_digit = get_min(min_digit, number % 10);
        max_digit = get_max(max_digit, number % 10);
        number /= 10;
    }
    printf("%d %d\n", min_digit, max_digit);

    return 0;
}
