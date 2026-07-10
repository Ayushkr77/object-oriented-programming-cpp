// note that in this file, many commits will be there, those are versions which represents the learning prgress how we learnt each thing one by one. try to see all the commits of this file. and see each and every block, every comment carefully on each version as comments as well changes
#include<bits/stdc++.h>
using namespace std;
class Student {
private:   // default is private as well
    string name;
    int age;

    static int studentCount;  // // Shared by all Student objects
    
public:  // need to keep this public so that we can access this from outside the class
    // Member Functions
    void display();
    void input();


    // setters and getters(bcz since the data members are private, we need to make functions to update them)
    // void setName(string name);
    // void setAge(int age);

    // to understand this, *this and method chaining
    Student& setName(string name);
    Student& setAge(int age);
    string getName();
    int getAge();



    void registerStudent();   // NOTE: This function is only for learning static data members. In a later version, when we learn constructors, this function will be removed and studentCount will be incremented automatically inside the constructor whenever a Student object is created.

    static void displayStudentCount(); // // Static Member Functions
};


// Static Data Member Initialization
int Student::studentCount = 0;

// we cannot define below functions inside int main. Function definitions cannot be inside another function. Remember: A function cannot be defined inside another function in C++. Only function calls are allowed inside main().
void Student:: display() {   // compiler internally behaves like void Student::display(Student* this)
    cout << "----------------------\n";
    cout << "Name : " << name << endl;  // The compiler automatically treats it as: cout << this->name;
    cout << "Age  : " << age << endl;
    cout << "----------------------\n";
}
void Student::input() {
    string tempName;
    int tempAge;
    cout << "Enter Name : ";
    cin >> tempName;
    cout << "Enter Age  : ";
    cin >> tempAge;
    // Use setters so validation is applied
    setName(tempName);
    setAge(tempAge);
}


void Student::registerStudent() {
    studentCount++;
}

void Student::displayStudentCount() {
    cout << "\nTotal Students Created : " << studentCount << endl;
}



Student& Student::setName(string name)
{
    if (!name.empty())
    {
        this->name = name;
    }
    return *this;  // Returning *this enables method chaining by returning a reference to the current object. here if we are removing this return statement, its still working fine but it may be possible that in a nother compilers, it'll give error.
}

Student& Student::setAge(int age) {
    if (age >= 0) {
        this->age = age; 
    }
    return *this;
}

string Student::getName() {
    return name;
}

int Student::getAge() {
    return age;
}


int main() {

    Student s1, s2, s3;

    s1.registerStudent();
    s2.registerStudent();
    s3.registerStudent();


    s1.input();
    s2.input();
    s3.input();

    cout << "\nStudent Details\n\n";

    s1.display();
    s2.display();
    s3.display();

    // Direct access is not allowed
    // s1.age = 25;      // Error
    // s1.name = "Ayush"; // Error

    s2.setName("Rohit").setAge(40);   // method chaining. // setName() returns *this (i.e., the same object), allowing setAge() to be called on it.

    cout << "\nAfter Updating Student 2\n\n";

    s1.display();
    s2.display();
    s3.display();


    Student::displayStudentCount();


    // this will not work as the variables/ data members are private 
    // s2.age = 40; 
    // s2.name = "Rohit";


    // to show that each object occupies separate memory
    cout << &s1 << endl;
    cout << &s2 << endl;
    cout << &s3 << endl;
}