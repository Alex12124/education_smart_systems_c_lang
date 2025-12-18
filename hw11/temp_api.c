#include "temp_api.h"
#include <limits.h>
#include <stdio.h>

void avg_month_temperature(sensor_t *info, int sz, uint8_t month)
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i < sz; i++)
    {   
        if (info[i].month == month)
        {
            sum += info[i].temperature;
            count++;
        }
    }
    if (count == 0)
    {
        printf("no data for avg temp for month %d\n", month);
        return;
    }
    printf("avg_temp = %.3f for month = %d\n", 
        sum / ((float) count), month);
}

void min_month_temperature(sensor_t *info, int sz, uint8_t month)
{
    int8_t min_temp = INT8_MAX;
  
    for (int i = 0; i < sz; i++)
    {   
        if (info[i].month == month)
        {
            if (info[i].temperature < min_temp)
            {
                min_temp = info[i].temperature;
            }
        }
    }

    if (min_temp == INT8_MAX)
    {
        printf("no data for min temp for month %d\n", month);
        return;
    }
    
    printf("min_temp = %d for month = %d\n", min_temp, month);
}

void max_month_temperature(sensor_t *info, int sz, uint8_t month)
{
    int8_t max_temp = INT8_MIN;
  
    for (int i = 0; i < sz; i++)
    {   
        if (info[i].month == month)
        {
            if (info[i].temperature > max_temp)
            {
                max_temp = info[i].temperature;
            }
        }
    }

    if (max_temp == INT8_MIN)
    {
        printf("no data for max temp for month %d\n", month);
        return;
    }

    printf("max_temp = %d for month = %d\n", max_temp, month);
}

void avg_year_temperature(sensor_t *info, int sz, uint16_t year)
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i < sz; i++)
    {   
        if (info[i].year == year)
        {
            sum += info[i].temperature;
            count++;
        }
    }
    if (count == 0)
    {
        printf("no data for avg temp for year %d\n", year);
        return;
    }
    printf("avg_temp = %.3f for year = %d\n",
        sum / ((float) count), year);
}

void min_year_temperature(sensor_t *info, int sz, uint16_t year)
{
    int min_temp = INT8_MAX;
  
    for (int i = 0; i < sz; i++)
    {   
        if (info[i].year == year)
        {
            if (info[i].temperature < min_temp)
            {
                min_temp = info[i].temperature;
            }
        }
    }
    if (min_temp == INT8_MAX)
    {
        printf("no data for min temp for year %d\n", year);
        return;
    }
    printf("min_temp = %d for year = %d\n",
        min_temp, year);
}

void max_year_temperature(sensor_t *info, int sz, uint16_t year)
{
    int max_temp = INT8_MIN;
  
    for (int i = 0; i < sz; i++)
    {   
        if (info[i].year == year)
        {
            if (info[i].temperature > max_temp)
            {
                max_temp = info[i].temperature;
            }
        }
    }
    if (max_temp == INT8_MIN)
    {
        printf("no data for max temp for year %d\n", year);
        return;
    }

    printf("max_temp = %d for year = %d\n",
        max_temp, year);

}

