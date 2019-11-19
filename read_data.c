#include "read_data.h"

bool read_file(char *filename){
// Variables init 
FILE *fileID;
char *mode = "r";
size_t buff_size = SIZE;
char *buffer = malloc(buff_size * sizeof(char));
struct Operation *pile = (struct Operation *)calloc(1,sizeof(operation_t));

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
    string2data(buffer,pile);

}
if(DEBUG){
    printf("\n\n\nOperation description:\n%s ",pile->note);
    printf("\nOperation date: %u - %u - %u ",pile->time.year,pile->time.month,pile->time.day);
    printf("\nOperation amount: %f ",pile->amount);
    }

fclose(fileID);
free(buffer);
free(pile);
return 1;
}

bool string2data(char *string, operation_t *dataptr){
    // Variable init
    char *date;
    char *datebuff;
    char *notebuff;
    
    date = strtok(string,";");
    dataptr->io = (int8_t) atoi(strtok(NULL,";"));
    notebuff = strtok(NULL,";");
    strcpy( dataptr->note,notebuff);
    dataptr->amount = atof(strtok(NULL,";"));
    notebuff = strtok(NULL,";"); // NEED TO SOLVE NOTES FIELD
    notebuff = strtok(NULL,";");
    strcpy( dataptr->cat ,notebuff);
    dataptr->account = (int8_t)atoi(strtok(NULL,";"));


    datebuff = strtok(date,"-");
    if(datebuff==NULL){
        printf("\nNO DATE FOR THE OPERATION!\n");
    }
    else{
        dataptr->time.day    = atoi(datebuff);
        dataptr->time.month   = atoi(strtok(NULL,"-"));
        dataptr->time.year     = atoi(strtok(NULL,"-"));

    }
    return 1;
}