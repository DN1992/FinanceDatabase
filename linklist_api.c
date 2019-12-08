/*
 * Filename: /home/diogo/Documents/FinanceDatabase/linklist_api.c
 * Path: /home/diogo/Documents/FinanceDatabase
 * Created Date: Monday, December 2nd 2019, 11:53:39 pm
 * Author: Diogo Neves
 * 
 * Copyright (c) 2019 ME!XD
 */

#include "linklist_api.h"


bool add2head(operation_t *head,operation_t *new_el){
    new_el->next_ptr=head;
    head = new_el;
    return true;
}

bool add2tail(operation_t *head,operation_t *new_el){
    operation_t *aux = head;
    while(aux->next_ptr!=NULL){
        aux=aux->next_ptr;
    }
    aux->next_ptr=new_el;
    aux=NULL;
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

bool remhead(operation_t * head){
    operation_t * new_head=head;
    head=head->next_ptr;
    free(new_head);
    return true;
}

bool remel(operation_t * head, int16_t index){
    
    operation_t * aux = head;
    for(int counter=1;counter<(index-1);++counter){
        aux = aux->next_ptr;
    }
    
    
    return true;
}