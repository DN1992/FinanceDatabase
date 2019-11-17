#include "read_data.h"

bool read_file(char *filename){
// Variables init 
FILE *fileID;
char *mode = "r";
size_t buff_size = SIZE;
char *buffer = malloc(buff_size * sizeof(char));

// Check filename integrity
if(DEBUG){
    printf("\nFile: %s\n",filename);
}

// FILE OPENING
fileID = fopen(filename,mode);
if(fileID==NULL){
    printf("\nERROR OPENING THE FILE!\n");
    return 0;
}
// READING EACH LINE
while(getline(&buffer,&buff_size,fileID) !=EOF){
    // Check line data integrity
    if(DEBUG){
        printf("\n Line data: \n %s",buffer);
    }
    string2data(buffer);

}
fclose(fileID);
free(buffer);
return 1;
}


bool string2data(char *string){
    // Variable init
    char *date;
    char *datebuff;
    int year;
    int month;
    int day;

    date = strtok(string,";");
    datebuff = strtok(date,"-");
    if(datebuff==NULL){
        printf("\nNO DATE FOR THE OPERATION!\n");
    }
    else{
        year = atoi(datebuff);
    }
    return 1;
}