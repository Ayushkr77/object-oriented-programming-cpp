#include<bits/stdc++.h>
using namespace std;

// ============================================================================
// Version 9
//
// Topics Covered:
// - Diamond Problem
// - Multiple Inheritance
// - Ambiguous Member Access
// - Duplicate Base Class Objects
// ============================================================================

class Animal
{
public:

    string name;

    Animal()
    {
        cout << "Animal Constructor Called\n";
    }

    ~Animal()
    {
        cout << "Animal Destructor Called\n";
    }
};



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
};



class Pet : public Animal
{
public:

    Pet()
    {
        cout << "Pet Constructor Called\n";
    }

    ~Pet()
    {
        cout << "Pet Destructor Called\n";
    }
};



class Dog : public Mammal, public Pet
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
};



int main()
{
    Dog dog;

    // dog.name = "Bruno";      // ❌ Compile Error
    // cout << dog.name;        // ❌ Compile Error

    // Why?
    //
    // Dog contains TWO Animal objects:
    //
    // Mammal -> Animal
    // Pet -> Animal
    //
    // Therefore, the compiler doesn't know
    // which 'name' should be accessed.

    dog.Mammal::name = "Bruno";
    dog.Pet::name = "Rocky";

    cout << "Name through Mammal : "
         << dog.Mammal::name << endl;

    cout << "Name through Pet : "
         << dog.Pet::name << endl;
}



// ============================================================================
// Experiment 1 : Ambiguous Member Access
//
// Objective:
// Observe the ambiguity created by duplicate base class objects.
//
// Steps:
//
// 1. Uncomment:
//
//        dog.name = "Bruno";
//
// 2. Compile.
//
// Observation:
//
// Compilation Error:
//
// request for member 'name' is ambiguous
//
// Conclusion:
//
// Dog contains two copies of Animal.
// The compiler cannot determine which 'name' is intended.
// ============================================================================



// ============================================================================
// Experiment 2 : Duplicate Base Class Objects
//
// Objective:
// Observe that Dog contains two Animal objects.
//
// Steps:
//
// 1. Assign:
//
//        dog.Mammal::name = "Bruno";
//
//        dog.Pet::name = "Rocky";
//
// 2. Print both.
//
// Observation:
//
// Bruno
// Rocky
//
// Conclusion:
//
// Mammal and Pet each maintain their own independent Animal object.
// ============================================================================



// ============================================================================
// Experiment 3 : Constructor Calling Order
//
// Objective:
// Observe constructor execution.
//
// Observation:
//
// Animal Constructor
// Mammal Constructor
// Animal Constructor
// Pet Constructor
// Dog Constructor
//
// Conclusion:
//
// Animal constructor executes twice because
// two Animal objects are created.
// ============================================================================



// ============================================================================
// Experiment 4 : Destructor Calling Order
//
// Objective:
// Observe destructor execution.
//
// Observation:
//
// Dog Destructor
// Pet Destructor
// Animal Destructor
// Mammal Destructor
// Animal Destructor
//
// Conclusion:
//
// Two Animal objects are destroyed independently.
// ============================================================================



// ============================================================================
// Experiment 5 : Why Virtual Inheritance?
//
// Objective:
// Understand why Virtual Inheritance exists.
//
// Observation:
//
// The duplicate Animal objects cause:
//
// • Memory duplication
// • Ambiguous member access
// • Constructor called twice
// • Destructor called twice
//
// Conclusion:
//
// Version 10 will solve all these problems using:
//
//        virtual public Animal
// ============================================================================