#include <stdio.h>


int is_simple(int number) {
    if (number < 2) {
        return 0;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }    
    return 1;
}


int main() {
    int number;
    scanf("%d", &number);
    if (is_simple(number)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
