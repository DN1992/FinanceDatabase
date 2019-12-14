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

#ifndef _LINKLIST_API
#define _LINKLIST_API

operation_t * add2head(operation_t *head,operation_t *new_el);
bool add2tail(operation_t *head,operation_t *new_el);
bool addel(operation_t * head, operation_t * new_el, int32_t index);
operation_t * getel(operation_t * head, int32_t index);
bool remtail(operation_t * head);
operation_t * remhead(operation_t * head);
bool remel(operation_t * head, int16_t index);
bool dellist(operation_t * head);

bool printlist(operation_t * head);
bool printlistel(operation_t * listel);

#endif