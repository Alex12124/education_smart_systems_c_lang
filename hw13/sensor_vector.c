#include "sensor_vector.h"
#include "stddef.h"
#include "stdlib.h"
#include "string.h"

void init(sensor_vector* v) {
    v->arr = NULL;
    v->cap = 0;
    v->sz = 0;
}

int push_back(sensor_vector* v, sensor_t val) {

    if (v->cap == 0)
    {
        sensor_t* new_arr = malloc(sizeof(sensor_t));
        if (new_arr == NULL)
        {
            return -1;
        }
        v->cap = 1;
        v->sz = 1;
        v->arr = new_arr;
        v->arr[0] = val;
        return 1;
    }
    
    if (v->cap == v->sz)
    {
        sensor_t* new_arr = malloc(sizeof(sensor_t) * v->cap * 2);
        if (new_arr == NULL)
        {
            return 0;
        }
        v->cap *= 2;
        memcpy(new_arr, v->arr, v->sz * sizeof(sensor_t));
        free(v->arr);
        v->arr = new_arr;
        v->arr[v->sz] = val;
        v->sz++;
    } else
    {
        v->arr[v->sz] = val;
        v->sz++;
    }
    return 1;
}

void pop_back(sensor_vector* v)
{
    if (v == NULL || v->arr == NULL || v->sz == 0)
    {
        return;
    }
    v->sz--;
}


void destroy(sensor_vector* v)
{
    if (v != NULL && v->arr != NULL)
    {
        free(v->arr);
        v->cap = 0;
        v->sz = 0;
    }
}
