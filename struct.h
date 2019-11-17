#include "stdint.h"
#ifndef _CUSTOM_STRUCTURES
#define _CUSTOM_STRUCTURES

struct Date{
    uint16_t year;
    uint8_t month;
    uint8_t day;
} date_t;

struct Operation{
    Operation   *point_id;
    uint16_t    id;
    Date        time;
    int8_t      io;
    float       amount;
    char        cat[10];
    char        subcat[10];
    char        note[50];
    Operation   *next_point; 
} operation;


#endif