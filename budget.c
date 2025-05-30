//budget.c
//logic of all the menu options

#include "budget.h"

//----------CHOICE 1: DISPLAY ALL--------------//

//displays all entries
void displayAll(entryArray* arrayOfEntries){

int size = arrayOfEntries->size;

entry** entries = arrayOfEntries->arrayPointer;

printf("%s", "Finances Summary\n");
printf("======================\n\n");

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
printf("%.2f\t\n", entries[i]->amount);
    }

}//end display all

//----------CHOICE 2: EXPENSE DISTRIBUTION--------------//

void expenseDistribution(entryArray* arrayOfEntries){

    //local variables
    float totalIncome = 0;
    float totalExpenses = 0;
    float needs = 0;
    float wants = 0;
    float netBalance = 0;

    int size = arrayOfEntries->size;
    entry** entries = arrayOfEntries->arrayPointer;
    
    //cycle through all entries
    for(int i = 0; i < size; i++){
        //check type
        if (strcmp(entries[i]->type, "income") == 0){
            totalIncome = totalIncome + entries[i]->amount;
        }
        //if not income then should be an expense
        else{
            totalExpenses = totalExpenses + entries[i]->amount;
            //check want or need
            if(strcmp(entries[i]->subtype, "Needs") == 0){
                needs = needs + entries[i]->amount;
            }
            //if not a need, its a want
            else{
                wants = wants + entries[i]->amount;
            }
        }

    }//end of for

    netBalance = totalIncome - totalExpenses;

    float needsOfExpenses = needs/totalExpenses*100;
    float needsOfIncome = needs/totalIncome*100;
    
    float wantsOfExpenses = wants/totalExpenses*100;
    float wantsOfIncome = wants/totalIncome*100;
    //printing

    printf("%s", "=====Expense Distribution Report=====\n");
   
    printf("Total Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Needs: $%.2f", needs);
    printf(" (%.2f%% of expenses, %.2f%% of income)\n", needsOfExpenses, needsOfIncome);
    printf("Wants: $%.2f", wants);
    printf(" (%.2f%% of expenses, %.2f%% of income)\n", wantsOfExpenses, wantsOfIncome);
    printf("Net Balance: $%.2f\n", netBalance);

    printf("=============================================\n");


}//end expense distribution

//----------CHOICE 3: SORT ENTRIES--------------//
void sortEntries(entryArray* arrayOfEntries){

     int size = arrayOfEntries->size;
    entry** entries = arrayOfEntries->arrayPointer;

    //making the function pointers
    int(*compareIDPointer)(const void*, const void*);
    compareIDPointer = &compareID;
    int(*compareDatesPointer)(const void*, const void*);
    compareDatesPointer = &compareDates;
    int(*compareAmountsPointer)(const void*, const void*);
    compareAmountsPointer = &compareAmounts;
    int(*compareDescriptionPointer)(const void*, const void*);
    compareDescriptionPointer = &compareDescription;

clearScreen();
printf("Sort Menu\n");
printf("1. Sort by ID\n");
printf("2. Sort by Date\n");
printf("3. Sort by Amount\n");
printf("4. Sort by Description\n");

printf("Enter your choice: ");
int choice;
scanf("%d", &choice );



switch(choice)
{
case 1://sort by id
	qsort(entries,size, sizeof(entry*), compareIDPointer);
	break;
case 2:
	qsort(entries,size, sizeof(entry*), compareDatesPointer);
	break;
case 3:
	qsort(entries,size, sizeof(entry*), compareAmountsPointer);
	break;
case 4:
qsort(entries,size, sizeof(entry*), compareDescriptionPointer);
	break;
default:
    printf("invalid choice");
    break;
}
}//end sort entries

//----------CHOICE 4: ADD ENTRIES--------------//

