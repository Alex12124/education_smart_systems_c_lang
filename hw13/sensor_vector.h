#pragma once
#include "sensor_t.h"

typedef struct {
    sensor_t* arr;
    int cap;
    int sz;
} sensor_vector;

void init(sensor_vector* v);
int push_back(sensor_vector* v, sensor_t val);
void pop_back(sensor_vector* v);
void destroy(sensor_vector* v);
