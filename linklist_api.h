/*H**********************************************************************
* FILENAME :        linklist_api.h             
*
* DESCRIPTION :
*       Link list auxiliary function lib created to manage link list 
*       elements and get the dataset from a specfic list.   
*
* PUBLIC FUNCTIONS :
*        add2head()
*        add2tail()
*        addel()
*        getel();
*        remhead()
*        remtail()
*        remel()
*
* NOTES : This List API is set to be used with a specific struct 
*         described in the header file "struct.h"
*
* AUTHOR :    Diogo Neves        START DATE :    1 Dev 19
*
* CHANGES :
*
*
*H*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "struct.h"
#include "data_operations.h"

#ifndef _LINKLIST_API
#define _LINKLIST_API

// Adds an element to the top of list
operation_t * add2head(operation_t *head,operation_t *new_el);

// Adds an element to the end of the list
bool add2tail(operation_t *head,operation_t *new_el);

// Adds an element in a specific position of the list
bool addel(operation_t * head, operation_t * new_el, int32_t index);

// Returns a pointer to the list element at the specified position
operation_t * getel(operation_t * head, int32_t index);

// Removes the last element of the list
bool remtail(operation_t * head);

// Removes the first element of list
operation_t * remhead(operation_t * head);

// Removes the element at the specified position
bool remel(operation_t * head, int16_t index);

// Deletes the list
bool dellist(operation_t * head);

// Prints all elements in the list
bool printlist(operation_t * head);

// Prints a specific element of the list
bool printlistel(operation_t * listel);

operation_t * list2array(operation_t * head, size_t N);

// Return the number of elements present in the list
size_t countelements(operation_t * head);

// Returns the concatenation of the date into a vector
int64_t datevec(date_t data);


bool writelist(operation_t * head,char *filename);

#endif