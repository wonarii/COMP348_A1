#ifndef __BUDGET_H
#define __BUDGET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


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

void clearScreen(void);
void displayAll(entryArray* arrayOfEntries);
void expenseDistribution(entryArray* arrayOfEntries);
void sortEntries(entryArray* arrayOfEntries);
int compareID(const void* a, const void* b);
int compareDates(const void* a, const void* b);
int compareAmounts(const void* a, const void* b);
int compareDescription(const void* a, const void* b);
void addEntry(entryArray* arrayOfEntries, int entryCounter);
#endif

