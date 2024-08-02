//? Create a Project to demonstrate an ATM Banking Application which will help to get to
//know the bank information.. The Project should contain all the necessary
//requirements i.e A Program should use the concept of OOP.(compulsory :
//Constructor),Make use of scope resolution operator, Loops, ConditionalStatements,
//Whichever is required.
//? Give comments where it is required , for better understanding of codes. It will help
//you and the project evaluator.
//? A Project should contain the following execution flow.
//1. The very first task is to Display the Welcome SCREEN for the User.
//It should display the current Date and Time
//A Menu to display the choice, Consider ATM PIN as 12345
//2. For Choice 1 : Enter the ATM Pin i.e 12345 and make use of logic for ONE Attempt only.
//3. For Choice 2 : It should display the Help Screen like this.
//4. For Incorrect PIN ( Exit the Screen with a Message Display )
//5. If PIN Entered is Correct, then the Program should display the Menu Screen.
//6. Select the Choice : Ask For DEPOSIT ,Enter the Amount to Deposit , Give the Initial Starting
//account balance as Rs. 60000 and Present Account balance as Rs. 20000,the Screen should
//display as shown:
//7. For UnSucessful Withdrawal : The Screen should be shown as below :
//8. Display the Appropriate output for checking the balance.
//9. After completion this project upload it on GitHub
//• Upload all features in develop branch after completion all features




#include <iostream>
#include <ctime>
using namespace std;

class ATM {
private:
    int pin;
    double balance;
    const int correctPin = 12345;

public:
   
    ATM() : balance(20000), pin(0) {}

    void displayWelcomeScreen() 
	{
        time_t now = time(0);
        char* dt = ctime(&now);
        cout << "*********************************" << endl;
        cout << "      Welcome to ATM Banking     " << endl;
        cout << "      Current Date and Time:     " << endl;
        cout << dt;
        cout << "*********************************" << endl;
    }

    void displayMenu() 
	{
        cout << "Please choose an option:" << endl;
        cout << "1. Enter ATM PIN" << endl;
        cout << "2. Help" << endl;
        cout << "3. Exit" << endl;
    }

    void displayHelpScreen() 
	{
        cout << "*********************************" << endl;
        cout << "Help Screen:" << endl;
        cout << "1. Enter the correct ATM PIN (12345) to access your account." << endl;
        cout << "2. You have only one attempt to enter the correct PIN." << endl;
        cout << "3. Use the menu to Deposit, Withdraw, or Check Balance." << endl;
        cout << "*********************************" << endl;
    }

    bool enterPin() 
	{
        cout << "Enter ATM PIN: ";
        cin >> pin;
        if (pin == correctPin) 
		{
            return true;
        } 
		else 
		{
            cout << "Incorrect PIN. Exiting the screen..." << endl;
            return false;
        }
    }

    void showAccountMenu() 
	{
        int choice;
        cout << "Account Menu:" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) 
		{
            case 1:
                deposit();
                break;
                
            case 2:
                withdraw();
                break;
                
            case 3:
                checkBalance();
                break;
                
            case 4:
                cout << "Exiting..." << endl;
                break;
                
            default:
                cout << "Invalid choice. Exiting..." << endl;
        }
    }

    void deposit() 
	{
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Deposit successful. Current balance: Rs. " << balance << endl;
    }

    void withdraw() 
	{
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > balance) 
		{
            cout << "Unsuccessful withdrawal. Insufficient balance." << endl;
        } 
		else 
		{
            balance -= amount;
            cout << "Withdrawal successful. Current balance: Rs. " << balance << endl;
        }
    }

    void checkBalance() 
	{
        cout << "Current balance: Rs. " << balance << endl;
    }
};

int main() 
{
    ATM atm;
    atm.displayWelcomeScreen();
    atm.displayMenu();

    int choice;
    cin >> choice;

    switch (choice) 
	{
        case 1:
            if (atm.enterPin()) 
			{
                atm.showAccountMenu();
            }
            break;
            
        case 2:
            atm.displayHelpScreen();
            break;
            
        case 3:
            cout << "Exiting..." << endl;
            break;
            
        default:
            cout << "Invalid choice. Exiting..." << endl;
    }

    return 0;
}






