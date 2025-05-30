//ordering.h

#ifndef __ORDERING_H
#define __ORDERING_H

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

int acceptChoice(void);
int compareID(const void* a, const void* b);
int compareDates(const void* a, const void* b);
int compareAmounts(const void* a, const void* b);
int compareDescription(const void* a, const void* b);

#endif