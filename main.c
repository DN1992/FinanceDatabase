#include "read_data.h"

int main(){

    char *test_file = "data/test_file.csv";
    // TODO Link List API
    operation_t * head = malloc(sizeof(operation_t));  
    operation_t * tail = head;
    read_file(test_file);

    return 1;
}