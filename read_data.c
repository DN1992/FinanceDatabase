#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "read_data.h"
#include "struct.h"

#define SIZE 256;

bool read_file(char *filename[]){
        
    size_t buff_size = SIZE;
    char *buffer = malloc(buff_size * sizeof(char));
    // ssize_t byte_size;
    if(buffer==NULL){};

    FILE *fileID;
    char mode = "r";
    fileID = fopen(*filename,mode);
    
    if (getline(&buffer,&buff_size,fileID) == -1){
        printf("\nError!\n");
        free(buff_size);
        free(buffer);
        return 1;
    };
    printf("\n Line read: \n %s",buffer);
    free(buff_size);
    free(buffer);
    return 0;
}