#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "temp_api.h"
#include "sensor_vector.h"



int compare_date(const void *lhs, const void *rhs)
{
    const sensor_t *lhs_sensor = (const sensor_t*)lhs;
    const sensor_t *rhs_sensor = (const sensor_t*)rhs;
    if (lhs_sensor->year != rhs_sensor->year)
    {
        return lhs_sensor->year - rhs_sensor->year;
    }
    else if (lhs_sensor->month != rhs_sensor->month)
    {
        return lhs_sensor->month - rhs_sensor->month;
    }
    else if (lhs_sensor->day != rhs_sensor->day)
    {
        return lhs_sensor->day - rhs_sensor->day;
    }
    else if (lhs_sensor->hour != rhs_sensor->hour)
    {
        return lhs_sensor->hour - rhs_sensor->hour;
    }
    else
    {
        return lhs_sensor->minute - rhs_sensor->minute;
    }
    
}

int compare_temperature(const void *lhs, const void *rhs)
{
    return ((const sensor_t*)lhs)->temperature - ((const sensor_t*)rhs)->temperature;
}

void sort_by_date(sensor_t *info, int sz)
{
    qsort(info, sz, sizeof(sensor_t), compare_date);
}

void sort_by_temperature(sensor_t *info, int sz)
{
    qsort(info, sz, sizeof(sensor_t), compare_temperature);
}

void print_sensor_vector(sensor_vector *sv, int sz)
{
    printf("==============================\n");
    for (int i = 0; i < sv->sz; i++)
    {
        printf("%04d-%02d-%02d %02d:%02d temp = %02d\n",
            sv->arr[i].year,
            sv->arr[i].month,
            sv->arr[i].day,
            sv->arr[i].hour,
            sv->arr[i].minute,
            sv->arr[i].temperature
        );
    }
}


int check_csv_filename(const char* filename)
{
    int sz = strlen(filename);
    int dot_count = 0;
    if (sz < 5)
    {
        return 0;
    }
    for (int i = 0; i < sz; i++)
    {
        if (filename[i] == '.')
        {
            dot_count++;
        }
    }
    if (dot_count != 1)
    {
        return 0;
    }
    if (strncmp(".csv", filename + sz - 4, 4))
    {
        return 0;
    }
    return 1;
}

int parse_record(const char* str, sensor_t* rec)
{
    char buffer[256];
    strcpy(buffer, str);
    char *token = strtok(buffer, ";");
    if (!token)
        return 0;

    int res = add_year(rec, token);
    if (res == 0)
        return 0;
    token = strtok(NULL, ";");
    if (!token)
        return 0;
    res = add_month(rec, token);
    if (res == 0)
        return 0;
    token = strtok(NULL, ";");
    if (!token)
        return 0;
    res = add_day(rec, token);
    if (res == 0)
        return 0;
    token = strtok(NULL, ";");
    if (!token)
        return 0;
    res = add_hour(rec, token);
    if (res == 0)
        return 0;
    token = strtok(NULL, ";");
    if (!token)
        return 0;
    res = add_minute(rec, token);
    if (res == 0)
        return 0;
    token = strtok(NULL, ";");
    if (!token)
        return 0;

    if (token[strlen(token) - 1] == '\r')
    {
        token[strlen(token) - 1] = '\0';
    }
    

    res = add_temperature(rec, token);
    if (res == 0)
        return 0;
    
    return check_day_month_match(rec);
}


void parse_csv(FILE* read_file, sensor_vector* sv, uint8_t month)
{
    char buffer[100];
    int line_count = 0;
    while (1)
    {
        line_count++;
        sensor_t sensor;
        char* str = fgets(buffer, 100, read_file);
        if (str == NULL)
        {
            return;
        }
        if (buffer[strlen(buffer) - 1] != '\n')
        {
            fprintf(stderr, "in line %d '\\n' expected "
                "or line is too long\n", line_count);
            continue;
        } else
        {
            buffer[strlen(buffer) - 1] = '\0';
        }
        int res = parse_record(buffer, &sensor);
        if (res == 0)
        {
            fprintf(stderr, "in line %d parse error\n", line_count);
            continue;
        }
        if (month == 0 || month == sensor.month)
        {
            push_back(sv, sensor);
        }
    }
}

