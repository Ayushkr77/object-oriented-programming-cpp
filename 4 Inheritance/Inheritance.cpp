// ============================================================================
// Multiple Inheritance Example
//
// Walker        Swimmer
//      \        /
//       \      /
//         Duck
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

class Walker
{
public:

    Walker()
    {
        cout << "Walker Constructor Called\n";
    }

    ~Walker()
    {
        cout << "Walker Destructor Called\n";
    }

    void walk()
    {
        cout << "Duck is walking.\n";
    }
};



class Swimmer
{
public:

    Swimmer()
    {
        cout << "Swimmer Constructor Called\n";
    }

    ~Swimmer()
    {
        cout << "Swimmer Destructor Called\n";
    }

    void swim()
    {
        cout << "Duck is swimming.\n";
    }
};



class Duck : public Walker, public Swimmer
{
public:

    Duck()
    {
        cout << "Duck Constructor Called\n";
    }

    ~Duck()
    {
        cout << "Duck Destructor Called\n";
    }

    void quack()
    {
        cout << "Duck says: Quack Quack!\n";
    }
};



int main()
{
    cout << "\n================ MULTIPLE INHERITANCE ================\n\n";

    Duck duck;

    duck.walk();
    duck.swim();
    duck.quack();
}


// ============================================================================
// Experiment 1 : Constructor Calling Order in Multiple Inheritance
//
// Objective:
// Observe the order in which constructors are called when a class
// inherits from multiple base classes.
//
// Steps:
//
// 1. Create an object:
//
//        Duck duck;
//
// 2. Run the program.
//
// Observation:
//
// Walker Constructor Called
// Swimmer Constructor Called
// Duck Constructor Called
//
// Notice that the constructors of the base classes execute first,
// following the order in which they are inherited:
//
//        class Duck : public Walker, public Swimmer
//
// Conclusion:
//
// In Multiple Inheritance, base class constructors are called
// from left to right (as written in the inheritance list),
// followed by the derived class constructor.
// ============================================================================



// ============================================================================
// Experiment 2 : Destructor Calling Order in Multiple Inheritance
//
// Objective:
// Observe the order in which destructors are called.
//
// Steps:
//
// 1. Run the program.
//
// 2. Observe the last lines of the output.
//
// Observation:
//
// Duck Destructor Called
// Swimmer Destructor Called
// Walker Destructor Called
//
// Notice that destructors execute in the exact reverse order
// of constructors.
//
// Conclusion:
//
// In Multiple Inheritance, destructors are called in reverse order:
// Derived Class → Rightmost Base Class → Leftmost Base Class.
// ============================================================================



// ============================================================================
// Experiment 3 : Accessing Members from Multiple Base Classes
//
// Objective:
// Understand how the derived class reuses members from multiple parents.
//
// Steps:
//
// 1. Observe that Duck defines only:
//
//        quack();
//
// 2. Duck does NOT define:
//
//        walk();
//        swim();
//
// 3. Yet the following calls work:
//
//        duck.walk();
//        duck.swim();
//
// Observation:
//
// Duck inherits walk() from Walker
// and swim() from Swimmer.
//
// Conclusion:
//
// Multiple Inheritance allows a class to reuse functionality
// from more than one base class.
// ============================================================================



// ============================================================================
// Experiment 4 : Base Class Order Matters
//
// Objective:
// Observe that the inheritance order controls the constructor order.
//
// Steps:
//
// 1. Change:
//
//        class Duck : public Walker, public Swimmer
//
// to
//
//        class Duck : public Swimmer, public Walker
//
// 2. Run the program.
//
// Observation:
//
// Swimmer Constructor Called
// Walker Constructor Called
// Duck Constructor Called
//
// Destructors:
//
// Duck Destructor Called
// Walker Destructor Called
// Swimmer Destructor Called
//
// Conclusion:
//
// The order of base classes in the inheritance list determines:
//
// • Constructor execution order
// • Destructor execution order
// ============================================================================



// ============================================================================
// Experiment 5 : Removing One Base Class
//
// Objective:
// Understand what functionality comes from each base class.
//
// Steps:
//
// 1. Remove:
//
//        public Swimmer
//
// from Duck.
//
// 2. Compile the program.
//
// 3. Try:
//
//        duck.swim();
//
// Observation:
//
// Compilation Error.
//
// Duck no longer inherits swim() because Swimmer has been removed.
//
// Conclusion:
//
// Every base class contributes its own members to the derived class.
// ============================================================================