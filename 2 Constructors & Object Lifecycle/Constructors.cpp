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
class Student {
private:   // default is private as well
    string name;
    int age;

    static int studentCount;  // // Shared by all Student objects    


public:  // need to keep this public so that we can access this from outside the class
    // Member Function Definition
    void display();


    static void displayStudentCount(); // Static Member Functions

    

    // Constructor Initialization List: Members are initialized before the constructor body executes. This is preferred over assigning values inside the constructor body because it directly initializes members instead of initializing them first and then assigning.
    // Mandatory for const data members, reference data members, and member objects that do not have a default constructor. We already dud these in the 3 experiments. u can see in commit history

    Student(): name("Unknown"), age(0){  // Initialization List. 
        studentCount++;
        cout << "Default Constructor Called\n";
    }

    Student(string name, int age): name(name), age(age) {  // Initialization List
        studentCount++;
        cout << "Parameterized Constructor using initialization list called for " << name << endl;
    }


    Student(string name): name(name), age(0) {  
        studentCount++;
        cout << "Parameterized Constructor (Name Only) using initialization list called for " << name << endl;
    }


    ~Student() {
        cout << "Destructor Called for " << name << endl;
    }


    // User-defined Copy Constructor: Creates a new object by copying the data from an existing object.
    // Student(const Student &other) {
    //     name = other.name;
    //     age = other.age;
    //     studentCount++;
    //     cout << "Copy Constructor Called\n";
    // }


    // User defined Copy Constructor with initialization list: Creates a new object by copying the data from an existing object.
    Student(const Student &other): name(other.name), age(other.age) {
        studentCount++;
        cout << "Copy Constructor Called for " << name << endl;
    }

};


void Student::displayStudentCount() {
    cout << "\nTotal Students Created : " << studentCount << endl;
}


// Static Data Member Initialization
int Student::studentCount = 0;

// we cannot define below functions inside int main. Function definitions cannot be inside another function. Remember: A function cannot be defined inside another function in C++. Only function calls are allowed inside main()// Member functions cannot be defined inside another function. They must be defined either inside the class or outside using ::..

void Student:: display() {   // compiler internally behaves like void Student::display(Student* this)
    cout << "----------------------\n";
    cout << "Name : " << name << endl;  // The compiler automatically treats it as: cout << this->name;
    cout << "Age  : " << age << endl;
    cout << "----------------------\n";
}







int main() {
    Student s1("Ayush", 23);

    Student s2 = s1;
    Student s3(s1);  // both are same. both call the copy constructor because they are creating new objects. Both create a new object by copying an existing object, so both invoke the copy constructor.

    Student s4;  // Calls the default constructor. which we'll study later in the Rule of Three.
    s4 = s1;  // // Does NOT call the copy constructor. It calls the copy assignment operator because s4 already exists. we'll study later in the Rule of Three.

    cout << "\nStudent Details\n\n";

    s1.display();
    s2.display();
    s3.display();
    s4.display();



    // Explanation
    // Student s1("Ayush", 23);  // Calls the parameterized constructor.
    // Student s2 = s1;  // Calls the copy constructor because s2 is being created from s1.
    // Student s3(s1);  // Also calls the copy constructor because s3 is being created from s1.

    // Student s4;  // Calls the default constructor to create an empty/default Student object.
    // s4 = s1;  // s4 already exists. This does not create a new object. It copies the contents of s1 into the existing object s4. This calls the copy assignment operator.



    // ============================================================================
    // Experiment 1: Compiler-Generated Copy Constructor
    //
    // Comment out the user-defined copy constructor and run:
    //
    // Student s2 = s1;
    //
    // The program still works because the compiler automatically generates a
    // default copy constructor that performs member-wise (shallow) copying.
    //
    // After understanding this, restore the user-defined copy constructor.
    // ============================================================================



    // ============================================================================
    // Experiment 2: Why is the Copy Constructor Passed by Reference?
    //
    // Temporarily change:
    //
    // Student(const Student &other)
    //
    // to
    //
    // Student(Student other)
    //
    // This results in infinite recursive calls (or a compile-time error,
    // depending on the compiler).
    //
    // Reason:
    // Passing 'other' by value requires making a copy of the argument.
    // Making that copy again requires calling the copy constructor.
    // This process repeats indefinitely.
    //
    // Therefore, a copy constructor must take its parameter by reference.
    // ============================================================================
}