//main.c file, contains the main function
//and the basic graphic user interface

#include "main.h"



//function declarations
void clearScreen(void);
void displayWelcome(void);
void displayMainMenu(void);
int acceptChoice(void);
int verifyChoice(int choice);
void goBack(void);

int entryCounter = 0;

//main function
int main(int argCount, char **argPointers){
//printf("%d",argCount);
//I/O stuff--------------

//will read the file
//argPointers' first element is the program's name, the second should be the file we give it
entryArray* arrayOfEntries = readFile(argPointers[1]);
//will set the entry counter to the amount of entries read
entryCounter = arrayOfEntries->size;

int choice = 0;

do{
//menu stuff--------------
clearScreen();
displayWelcome();
displayMainMenu();

choice = acceptChoice();

//clearScreen();

//will go to the option chosen
switch(choice)
{
case 1:
	clearScreen();
	displayAll(arrayOfEntries);
	goBack();
	break;
case 2:
	clearScreen();
	expenseDistribution(arrayOfEntries);
	goBack();
	break;
case 3:
	sortEntries(arrayOfEntries);
	break;
case 4:
	clearScreen();
	addEntry(arrayOfEntries, entryCounter);
	 entryCounter++;
	goBack();
	break;
case 5:
clearScreen();
	displayAll(arrayOfEntries);
	modifyEntry(arrayOfEntries);
	goBack();
	break;
case 6: 
//	filterByMonth();
	break;
case 7:
//	exit();
	break;
}

}while(choice!=7);
//end of the program
return(0);
}//end main
//-----------------------------OTHER FUNCTIONS---------------------------------------

//clears the screen of previous displays
void clearScreen(void){
system("clear");
}

//displays welcome message
void displayWelcome(void){
printf("Budget Tracking System");
printf("\n======================\n");
}

//displays the main menu
void displayMainMenu(void){
printf("1. Display all entries\n");
printf("2. Expense Distribution\n");
printf("3. Sort Entries\n");
printf("4. Add Income/Expense Entry\n");
printf("5. Modify Entry\n");
printf("6. Filter by Month\n");
printf("7. Exit\n");

printf("Choice: ");

}

//collects user input for the choice
int acceptChoice(void){
int choice;
scanf("%d", &choice );
//goes to next function
choice = verifyChoice(choice);
return choice;
}

//verifies user input for the choice
int verifyChoice(int choice){
if(choice<1 || choice>8){
printf("Invalid choice.\nEnter new choice: ");
//goes back, can cause a loop	(recursion)
acceptChoice();
}
else{
return choice;
}
}//end verify choice

//-------Go back----------//
void goBack(void){
	printf("\nTo go back to main menu, enter any character: ");
	char delay[100];
    scanf("%99s", delay);
}