#include <stdio.h>

int get_min(int a, int b) {
    return a < b ? a : b;
}


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



int get_min_element(int* arr, int sz) {
    int min = 0x7FFFFFFF;
    for (int i = 0; i < sz; ++i) {
        min = get_min(min, arr[i]);
    }
    return min;
}


int main() {
    int a, b, c, d, e = 0;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    int arr[] = {a, b, c, d, e};
    printf("%d\n", get_min_element(arr, 5) + get_max_element(arr, 5));
    return 0;
}
