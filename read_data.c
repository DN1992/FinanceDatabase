#include "read_data.h"

bool read_file(char *filename){
    // Variables init 
    FILE *fileID;
    operation_t * new_el;
    size_t buff_size = BUFFSIZE;
    char *buffer = malloc(buff_size*sizeof(char));
    

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
        
        new_el = str2dat_elem(buffer);
        add2back(tail,new_el);
    }
    
    /////////////////////////////////////////////////////////////////////////////////
    /////////                     CLOSING AND EXITING                      //////////
    /////////////////////////////////////////////////////////////////////////////////
    fclose(fileID);
    

    //TODO move to LINK-LIST API 
    while(list->next_ptr!=NULL){
        aux_ptr = list;
        list = list->next_ptr;
        free(aux_ptr);
    }
    if(list!=last_el){
        printf("\nLista corrompida\n");
    }
    free(buffer);
    free(list);
    return 1;       
}



/////////////////////////////////////////////////////////////////////////////////
//////////                   WRITES BUFFER INTO LIST                   //////////
/////////////////////////////////////////////////////////////////////////////////
struct Operation *str2dat_elem(char *string, operation_t *dataptr){
    // Variable init
    char * date;
    char * buffer;

    // Next list element init 
    operation_t *new_el = (operation_t *)calloc(1,sizeof(operation_t));
    new_el->id = dataptr->id + 1;
    dataptr->next_ptr = new_el;
    new_el->next_ptr = NULL;
    
    // SAVE DATE
    if((buffer=strsep(&string,";"))!=NULL){
        date = buffer;
    }
    // SAVE CASH FLOW SIGNAL
    if((buffer=strsep(&string,";"))!=NULL){
        new_el->io = (int8_t) atoi(buffer) ;
    }
    // SAVE CASH FLOW SIGNAL
    if((buffer = strsep(&string,";")) != NULL){
        strncpy(new_el->title, buffer,sizeof(new_el->title));
        new_el->title[NOTESIZE-1] = '\0';
    }
    
    if((buffer=strsep(&string,";"))!=NULL){
        new_el->amount = atof(buffer);
    }
    
    buffer=strsep(&string,";");

    if((buffer=strsep(&string,";"))!=NULL){
        strncpy(new_el->subcat,buffer,sizeof(new_el->subcat));
        new_el->subcat[CATSIZE-1] = '\0';
    }
    if((buffer=strsep(&string,";"))!=NULL){
        strncpy(new_el->cat,buffer,sizeof(new_el->cat));
        new_el->cat[CATSIZE-1] = '\0';
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
    return new_el;
}