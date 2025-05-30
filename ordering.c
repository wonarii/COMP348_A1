//ordering.c
//for sorting 
#include "ordering.h"

//---------BY ID----------------//
int compareID(const void* a, const void* b){
    //casting pointers (removing 1 level of pointer)
    const entry* ea = *(const entry**)a;
    const entry* eb = *(const entry**)b;
    //comparing
    return ea->id - eb->id;
}
    

//---------BY DATE----------------//
int compareDates(const void* a, const void* b){
    //casting pointers (removing 1 level of pointer)
    const entry* ea = *(const entry**)a;
    const entry* eb = *(const entry**)b;
    return strcmp(ea->date,eb->date);
}


//---------BY AMOUNT----------------//
int compareAmounts(const void* a, const void* b){
     //casting pointers (removing 1 level of pointer)
    const entry* ea = *(const entry**)a;
    const entry* eb = *(const entry**)b;
    return ea->amount - eb->amount;
}

//---------BY DESCRIPTION----------------//
int compareDescription(const void* a, const void* b){
    //casting pointers (removing 1 level of pointer)
    const entry* ea = *(const entry**)a;
    const entry* eb = *(const entry**)b;
    return strcmp(ea->description,eb->description);
}







