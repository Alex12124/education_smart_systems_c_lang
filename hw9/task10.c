#include <stdio.h>
#include <limits.h>

enum {ARR_SIZE = 12};

void pack_string(char *str, int sz)
{
    int left = 0;
    int right = 1;
    for (; right < sz; right++)
    {
        if (str[left] != str[right])
        {
            printf("%c%d", str[left], right - left);
            left = right;
        }
    }
    printf("%c%d\n", str[left], right - left);
}


int main()
{
    char str[1001];
    int sz = 0;
    for (char c = getchar(); c != '.'; c = getchar())
    {
        str[sz] = c;
        sz++;
    }
    str[sz] = '\0';
    pack_string(str, sz);
}
