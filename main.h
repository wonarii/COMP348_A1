//header file for main.c

#ifndef __MAIN_H
#define __MAIN_H
//stuff to include will go here
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//publibly accessible functions:
void readFile(char *filename);

//defining struct entry
typedef struct{
int id;
char *date;
char *type;
char *subtype;
char *description;
float amount;
}entry;


#endif
