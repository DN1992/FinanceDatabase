/*
 * Filename: /home/diogo/Documents/FinanceDatabase/aux.c
 * Path: /home/diogo/Documents/FinanceDatabase
 * Created Date: Saturday, December 14th 2019, 7:36:02 pm
 * Author: Diogo Neves
 * 
 * Copyright (c) 2019 Your Company
 */

void Stack_or_heap(void* ptr) {
    int dummy;
    switch (ptr > &dummy){
        case 0:
            printf("\nList is on heap\n");
        break;
        case 1:
            printf("\nList is on stack\n");
        break;
    }
}