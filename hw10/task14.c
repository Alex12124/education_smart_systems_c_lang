#include <stdio.h>
#include <limits.h>

enum {ARR_SIZE = 101};



int main() {
    char name[ARR_SIZE];
    char last_name[ARR_SIZE];
    char patronymic[ARR_SIZE];
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

    fscanf(read_file, "%100s", last_name);
    fscanf(read_file, "%100s", name);
    
    fscanf(read_file, "%100s", patronymic);
    fprintf(write_file, "Hello, %s %s!", name, last_name);
    fclose(read_file);
    fclose(write_file);
    return 0;
}
