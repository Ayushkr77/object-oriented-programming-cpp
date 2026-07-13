// note that in this file, many commits will be there, those are versions which represents the learning prgress how we learnt each thing one by one. try to see all the commits of this file. and see each and every block, every comment carefully on each version as comments as well changes
// this file is the continuation of StudentManagement.cpp file(1 OOP Foundations + Classes\StudentManagement.cpp)

// ============================================================================
// Constructors.cpp
//
// This file contains the complete implementation of Day 2 concepts.
// Each Git commit represents one version, gradually introducing constructors,
// object lifecycle, dynamic memory management, copy constructors,
// shallow/deep copy, and the Rule of Three.
//
// Explore the commit history to see how the code evolves step by step.
// ============================================================================



// ============================================================================
// Rule of Three
// If a class manages dynamic memory (or any resource), then if you implement
// any one of these, you should usually implement all three:
//
// 1. Destructor
// 2. Copy Constructor
// 3. Copy Assignment Operator
//
// This ensures proper copying and cleanup of dynamically allocated memory.
// ============================================================================

#include<bits/stdc++.h>
using namespace std;

class MyString
{
private:

    char* data;      // Dynamically allocated character array (Heap Memory)

public:

    MyString(const char* text)
    {
        // Allocate memory on the heap to store a copy of the string
        data = new char[strlen(text) + 1];

        // Copies the string contents into the newly allocated memory.
        strcpy(data, text);

        cout << "Constructor Called for \"" << data << "\"\n";
    }

    // Deep Copy Constructor
    MyString(const MyString &other)
    {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);

        cout << "Copy Constructor Called for \"" << data << "\"\n";
    }

    // Copy Assignment Operator
    // Called when an existing object is assigned the value of another object.
    MyString& operator=(const MyString &other)
    {
        cout << "Copy Assignment Operator Called\n";

        // Protect against self-assignment
        if (this == &other)
            return *this;

        // Free the old memory
        delete[] data;

        // Allocate new memory
        data = new char[strlen(other.data) + 1];

        // Copy the contents
        strcpy(data, other.data);

        // Return the current object to allow chained assignments
        return *this;
    }

    ~MyString()
    {
        cout << "Destructor Called for \"" << data << "\"\n";

        delete[] data;
    }

    void display()
    {
        cout << "Data : " << data << endl;
        cout << "Heap Address : "
             << static_cast<void*>(data) << endl;
    }

    // Just for testing Deep Copy
    void setFirstChar(char ch)
    {
        data[0] = ch;
    }
};

int main()
{
    MyString s1("Hello");

    MyString s2 = s1;          // Copy Constructor

    MyString s3("World");

    s3 = s1;                   // Copy Assignment Operator

    cout << "\nAfter Copying\n\n";

    s1.display();
    s2.display();
    s3.display();

    cout << "\nModifying s2...\n\n";

    s2.setFirstChar('Y');

    s1.display();
    s2.display();
    s3.display();

    // =========================================================================
    // Summary
    //
    // MyString s2 = s1;
    // --> Copy Constructor (New object is created)
    //
    // MyString s3("World");
    // s3 = s1;
    // --> Copy Assignment Operator (Existing object is assigned)
    //
    // Destructor is automatically called when objects go out of scope.
    //
    // Together, Destructor + Copy Constructor + Copy Assignment Operator
    // form the Rule of Three.
    // =========================================================================
}