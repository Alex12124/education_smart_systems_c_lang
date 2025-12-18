#include <stdint.h>
#include "temp_api.h"

enum { INFO_SZ = 30 };

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

int AddInfo(sensor_t *info)
{
    int counter = 0;
    AddRecord(info, counter++, 2021, 9, 6, 19, 12, 15);
    AddRecord(info, counter++, 2021, 9, 5, 19, 12, 16);
    AddRecord(info, counter++, 2021, 9, 4, 19, 12, 17);
    AddRecord(info, counter++, 2021, 9, 3, 19, 12, 10);
    AddRecord(info, counter++, 2021, 5, 6, 22, 12, 18);
    AddRecord(info, counter++, 2021, 7, 6, 12, 10, 25);
}


int main(int argc, char** argv)
{
    sensor_t info[INFO_SZ];
    int sz = AddInfo(info);
    max_month_temperature(info, sz, 12);
    min_month_temperature(info, sz, 9);
    avg_month_temperature(info, sz, 9);
    max_year_temperature(info, sz, 2021);
    min_year_temperature(info, sz, 2021);
    avg_year_temperature(info, sz, 2022);
    return 0;
}