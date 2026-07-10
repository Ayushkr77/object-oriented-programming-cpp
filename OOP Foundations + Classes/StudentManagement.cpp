// note that in this file, many commits will be there, those are versions which represents the learning prgress how we learnt each thing one by one. try to see all the commits of this file
#include<bits/stdc++.h>
using namespace std;
class Student {
private:   // default is private as well
    string name;
    int age;
    
public:  // need to keep this public so that we can access this from outside the class
    void display();
    void input();

    // setters and getters(bcz since the data members are private, we need to make functions to update them)
    void setName(string newName);
    void setAge(int newAge);
    string getName();
    int getAge();
};

// we cannot define below functions inside int main. Function definitions cannot be inside another function. Remember: A function cannot be defined inside another function in C++. Only function calls are allowed inside main().
void Student:: display() {   // compiler internally behaves like void Student::display(Student* this)
    cout << "----------------------\n";
    cout << "Name : " << getName() << endl;  // name will also work instead of getName() but for now its kept intentionally as we are learning setters and getters
    cout << "Age  : " << getAge() << endl;
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


void Student::setName(string newName) {
    if (!newName.empty()) {
        name = newName;
    }
    else {
        cout << "Invalid Name!\n";
    }

}

void Student::setAge(int newAge) {
    if (newAge >= 0) {
        age = newAge;
    }
    else {
        cout << "Invalid Age!\n";
    }
}

string Student::getName() {
    return name;
}

int Student::getAge() {
    return age;
}


int main() {

    Student s1, s2, s3;

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

    // Updating using setters
    s2.setName("Rohit");
    s2.setAge(40);

    cout << "\nAfter Updating Student 2\n\n";

    s1.display();
    s2.display();
    s3.display();


    // this will not work as the variables/ data members are private 
    // s2.age = 40; 
    // s2.name = "Rohit";


    // to show that each object occupies separate memory
    cout << &s1 << endl;
    cout << &s2 << endl;
    cout << &s3 << endl;
}