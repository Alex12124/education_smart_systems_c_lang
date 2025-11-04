#include <stdio.h>

int get_max(int a, int b) {
    return a > b ? a : b;
}


int get_max_element(int* arr, int sz) {
    int max = 0x80000000;
    for (int i = 0; i < sz; ++i) {
        max = get_max(max, arr[i]);
    }
    return max;
}


int main() {
    int flag = 1;
    int number = 0;
    scanf("%d", &number);
    while (number > 0) {
        if (number % 10 % 2 == 1) {
            flag = 0;
            break;    
        }
        number /= 10;
    }
    if (flag == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
