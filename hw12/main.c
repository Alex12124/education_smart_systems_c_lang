#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "temp_api.h"

enum { INFO_SZ = 30 };


int CompareDate(const void *lhs, const void *rhs)
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

int CompareTemperature(const void *lhs, const void *rhs)
{
    return ((const sensor_t*)lhs)->temperature - ((const sensor_t*)rhs)->temperature;
}

void SortByDate(sensor_t *info, int sz)
{
    qsort(info, sz, sizeof(sensor_t), CompareDate);
}

void SortByTemperature(sensor_t *info, int sz)
{
    qsort(info, sz, sizeof(sensor_t), CompareTemperature);
}

void AddRecord(sensor_t *info, int number,
    uint16_t year, uint8_t month, uint8_t day,
    uint8_t hour, uint8_t minute, int8_t temperature)
{
    info[number].year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].hour = hour;
    info[number].minute = minute;
    info[number].temperature = temperature;
}

int DeleteRecord(sensor_t *info, int sz, int number)
{
    if (number < 0 || number >= sz)
    {
        return sz;
    }
    memcpy(info + number, info + number + 1, (sz - number - 1) * sizeof(sensor_t));
    return sz - 1;
}

void Print(sensor_t *info, int sz)
{
    printf("==============================\n");
    for (int i = 0; i < sz; i++)
    {
        printf("%04d-%02d-%02d %02d:%02d temp = %02d\n",
            info[i].year,
            info[i].month,
            info[i].day,
            info[i].hour,
            info[i].minute,
            info[i].temperature
        );
    }
}



int AddInfo(sensor_t *info)
{
    int counter = 0;
    AddRecord(info, counter++, 2021, 9, 6, 19, 12, 15);
    AddRecord(info, counter++, 2021, 9, 5, 19, 12, 16);
    AddRecord(info, counter++, 2021, 9, 4, 19, 12, 17);
    AddRecord(info, counter++, 2021, 9, 3, 19, 12, 10);
    AddRecord(info, counter++, 2021, 5, 6, 22, 12, 18);
    AddRecord(info, counter++, 2021, 7, 6, 12, 10, 25);
    return counter;
}


int main(int argc, char** argv)
{
    int res = 0;
    char filename[101];
    uint8_t month = 0;
    while ((res = getopt(argc, argv, "hf:m:")) != -1)
    {
        switch (res)
        {
        case 'h':
            printf("Application for temperature sensor.\n"
                   "It can work with temperature data:\n"
                   "    [add, delete, sort, print]\n"
                   "Also it prints temperature stats for month or year:\n"
                   "    [max_month, min_month, avg_month, max_year, min_year, avg_year]\n"
                   "Available flags:\n"
                   "    [-h, -f <filename>, -m <month:from 1 to 12>]\n"
                   "h - for print help\n"
                   "f - for transfer csv file for processing\n"
                   "m - for transfer month for print month stats\n"
                );
            return 0;
        case 'f':
            strcpy(filename, optarg);
            printf("%s\n", filename);
            break;
        case 'm':
            int n = sscanf(optarg, "%"SCNu8, &month);
            if (n <= 0)
            {
                fprintf(stderr, "month should be uint8_t value\n");
                return -1;
            }
            
            printf("month = %d\n", month);
            break;
        default:
            break;
        }
    }
    
    sensor_t info[INFO_SZ];
    int sz = AddInfo(info);
    Print(info, sz);
    sz = DeleteRecord(info, sz, 2);
    Print(info, sz);
    SortByDate(info, sz);
    Print(info, sz);
    SortByTemperature(info, sz);
    Print(info, sz);
    printf("==============================\n");
    if (month > 0 && month < 13)
    {
        max_month_temperature(info, sz, month);
        min_month_temperature(info, sz, month);
        avg_month_temperature(info, sz, month);
    }
    return 0;
}
