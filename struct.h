#include "stdint.h"
#ifndef _CUSTOM_STRUCTURES
#define _CUSTOM_STRUCTURES

#define NOTESIZE 60
#define CATSIZE 15

typedef struct Date{
    uint16_t year;
    uint8_t month;
    uint8_t day;
} date_t;

typedef struct Operation{
    uint32_t id;
    date_t time;
    uint8_t account;
    float amount;
    char cat[CATSIZE];
    char subcat[CATSIZE];
    char title[NOTESIZE];
    struct Operation *next_ptr; 
} operation_t;

#endif