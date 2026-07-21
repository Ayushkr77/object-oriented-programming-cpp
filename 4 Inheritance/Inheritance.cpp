// note that in this file, many commits will be there, those are versions which represents the learning progress how we learnt each thing one by one. Try to see all the commits of this file. Also, see every block, every comment, and every change carefully.

#include<bits/stdc++.h>
using namespace std;

// ============================================================================
// Version 2
//
// Topics Covered:
// - Protected Members
// - Difference between private and protected
// - Accessibility Rules
// - Controlled Access
// ============================================================================



// ============================================================================
// Base Class
//
// Animal is the Base Class (also called Parent Class or Super Class).
// It contains the common properties and behaviors that can be reused
// by derived classes.
//
// The common data members are now protected.
// This allows derived classes to access them directly while preventing
// outside code from accessing them.
// ============================================================================
class Animal
{
protected:

    string name;
    int age;

public:

    // Setter Functions
    void setName(string name)
    {
        this->name = name;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    void eat()
    {
        cout << name << " is eating.\n";
    }

    void sleep()
    {
        cout << name << " is sleeping.\n";
    }
};



// ============================================================================
// Derived Class
//
// Dog inherits all accessible members of Animal.
//
// Since name and age are protected, Dog can access them directly.
//
// Outside code still cannot access them.
// ============================================================================
class Dog : public Animal
{
public:

    string breed;

    void bark()
    {
        cout << name << " says: Bark Bark!\n";
    }

    void displayDetails()
    {
        cout << "Dog Details\n\n";

        cout << "Name  : " << name << endl;
        cout << "Age   : " << age << endl;
        cout << "Breed : " << breed << endl;

        cout << endl;
    }
};



int main()
{
    Dog dog;

    // Protected members cannot be accessed directly from outside the class.
    // Therefore, we use setter functions.
    dog.setName("Bruno");
    dog.setAge(3);

    // breed belongs to Dog itself, so it is still public.
    dog.breed = "Golden Retriever";

    // displayDetails() is a member function of Dog.
    // Since it belongs to the derived class, it can directly access
    // the protected members inherited from Animal.
    dog.displayDetails();

    // Functions inherited from Animal
    dog.eat();
    dog.sleep();

    // Function belonging to Dog
    dog.bark();
}



// ============================================================================
// Experiment 1: Understanding private
//
// Objective:
// See why private is too restrictive.
//
// Steps:
//
// 1. Replace
//
//        protected:
//
// with
//
//        private:
//
// 2. Compile the program.
//
// Observation:
//
// displayDetails() and bark() will produce compilation errors because
// private members cannot be directly accessed by derived classes.
//
// Conclusion:
//
// private completely hides members from derived classes.
// ============================================================================



// ============================================================================
// Experiment 2: Understanding protected
//
// Objective:
// Understand why protected exists.
//
// Steps:
//
// 1. Keep
//
//        protected:
//
// 2. Inside Dog, access:
//
//        cout << name;
//        cout << age;
//
// 3. Compile.
//
// Observation:
//
// The program works.
//
// 4. Now try in main():
//
//        dog.name = "Rocky";
//
// Compile again.
//
// Observation:
//
// Compilation fails because protected members cannot be accessed
// directly from outside the class.
//
// Conclusion:
//
// protected allows access inside the inheritance hierarchy while
// still hiding members from outside code.
// ============================================================================