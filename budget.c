//budget.c
//logic of all the menu options

#include "budget.h"

//----------CHOICE 1: DISPLAY ALL--------------//

//displays all entries
void displayAll(entryArray* arrayOfEntries){

int size = arrayOfEntries->size;

entry** entries = arrayOfEntries->arrayPointer;

//printing the nice header------------------------
printf("\nID\t Date\t\tType\t\tCategory\tDescription\tAmount\n");
printf("--------------------------------------------------------------------------------------\n");

    for(int i = 0; i < size; i++){
    //printing the strcuture
printf("%d\t", entries[i]->id);
printf("%s\t", entries[i]->date);
printf("%s\t\t", entries[i]->type);
printf("%s\t\t", entries[i]->subtype);
printf("%s  \t", entries[i]->description);
printf("%f\t\n", entries[i]->amount);
    }


}
