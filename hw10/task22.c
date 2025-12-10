#include <stdio.h>
#include <string.h>

enum {ARR_SIZE = 21};

int is_vowel(char c)
{
    const char *vowels = "aehiouwy";
    for (int i = 0; i < strlen(vowels); i++)
    {
        if (vowels[i] == c)
        {
            return 1;
        }
    }
    return 0;
}

char replace_consonant_to_digit(char c)
{
    const char *consonants_1 = "bfpv";
    const char *consonants_2 = "cgjkqsxz";
    const char *consonants_3 = "dt";
    const char *consonants_4 = "l";
    const char *consonants_5 = "mn";
    const char *consonants_6 = "r";

    for (int i = 0; i < strlen(consonants_1); i++)
    {
        if (consonants_1[i] == c)
        {
            return '1';
        } 
    }
    for (int i = 0; i < strlen(consonants_2); i++)
    {
        if (consonants_2[i] == c)
        {
            return '2';
        } 
    }
    for (int i = 0; i < strlen(consonants_3); i++)
    {
        if (consonants_3[i] == c)
        {
            return '3';
        } 
    }
    for (int i = 0; i < strlen(consonants_4); i++)
    {
        if (consonants_4[i] == c)
        {
            return '4';
        } 
    }
    for (int i = 0; i < strlen(consonants_5); i++)
    {
        if (consonants_5[i] == c)
        {
            return '5';
        } 
    }
    for (int i = 0; i < strlen(consonants_6); i++)
    {
        if (consonants_6[i] == c)
        {
            return '6';
        } 
    }
    return '0';
}

void soundex(char* modified_str, const char *str)
{
    int modified_sz = 0;
    modified_str[0] = str[0];
    modified_sz++;
    for (int i = 1; i < strlen(str); i++)
    {
        if (is_vowel(str[i]))
        {
            continue;
        }
        modified_str[modified_sz] = str[i];
        modified_sz++;
    }
    modified_str[modified_sz] = '\0';
    for (int i = 1; i < modified_sz; i++)
    {
        modified_str[i] = replace_consonant_to_digit(modified_str[i]);
    }
    int right = 2;
    for (int left = 1; left < modified_sz; left++)
    {
        if (left == modified_sz - 1)
        {
            break;
        }
        
        if (modified_str[left] == modified_str[right])
        {
            while (right < modified_sz && 
                modified_str[right] == modified_str[left])
            {
                right++;
            }
            memcpy(modified_str + left + 1, 
                modified_str + right, modified_sz - right + 1);
            modified_sz = strlen(modified_str);
            right = left + 2;
        } else
        {
            right++;
        }
    }
    if (modified_sz < 4)
    {
        for (int i = 0; i < (4 - modified_sz); i++)
        {
            modified_str[modified_sz + i] = '0';
        }
    }
    modified_str[4] = '\0';
}

int main() {
    char modified_str[ARR_SIZE];
    int sz = 0;
    char str[ARR_SIZE];
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
            continue;
        }
        
        str[sz] = c;
        sz++;
    }
    str[sz] = '\0';

    soundex(modified_str, str);
    fprintf(write_file, modified_str);
    
    fclose(read_file);
    fclose(write_file);
    return 0;
}
