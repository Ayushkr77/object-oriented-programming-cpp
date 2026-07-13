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

#include<bits/stdc++.h>
using namespace std;
class MyString
{
private:

    char* data;  // Dynamically allocated character array (Heap Memory)

public:

    MyString(const char* text) {
        data = new char[strlen(text) + 1];   // Allocate memory on the heap to store a copy of the string

        strcpy(data, text);  // this is not same as data=text;   // Copies the string contents into the newly allocated memory. This is different from: data = text; (which copies only the pointer).
        // strcpy(data, text); (Copies the characters). data has its own memory, and the contents of text are copied into it.
        // data = text; (Copies the pointer). No characters are copied. Only the address is copied, so both pointers refer to the same string.

        cout << "Constructor Called for \"" << data << "\"\n";
    }


    MyString(const MyString &other) {
        data = new char[strlen(other.data) + 1];

        strcpy(data, other.data);

        cout << "Deep Copy Constructor Called\n";
    }


    ~MyString()
    {
        cout << "Destructor Called for \"" << data << "\"\n";

        delete[] data;
    }

    void display()
    {
        cout << "Data : " << data << endl;
        cout << "Address Stored in Pointer : "
            << static_cast<void*>(data) << endl;  // see what this means and also see why cant we use &data
    }
};


int main() {
    MyString s1("Hello");  // see what this means

    MyString s2 = s1;    // now deep copy

    s1.display();
    s2.display();
}


// Explanation
// 1. Direct Initialization
// MyString s1("Hello");
// Creates a new object s1.
// Calls the constructor MyString(const char*).
// No temporary object is created.


// 2. Copy Initialization
// MyString s2 = s1;
// Creates a new object s2.
// Calls the copy constructor MyString(const MyString&).
// Although '=' is written, this is NOT assignment because s2 does not exist yet.


// 3. Direct Copy Initialization
// MyString s3(s1);
// Creates a new object s3.
// Calls the copy constructor.
// Equivalent to: MyString s3 = s1.


// 4. Copy Assignment
// s1 = s2;
// s1 already exists.
// Does NOT call the copy constructor.
// Calls the copy assignment operator (operator=) to copy the contents of s2 into s1.


// 5. Assignment from a Temporary Object
// s1 = MyString("Hello");
// Step 1: A temporary MyString object is created using the constructor.
// Step 2: The temporary is assigned to the existing object s1 using operator=.
// Step 3: The temporary object is destroyed automatically after the assignment.
// Sequence: Constructor -> Copy Assignment Operator -> Destructor (temporary)


// | Statement                 | Meaning                                                                      | Function Called                                     |
// | ------------------------- | ---------------------------------------------------------------------------- | --------------------------------------------------- |
// | `MyString s1("Hello");`   | Creates a new object using a C-string.                                       | Constructor                                         |
// | `MyString s2 = s1;`       | Creates a new object as a copy of `s1`.                                      | Copy Constructor                                    |
// | `MyString s2(s1);`        | Creates a new object as a copy of `s1` (same as above).                      | Copy Constructor                                    |
// | `s1 = s2;`                | Copies data into an already existing object.                                 | Copy Assignment Operator (`operator=`)              |
// | `s1 = MyString("Hello");` | Creates a temporary object, assigns it to `s1`, then destroys the temporary. | Constructor → Copy Assignment Operator → Destructor |


// Object doesn't exist yet? → Constructor or Copy Constructor (Initialization)
// Object already exists? → Copy Assignment Operator (Assignment)