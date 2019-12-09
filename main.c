#include "read_data.h"
#include "linklist_api.h"

int main(){
    // TODO Link List API
    // TODO Test Link list API  
    
    // Choose file name
    char *test_file = "data/test_file.csv";
   
    // Get data
    operation_t * list_head = read_file(test_file);




    
    // Delete list
    for(int counter = 0;list_head->next_ptr != NULL;++counter){
        list_head = remhead(list_head);
    }   
    free(list_head);

    return true;
}