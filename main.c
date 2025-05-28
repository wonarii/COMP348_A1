//main.c file, contains the main function
//and the basic graphic user interface

#include "main.h"

//function declarations
void clearScreen(void);
void displayWelcome(void);
void displayMainMenu(void);
int acceptChoice(void);
int verifyChoice(int choice);


//main function
int main(int argCount, char **argPointers){
//printf("%d",argCount);
//I/O stuff--------------

//will read the file
//argPointers' first element is the program's name, the second should be the file we give it
readFile(argPointers[1]);

//menu stuff--------------
//clearScreen();
displayWelcome();
displayMainMenu();

int choice = acceptChoice();

//clearScreen();

//will go to the option chosen
switch(choice)
{
case 1:
//	displayAll();
	break;
case 2:
//	expenseDistribution();
	break;
case 3:
//	sortEntries();
	break;
case 4:
//	addEntry();
	break;
case 5:
//	modifyEntry();
	break;
case 6: 
//	filterByMonth();
	break;
case 7:
//	exit();
	break;
}

//end of the program
return(0);
}

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
}
