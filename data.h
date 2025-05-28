//data.h

#ifndef __DATA_H
#define __DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defining the struct entry
typedef struct{
int id;
char *date;
char *type;
char *subtype;
char *description;
float amount;
}entry;


//linked list node
typedef struct node{
    entry info;
    struct node* next;
}node;

typedef struct{
    entry *arrayPointer;
    int size;
}entryArray;

#endif

