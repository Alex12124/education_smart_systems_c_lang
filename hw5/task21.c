#include <stdio.h>

int is_upper_symbol(char c) {
    return c > 64 && c < 91;
}


int main() {
    for (char c = getchar(); c != '.'; c = getchar()) {
        if (is_upper_symbol(c)) {
            putchar(c + 32);
        } else {
            putchar(c);
        }
    }
    printf("\n");
    return 0;
}
