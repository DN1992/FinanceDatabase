/*
 * Filename: /home/diogo/Documents/FinanceDatabase/main.c
 * Path: /home/diogo/Documents/FinanceDatabase
 * Created Date: Sunday, December 1st 2019, 11:12:14 pm
 * Author: Diogo Neves
 * 
 * Copyright (c) 2019 Your Company
 */


#include "read_data.h"
#include "linklist_api.h"

void Stack_or_heap(void* ptr);

int main(){
    
    // Choose file name
    char * test_file = "data/test_file.csv";
    // Get data
    operation_t * list_head = read_file(test_file);
    
    printlist(list_head);
    
    char filename[] = "testelist.txt";
    writelist(list_head,filename);

    // Delete list
    dellist(list_head);
    return true;
}