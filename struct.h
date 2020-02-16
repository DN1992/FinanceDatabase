#include "stdint.h"
#ifndef _CUSTOM_STRUCTURES
#define _CUSTOM_STRUCTURES

#define TITLESIZE 25
#define CATSIZE 18
#define NOTESIZE 60

/* Data structure cointaining the date data into positive integer fields */
typedef struct Date{
    uint16_t year;
    uint8_t month;
    uint8_t day;
} date_t;

/* Operation List Structure with 8 data fields and a pointer to the next 
 * structure allocating 152 bytes per each list element. The fields are the 
 * following:
 *      id      - field containing identification number
 *      time    - structure containing the date data
 *      account - field containing the bank account identification number  
 *      amount  - field with the transaction value
 *      cat     - field with the operation catergory string
 *      subcat  - field with the operation sub catergory string
 *      title   - field with the title given to the operation
 *      note    - notes given to the operation
 *      
 *      *next_ptr is the pointer the next data structure in the list 
 */
typedef struct Operation{
    uint32_t id;
    date_t time;
    uint8_t account;
    float amount;
    char cat[CATSIZE];
    char subcat[CATSIZE];
    char title[TITLESIZE];
    char note[NOTESIZE];
    struct Operation *next_ptr; 
} operation_t;

#endif