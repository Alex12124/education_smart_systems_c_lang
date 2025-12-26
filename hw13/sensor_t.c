#include "sensor_t.h"
#include <stdint.h>
#include <string.h>

enum {
    YEAR_MAX = 9999,
    YEAR_MIN = 1000,
    MONTH_MAX = 12,
    MONTH_MIN = 1,
    DAY_MAX = 31,
    DAY_MIN = 1,
    HOUR_MAX = 23,
    HOUR_MIN = 0,
    MINUTE_MAX = 59,
    MINUTE_MIN = 0,
    TEMPERATURE_ABS_MAX = 99,
};

static int month_to_count_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static int is_leap_year(uint16_t year)
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

static int is_digit(char c)
{
    return '0' <= c && c <= '9';
}

static char* trim(char* str, char delimeter)
{
    int left_pos = 0;
    int right_pos = 0;
    int sz = strlen(str);
    if (sz == 0)
    {
        return str;
    }
    
    
    for (left_pos = 0; left_pos < sz; left_pos++)
    {
        if (str[left_pos] != delimeter)
            break;
    }

    for (right_pos = sz - 1; right_pos >= left_pos; right_pos--)
    {
        if (str[right_pos] != delimeter)
            break;
    }
    str[right_pos + 1] = '\0';
    return str + left_pos;
}

int add_year(sensor_t *sensor, char* year_str)
{
    year_str = trim(year_str, ' ');
    
    uint32_t year = 0;
    for (int i = 0; i < strlen(year_str); i++)
    {
        if (!is_digit(year_str[i]))
        {   
            return 0;
        }
        year = year * 10 + (year_str[i] - '0');
        if (year > YEAR_MAX)
        {
            return 0;
        }
    }
    if (year < YEAR_MIN)
    {
        return 0;
    }
    sensor->year = year;
    return 1;
}

int add_month(sensor_t *sensor, char* month_str)
{
    month_str = trim(month_str, ' ');
    uint8_t month = 0;
    for (int i = 0; i < strlen(month_str); i++)
    {
        if (!is_digit(month_str[i]))
        {   
            return 0;
        }
        month = month * 10 + (month_str[i] - '0');
        if (month > MONTH_MAX)
        {
            return 0;
        }
    }
    if (month < MONTH_MIN)
    {
        return 0;
    }
    sensor->month = month;
    return 1;
}

int add_day(sensor_t *sensor, char* day_str)
{
    day_str = trim(day_str, ' ');
    uint16_t day = 0;
    for (int i = 0; i < strlen(day_str); i++)
    {
        if (!is_digit(day_str[i]))
        {   
            return 0;
        }
        day = day * 10 + (day_str[i] - '0');
        if (day > DAY_MAX)
        {
            return 0;
        }
    }
    if (day < DAY_MIN)
    {
        return 0;
    }
    sensor->day = day;
    return 1;
}

int add_hour(sensor_t *sensor, char* hour_str)
{
    hour_str = trim(hour_str, ' ');
    uint16_t hour = 0;
    for (int i = 0; i < strlen(hour_str); i++)
    {
        if (!is_digit(hour_str[i]))
        {   
            return 0;
        }
        hour = hour * 10 + (hour_str[i] - '0');
        if (hour > HOUR_MAX)
        {
            return 0;
        }
    }
    if (hour < HOUR_MIN)
    {
        return 0;
    }
    sensor->hour = hour;
    return 1;
}

int add_minute(sensor_t *sensor, char* minute_str)
{
    minute_str = trim(minute_str, ' ');
    uint16_t minute = 0;
    for (int i = 0; i < strlen(minute_str); i++)
    {
        if (!is_digit(minute_str[i]))
        {   
            return 0;
        }
        minute = minute * 10 + (minute_str[i] - '0');
        if (minute > MINUTE_MAX)
        {
            return 0;
        }
    }
    if (minute < MINUTE_MIN)
    {
        return 0;
    }
    sensor->minute = minute;
    return 1;
}

int add_temperature(sensor_t *sensor, char* temperature_str)
{
    temperature_str = trim(temperature_str, ' ');
    if (strlen(temperature_str) == 0)
    {
        return 0;
    }
    int has_minus = temperature_str[0] == '-';
    
    int16_t temperature = 0;
    for (int i = 0; i < strlen(temperature_str); i++)
    {
        if (i == 0 && has_minus)
        {
            continue;
        }
        
        if (!is_digit(temperature_str[i]))
        {   
            return 0;
        }
        temperature = temperature * 10 + (temperature_str[i] - '0');
        if (temperature > TEMPERATURE_ABS_MAX)
        {
            return 0;
        }
    }
    if (has_minus)
    {
        sensor->temperature = -temperature;
    } else
    {
        sensor->temperature = temperature;
    }
    
    return 1;
}

int check_day_month_match(sensor_t *sensor)
{
    uint8_t month = sensor->month;
    uint16_t year = sensor->year;
    uint8_t day = sensor->day;
    if (month < MONTH_MIN || month > MONTH_MAX)
    {
        return 0;
    }
    if (year < YEAR_MIN || year > YEAR_MAX)
    {
        return 0;
    }
    if (is_leap_year(year) && month == 2)
    {
        return DAY_MIN <= day && day <= 29;
    }
    return DAY_MIN <= day && day <= month_to_count_days[month - 1];
}
