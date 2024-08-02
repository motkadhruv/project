//• Write a program to demonstrate a Food Billing System.
//• Display the Menu using appropriate codes.
//• For Menu kinds of Programming , use the core logic of
//Loops/conditional statements.
//• You need to strictly follow the syntaxes’s of that logic which you are
//using.
//• Write the necessary comments for better understanding to you as well
//as to the faculty.
//Adhere to the coding principles
//Execution Flow of the Project:
//o First, display the food items available
//o Then after the user can choose any of the item displayed
//o Also take the quantity of selected food item by the customer, then ask
//the user that he/she wanna select more?
//o If yes then again display the food items available and take an order from
//the customer. Here, you have to consider the total bill as the price of
//food items previously selected plus the price of new items added
//should display as a whole bill.
//o If no then display the final bill on the screen
//Example of such system id given below



#include <stdio.h>
#include <string.h>

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Burger - 100.00rs\n");
    printf("2. Pizza - 150.00rs\n");
    printf("3. dosa - 120.00rs\n");
    printf("4. cooldring - 20.00rs\n");
    printf("5. Exit\n");
}

float getItemPrice(int itemCode) 
{
    switch (itemCode) 
	{
        case 1: return 100.00;
        case 2: return 150.00;
        case 3: return 120.00;
        case 4: return 20.00;
        default: return 0.00;
    }
}

int main() 
{
    int itemCode, quantity;
    float totalBill = 0.0;
    char choice;

    do {
        displayMenu();
        printf("Please select an item (1-5): ");
        scanf("%d", &itemCode);

        if (itemCode == 5) 
		{
            break;
        }


        printf("Enter the quantity: ");
        scanf("%d", &quantity);
        totalBill += getItemPrice(itemCode) * quantity;

        printf("Do you want to select more items? (y/n): ");
        scanf(" %c", &choice);

    } 
	while (choice == 'y' || choice == 'Y');

    printf("\nYour total bill is: rs%.2f\n", totalBill);
    printf("Thank you for visiting our restaurant!\n");

    return 0;
}


