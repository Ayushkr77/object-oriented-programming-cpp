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
    void createAccount();

    // Member Function Definition
    void displayAccount();
};


// Member Function Definitions

void BankAccount::createAccount()
{
    cout << "Enter Account Holder Name : ";
    cin >> accountHolder;

    cout << "Enter Account Number : ";
    cin >> accountNumber;

    cout << "Enter Initial Balance : ";
    cin >> balance;
}

void BankAccount::displayAccount()
{
    cout << "\n----------------------------\n";
    cout << "Account Holder : " << accountHolder << endl;
    cout << "Account Number : " << accountNumber << endl;
    cout << "Balance        : " << balance << endl;
    cout << "----------------------------\n";
}

int main()
{
    BankAccount account;

    account.createAccount();

    cout << "\nAccount Details\n";

    account.displayAccount();
}