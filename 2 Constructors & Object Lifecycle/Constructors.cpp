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

    int &roll;      // Reference Data Member. Experiment 2: Reference Data Member. A reference data member MUST be initialized using the initialization list. A reference cannot be changed (reseated) after it is created.
    


public:  // need to keep this public so that we can access this from outside the class
    // Member Function Definition
    void display();


    static void displayStudentCount(); // Static Member Functions

    



    // Student() {  // User-defined Default Constructor
    //     name = "Unknown";  // or this->name is also fine
    //     age = 0;
    //     studentCount++;
    //     cout << "Default Constructor Called\n";
    // }

    // Student(string name, int age) {  // User-defined Parameterized Constructor
    //     this->name = name;
    //     this->age = age;
    //     studentCount++;
    //     cout << "Parameterized Constructor Called for " << name << endl;
    // }


    // // Constructor Overloading: A class can have multiple constructors as long as their function signatures (number/type/order of parameters) are different.
    // Student(string name) {  // User-defined Parameterized Constructor (Name Only). Constructor Overloading
    //     this->name=name;
    //     this->age=0;
    //     studentCount++;
    //     cout << "Parameterized Constructor (Name Only) Called for " << name << endl;
    // }



    // Student(): name("Unknown"), age(0){  // Initialization List. 
    //     studentCount++;
    //     cout << "Default Constructor Called\n";
    // }

    // Student(string name, int age) {
    //     id = 101;          // ❌ Error
    // }

    // Student(string name, int age): name(name), age(age) {  // Initialization List
    //     studentCount++;
    //     cout << "Parameterized Constructor using initialization list called for " << name << endl;
    // }


    // Student(string name): name(name), age(0) {  
    //     studentCount++;
    //     cout << "Parameterized Constructor (Name Only) using initialization list called for " << name << endl;
    // }


    Student(string name, int age, int &roll): name(name), age(age), roll(roll) { // Initialization List. if roll not provided, error. it'll show error if any const or ref variable is not mentioned in the initialization list
        cout << "Parameterized Constructor Called\n";
    }

    // Student(string name, int age, int &roll) {
    //     this->name = name;
    //     this->age = age;

    //     this->roll = roll;      // ❌ Compile Error
    // }

};


void Student::displayStudentCount() {
    cout << "\nTotal Students Created : " << studentCount << endl;
}


// Static Data Member Initialization
int Student::studentCount = 0;

// we cannot define below functions inside int main. Function definitions cannot be inside another function. Remember: A function cannot be defined inside another function in C++. Only function calls are allowed inside main()// Member functions cannot be defined inside another function. They must be defined either inside the class or outside using ::..

// void Student:: display() {   // compiler internally behaves like void Student::display(Student* this)
//     cout << "----------------------\n";
//     cout << "Name : " << name << endl;  // The compiler automatically treats it as: cout << this->name;
//     cout << "Age  : " << age << endl;
//     cout << "----------------------\n";
// }


void Student:: display() { 
    cout << "----------------------\n";
    cout << "Name : " << name << endl;
    cout << "Age  : " << age << endl;
    cout << "Roll : " << roll << endl;
    cout << "----------------------\n";
}





int main() {
    // Student s1;
    // Student s2("Ayush", 23);
    // Student s3("Rahul");

    // cout << "\nStudent Details\n\n";

    // s1.display();
    // s2.display();
    // s3.display();

    // Student::displayStudentCount();



    // for experiment 2
    int rollNumber = 101;
    Student s1("Ayush", 23, rollNumber);
    s1.display();
    cout << "\nChanging rollNumber...\n\n";
    rollNumber = 200;
    s1.display();

    // to understand ref variable
    // int x = 10;
    // int &ref = x;   // ref is another name for x
    // cout << x << endl;    // 10
    // cout << ref << endl;  // 10
    // ref = 20;
    // cout << x << endl;    // 20
    // cout << ref << endl;  // 20
    // ref and x refer to the same memory location.
}