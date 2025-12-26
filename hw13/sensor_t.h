#pragma once
#include <stdint.h>

typedef struct
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
} sensor_t;

int add_year(sensor_t *sensor, char* year_str);
int add_month(sensor_t *sensor, char* month_str);
int add_day(sensor_t *sensor, char* day_str);
int add_hour(sensor_t *sensor, char* hour_str);
int add_minute(sensor_t *sensor, char* minute_str);
int add_temperature(sensor_t *sensor, char* temperature_str);
int check_day_month_match(sensor_t *sensor);