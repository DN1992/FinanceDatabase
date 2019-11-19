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

// Functions parameters
#define SIZE 256
#define DEBUG 1

// Opens the file and reads each line of data
bool read_file(char *filename);

// Transforms the line string into data
bool string2data();

// Transforms the string into a date
bool string2date();
