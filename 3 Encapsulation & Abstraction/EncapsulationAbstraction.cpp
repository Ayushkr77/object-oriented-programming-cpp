// note that in this file, many commits will be there, those are versions which represents the learning progress how we learnt each thing one by one. Try to see all the commits of this file. Also, see every block, every comment, and every change carefully.

// ============================================================================
// Encapsulation vs Abstraction
//
// Encapsulation:
// - Encapsulation is the process of bundling data and functions into a single
//   unit (class) while restricting direct access to the object's data.
// - It focuses on protecting the internal state of an object.
// - Achieved using private/protected data members and controlled access
//   through public member functions (getters, setters, etc.).
//
// Abstraction:
// - Abstraction is the process of hiding implementation details and exposing
//   only the essential functionality to the user.
// - It focuses on simplifying how users interact with an object.
// - Achieved by providing meaningful operations such as deposit(),
//   withdraw(), and checkBalance(), without revealing how they work.
//
// How They Work Together:
//
// Encapsulation protects the object's data.
//
// Abstraction hides the complexity of operating on that data.
//
// In this BankAccount example:
//
// Encapsulation:
//      private:
//          accountHolder
//          accountNumber
//          balance
//
// Abstraction:
//      deposit()
//      withdraw()
//      checkBalance()
//      displayAccount()
//
// The user cannot modify balance directly, but can interact with it through
// meaningful operations provided by the class.
// ============================================================================

// ============================================================================
// Why "Encapsulation vs Abstraction"?
//
// These concepts are often compared because both hide something,
// but they hide different things.
//
// Encapsulation hides DATA.
//
// Abstraction hides IMPLEMENTATION DETAILS.
//
// They are complementary concepts, not competing concepts.
// In real-world software, they are almost always used together.
// ============================================================================



#include<bits/stdc++.h>
using namespace std;

// BankAccount class demonstrating basic encapsulation. Encapsulation = Data + Functions inside one class.
class BankAccount
{
// ============================================================================
// Encapsulation
//
// Private data members represent the object's internal state.
// They cannot be accessed directly from outside the class.
// Access is provided only through controlled public member functions, allowing the class to validate or restrict modifications before changing its internal state.
// ============================================================================
private:    // Data is hidden inside the class
    string accountHolder;
    int accountNumber;
    double balance;


// ============================================================================
// Abstraction
//
// Public member functions form the interface of the class.
// Users interact with the object through meaningful operations. They only know WHAT each function does, not HOW it is implemented.
// ============================================================================
public:     // Functions provide controlled interaction with the object


    // ============================================================================
    // Encapsulation
    //
    // Setter functions provide controlled modification of private data members.
    // Validation can be performed here before updating the object's state.
    // ============================================================================
    // Member Function Definition
    void setAccountHolder(string accountHolder);
    void setAccountNumber(int accountNumber);

    void deposit(double amount);
    void withdraw(double amount);
    void checkBalance();
    

    // ============================================================================
    // Encapsulation
    //
    // Getter functions provide controlled read access to private data members
    // without exposing the data directly.
    // ============================================================================
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


// ============================================================================
// Abstraction
//
// The user simply requests a deposit.
//
// The class decides:
//
// • Is the amount valid?
// • Should the balance be updated?
// • Should additional work (logging, notifications, etc.) be performed?
//
// The user only sees deposit().
// ============================================================================
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


// ============================================================================
// Abstraction
//
// The user simply requests a withdrawal.
//
// The class hides:
//
// • Balance validation
// • Withdrawal rules
// • Balance update
//
// The implementation remains completely hidden.
// ============================================================================
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


// ============================================================================
// Abstraction
//
// The user requests the current balance.
// How the balance is stored or retrieved is hidden inside the class.
// ============================================================================
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


// ============================================================================
// Encapsulation + Abstraction
//
// Encapsulation:
// displayAccount() accesses private data through public getter functions.
//
// Abstraction:
// The user simply requests the account details.
// The retrieval of information is hidden inside the class.
// ============================================================================
void BankAccount::displayAccount()
{
    cout << "\n----------------------------\n";
    cout << "Account Holder : " << getAccountHolder() << endl;
    cout << "Account Number : " << getAccountNumber() << endl;
    cout << "Balance        : Rs. " << getBalance() << endl;
    cout << "----------------------------\n";
}



// ============================================================================
// Demonstration
//
// This example combines both concepts.
//
// Encapsulation protects the object's state.
//
// Abstraction provides a simple interface for interacting with the object.
//
// The user never directly modifies the balance.
// Instead, meaningful operations are provided.
//
// This is how both concepts work together in real-world software.
// ============================================================================
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
// Experiment 1: Demonstrating Encapsulation
//
// Objective:
// Understand how encapsulation protects an object's data.
//
// Steps:
//
// 1. Uncomment:
//
//        account.balance = 50000;
//
// 2. Compile.
//
// 3. Observe the compiler error.
//
// 4. Comment it again.
//
// Observation:
//
// balance is a private data member.
//
// Therefore, it cannot be accessed directly from outside the class.
//
// Conclusion:
//
// Encapsulation protects the internal state of the object by restricting
// direct access to its data.
// ============================================================================

// ============================================================================
// Experiment 2: Demonstrating Abstraction
//
// Objective:
//
// Understand that users interact only with the interface while the
// implementation remains hidden.
//
// Steps:
//
// 1. Modify ONLY the implementation of deposit().
//
//        balance += amount;
//
//        cout << "Transaction Logged\n";
//        cout << "SMS Notification Sent\n";
//        cout << "Database Updated\n";
//
// 2. Do NOT modify main().
//
// 3. Run the program.
//
// Observation:
//
// main() still contains:
//
//        account.deposit(1000);
//
// The user doesn't know that additional work is now happening.
//
// Conclusion:
//
// The implementation changed.
//
// The interface remained the same.
//
// This demonstrates abstraction.
// ============================================================================


// ============================================================================
// Final Comparison
//
// Encapsulation
// --------------
// • Hides data.
// • Protects the object's internal state.
// • Achieved using access specifiers.
//
// Abstraction
// -----------
// • Hides implementation.
// • Simplifies object usage.
// • Achieved by exposing meaningful public interfaces and hiding their implementation details.
//
// They are complementary concepts.
//
// Encapsulation answers:
//
//      "How do we protect the data?"
//
// Abstraction answers:
//
//      "How do we simplify the object's usage?"
//
// In most real-world applications, both concepts are used together.
// ============================================================================


// Question 1
// Why can't the user write?
// account.balance = 100000;
// Because balance is private.
// That's Encapsulation.

// Question 2
// Why does the user write?
// account.deposit(5000);
// instead of
// account.balance += 5000;
// Because the class hides the implementation and exposes only meaningful operations.
// That's Abstraction.





// Interview Tip:
//
// Encapsulation and Abstraction are NOT the same.
//
// Encapsulation focuses on protecting data.
//
// Abstraction focuses on simplifying usage.
//
// In practice, good software uses both together.