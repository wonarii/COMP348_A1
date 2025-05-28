
//data.c
//reads the input file and then stores the information
#include "data.h"

//constants
const char *PIPE = "|";
const char *NEWLINE = "\n";

//declaring the functions
//entryArray
void readFile(char filename[]);
entry* createStruct(FILE* fp);
char* collectData(FILE* fp);

char endChar = '0';
node *head = NULL;

//will return a struct containing an array--------------------
//entryArray 
void readFile(char filename[]){

//creates the file pointer
FILE *fp = fopen(filename,"r");

//if file cannot be read
if(fp == NULL) {
printf("Could not open %s \n", filename);
//exit();
}



//linked list
/*

while(endChar != EOF){

if(head == NULL){
    node newNode = {
        .info = createStruct(fp),
        .next = NULL;
    };
    head = &newNode;

}
else{
    node newNode = {
        .info = createStruct(fp),
        .next = head;
    };
}
}
*/
//FAILED ARRAY STUFF_------------------------------------------------
/*
int size = 100;
//creating an array of struct pointers
entry entries[size];

//creating a pointer to the array of struct pointers
entry*entryArrayPointer = &entries[size];

int index=0;

while(endChar != EOF){

    //if array is full, double the size
    if(index >= size){
        entry newEntries[size*2];
        for(int i=0; i<size; i++){
            newEntries[i]= entries[i];
        }
        size = size*2;
        entryArrayPointer = &newEntries[size];
    }

/*(entryArrayPointer+index)=*createStruct(fp);

//printing the strcuture
printf("id: %d\n", entries[0].id);
printf("date: %s\n", entries[0].date);
printf("type: %s\n", entries[0].type);
printf("subtype: %s\n", entries[0].subtype);
printf("description: %s\n", entries[0].description);
printf("amount: %f\n", entries[0].amount);

//increments index for the next spot in the array
index ++;
}

entryArray arrayOfEntries={
    .arrayPointer = entryArrayPointer,
    .size = size
} ;

return arrayOfEntries;*/


}//end of readFile


//creating a struct with the data collected
entry* createStruct(FILE* fp){

    //temporary sstrings to hold the data
 char* idStr = collectData(fp);
    char* dateStr = collectData(fp);
    char* typeStr = collectData(fp);
    char* subtypeStr = collectData(fp);
    char* descStr = collectData(fp);
    char* amountStr = collectData(fp);


entry *newEntry= malloc(sizeof(entry));

    newEntry->id = atoi(idStr);
    newEntry->date = dateStr;
    newEntry->type = typeStr;
    newEntry->subtype = subtypeStr;
    newEntry->description = descStr;
    newEntry->amount = atof(amountStr);

printf("id: %d\n", newEntry->id);
printf("date: %s\n", newEntry->date);
printf("type: %s\n", newEntry->type);
printf("subtype: %s\n", newEntry->subtype);
printf("description: %s\n", newEntry->description);
printf("amount: %f\n", newEntry->amount);

//id
//newEntry->id = atoi(collectData());
//date
//strcpy(newEntry->date, collectData());
//type
//newEntry.type = collectData();
//subtype
//newEntry.subtype = collectData();
//description
//newEntry.description = collectData();
//amount
//newEntry.amount = atof(collectData());



return newEntry;
}//end of create struct


char* collectData(FILE* fp){
//collecting data

char data[100]="";
char nextChar =fgetc(fp);
int counter = 0;
int lengthOfString;

while(nextChar != *PIPE && counter <100 && nextChar != *NEWLINE && nextChar!= EOF){

strncat(data, &nextChar, 1);

nextChar = fgetc(fp);
counter ++;
}//end of while
//when while exits, we should have the a complete piece of data

//when the end of the file is reached
if(nextChar == EOF){
    endChar = EOF;
}

else{
//for testing
printf("TESTING: %s END", data);

}

char* dataPointer = strdup(data); 

return dataPointer;
}//end of collectData
