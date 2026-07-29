#include<bits/stdc++.h>
using namespace std;

// ============================================================================
// NOTE:
//
// This file will evolve through multiple Git commits (versions).
//
// Every version introduces exactly ONE new concept.
//
// Don't just read the final code.
//
// Open the Git history and observe how the implementation gradually evolves.
//
// That progression is the real learning.
// ============================================================================



// ============================================================================
// Version 1
//
// Topics Covered:
//
// - Introduction to Polymorphism
// - One Interface, Many Forms
// - Same Function Name
// - Different Behaviors
// ============================================================================



// ============================================================================
// Base Class
//
// Animal represents the common concept.
//
// Every animal can make a sound.
//
// Currently this is just a normal member function.
//
// Runtime Polymorphism has NOT started yet.
// ============================================================================
class Animal
{
public:

    void sound()
    {
        cout << "Animal makes a sound." << endl;
    }
};



// ============================================================================
// Derived Class : Dog
//
// Dog provides its own version of sound().
//
// Notice:
//
// Function name remains the same.
//
// Only the behavior changes.
// ============================================================================
class Dog : public Animal
{
public:

    void sound()
    {
        cout << "Dog says: Bark Bark!" << endl;
    }
};



// ============================================================================
// Derived Class : Cat
// ============================================================================
class Cat : public Animal
{
public:

    void sound()
    {
        cout << "Cat says: Meow Meow!" << endl;
    }
};



// ============================================================================
// Derived Class : Cow
// ============================================================================
class Cow : public Animal
{
public:

    void sound()
    {
        cout << "Cow says: Moo Moo!" << endl;
    }
};



// ============================================================================
// Demonstration
//
// Each object calls its own implementation.
//
// The compiler already knows each object's type.
//
// Therefore,
// Runtime Polymorphism is NOT happening.
// ============================================================================
int main()
{
    Dog dog;
    Cat cat;
    Cow cow;

    Animal animal;
    animal.sound();

    cout << "Dog:" << endl;
    dog.sound();

    cout << endl;

    cout << "Cat:" << endl;
    cat.sound();

    cout << endl;

    cout << "Cow:" << endl;
    cow.sound();
}



// ============================================================================
// Experiment 1 : Base Class Function
//
// Objective:
//
// Observe the Base Class implementation.
//
// Uncomment:
//
// Animal animal;
//
// animal.sound();
//
// Observation:
//
// Animal makes a sound.
//
// Conclusion:
//
// Base Class also has its own implementation.
// ============================================================================



// ============================================================================
// Experiment 2 : Add a New Animal
//
// Objective:
//
// Observe how easy it is to extend.
//
// Create:
//
// class Lion : public Animal
// {
// public:
//
//     void sound()
//     {
//         cout << "Lion says: Roar!" << endl;
//     }
// };
//
// Observation:
//
// Only the implementation changes.
//
// The interface remains:
//
// sound()
// ============================================================================



// ============================================================================
// Experiment 3 : Different Function Names
//
// Objective:
//
// Observe why common interfaces are useful.
//
// Rename:
//
// Dog::sound()
//
// to
//
// bark()
//
// Now you'll have:
//
// dog.bark();
//
// cat.sound();
//
// cow.sound();
//
// Conclusion:
//
// Using different function names destroys the common interface.
// ============================================================================



// ============================================================================
// Experiment 4 : Calling Base Class Function
//
// Objective:
//
// Observe inherited functions.
//
// Uncomment:
//
// Dog dog;
//
// dog.Animal::sound();
//
// Observation:
//
// Animal makes a sound.
//
// Conclusion:
//
// Derived classes inherit Base Class functions.
//
// The Scope Resolution Operator allows us to explicitly call them.
// ============================================================================



// ============================================================================
// Important Observation
//
// This version demonstrates only the IDEA of Polymorphism.
//
// It is NOT Runtime Polymorphism.
//
// Why?
//
// • No virtual keyword
// • No Base Class pointer
// • No Dynamic Dispatch
// • No VTable
// • No VPtr
//
// The compiler directly calls:
//
// Dog::sound()
//
// because it already knows the object's type.
//
// Runtime Polymorphism begins in Version 5.
// ============================================================================