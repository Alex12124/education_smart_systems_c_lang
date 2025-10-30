#include <stdio.h>

int main() {
    int number = 0;
    scanf("%d", &number);
    if (number > 2 && number < 6) {
        printf("spring\n");
    } else if (number > 5 && number < 9) {
        printf("summer\n");
    } else if (number > 8 && number < 12) {
        printf("autumn\n");
    } else {
        printf("winter\n");
    }
    return 0;
}
