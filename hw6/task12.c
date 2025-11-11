#include <stdio.h>

static const float PI = 3.14159265;


float abs_fun(float x) {
    return x > 0 ? x : -x;
}


float sinus(float x, float epsilon)
{
    x *= (PI / 180);
    float sum = 0.0;
    float member = x;
    int i = 1;
    while (abs_fun(member) > epsilon)
    {
        if (i % 2 == 1)
        {
            sum += member;
        } else {
            sum -= member;
        }
        member *= x * x / ((2 * i) * (2 * i + 1));
        i++;
    }
    return sum;
}


int main(void)
{
    float number = 0;
    scanf("%f", &number);
    printf("%.3f\n", sinus(number, 0.001));
    return 0;
}
