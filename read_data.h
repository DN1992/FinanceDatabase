/*H**********************************************************************
* FILENAME :        read_data.h             
*
* DESCRIPTION :
*       File compression and decompression routines.
*
* PUBLIC FUNCTIONS :
*       bool    read_file( char * filename)
*
* NOTES :
*       These functions are responsible for the reading of the data in
*       the csv files and writting it into the structured list.
*       See www.SITE.com for more info
*
* AUTHOR :    Diogo Neves        START DATE :    17 Nov 19
*
* CHANGES :
*         -
*
*H*/

// Linux libraries
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom libraries
#include "struct.h"
#include "linklist_api.h"

// Functions parameters
#define BUFFSIZE 2048
#define DEBUG 1

// Opens the file and reads each line of data
operation_t * read_file(char *filename);

// Transforms the line string into data
operation_t * str2dat_elem(char *stringr);

// Transforms the string into a date
bool string2date();
