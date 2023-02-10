#include <iostream>
using namespace std;



void deposit(double &deposit, double &balance_deposit);
void withdraw(double &user_withdraw, double &balance_deposit);
void personalDisplay(string &holder_name, string &account_type, int &account_number, double &balance_deposit);

//function 1
void personalInformation(string &holder_name, string &account_type, int &account_number, double &balance_deposit)
{

    cout << "Enter account holder's name: " << endl;
    cin >> holder_name;

    cout << "Enter account type: " << endl;
    cin >> account_type;

    cout << "Enter account number: " << endl;
    cin >> account_number;

    cout << "Enter balance to deposit: " << endl;
    cin >> balance_deposit;
}

//function 2
void choiceDisplay(int &choice, string &holder_name, string &account_type, int &account_number, double &balance_deposit, double &user_withdraw, double &user_deposit)
{
    cout << "1. Your information" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "\n " << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice;

    if (choice == 1)
    {
        personalDisplay(holder_name, account_type, account_number, balance_deposit);
    }
    else if (choice == 2)
    {
        deposit(user_deposit, balance_deposit);
    }
    else if (choice == 3)
    {
        withdraw(user_withdraw, balance_deposit);
    }
    else
    {
        cout << "That is not a choice. Please try again." << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;
    }
}

//function 3
void personalDisplay(string &holder_name, string &account_type, int &account_number, double &balance_deposit)
{
    cout << "Account Holders Name: " << holder_name << endl;
    cout << "Account Type: " << account_type << endl;
    cout << "Account Number: " << account_number << endl;
    cout << "Balance of deposit: " << balance_deposit << endl;
}

//function 4
void deposit(double &deposit, double &balance_deposit)
{
    cout << "How much would you like to depost?" << endl;
    cin >> deposit;

    cout << "Your balance is now: $" << deposit + balance_deposit << endl;
}

//function 5
void withdraw(double &user_withdraw, double &balance_deposit)
{

    cout << "Your balance: $" << balance_deposit << endl;

    cout << "How much would you like to withdraw?" << endl;
    cin >> user_withdraw;

    if (user_withdraw > balance_deposit)
    {
        cout << "You do not have enough money to withdraw. Please try again. \n" << endl;
        cout << "How much would you like to withdraw?" << endl;
        cin >> user_withdraw;
    }

    cout << "Remaining balance: $" << balance_deposit - user_withdraw << endl;
}

//function 6
void addBalance(double &balance_deposit, string &balance_choice, string &holder_name_two, string &account_type_two, int &account_number_two, double &balance_deposit_two)
{
    cout << "Would you like to add your balance to another account? (y/n)" << endl;
    cin >> balance_choice;

    if (balance_choice == "y" || balance_choice == "Y")
    {
        cout << "Please enter second account information: \n"
             << endl;

        cout << "Enter account holder's name: " << endl;
        cin >> holder_name_two;

        cout << "Enter account type: " << endl;
        cin >> account_type_two;

        cout << "Enter account number: " << endl;
        cin >> account_number_two;
        
        balance_deposit_two += balance_deposit;

        balance_deposit = 0;

        cout << "Updated " << holder_name_two << "'s Account. \n" << endl;
        cout << "Balance: $" << balance_deposit_two << endl;
        cout << balance_deposit << endl;
    }
}

int main()
{
    string holder_name = " ";
    string account_type = " ";
    string ans = " ";

    //acount 2
    string balance_choice = " ";
    string holder_name_two = " ";
    string account_type_two = " ";
    int account_number_two = 0;
    double balance_deposit_two = 0;

    int account_number = 0;
    int choice = 0;

    double balance_deposit = 0;
    double user_deposit = 0;
    double user_withdraw = 0;

    while (true)
    {
        //bank display
        cout << " ____    _    _   _ _  __     _    ____ ____ ___  _   _ _   _ _____ " << endl;
        cout << "| __ )  / \\  | \\ | | |/ /    / \\  / ___/ ___/ _ \\| | | | \\ | |_   _|" << endl;
        cout << "|  _ \\ / _ \\ |  \\| | ' /    / _ \\| |  | |  | | | | | | |  \\| | | | " << endl;
        cout << "| |_) / ___ \\| |\\  | . \\   / ___ \\ |__| |__| |_| | |_| | |\\  | | | " << endl;
        cout << "|____/_/   \\_\\_| \\_|_|\\_\\ /_/   \\_\\____\\____\\___/ \\___/|_| \\_| |_|" << endl;

        //call functions
        personalInformation(holder_name, account_type, account_number, balance_deposit);
        choiceDisplay(choice, holder_name, account_type, account_number, balance_deposit, user_withdraw, user_deposit);
        addBalance(balance_deposit, balance_choice, holder_name_two, account_type_two, account_number_two, balance_deposit_two);

        cout << "Would you like to exit? (y/n)" << endl;
        cin >> ans;

        if (ans == "y" || ans == "Y")
        {
            break;
        }
        else
        {
            continue;
        }
    }
}