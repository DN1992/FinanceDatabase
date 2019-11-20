#include "stdint.h"
#ifndef _CUSTOM_STRUCTURES
#define _CUSTOM_STRUCTURES

typedef struct Date{
    uint16_t year;
    uint8_t month;
    uint8_t day;
} date_t;

typedef struct Operation{
    uint32_t id;
    date_t time;
    uint8_t account;
    int8_t io;
    float amount;
    char cat[10];
    char subcat[10];
    char note[50];
    struct Operation *next_ptr; 
} operation_t;

#endif