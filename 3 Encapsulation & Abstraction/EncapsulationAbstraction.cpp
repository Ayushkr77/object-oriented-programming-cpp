// note that in this file, many commits will be there, those are versions which represents the learning progress how we learnt each thing one by one. Try to see all the commits of this file. Also, see every block, every comment, and every change carefully.

// ============================================================================
// EncapsulationAbstraction.cpp
//
// This file contains the complete implementation of Day 3 concepts.
// Each Git commit represents one version, gradually introducing
// encapsulation, data hiding, getters & setters, abstraction,
// interface vs implementation, pure virtual functions,
// abstract classes, and finally the difference between
// encapsulation and abstraction.
//
// Explore the commit history to see how the code evolves step by step.
// ============================================================================





#include<bits/stdc++.h>
using namespace std;

// BankAccount class demonstrating basic encapsulation. Encapsulation = Data + Functions inside one class.
class BankAccount
{
private:    // Data is hidden inside the class
    string accountHolder;
    int accountNumber;
    double balance;

public:     // Functions provide controlled interaction with the object

    // Member Function Definition
    void setAccountHolder(string accountHolder);
    void setAccountNumber(int accountNumber);

    void deposit(double amount);
    void withdraw(double amount);
    void checkBalance();
    
    string getAccountHolder();
    int getAccountNumber();
    double getBalance();


    // Member Function Definition
    void displayAccount();
};


// Deposit money into the account
// Instead of allowing users to directly modify the balance using setBalance(), we expose meaningful operations like deposit() and withdraw(). This hides the internal implementation and demonstrates abstraction.
void BankAccount::deposit(double amount)
{
    if (amount > 0)
    {
        balance += amount;
        cout << "Rs. " << amount << " deposited successfully.\n";
    }
    else
    {
        cout << "Invalid deposit amount.\n";
    }
}


// Withdraw money from the account
void BankAccount::withdraw(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid withdrawal amount.\n";
    }
    else if (amount > balance)
    {
        cout << "Insufficient Balance.\n";
    }
    else
    {
        balance -= amount;
        cout << "Rs. " << amount << " withdrawn successfully.\n";
    }
}


// Display only the current balance
// The user only requests to check the balance. How the balance is stored or retrieved is hidden inside the class.
void BankAccount::checkBalance()
{
    cout << "Current Balance : Rs. " << getBalance() << endl;
}


// Implement setters

void BankAccount::setAccountHolder(string accountHolder)
{
    this->accountHolder = accountHolder;
}

void BankAccount::setAccountNumber(int accountNumber)
{
    this->accountNumber = accountNumber;
}



// Implement getters
string BankAccount::getAccountHolder()
{
    return accountHolder;
}

int BankAccount::getAccountNumber()
{
    return accountNumber;
}

double BankAccount::getBalance()
{
    return balance;
}


// displayAccount() uses getter functions instead of accessing data members directly. This shows that member functions can use other member functions, improving code reusability.
void BankAccount::displayAccount()
{
    cout << "\n----------------------------\n";
    cout << "Account Holder : " << getAccountHolder() << endl;
    cout << "Account Number : " << getAccountNumber() << endl;
    cout << "Balance        : Rs. " << getBalance() << endl;
    cout << "----------------------------\n";
}


int main()
{
    BankAccount account;

    string holder;
    int number;
    double balance;


    // NOTE:
    // Declaring member functions inside the class and defining them outside using the
    // scope resolution operator (::) is NOT abstraction. It is simply a way to organize
    // the code and separate the interface (what functions are available) from the
    // implementation (how those functions work).
    //
    // Abstraction means hiding the internal implementation from the user and exposing
    // only the necessary operations. For example, the user simply calls deposit() or
    // withdraw() without knowing how the balance is validated or updated internally.
    cout << "Enter Account Holder Name : ";
    cin >> holder;

    cout << "Enter Account Number : ";
    cin >> number;

    cout << "Enter Initial Balance : ";
    cin >> balance;

    account.setAccountHolder(holder);
    account.setAccountNumber(number);
    account.deposit(balance);

    cout << "\nInitial Account Details\n";
    account.displayAccount();

    cout << "\nDepositing Rs. 2000...\n";
    account.deposit(2000);
    account.checkBalance();

    cout << "\nWithdrawing Rs. 1500...\n";
    account.withdraw(1500);
    account.checkBalance();

    cout << "\nTrying to withdraw Rs. 100000...\n";
    account.withdraw(100000);
    account.checkBalance();
}

