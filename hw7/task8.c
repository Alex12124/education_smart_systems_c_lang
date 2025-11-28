#include <stdio.h>
#include <string.h>

void print_a_to_b(int a, int b)
{
    if (a == b)
    {
        printf("%d\n", a);
        return;
    }
    if (a < b)
    {
        printf("%d ", a);
        print_a_to_b(a + 1, b);
    } else
    {
        printf("%d ", a);
        print_a_to_b(a - 1, b);
    }
    
    
    
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    print_a_to_b(a, b);

    return 0;
}
