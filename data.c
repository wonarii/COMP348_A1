
//data.c
//reads the input file and then stores the information
#include "data.h"

//constants
const char *PIPE = "|";
const char *NEWLINE = "\n";

//declaring the functions
struct entry[] readFile(char filename[]);
struct entry createStruct(char data[]);
char* collectData(void);


//will return an array of struct
struct* readFile(char filename[]){

//creates the file pointer
FILE *fp;
fp = fopen(filename,"r");

//if file cannot be read
if(fp == NULL) {
printf("Could not open %s \n", filename);
//exit();
}

//creating an array of struct
struct entry entries[];

entries[0]=createStruct();

//printing the strcuture
printf("id: %d\n", entries[0].id);
printf("date: %s\n", entries[0].date);
printf("type: %s\n", entries[0].type);
printf("subtype: %s\n", entries[0].subtype);
printf("description: %s\n", entries[0].description);
printf("amount: %f\n", entries[0].amount);



}//end of readFile


//creating a struct with the data collected
struct *entry createStruct(char data[]){

//struct entry *newEntry= malloc(sizeof(struct entry));
struct entry newEntry;

//id
newEntry.id = atoi(collectData());
//date
strcpy(newEntry.date, collectData());
//type
newEntry.type = collectData();
//subtype
newEntry.subtype = collectData();
//description
newEntry.description = collectData();
//amount
newEntry.amount = atof(collectData());

return newEntry;
}//end of create struct


char* collectData(void){
//collecting data

char data[100]="";
char nextChar =fgetc(fp);
int counter = 0;
int lengthOfString;

while(nextChar != *PIPE && counter <100 && nextChar != *NEWLINE){
printf("in da loop");

strncat(data, &nextChar, 1);

nextChar = fgetc(fp);
counter ++;
}//end of while
//when while exits, we should have the a complete piece of data

//for testing
printf("%s", data);
//to skip the | or \n
fp=fp+1;

int size = data.strlen();

//pointer to an array of "size" characters
char* dataPointer = (char*)malloc(size * sizeof(char));

//filling the array
for(int i = 0; i < size; i++){
dataPointer[i] = data[i];
}

return dataPointer;
}//end of collectData
