#include "read_data.h"

bool read_file(char *filename){
    // Variables init 
    FILE *fileID;

    size_t buff_size = SIZE;
    char *buffer = malloc(buff_size * sizeof(char));
    operation_t *list = calloc(1,sizeof(operation_t));
    list->id = 1;
    list->next_ptr = NULL;
    operation_t *last_el = list;

    // FILE OPENING
    fileID = fopen(filename,"r");
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
    printf("\nTitulo do ultimo: \n %s\n",last_el->title);
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
    char * date;
    char * buffer;

    // Next list element init 
    operation_t *new_el = (operation_t *)calloc(1,sizeof(operation_t));
    new_el->id = dataptr->id + 1;
    dataptr->next_ptr = new_el;
    new_el->next_ptr = NULL;
    



    // SAVE DATE DATA
    if((buffer=strsep(&string,";"))!=NULL){
        date = buffer;
    }
    if((buffer=strsep(&string,";"))!=NULL){
        new_el->io = (int8_t) atoi(buffer) ;
    }
    if((buffer = strsep(&string,";")) != NULL){
        strcpy(new_el->title, buffer);
    }
    if((buffer=strsep(&string,";"))!=NULL){
        new_el->amount = atof(buffer);
    }
    
    buffer=strsep(&string,";");

    if((buffer=strsep(&string,";"))!=NULL){
        strcpy(new_el->subcat,buffer);
    }
    if((buffer=strsep(&string,";"))!=NULL){
        strcpy(new_el->cat,buffer);
    }
    if((buffer=strsep(&string,";"))!=NULL){
        if(!(strcmp(buffer,"CGD"))){
            new_el->account=1;
        }
        else if(!(strcmp(buffer,"Activo"))){
            new_el->account=2;
        }
    }

    // DIVIDES DATE INTO A VECTOR
    buffer = strsep(&date,"-");
    if(buffer==NULL){
        printf("\nNO DATE FOR THE OPERATION!\n");
    }
    else{
        new_el->time.day    = atoi( buffer );
        new_el->time.month  = atoi( strsep(&date,"-") );
        new_el->time.year   = atoi( strsep(&date,"-") );

    }
    free(date);
    free(buffer);
    return new_el;
}