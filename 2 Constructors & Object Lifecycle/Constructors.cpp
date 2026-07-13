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
class String
{
private:

    char* data;  // Dynamically allocated character array (Heap Memory)

public:

    String(const char* text) {
        data = new char[strlen(text) + 1];   // Allocate memory on the heap to store a copy of the string

        strcpy(data, text);  // this is not same as data=text;   // Copies the string contents into the newly allocated memory. This is different from: data = text; (which copies only the pointer).
        // strcpy(data, text); (Copies the characters). data has its own memory, and the contents of text are copied into it.
        // data = text; (Copies the pointer). No characters are copied. Only the address is copied, so both pointers refer to the same string.

        cout << "Constructor Called for \"" << data << "\"\n";
    }

    ~String()
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
    String s1("Hello");

    String s2 = s1;   // shallow copy. Since we haven't defined a copy constructor, C++ generates a default copy constructor, which simply copies the pointer.

    s1.display();
    s2.display();
}