#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef _DATA_OPERATIONS
#define _DATA_OPERATIONS

#include "struct.h"
#include "params.h"

// Returns the concatenation of the date into a vector 
int64_t datevec(date_t data);

// DIVIDES DATE INTO A VECTOR
void vec2date(char *string[],operation_t *element);


char * accountID2string(uint8_t numID);

uint8_t accountID2integer(char *string);

#endif