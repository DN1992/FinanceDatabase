#include "read_data.h"

bool read_file(char *filename){
// Variables init 
FILE *fileID;
char *mode = "r";
size_t buff_size = SIZE;
char *buffer = malloc(buff_size * sizeof(char));
operation_t *list = calloc(1,sizeof(operation_t));
list->id = 1;
list->next_ptr = NULL;
operation_t *last_el = list;

// FILE OPENING
fileID = fopen(filename,mode);
if(fileID==NULL){
    printf("\nERROR OPENING THE FILE!\n");
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////
/////////                       READS EACH LINE                        //////////
/////////////////////////////////////////////////////////////////////////////////

while(getline(&buffer,&buff_size,fileID) !=EOF){

    last_el = str2dat_elem(buffer,last_el);
}
if(DEBUG){
    printf("\nOPERATION DESCRIPTION: %s ",last_el->note);
    printf("\nOperation date: %u - %u - %u ",last_el->time.year,last_el->time.month,last_el->time.day);
    printf("\nOperation amount: %f ",last_el->amount);
    printf("\nOperation category: %s ",last_el->cat);
    printf("\nOperation account: %d \n",last_el->account);
    }

/////////////////////////////////////////////////////////////////////////////////
/////////                     CLOSING AND EXITING                      //////////
/////////////////////////////////////////////////////////////////////////////////
fclose(fileID);
free(buffer);
free(list);
return 1;
}

struct Operation *str2dat_elem(char *string, operation_t *dataptr){
    // Variable init
    char *date;
    char *datebuff;
    char *notebuff;
    // Next list element init 
    operation_t *new_el = (operation_t *)calloc(1,sizeof(operation_t));
    new_el->id = dataptr->id + 1;
    dataptr->next_ptr = new_el;
    new_el->next_ptr = NULL;
    
    // SAVE DATE DATA
    date = strtok(string,";");

    // GETS CASHFLOW DIRECTION
    new_el->io = (int8_t) atoi(strtok(NULL,";"));
    // COPIES OPERATION TITLE
    strcpy( new_el->note,strtok(NULL,";"));
    // GETS AMOUNT MOVED
    new_el->amount = atof(strtok(NULL,";"));
     // GET NOTES - NEED TO SOLVE FIELD
    notebuff = strtok(NULL,";"); 
    // COPIES MOVEMENT CATEGORY
    strcpy(new_el->cat ,strtok(NULL,";"));
    // GETS OPERATION ACCOUNT ID  
    new_el->account = (int8_t)atoi(strtok(NULL,";"));

    // DIVIDES DATE INTO A VECTOR
    datebuff = strtok(date,"-");
    if(datebuff==NULL){
        printf("\nNO DATE FOR THE OPERATION!\n");
    }
    else{
        new_el->time.day    = atoi(datebuff);
        new_el->time.month  = atoi(strtok(NULL,"-"));
        new_el->time.year   = atoi(strtok(NULL,"-"));

    }
    return new_el;
}