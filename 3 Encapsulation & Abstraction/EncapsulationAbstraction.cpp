// ============================================================================
// Abstract Class
//
// A class becomes abstract if it contains at least one pure virtual function.
// Abstract classes cannot be instantiated, but they can contain:
// 1. Data members
// 2. Constructors
// 3. Normal member functions
// 4. Virtual functions
// 5. Pure virtual functions
//
// They act as blueprints for derived classes.
// ============================================================================

#include<bits/stdc++.h>
using namespace std;

class Animal
{
protected:
    string name;

public:

    // Abstract classes can have constructors.
    // Abstract classes can have constructors. Although we cannot create objects of an abstract class directly, its constructor is automatically called whenever a derived class object is created because every derived object contains a base class part.
    Animal(string name)
    {
        this->name = name;
    }

    // Abstract classes can also have normal member functions.
    void displayName()
    {
        cout << "Animal : " << name << endl;
    }

    // Virtual Function
    // A virtual function provides a default implementation in the base class.
    // Derived classes may override it if needed.
    virtual void eat()
    {
        cout << name << " is eating.\n";
    }

    // Pure Virtual Function
    // '= 0' makes this function pure virtual.
    // Every derived class MUST provide its own implementation.
    virtual void sound() = 0;
};


class Dog : public Animal
{
public:

    // Calling the constructor of the abstract base class.
    Dog() : Animal("Dog")
    {
    }

    // Overriding the virtual function (optional).
    // 'override' is optional but recommended because it lets the compiler
    // verify that this function correctly overrides a virtual function.
    void eat() override
    {
        cout << "Dog is eating.\n";
    }

    // Overriding the pure virtual function (mandatory).
    void sound() override
    {
        cout << "Dog says: Bark Bark!\n";
    }
};


class Cat : public Animal
{
public:

    // Calling the constructor of the abstract base class.
    Cat() : Animal("Cat")
    {
    }

    // We are not overriding eat().
    // So Cat will use Animal's default implementation.

    // Overriding the pure virtual function (mandatory).
    void sound() override
    {
        cout << "Cat says: Meow Meow!\n";
    }
};


int main()
{
    // Animal animal("Animal");    // ❌ Compile Error
    // Animal is an abstract class because it contains a pure virtual function.

    // A class becomes abstract if it contains at least one pure virtual
    // function. Objects of an abstract class cannot be created.

    Dog dog;
    Cat cat;

    cout << "Dog:\n";
    dog.displayName();
    dog.eat();
    dog.sound();

    cout << "\nCat:\n";
    cat.displayName();
    cat.eat();      // Uses Animal's implementation.
    cat.sound();
}



// ============================================================================
// Experiment 1: Creating an Object of an Abstract Class
//
// Objective:
// Understand that objects of an abstract class cannot be created.
//
// Steps:
// 1. Uncomment:
//        Animal animal("Animal");
// 2. Compile the program.
// 3. Observe the compiler error.
// 4. Comment it again.
//
// Observation:
// Animal contains a pure virtual function, making it an abstract class.
// Therefore, objects of Animal cannot be created.
// ============================================================================


// ============================================================================
// Experiment 2: Forgetting to Override a Pure Virtual Function
//
// Objective:
// Understand that every derived class must implement all inherited pure
// virtual functions.
//
// Steps:
// 1. Temporarily comment out Cat::sound().
// 2. Compile the program.
// 3. Observe the compiler error.
// 4. Restore Cat::sound().
//
// Observation:
// Since Animal::sound() is a pure virtual function, Cat must provide its own
// implementation. Otherwise, Cat also becomes an abstract class, and its
// objects cannot be created.
// ============================================================================

// ============================================================================
// Experiment 3: Abstract Classes Can Have Implemented Members
//
// Objective:
// Understand that abstract classes can contain constructors, data members,
// and normal member functions.
//
// Steps:
// 1. Notice that Animal has:
//        - a data member (name)
//        - a constructor
//        - displayName()
//        - eat()
// 2. Run the program.
// 3. Observe that Dog and Cat inherit and use these members.
//
// Observation:
// An abstract class cannot be instantiated, but it can still provide common
// data and functionality that all derived classes inherit and reuse.
// ============================================================================