// note that in this file, many commits will be there, those are versions which represents the learning progress how we learnt each thing one by one. Try to see all the commits of this file. Also, see every block, every comment, and every change carefully.

#include<bits/stdc++.h>
using namespace std;

// ============================================================================
// Version 3
//
// Topics Covered:
// - Constructor Calling Order
// - Base Class Constructor
// - Derived Class Constructor
// - Constructor Chaining
// - Order of Execution
// ============================================================================



// ============================================================================
// Base Class
//
// Animal is the Base Class (also called Parent Class or Super Class).
// It contains the common properties and behaviors that can be reused
// by derived classes.
//
// The common data members are protected.
// This allows derived classes to access them directly while preventing
// outside code from accessing them.
// ============================================================================
class Animal
{
protected:

    string name;
    int age;

public:

    // Base Class Constructor
    Animal()
    {
        cout << "Animal Constructor Called\n";
    }

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

    // Derived Class Constructor
    Dog()
    {
        cout << "Dog Constructor Called\n";
    }

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
    // Constructor Chaining starts here.
    // First Animal() is called automatically.
    // Then Dog() is called automatically.
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
// Experiment 1: Constructor Calling Order
//
// Objective:
// Understand the constructor execution sequence.
//
// Steps:
//
// 1. Create an object:
//
//        Dog dog;
//
// 2. Run the program.
//
// Observation:
//
// Animal Constructor Called
// Dog Constructor Called
//
// Conclusion:
//
// The Base Class constructor always executes before the Derived Class
// constructor.
// ============================================================================



// ============================================================================
// Experiment 2: Constructor Chaining
//
// Objective:
// Understand that constructor chaining happens automatically.
//
// Steps:
//
// 1. Observe that you only created:
//
//        Dog dog;
//
// 2. Notice that you never explicitly called:
//
//        Animal();
//
// 3. Run the program.
//
// Observation:
//
// Even though Animal() was never called manually,
// it executes automatically before Dog().
//
// Conclusion:
//
// C++ automatically calls the Base Class constructor before the
// Derived Class constructor. This automatic sequence is called
// Constructor Chaining.
// ============================================================================