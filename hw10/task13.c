#include <stdio.h>
#include <string.h>

enum {ARR_SIZE = 1001};

int add_html_extension(char *file_path)
{
    int sz = strlen(file_path);
    int pos_last_slash = 0;
    int dot_pos = 0;
    for (int i = sz - 1; i >= 0; i--)
    {
        if (file_path[i] == '/')
        {
            pos_last_slash = i;
            break;
        }
        
        if (file_path[i] == '.')
        {
            dot_pos = i;
            break;
        }
    }
    if (pos_last_slash == 0 && dot_pos == 0)
    {
        dot_pos = sz;
    } else if(pos_last_slash > 0 && dot_pos == 0)
    {
        dot_pos = sz;
    } else if (pos_last_slash > 0 && dot_pos < pos_last_slash)
    {
        dot_pos == sz;
    }
    file_path[dot_pos] = '.';
    const char *html_str = "html";
    for (int i = dot_pos + 1; i < dot_pos + 1 + strlen(html_str); i++)
    {
        file_path[i] = html_str[i - dot_pos - 1];
    }
    file_path[dot_pos + strlen(html_str) + 1] = '\0';
    return dot_pos + strlen(html_str) + 1;
}

int main() {
    int sz = 0;
    int count = 0;
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

    fscanf(read_file, "%1000s", str);
    add_html_extension(str);
    fprintf(write_file, "%s", str);
    fclose(read_file);
    fclose(write_file);
    return 0;
}
