#include <stdio.h>

int sum_of_digits(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}
int main() {
    int number = 0;
    scanf("%d", &number);
    if (sum_of_digits(number) == 10) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    


    return 0;
}
