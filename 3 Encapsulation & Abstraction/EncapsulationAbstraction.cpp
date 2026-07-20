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
    void setBalance(double balance);
    string getAccountHolder();
    int getAccountNumber();
    double getBalance();


    // Member Function Definition
    void displayAccount();
};



// Implement setters

void BankAccount::setAccountHolder(string accountHolder)
{
    this->accountHolder = accountHolder;
}

void BankAccount::setAccountNumber(int accountNumber)
{
    this->accountNumber = accountNumber;
}

void BankAccount::setBalance(double balance)
{
    if(balance >= 0)
    {
        this->balance = balance;
    }
    else
    {
        cout << "Invalid Balance! Setting Balance to 0.\n";
        this->balance = 0;
    }
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


void BankAccount::displayAccount()
{
    cout << "\n----------------------------\n";
    cout << "Account Holder : " << getAccountHolder() << endl;
    cout << "Account Number : " << getAccountNumber() << endl;
    cout << "Balance        : " << getBalance() << endl;
    cout << "----------------------------\n";
}


int main()
{
    BankAccount account;

    string holder;
    int number;
    double balance;

    // notice that now we are taking input inside int main only, not inside classes
    // Input is taken in main(), not inside the class. This keeps the class independent of the input source (keyboard, file, database, API, GUI). The class only validates and stores the data using setters.
    // Classes should focus on managing their own data and behavior, not on how data is entered. Input may come from a keyboard, file, database, or API. By taking input outside the class and passing values through setters or constructors, the class becomes reusable, easier to test, and independent of the input source.
    cout << "Enter Account Holder Name : ";
    cin >> holder;

    cout << "Enter Account Number : ";
    cin >> number;

    cout << "Enter Initial Balance : ";
    cin >> balance;

    account.setAccountHolder(holder);
    account.setAccountNumber(number);
    account.setBalance(balance);

    cout << "\nAccount Details\n";

    account.displayAccount();
}


// ============================================================================
// Experiment 1: Read-only Property
//
// Objective:
// Understand how to make a data member read-only.
//
// Steps:
// 1. Temporarily comment out the setter (setAccountNumber()) and its definition.
// 2. Keep only the getter (getAccountNumber()).
// 3. Temporarily initialize accountNumber directly inside the class/constructor
//    since it can no longer be set from outside.
// 4. Try calling:
//        account.getAccountNumber();      // ✅ Allowed
//        account.setAccountNumber(1001);  // ❌ Compile Error (setter doesn't exist)
//
// Observation:
// The value can be viewed but cannot be modified from outside the class.
//
// Real-world Examples:
// Account Number, Employee ID, Roll Number, Aadhaar Number, etc.
//
// After understanding the concept, restore the setter.
// ============================================================================

// ============================================================================
// Experiment 2: Write-only Property
//
// Objective:
// Understand how to make a data member write-only.
//
// Steps:
// 1. Add a private data member:
//        string pin;
// 2. Create only the setter:
//        setPin(string pin);
// 3. Do NOT create getPin().
// 4. Try calling:
//        account.setPin("1234");   // ✅ Allowed
//        account.getPin();         // ❌ Compile Error (getter doesn't exist)
//
// Observation:
// The value can be modified but cannot be read from outside the class.
//
// Real-world Examples:
// Passwords, ATM PINs, Security Keys, OTPs, etc.
//
// After understanding the concept, remove the 'pin' data member and its setter.
// ============================================================================