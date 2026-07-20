// For pure virtual functions, we'll use a different example because Pure Virtual Functions and Abstract Classes introduce inheritance and polymorphism. Mixing them into our current banking example will require major restructuring, which distracts from the concept.
// ============================================================================
// For Pure Virtual Functions, we'll use a different example because they
// introduce inheritance and polymorphism. Mixing them into our current
// BankAccount example would require major restructuring, which would distract
// from the core concept. We'll revisit the BankAccount example when we study
// runtime polymorphism in detail.
// ============================================================================

#include<bits/stdc++.h>
using namespace std;
class Animal
{
public:

    // Virtual Function
    // A virtual function provides a default implementation in the base class.
    // Derived classes may override it if needed.
    virtual void eat()
    {
        cout << "Animal is eating.\n";
    }

    // Pure Virtual Function
    // '= 0' makes this function pure virtual.
    // It has no implementation here, and every derived class MUST override it.
    virtual void sound() = 0;
};


class Dog : public Animal
{
public:

    // Overriding the virtual function (optional)
    void eat() override  // writing overwrite is optional but its recommended bcz 'override' tells the compiler that this function must override a virtual function from the base class. If the function name or parameter list (function signature) does not exactly match the base class function, the compiler reports an error.
    {
        cout << "Dog is eating.\n";
    }

    // Overriding the pure virtual function (mandatory)
    void sound() override
    {
        cout << "Dog says: Bark Bark!\n";
    }
};


class Cat : public Animal
{
public:

    // We are not overriding eat().
    // So Cat will use Animal's default implementation.

    // Overriding the pure virtual function (mandatory)
    void sound() override
    {
        cout << "Cat says: Meow Meow!\n";
    }
};


int main()
{
    // Animal animal;    // ❌ Compile Error
    // Animal is an abstract class because it contains a pure virtual function.

    // A class is abstract if it has at least one pure virtual function that has not been implemented.

    Dog dog;
    Cat cat;

    cout << "Dog:\n";
    dog.eat();      // Dog's overridden version
    dog.sound();

    cout << "\nCat:\n";
    cat.eat();      // Animal's default implementation
    cat.sound();
}



// ============================================================================
// Experiment 1: Forgetting to Override a Pure Virtual Function
//
// Objective:
// Understand that every derived class must implement all pure virtual
// functions of the base class.
//
// Steps:
// 1. Temporarily comment out Dog::sound().
// 2. Compile the program.
// 3. Observe the compiler error.
// 4. Restore Dog::sound().
//
// Observation:
// Since Animal::sound() is a pure virtual function, Dog must provide its own
// implementation. Otherwise, Dog also becomes an abstract class, and its
// objects cannot be created.
// ============================================================================

// ============================================================================
// Experiment 2: Creating an Object of an Abstract Class
//
// Objective:
// Understand that abstract classes cannot be instantiated.
//
// Steps:
// 1. Uncomment the following line:
//        Animal a;
// 2. Compile the program.
// 3. Observe the compiler error.
// 4. Comment it again.
//
// Observation:
// Animal contains a pure virtual function, making it an abstract class.
// Therefore, objects of Animal cannot be created. Only derived classes that
// implement all pure virtual functions can be instantiated.

// Since Animal::sound() is a pure virtual function, every derived class must
// provide its own implementation. Otherwise, the derived class also remains
// an abstract class, and objects of that derived class cannot be created.

// A derived class automatically becomes an abstract class if it does not implement all the pure virtual functions inherited from its base class. Since abstract classes cannot be instantiated, objects of that derived class also cannot be created until the missing implementations are provided.
// ============================================================================