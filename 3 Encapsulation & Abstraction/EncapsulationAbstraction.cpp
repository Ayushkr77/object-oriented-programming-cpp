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

    // ============================================================================
    // Interface
    //
    // The class declaration represents the interface.
    // It tells users WHAT operations are available, but not HOW they are performed.
    // ============================================================================

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


// ============================================================================
// Implementation
//
// The function definitions represent the implementation.
// This is where the actual business logic is written.
// Users don't need to know these details.
// ============================================================================


// Deposit money into the account
// Instead of allowing users to directly modify the balance using setBalance(), we expose meaningful operations like deposit() and withdraw(). This hides the internal implementation and demonstrates abstraction.
// Implementation of deposit(). The user simply calls deposit(amount). The validation and balance update are hidden inside the class.
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
// Implementation of withdraw(). The class checks whether sufficient balance exists before updating it. The user only requests the withdrawal.
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
// Implementation of checkBalance(). The user requests the current balance without knowing how it is stored.
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



// ============================================================================
// Understanding Interface vs Implementation
//
// Objective:
// Understand that users interact only with the interface, while the
// implementation remains hidden and can change without affecting user code.
//
// Steps:
// 1. Keep the interface (function declarations) exactly the same.
//        void deposit(double amount);
//        void withdraw(double amount);
//        void checkBalance();
//
// 2. Observe how main() calls only the interface.
//        account.deposit(1000);
//
// 3. Now modify ONLY the implementation of deposit() by adding extra logic.
//
//        void BankAccount::deposit(double amount)
//        {
//            if(amount > 0)
//            {
//                balance += amount;
//
//                cout << "Transaction Logged\n";
//                cout << "SMS Notification Sent\n";
//                cout << "Email Notification Sent\n";
//            }
//        }
//
// 4. Run the program again. Notice that main() remains exactly the same.
//        account.deposit(1000);
//
// Observation:
// The implementation changed, but the interface remained unchanged.
// The user still performs the same operation without knowing how it is
// internally implemented.
//
// Conclusion:
// Interface tells the user WHAT operations are available.
// Implementation defines HOW those operations are performed.
// Since users depend only on the interface, the internal implementation
// can change freely without affecting the user code.
// ============================================================================