#include <stdio.h>
#include <string.h>

enum {ARR_SIZE = 1001, ENGLISH_SYMBOLS = 26};

int triangle_order(int count)
{
    if (count < 3)
        return 0;
    int n = 0;
    int sum = 0;
    for (int i = 1; sum < count; i++) {
        n = i;
        sum += i;
    }

    if (sum != count)
        return 0;
    return n;
}

void print_triangle(FILE* write_file, int order)
{

    for (int i = 1; i <= order; i++)
    {
        for (int j = 0; j < order - i; j++)
        {
            fprintf(write_file, " ");
        }
        int first_star = 1;
        for (int j = 0; j < i; j++)
        {
            if (first_star)
            {
                first_star = 0;
                fprintf(write_file, "*");
            } else
            {
                fprintf(write_file, " *");
            }
        }
        fprintf(write_file, "\n");
    }
        
}

int main() {
    int sz = 0;
    int count = 0;
    char str[ARR_SIZE];
    char dest[ARR_SIZE];
    FILE* read_file = fopen("input.txt", "r");
    FILE* write_file = fopen("output.txt", "w");
    if (read_file == NULL) {
        fprintf(stderr, "Cannot open read file\n");
        return -1;
    }
    if (write_file == NULL) {
        fprintf(stderr, "Cannot open write file\n");
        fclose(read_file);
        return -1;
    }
    for (int c = fgetc(read_file); c != EOF; c = fgetc(read_file))
    {
        if (c == '*')
        {
            count++;
        }
    }
    fclose(read_file);
    int order = triangle_order(count);
    if (order == 0)
    {
        fprintf(write_file, "NO\n");
    } else
    {
        print_triangle(write_file, order);
    }
    
    
    fclose(write_file);
    return 0;
}