void addEntry(entryArray* arrayOfEntries, int entryCounter){

    int size = arrayOfEntries->size;
    entry** entries = arrayOfEntries->arrayPointer;

    printf("====Add Income/Expense Entry====\n");

    //date
    
    printf("Use today's date? (y/n): ");
    char yesNo;
   scanf(" %1c", &yesNo );
    char yes = 'y';

    char dateStr[100];
   if (yesNo == yes){
    struct tm* date;
    time_t t = time(NULL);

    // Get the localtime
    date = localtime(&t);

      
       //formats data into a string
       //snprintf(destination(char array -> char*), size(bytes), format(string with the %s or %d), values(whatever))
       snprintf(dateStr, sizeof(dateStr), "%04d-%02d-%02d",
         date->tm_year + 1900, date->tm_mon + 1, date->tm_mday);
   }
   else{
        printf("\nEnter date (YYYY-MM-DD): ");
        scanf("%10s", dateStr);
   }

   //type
   printf("\nType (income/expense): ");
  char typeStr[100];
   scanf("%s", typeStr);

   //subtype
   printf("\nCategory: ");
  char subtypeStr[100];
   scanf("%s", subtypeStr);

     //description
   printf("\nDescription: ");
  char descriptionStr[100];
   scanf("%s", descriptionStr);

     //Amount
   printf("\nAmount: $");
  char amountStr[100];
   scanf("%s", amountStr);

   //id
   int id = entryCounter +101;
  

   //creaating the new entry
   entry *newEntry= malloc(sizeof(entry));

    newEntry->id = id;
    newEntry->date = strdup(dateStr);
    newEntry->type = strdup(typeStr);
    newEntry->subtype = strdup(subtypeStr);
    newEntry->description = strdup(descriptionStr);
    newEntry->amount = atof(amountStr);
//strdup() duplicates the string so it isn't erased afterwards(local varaible probelms)


    //adding the entry to the array
    entries[size]=newEntry;
    arrayOfEntries->size++;



    printf("Entry added successfully with ID: %d", entryCounter+101);
}

//----------CHOICE 5: MODIFY ENTRIES--------------//

void modifyEntry(entryArray* arrayOfEntries){

    int size = arrayOfEntries->size;
    entry** entries = arrayOfEntries->arrayPointer;

    printf("\n======Modify Entry======\n");

    printf("\nEnter ID of entry to modify: ");
    int idToModify;
     scanf("%d", &idToModify);

    //find which index this entry is at
    int index = 0;
    while(idToModify != entries[index]->id ){
        index ++;
    }


     //print out the current data
     printf("\nCurrent Details: ");
     printf("\nID: %d", entries[index]->id );
     printf("\nDate: %s", entries[index]->date );
     printf("\nType: %s", entries[index]->type );
     printf("\nSubtype: %s", entries[index]->subtype );
     printf("\nDescription: %s", entries[index]->description );
     printf("\nAmount: %.2f", entries[index]->amount );

     printf("\n What would you like to modify?");
     printf("\n1. Date");
     printf("\n2. Amount");
     printf("\nChoice: ");

     int choice;
    scanf("%d", &choice );
    //modify DATE
    if(choice == 1){
        printf("\nEnter new date (YYYY-MM-DD): ");
        char dateStr[100];
        scanf("%10s", dateStr);
        entries[index]->date = strdup(dateStr);
        printf("Entry updated successfully");
    }
    if(choice == 2){
        printf("\nEnter new amount: $");
        char amountStr[100];
        scanf("%s", amountStr);
        entries[index]->amount = atof(amountStr);
        printf("Entry updated successfully");
    }
}//end of modify entry

//----------CHOICE 6: FILTER BY MONTH--------------//

void filterByMonth(entryArray* arrayOfEntries){

    int size = arrayOfEntries->size;
    entry** entries = arrayOfEntries->arrayPointer;

    printf("\n======Filter By Month======\n");

    
    printf("\nEnter year (YYYY): ");
 char yearStr[100];
    scanf("%4s", yearStr);
    printf("\nEnter month (MM): ");
     char monthStr[100];
    scanf("%2s", monthStr);

    char dateStr[100];
   snprintf(dateStr, sizeof(dateStr), "%.4s-%.2s",
         yearStr, monthStr);
   
printf("\nEntries for %s:", dateStr);

printf("\nID\t Date\t\tType\t\tCategory\tDescription\tAmount\n");
printf("--------------------------------------------------------------------------------------\n");

int printCount=0;

    for(int i = 0; i < size; i++){

if (strncmp(entries[i]->date, dateStr, 7) == 0) {
    // The first 7 characters match
    //printing the strcuture
printf("%d\t", entries[i]->id);
printf("%s\t", entries[i]->date);
printf("%s\t\t", entries[i]->type);
printf("%s\t\t", entries[i]->subtype);
printf("%s  \t", entries[i]->description);
printf("%.2f\t\n", entries[i]->amount);
printCount ++;
    }
    }
    if(printCount == 0){
        printf("\nThere are no entries for that month");
    }
}