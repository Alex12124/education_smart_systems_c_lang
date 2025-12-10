#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum {
    STR_SIZE = 1001,
    ARR_SIZE = 501
};

int is_digit(char c)
{
    return '0' <= c && c <= '9';
}


int find_numbers(int *dest, char *str, int str_sz)
{
    int sz = 0;
    int left = 0;
    int right = 0;
    while (left < str_sz)
    {
        if (!is_digit(str[left]))
        {
            left++;
        } else
        {
            right = left;
            char number_str[11];
            int number_str_sz = 0;
            for (; is_digit(str[right]); right++)
            {
                number_str[number_str_sz] = str[right];
                number_str_sz++;
            }
            
            number_str[number_str_sz] = '\0';
            int number = atoi(number_str);
            dest[sz] = number;
            sz++;
            left = right + 1;
        }
    }
    return sz;
}

int int_swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_int_array(int *arr, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int_swap(arr + j, arr + j + 1);
            }
        }
        
    }
    
}

void print_array(FILE* write_file, int *arr, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        if (i == sz - 1)
        {
            fprintf(write_file, "%d\n", arr[i]);
        }
        else
        {
            fprintf(write_file, "%d ", arr[i]);
        }
    }
}

int main() {
    int lowercase_count = 0;
    int uppercase_count = 0;
    int str_sz = 0;
    char str[STR_SIZE];
    int arr[ARR_SIZE] = {0};
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
        if (c == '\n')
        {
            break;
        }
        str[str_sz] = c; 
        str_sz++;
    }
    str[str_sz] = '\0';

    int arr_sz = find_numbers(arr, str, str_sz);
    sort_int_array(arr, arr_sz);
    print_array(write_file, arr, arr_sz);
    fclose(read_file);
    fclose(write_file);
    return 0;
}
