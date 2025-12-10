#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int find_last_symbol_index(char *buffer, int sz)
{
    for (int i = sz - 1; i >= 0; i--)
    {
        if (buffer[i] != '\n')
        {
            return i;
        }
    }
    return -1; 
}

int main() {
    int sz = 0;
    char buffer[1001];
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
        buffer[sz] = c;
        sz++;
    }
    buffer[sz] = '\0';
    
    int last_symbol_index = find_last_symbol_index(buffer, sz);

    if (last_symbol_index < 0)
    {
        fclose(read_file);
        fclose(write_file);
        return 0;
    }
    
    for (int i = 0; i < sz; i++)
    {
        if (i == last_symbol_index)
        {
            break;
        }
        
        if (buffer[i] == buffer[last_symbol_index]) {
            fprintf(write_file, "%d ", i);
        }
    }
    fprintf(write_file, "\n");
    

    fclose(read_file);
    fclose(write_file);
    return 0;
}
