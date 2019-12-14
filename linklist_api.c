/*
 * Filename: /home/diogo/Documents/FinanceDatabase/linklist_api.c
 * Path: /home/diogo/Documents/FinanceDatabase
 * Created Date: Monday, December 2nd 2019, 11:53:39 pm
 * Author: Diogo Neves
 * 
 * Copyright (c) 2019 ME!XD
 */

#include "linklist_api.h"

operation_t * add2head(operation_t *head,operation_t *new_el){
    new_el->next_ptr=head;
    return new_el;
}

bool add2tail(operation_t *head,operation_t *new_el){
    operation_t *aux = head;
    while(aux->next_ptr!=NULL){
        aux=aux->next_ptr;
    }
    aux->next_ptr=new_el;
    return true;
}

bool addel(operation_t * head, operation_t * new_el, int32_t index){
    operation_t * aux = head;
    for(int counter=1;counter<(index-1);++counter){
        aux = aux->next_ptr;
    }
    new_el->next_ptr = aux->next_ptr;
    aux->next_ptr = new_el;
    return true;
}

operation_t * getel(operation_t * head, int32_t index){
    operation_t * element = head;
    for(int counter=1;counter<(index-1);++counter){
        element = element->next_ptr;
    }
    return element;
}

bool remtail(operation_t * head){
    operation_t *pre_tail = head;

    while(pre_tail->next_ptr->next_ptr!=NULL){
        pre_tail = pre_tail->next_ptr;
    }
    free(pre_tail+1);
    pre_tail->next_ptr = NULL;
    return true;
}

operation_t * remhead(operation_t * head){
    operation_t * new_head=head->next_ptr;
    free(head);
    return new_head;
}

bool remel(operation_t * head, int16_t index){
    
    operation_t * aux = head;
    for(int counter=1;counter<(index-1);++counter){
        aux = aux->next_ptr;
    }
    
    
    return true;
}

bool dellist(operation_t * head){
    for(int32_t counter = 1;head != NULL;++counter){
        head = remhead(head);
    }
    return true;
}

bool printlist(operation_t * head){
    
    for(operation_t * aux = head; aux!=NULL; aux=aux->next_ptr){
        printlistel(aux);
    }

    return true;
}
bool printlistel(operation_t * listel){

    printf("\n#%d in %d-%d-%d\n",listel->id, listel->time.day,listel->time.month,listel->time.year);
    printf("Title: %s\n",listel->title);
    printf("Amount: %.2f€\n",listel->amount);
    printf("Cat: %s - %s\n",listel->cat,listel->subcat);

    return true;
}


