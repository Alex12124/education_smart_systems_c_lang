#include <stdint.h>
#include <limits.h>

typedef struct
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
} sensor_t;




void avg_month_temperature(sensor_t *info, int sz, uint8_t month);
void min_month_temperature(sensor_t *info, int sz, uint8_t month);
void max_month_temperature(sensor_t *info, int sz, uint8_t month);
void avg_year_temperature(sensor_t *info, int sz, uint16_t year);
void min_year_temperature(sensor_t *info, int sz, uint16_t year);
void max_year_temperature(sensor_t *info, int sz, uint16_t year);
