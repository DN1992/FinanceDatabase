/*
 * Filename: /home/diogo/Documents/FinanceDatabase/read_data.c
 * Path: /home/diogo/Documents/FinanceDatabase
 * Created Date: Sunday, December 8th 2019, 10:45:52 pm
 * Author: Diogo Neves
 * 
 * Copyright (c) 2019 Your Company
 */


#include "read_data.h"

operation_t * read_file(char *filename){
    // Variables init 
    FILE *fileID;

    size_t buff_size = BUFFSIZE;
    char *buffer = calloc(buff_size,sizeof(char));
    operation_t * list = (operation_t *)calloc(1,sizeof(operation_t));
    list->id = 1;
    unsigned int counter = 1;
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
        last_el = str2dat_elem(buffer);
        add2tail(list,last_el);
        last_el->id = (counter++);
    }
    
    /////////////////////////////////////////////////////////////////////////////////
    /////////                     CLOSING AND EXITING                      //////////
    /////////////////////////////////////////////////////////////////////////////////
    fclose(fileID);
    free(buffer);
    list = remhead(list);
    return list;     
}



/////////////////////////////////////////////////////////////////////////////////
//////////                   WRITES BUFFER INTO LIST                   //////////
/////////////////////////////////////////////////////////////////////////////////
operation_t * str2dat_elem(char *string){
    // Variable init
    char * buffer;
    int8_t io;


    // Next list element init 
    operation_t * new_el = (operation_t *)calloc(1,sizeof(operation_t));
    new_el->next_ptr = NULL;
    
    // SAVE DATE
    if((buffer=strsep(&string,";"))!=NULL){
        string2date(buffer,new_el);
    }
    // SAVE CASH FLOW SIGNAL
    if((buffer=strsep(&string,";"))!=NULL){
        io = (int8_t) atoi(buffer) ;
        io = ( io == 0 ? -1 : 1 );
    }
    
    // SAVE TRANSFER TITLE
    if((buffer = strsep(&string,";")) != NULL){
        strncpy(new_el->title, buffer,sizeof(new_el->title));
        new_el->title[NOTESIZE-1] = '\0';
    }
    
    // SAVE TRANSFER AMOUNT
    if((buffer=strsep(&string,";"))!=NULL){
        new_el->amount = (float) io*atof(buffer);
    }
    
    // DISCARD TRANSFER NOTE
    buffer=strsep(&string,";");

    // SAVE TRANSFER CATEGORIES
    if((buffer=strsep(&string,";"))!=NULL){
        strncpy(new_el->subcat,buffer,sizeof(new_el->subcat));
        new_el->subcat[CATSIZE-1] = '\0';
    }
    if((buffer=strsep(&string,";"))!=NULL){
        strncpy(new_el->cat,buffer,sizeof(new_el->cat));
        new_el->cat[CATSIZE-1] = '\0';
    }
    // SAVE TRANSFER ACCOUNT
    if((buffer=strsep(&string,";"))!=NULL){
        new_el->account=accountID2integer(buffer);
    }


    return new_el;
}