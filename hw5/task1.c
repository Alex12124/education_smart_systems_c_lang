#include <stdio.h>


int power(int number, int degree) {
    int res = number;
    for (int i = 1; i < degree; ++i) {
        res *= number;
    }
    return res;
}

int main() {
    int a = 0;
    scanf("%d", &a);
    for (int i = 1; i <= a; ++i) {
        printf("%d %d %d\n", i, power(i, 2), power(i, 3)); 
    }
    
    return 0;
}
