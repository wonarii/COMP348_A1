
//data.c
//reads the input file and then stores the information
#include "data.h"

//constants
const char *PIPE = "|";
const char *NEWLINE = "\n";

//declaring the functions
entryArray* readFile(char filename[]);
entry* createStruct(FILE* fp);
char* collectData(FILE* fp);

char endChar = '0';
//node *head = NULL;


entryArray* readFile(char filename[]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open %s \n", filename);
        return NULL;
    }

    int size = 50;
    int index = 0;

    //memory allocated for an array of pointers to entry structs
    entry **entries = malloc(size * sizeof(entry*));
    //if the memory allocation fails, entries will be NUL, NULL=0
    if (!entries) return NULL;

    while (endChar != EOF) {
        //in case no space left in array
        /*/
        if (index >= size) {
            size *= 2;
            //reallocating to a doubly sized array
            entry *temp = realloc(entries, size * sizeof(entry*));
            //if it doesn'nt work
            if (temp ==NULL){ 
                    //ERROR CODE HERE?
                break;}
            entries = temp;
        }
            */
        //will create entry structs to fill the array by reading the file

         entries[index] = createStruct(fp);
       
        index++;
    }

    //i need to storeeverything in an entryArray struct to remember the size nd contents
    entryArray *pointerToArrayOfEntries = malloc(sizeof(entryArray));
    pointerToArrayOfEntries->arrayPointer = entries;
    pointerToArrayOfEntries->size = index; 

    //closes the file pointer:)
    fclose(fp);
    return pointerToArrayOfEntries;

}//end of readFile


//creating a struct with the data collected
entry* createStruct(FILE* fp){

    //temporary strings to hold the data
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



char* dataPointer = strdup(data); 

return dataPointer;
}//end of collectData


///----------------------------WRITING TO THE FILE------------------------------//

entryArray* writeToFile(char filename[], entryArray* arrayOfEntries) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Could not open %s \n", filename);
        return NULL;
    }

    int size = arrayOfEntries->size;
    entry** entries = arrayOfEntries->arrayPointer;

    //I will use a for loop to write each entry
    for(int i =0; i < size; i++){
//creating the string for 1 entry
char entryStr[606];
snprintf(entryStr, sizeof(entryStr), "%d|%s|%s|%s|%s|%.2f\n",
         entries[i]->id, entries[i]->date, entries[i]->type, entries[i]->subtype, entries[i]->description, entries[i]->amount);
//printing the entry to the file
fprintf(fp,"%s", entryStr);
    }

    fclose(fp);
}

//------------CLEAN UP---------------//

void cleanUp(entryArray* arrayOfEntries) {
    //if arrayOfEntries is null
    if (!arrayOfEntries) return;

    int size = arrayOfEntries->size;
    entry **entries = arrayOfEntries->arrayPointer;

    //frees all the entries, data by data
    for (int i = 0; i < size; i++) {
        if (entries[i]) {
            free(entries[i]->date);
            free(entries[i]->type);
            free(entries[i]->subtype);
            free(entries[i]->description);
            free(entries[i]);
        }
    }
    //then free the array of entries
    free(entries);
    //then free the struct with the array of entries in it
    free(arrayOfEntries);
}