static void print_help()
{
    printf("Application for temperature sensor.\n"
        "It can work with temperature data:\n"
        "    [add, delete, sort, print]\n"
        "Also it prints temperature stats for month or year:\n"
        "    [max_month, min_month, avg_month, max_year, min_year, avg_year]\n"
        "Available flags:\n"
        "    [-h, -f <filename>, -m <month:from 1 to 12>]\n"
        "h - for print help\n"
        "f - for transfer csv file for processing\n"
        "m - for print month stats\n"
    );
}


static void command_arguments_processing(int argc, char** argv, char* filename,
    uint8_t* month)
{
    int res = 0;
    
    while ((res = getopt(argc, argv, "hf:m:")) != -1)
    {
        switch (res)
        {
        case 'h':
            print_help();
            exit(0);
        case 'f':
            strcpy(filename, optarg);
            break;
        case 'm':
            int n = sscanf(optarg, "%"SCNu8, month);
            if (n <= 0)
            {
                fprintf(stderr, "month should be uint8_t value\n");
                exit(1);
            }
            break;
        case '?':
            exit(1);
        }
    }
    if (strlen(filename) == 0 && *month == 0)
    {
        print_help();
        exit(0);
    }
}

void print_stats(const sensor_vector *sv, uint8_t month)
{
    uint16_t min_year = sv->arr[0].year;
    uint16_t max_year = sv->arr[sv->sz - 1].year;
    printf("  # Year Month MonthAvg MonthMax MonthMin\n");
    int count = 1;
    if (month != 0)
    {
        for (uint16_t year = min_year; year <= max_year; year++)
        {
            temperature_stats stats = get_month_stats(sv->arr, sv->sz, year, month);
            printf("%3d %-4d   %-3d % -7.3f    % -5d    % -5d\n", 
                count, year, month, stats.avg_temp, 
                stats.max_temp, stats.min_temp);
            count++;
            
        }
        exit(0);
    }
    for (uint8_t month = 1; month < 13; month++)
    {
        for (uint16_t year = min_year; year <= max_year; year++)
        {
            temperature_stats stats = get_month_stats(sv->arr, sv->sz, year, month);
            printf("%3d %-4d   %-3d % -7.3f    % -5d    % -5d\n", 
                count, year, month, stats.avg_temp, 
                stats.max_temp, stats.min_temp);
            count++;
        }
    }
    printf("  # Year YearAvg YearMax YearMin\n");
    count = 1;
    for (uint16_t year = min_year; year <= max_year; year++)
    {
        temperature_stats stats = get_year_stats(sv->arr, sv->sz, year);
        printf("%3d %-4d % -6.3f   % -5d    % -4d\n", 
            count, year, stats.avg_temp, 
            stats.max_temp, stats.min_temp);
        count++;
    }
}

int main(int argc, char** argv)
{
    char filename[101] = {0};
    uint8_t month = 0;
    command_arguments_processing(argc, argv, filename, &month);
    if (check_csv_filename(filename) == 0)
    {
        fprintf(stderr, "Correct csv filename expected\n");
        return 1;
    }
    FILE* read_file = fopen(filename, "r");
    if (read_file == NULL)
    {
        fprintf(stderr, "Error when open csv file for read\n");
        return 1;
    }
    sensor_vector sv;
    init(&sv);
    parse_csv(read_file, &sv, month);
    if (sv.sz == 0)
    {
        return 0;
    }
    sort_by_date(sv.arr, sv.sz);
    print_stats(&sv, month);
    destroy(&sv);
    fclose(read_file);
    return 0;
}
