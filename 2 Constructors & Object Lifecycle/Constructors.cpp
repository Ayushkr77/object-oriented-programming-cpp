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
    // Mandatory for const data members, reference data members, and member objects that do not have a default constructor. We already dud these in the 3 experiments.

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
    Student s1;
    Student s2("Ayush", 23);
    Student s3("Rahul");

    cout << "\nStudent Details\n\n";

    s1.display();
    s2.display();
    s3.display();

    Student::displayStudentCount();
}




