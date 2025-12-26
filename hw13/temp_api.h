#pragma once
#include <stdint.h>
#include <limits.h>
#include "sensor_t.h"

typedef struct
{
    int8_t min_temp;
    int8_t max_temp;
    float avg_temp;
    int error;
} temperature_stats;


temperature_stats get_month_stats(const sensor_t *info, int sz, uint32_t year,
    uint8_t month);
void avg_month_temperature(const sensor_t *info, int sz, uint16_t year, uint8_t month);
void min_month_temperature(const sensor_t *info, int sz, uint16_t year, uint8_t month);
void max_month_temperature(const sensor_t *info, int sz, uint16_t year, uint8_t month);

temperature_stats get_year_stats(const sensor_t *info, int sz, uint16_t year);
void avg_year_temperature(const sensor_t *info, int sz, uint16_t year);
void min_year_temperature(const sensor_t *info, int sz, uint16_t year);
void max_year_temperature(const sensor_t *info, int sz, uint16_t year);
