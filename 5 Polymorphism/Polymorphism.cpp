#include<bits/stdc++.h>
using namespace std;

// ============================================================================
// Version 4
//
// Topics Covered:
//
// - Function Overriding
// - Same Function Signature
// - Base Class
// - Derived Class
// - Method Hiding
// ============================================================================



// ============================================================================
// Base Class
//
// Animal provides a generic implementation.
//
// Derived classes will override this function.
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
// Dog overrides sound().
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
// Cat overrides sound().
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
// Cow overrides sound().
// ============================================================================
class Cow : public Animal
{
public:

    void sound()
    {
        cout << "Cow says: Moo Moo!" << endl;
    }
};



int main()
{
    Dog dog;
    Cat cat;
    Cow cow;

    cout << "Dog:" << endl;
    dog.sound();

    cout << endl;

    cout << "Cat:" << endl;
    cat.sound();

    cout << endl;

    cout << "Cow:" << endl;
    cow.sound();

    cout << endl;

    cout << "Calling Base Class Function Explicitly:" << endl;

    dog.Animal::sound();
}



// ============================================================================
// Experiment 1 : Calling Base Class Function
//
// Objective:
//
// Observe explicit Base Class access.
//
// Try:
//
// dog.Animal::sound();
//
// Observation:
//
// Animal makes a sound.
//
// Conclusion:
//
// Even though Dog overrides sound(),
// the Base Class version still exists and
// can be accessed using the Scope Resolution Operator.
// ============================================================================



// ============================================================================
// Experiment 2 : Remove Dog::sound()
//
// Objective:
//
// Observe inherited behavior.
//
// Remove:
//
// void sound()
//
// from Dog.
//
// Observation:
//
// dog.sound();
//
// now calls
//
// Animal::sound()
//
// Conclusion:
//
// If a Derived Class does not override,
// it inherits the Base implementation.
// ============================================================================



// ============================================================================
// Experiment 3 : Change Parameter List
//
// Objective:
//
// Observe overriding requirements.
//
// Replace:
//
// void sound()
//
// with
//
// void sound(int volume)
//
// Observation:
//
// Dog no longer overrides Animal::sound().
//
// Conclusion:
//
// The parameter list must match for overriding.
// ============================================================================



// ============================================================================
// Experiment 4 : Different Return Type
//
// Objective:
//
// Observe return type rules.
//
// Try:
//
// int sound();
//
// Observation:
//
// Compilation Error (or no valid override).
//
// Conclusion:
//
// Return type generally cannot be changed
// when overriding (except for certain covariant cases,
// which are beyond our current scope).
// ============================================================================



// ============================================================================
// Experiment 5 : Why This Is Not Runtime Polymorphism
//
// Objective:
//
// Understand the limitation.
//
// Observe:
//
// Dog dog;
//
// dog.sound();
//
// Compiler already knows
// that the object is Dog.
//
// Therefore,
// it directly calls Dog::sound().
//
// Conclusion:
//
// Runtime Polymorphism has NOT started.
//
// That begins only after introducing:
//
// virtual
// ============================================================================



// ============================================================================
// Important Observation
//
// Function Overriding simply means
// a Derived Class provides its own implementation
// of a Base Class function.
//
// It does NOT automatically create
// Runtime Polymorphism.
//
// Runtime Polymorphism requires:
//
// • Function Overriding
// • virtual keyword
// • Base Class pointer/reference
// • Dynamic Dispatch
// ============================================================================