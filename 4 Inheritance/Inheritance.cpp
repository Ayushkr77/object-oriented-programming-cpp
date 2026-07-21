// note that in this file, many commits will be there, those are versions which represents the learning progress how we learnt each thing one by one. Try to see all the commits of this file. Also, see every block, every comment, and every change carefully.

#include<bits/stdc++.h>
using namespace std;

// ============================================================================
// Version 5
//
// Topics Covered:
// - Multilevel Inheritance
// - Constructor Calling Order
// - Destructor Calling Order
// - Constructor Chaining
// - Destructor Chaining
// ============================================================================



// ============================================================================
// Base Class
// ============================================================================
class Animal
{
protected:

    string name;
    int age;

public:

    Animal()
    {
        cout << "Animal Constructor Called\n";
    }

    ~Animal()
    {
        cout << "Animal Destructor Called\n";
    }

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
// Intermediate Class
//
// Mammal inherits Animal.
// Dog will inherit Mammal.
// This creates a Multilevel Inheritance chain.
//
// Animal
//    ▲
// Mammal
//    ▲
// Dog
// ============================================================================
class Mammal : public Animal
{
public:

    Mammal()
    {
        cout << "Mammal Constructor Called\n";
    }

    ~Mammal()
    {
        cout << "Mammal Destructor Called\n";
    }

    void walk()
    {
        cout << name << " is walking.\n";
    }
};



// ============================================================================
// Derived Class
// ============================================================================
class Dog : public Mammal
{
public:

    Dog()
    {
        cout << "Dog Constructor Called\n";
    }

    ~Dog()
    {
        cout << "Dog Destructor Called\n";
    }

    string breed;

    void bark()
    {
        cout << name << " says: Bark Bark!\n";
    }

    void displayDetails()
    {
        cout << "\nDog Details\n\n";

        cout << "Name  : " << name << endl;
        cout << "Age   : " << age << endl;
        cout << "Breed : " << breed << endl;

        cout << endl;
    }
};



int main()
{
    Dog dog;

    dog.setName("Bruno");
    dog.setAge(3);
    dog.breed = "Golden Retriever";

    dog.displayDetails();

    dog.eat();      // Animal
    dog.sleep();    // Animal
    dog.walk();     // Mammal
    dog.bark();     // Dog
}



// ============================================================================
// Experiment 1 : Constructor Calling Order
//
// Objective:
// Observe constructor execution in Multilevel Inheritance.
//
// Steps:
//
// 1. Create:
//
//        Dog dog;
//
// 2. Run the program.
//
// Observation:
//
// Animal Constructor Called
// Mammal Constructor Called
// Dog Constructor Called
//
// Conclusion:
//
// Constructors execute from the Base Class towards the
// most Derived Class.
// ============================================================================



// ============================================================================
// Experiment 2 : Destructor Calling Order
//
// Objective:
// Observe destructor execution in Multilevel Inheritance.
//
// Steps:
//
// 1. Run the program.
//
// 2. Observe the last lines printed.
//
// Observation:
//
// Dog Destructor Called
// Mammal Destructor Called
// Animal Destructor Called
//
// Conclusion:
//
// Destructors execute in the exact reverse order of constructors.
// ============================================================================



// ============================================================================
// Experiment 3 : Indirect Inheritance
//
// Objective:
// Understand indirect inheritance.
//
// Steps:
//
// 1. Observe Dog does NOT contain:
//
//        eat()
//        sleep()
//
// 2. Observe Mammal does NOT contain:
//
//        eat()
//        sleep()
//
// 3. Yet Dog successfully calls:
//
//        dog.eat();
//        dog.sleep();
//
// Observation:
//
// Dog inherits these members indirectly from Animal through Mammal.
//
// Conclusion:
//
// A derived class inherits all accessible members of every
// ancestor class.
// ============================================================================