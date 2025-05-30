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
    printf("Net Balance: $%.2f", netBalance);

    printf("=============================================\n");


}//end expense distribution