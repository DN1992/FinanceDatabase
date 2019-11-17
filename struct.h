#include "stdint.h"
#ifndef _CUSTOM_STRUCTURES
#define _CUSTOM_STRUCTURES

typedef struct Date{
    uint16_t year;
    uint8_t month;
    uint8_t day;
} date_t;

typedef struct Operation{
    struct operation_t *point_id;
    uint16_t id;
    date_t time;
    int8_t io;
    float amount;
    char cat[10];
    char subcat[10];
    char note[50];
    struct operation_t *next_point; 
} operation_t;


#endif