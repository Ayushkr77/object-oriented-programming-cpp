#include<bits/stdc++.h>
using namespace std;

// ============================================================================
// Version 8
//
// Topics Covered:
// - Hybrid Inheritance
// - Combination of Multiple + Multilevel Inheritance
// - Constructor Calling Order
// - Destructor Calling Order

        //           Animal
        //              │
        //              ▼
        //            Bird
        //              │
        //              │
        // Flyer        │        Swimmer
        //    │         │           │
        //    │         │           │
        //    └─────────┼───────────┘
        //              ▼
        //            Duck
// ============================================================================

class Animal
{
public:

    Animal()
    {
        cout << "Animal Constructor Called\n";
    }

    ~Animal()
    {
        cout << "Animal Destructor Called\n";
    }

    void eat()
    {
        cout << "Animal is eating.\n";
    }
};



class Bird : public Animal
{
public:

    Bird()
    {
        cout << "Bird Constructor Called\n";
    }

    ~Bird()
    {
        cout << "Bird Destructor Called\n";
    }

    void layEggs()
    {
        cout << "Bird lays eggs.\n";
    }
};



class Flyer
{
public:

    Flyer()
    {
        cout << "Flyer Constructor Called\n";
    }

    ~Flyer()
    {
        cout << "Flyer Destructor Called\n";
    }

    void fly()
    {
        cout << "Duck is flying.\n";
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



class Duck : public Bird, public Flyer, public Swimmer
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
    Duck duck;

    cout << endl;

    duck.eat();
    duck.layEggs();
    duck.fly();
    duck.swim();
    duck.quack();
}



// ============================================================================
// Experiment 1 : Constructor Calling Order
//
// Objective:
// Observe constructor execution in Hybrid Inheritance.
//
// Steps:
//
// 1. Create:
//
//        Duck duck;
//
// 2. Run the program.
//
// Observation:
//
// Animal Constructor Called
// Bird Constructor Called
// Flyer Constructor Called
// Swimmer Constructor Called
// Duck Constructor Called
//
// Conclusion:
//
// Constructors execute from base classes to the derived class,
// following the inheritance hierarchy.
// ============================================================================



// ============================================================================
// Experiment 2 : Destructor Calling Order
//
// Objective:
// Observe destructor execution.
//
// Steps:
//
// 1. Run the program.
//
// 2. Observe the last lines.
//
// Observation:
//
// Duck Destructor Called
// Swimmer Destructor Called
// Flyer Destructor Called
// Bird Destructor Called
// Animal Destructor Called
//
// Conclusion:
//
// Destructors execute in the reverse order of constructors.
// ============================================================================



// ============================================================================
// Experiment 3 : Hybrid Inheritance
//
// Objective:
// Identify why this hierarchy is called Hybrid.
//
// Steps:
//
// Observe:
//
// Animal → Bird
//
// (Multilevel)
//
// Duck inherits from:
//
// Bird
// Flyer
// Swimmer
//
// (Multiple)
//
// Observation:
//
// The hierarchy combines multiple inheritance types.
//
// Conclusion:
//
// Hybrid Inheritance is simply a combination of two or more
// inheritance types.
// ============================================================================



// ============================================================================
// Experiment 4 : Removing One Parent
//
// Objective:
// Observe inherited functionality.
//
// Steps:
//
// Remove:
//
//        public Swimmer
//
// from Duck.
//
// Try:
//
//        duck.swim();
//
// Observation:
//
// Compilation Error.
//
// Conclusion:
//
// Every parent contributes its own members.
// ============================================================================



// ============================================================================
// Experiment 5 : Constructor Order Depends on Inheritance List
//
// Objective:
// Observe constructor execution order.
//
// Steps:
//
// Change:
//
// class Duck : public Bird, public Flyer, public Swimmer
//
// to
//
// class Duck : public Swimmer, public Flyer, public Bird
//
// Observation:
//
// Constructors execute in the same order as the inheritance list.
//
// Conclusion:
//
// Constructor order depends on the order of base classes
// in the inheritance list.
// ============================================================================