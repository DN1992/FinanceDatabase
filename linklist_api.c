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
    return TRUE;
}

bool add2tail(operation_t *head,operation_t *new_el){
    operation_t *aux = head;
    while(aux->next_ptr!=NULL){
        aux=aux->next_ptr;
    }
    aux->next_ptr=new_el;
    aux=NULL;
    return TRUE;
}

bool addel(operation_t * head, operation_t * new_el, int16_t index){
    operation_t * aux = head;
    for(int counter=1;counter<(index-1);++counter){
        aux = aux->next_ptr;
    }
    new_el->next_ptr = aux->next_ptr;
    aux->next_ptr = new_el;
    return TRUE;
}
operation_t * getel();
operation_t * remtail();
operation_t * remhead();
operation_t * remel();