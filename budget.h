#ifndef __BUDGET_H
#define __BUDGET_H

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


typedef struct{
    entry **arrayPointer;
    int size;
}entryArray;

void displayAll(entryArray* arrayOfEntries);
void expenseDistribution(entryArray* arrayOfEntries);


#endif

