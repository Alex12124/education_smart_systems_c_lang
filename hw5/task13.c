#include <stdio.h>

int main(void) {
    int number = 0;
    int odd_count = 0;
    int even_count = 0;
    scanf("%d", &number);
    while (number) {
        if ((number % 10) % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
        number /= 10;
    }
    printf("%d %d\n", even_count, odd_count);

    return 0;
}
