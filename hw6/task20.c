#include <stdio.h>



int main() {
    int open_brackets = 0;
    int close_brackets = 0;

    for (char c = getchar(); c != '.'; c = getchar())
    {
        if (c == '(')
        {
            open_brackets++;
        } else if (c == ')')
        {
            close_brackets++;
        }
        if (close_brackets > open_brackets)
        {
            break;
        }
        
    }
    if (close_brackets == open_brackets)
    {
        printf("YES\n");
    } else
    {
        printf("NO\n");
    }
    
    
    return 0;
}
