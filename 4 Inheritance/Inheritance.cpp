#include<bits/stdc++.h>
using namespace std;

// ============================================================================
// Version 10
//
// Topics Covered:
// - Virtual Inheritance
// - Solving the Diamond Problem
// - Shared Base Class Object
// - Constructor Behavior
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



// Virtual Inheritance
class Mammal : virtual public Animal
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



// Virtual Inheritance
class Pet : virtual public Animal
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

    // The most derived class constructs the virtual base class.
    Dog() : Animal()
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

    cout << endl;

    // No ambiguity anymore.
    dog.name = "Bruno";

    cout << "Dog Name : " << dog.name << endl;
}



// ============================================================================
// Experiment 1 : Constructor Calling Order
//
// Objective:
// Observe constructor execution with Virtual Inheritance.
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
// Pet Constructor Called
// Dog Constructor Called
//
// Notice:
//
// Animal Constructor is called ONLY ONCE.
//
// Conclusion:
//
// Virtual Inheritance creates a single shared Animal object.
// ============================================================================



// ============================================================================
// Experiment 2 : Ambiguity Removed
//
// Objective:
// Verify that ambiguity no longer exists.
//
// Steps:
//
// 1. Write:
//
//        dog.name = "Bruno";
//
// 2. Compile.
//
// Observation:
//
// Program compiles successfully.
//
// Conclusion:
//
// Since only one Animal object exists,
// member access is no longer ambiguous.
// ============================================================================



// ============================================================================
// Experiment 3 : Shared Base Class
//
// Objective:
// Observe that Mammal and Pet share the same Animal object.
//
// Steps:
//
// 1. Assign:
//
//        dog.name = "Charlie";
//
// 2. Print:
//
//        cout << dog.name;
//
// Observation:
//
// Only one value exists because there is only one Animal object.
//
// Conclusion:
//
// Virtual Inheritance creates one shared base class object.
// ============================================================================



// ============================================================================
// Experiment 4 : Remove 'virtual'
//
// Objective:
// Observe what happens when Virtual Inheritance is removed.
//
// Steps:
//
// 1. Change:
//
//        class Mammal : public Animal
//
//        class Pet : public Animal
//
// 2. Compile.
//
// Observation:
//
// dog.name becomes ambiguous.
//
// Animal Constructor is called twice.
//
// Conclusion:
//
// Removing virtual recreates the Diamond Problem.
// ============================================================================



// ============================================================================
// Experiment 5 : Most Derived Class Constructs Virtual Base. Problem in this.
//
// Objective:
// Understand constructor behavior.
//
// Steps:
//
// 1. Observe:
//
//        Dog() : Animal()
//
// 2. Remove:
//
//        : Animal()
//
// 3. Compile and run.
//
// Observation:
//
// Animal is still constructed once because it has a default constructor.
// If Animal required parameters, Dog would be responsible for providing them.
//
// Conclusion:
//
// The most derived class is responsible for constructing
// the virtual base class.
// ============================================================================