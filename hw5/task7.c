#include <stdio.h>

int main(void) {
    int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int number = 0;
    int flag = 0;
    scanf("%d", &number);
    while (number > 0) {
        arr[number % 10]++;
        number /= 10;
    }
    
    for (int i = 0; i < 10; i++) {
        if (arr[i] > 1) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    

    return 0;
}
