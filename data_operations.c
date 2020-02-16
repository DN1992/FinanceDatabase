#include "data_operations.h"


int64_t datevec(date_t data){
    return (data.day + 100*data.month + 100*100*data.year);
}

// DIVIDES DATE INTO A VECTOR
void string2date(char *string,operation_t *element){
    char * buffer;
    buffer = strsep(&string,"-");
    if(buffer==NULL){
        printf("\nNO DATE FOR THE OPERATION!\n");
    }
    else{
        element->time.day    = atoi( buffer );
        element->time.month  = atoi( strsep(&string,"-") );
        element->time.year   = atoi( strsep(&string,"-") );

    }

}

// SAVE TRANSFER ACCOUNT
uint8_t accountID2integer(char *string){
    uint8_t account;
       
    if(!(strcmp(string,FIRSTACCOUNT_NAME))){
        account=1;
    }
    else if(!(strcmp(string,SECONDACCOUNT_NAME))){
        account=2;
    }
    else if(!(strcmp(string,THIRDACCOUNT_NAME))){
        account=3;
    }
    return account;
}


char * accountID2string(uint8_t numID){
    char name[ACCOUNT_NAME_SIZE];
    char * ptr = name;
    
    if(numID == 1){
        strcpy(name,FIRSTACCOUNT_NAME);
    }
    else if(numID == 2){
        strcpy(name,SECONDACCOUNT_NAME);
    }
    else if(numID == 3){
        strcpy(name,THIRDACCOUNT_NAME);
    }
    else{
        strcpy(name,"FAILLURE");
    }
    
    return ptr;
    
}