/*
 * Filename: /home/diogo/Documents/FinanceDatabase/linklist_api.c
 * Path: /home/diogo/Documents/FinanceDatabase
 * Created Date: Monday, December 2nd 2019, 11:53:39 pm
 * Author: Diogo Neves
 * 
 * Copyright (c) 2019 ME!XD
 */

#include "linklist_api.h"

// Adds an element to the top of list
operation_t * add2head(operation_t *head,operation_t *new_el){
    new_el->next_ptr=head;
    return new_el;
}

// Adds an element to the end of the list
bool add2tail(operation_t *head,operation_t *new_el){
    operation_t *aux = head;
    while(aux->next_ptr!=NULL){
        aux=aux->next_ptr;
    }
    aux->next_ptr=new_el;
    return true;
}

// Adds an element in a specific position of the list
bool addel(operation_t * head, operation_t * new_el, int32_t index){
    operation_t * aux = head;
    for(int counter=1;counter<(index-1);++counter){
        aux = aux->next_ptr;
    }
    new_el->next_ptr = aux->next_ptr;
    aux->next_ptr = new_el;
    return true;
}

// Returns a pointer to the list element at the specified position
operation_t * getel(operation_t * head, int32_t index){
    operation_t * element = head;
    for(int counter=1;counter<(index-1);++counter){
        element = element->next_ptr;
    }
    return element;
}

// Removes the last element of the list
bool remtail(operation_t * head){
    operation_t *pre_tail = head;

    while(pre_tail->next_ptr->next_ptr!=NULL){
        pre_tail = pre_tail->next_ptr;
    }
    free(pre_tail+1);
    pre_tail->next_ptr = NULL;
    return true;
}

// Removes the first element of list
operation_t * remhead(operation_t * head){
    operation_t * new_head=head->next_ptr;
    free(head);
    return new_head;
}

// Removes the element at the specified position
bool remel(operation_t * head, int16_t index){
    
    operation_t * aux = head;
    for(int counter=1;counter<(index-1);++counter){
        aux = aux->next_ptr;
    }
    
    
    return true;
}

// Deletes the list
bool dellist(operation_t * head){
    for(int32_t counter = 1;head != NULL;++counter){
        head = remhead(head);
    }
    return true;
}

// Prints all elements in the list
bool printlist(operation_t * head){
    
    for(operation_t * aux = head; aux!=NULL; aux=aux->next_ptr){
        printlistel(aux);
    }

    return true;
}

// Prints a specific element of the list
bool printlistel(operation_t * listel){

    printf("\n#%d in %d-%d-%d\n",listel->id, listel->time.day,listel->time.month,listel->time.year);
    printf("Title: %s\n",listel->title);
    printf("Amount: %.2f€\n",listel->amount);
    printf("Cat: %s - %s\n",listel->cat,listel->subcat);

    return true;
}

// TODO: Check what this function does
operation_t* list2array(operation_t * head, size_t N){
    operation_t *aux_ptr;
    int counter=0;
    operation_t *list_array[N];
    for(aux_ptr=head;aux_ptr!=NULL;aux_ptr=aux_ptr->next_ptr){
        list_array[counter] = aux_ptr;
        ++counter;
    }
    return *list_array;
}

// Return the number of elements present in the list
size_t countelements(operation_t * head){
    size_t counter=0;
    operation_t *aux = head;
    while(aux!=NULL){
        ++counter;
        aux=aux->next_ptr;
    }
    return counter;
}

bool writelist(operation_t * head,char *filename){
    operation_t *aux = head;
    FILE *fileID;
    fileID = fopen(filename,"w");
    if(fileID==NULL){
        printf("\nERROR OPENING THE FILE!\n");
        return 0;
    }
    while(aux!=NULL){

        fprintf(fileID,"%d-%d-%d;%s;%.2f;%s;%s;%d\n", aux->time.day, 
                                aux->time.month,aux->time.year, aux->title, 
                                aux->amount, aux->cat, aux->subcat, aux->account);
        aux = aux->next_ptr;
    }
    fclose(fileID);
    return true;
}

// TODO: FIELD CRITERIA
// TODO: SORTING ROUTINE