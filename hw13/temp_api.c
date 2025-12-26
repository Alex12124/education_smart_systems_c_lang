#include "temp_api.h"
#include <limits.h>
#include <stdio.h>


typedef int (*temp_date_filter)(const sensor_t*, uint32_t);

static int temp_month_filter(const sensor_t *sensor, uint32_t time_unit)
{
    uint16_t year = time_unit >> 8;
    uint8_t month = time_unit & 0xFF;
    return sensor->month == month &&
        sensor->year == year;
}

static int temp_year_filter(const sensor_t *sensor, uint32_t year)
{
    return sensor->year == year;
}

static temperature_stats get_temp_stats(const sensor_t *info, int sz,
    temp_date_filter filter, uint32_t time_unit)
{
    temperature_stats res;
    res.error = 0;
    int sum = 0;
    int count = 0;
    int8_t min_temp = INT8_MAX;
    int8_t max_temp = INT8_MIN;
    for (int i = 0; i < sz; i++)
    {   
        if (filter(info + i, time_unit))
        {
            sum += info[i].temperature;
            count++;
            if (info[i].temperature < min_temp)
                min_temp = info[i].temperature;
            
            if (info[i].temperature > max_temp)
                max_temp = info[i].temperature;
        }
    }
    if (count == 0)
    {
        res.error = 1;
        return res;
    }
    
    res.avg_temp = sum / ((float) count);
    res.min_temp = min_temp;
    res.max_temp = max_temp;
    return res;
}

temperature_stats get_month_stats(const sensor_t *info, int sz, uint32_t year,
    uint8_t month)
{
    uint32_t time_unit = 0;
    time_unit = year << 8 | month;
    return get_temp_stats(info, sz, temp_month_filter, time_unit);
}

temperature_stats get_year_stats(const sensor_t *info, int sz, uint16_t year)
{
    return get_temp_stats(info, sz, temp_year_filter, year);
}

void avg_month_temperature(const sensor_t *info, int sz, uint16_t year, uint8_t month)
{
    temperature_stats stats = get_month_stats(info, sz, year, month);
    if (stats.error == 1)
    {
        printf("no data for avg temp for month %d\n", month);
        return;
    }
    printf("avg_temp = %.3f for month = %d\n", 
        stats.avg_temp, month);
}

void min_month_temperature(const sensor_t *info, int sz, uint16_t year, uint8_t month)
{
    temperature_stats stats = get_month_stats(info, sz, year, month);
    if (stats.error == 1)
    {
        printf("no data for avg temp for month %d\n", month);
        return;
    }
    
    printf("min_temp = %d for month = %d\n", stats.min_temp, month);
}

void max_month_temperature(const sensor_t *info, int sz, uint16_t year, uint8_t month)
{
    temperature_stats stats = get_month_stats(info, sz, year, month);
    if (stats.error == 1)
    {
        printf("no data for avg temp for month %d\n", month);
        return;
    }

    printf("max_temp = %d for month = %d\n", stats.max_temp, month);
}

void avg_year_temperature(const sensor_t *info, int sz, uint16_t year)
{
    temperature_stats stats = get_year_stats(info, sz, year);
    if (stats.error == 1)
    {
        printf("no data for avg temp for year = %d\n", year);
        return;
    }
    printf("avg_temp = %.3f for year = %d\n",
        stats.avg_temp, year);
}

void min_year_temperature(const sensor_t *info, int sz, uint16_t year)
{
    temperature_stats stats = get_year_stats(info, sz, year);
    if (stats.error == 1)
    {
        printf("no data for avg temp for year = %d\n", year);
        return;
    }
    printf("min_temp = %d for year = %d\n",
        stats.min_temp, year);
}

void max_year_temperature(const sensor_t *info, int sz, uint16_t year)
{
    temperature_stats stats = get_year_stats(info, sz, year);
    if (stats.error == 1)
    {
        printf("no data for avg temp for year = %d\n", year);
        return;
    }

    printf("max_temp = %d for year = %d\n",
        stats.max_temp, year);

}
