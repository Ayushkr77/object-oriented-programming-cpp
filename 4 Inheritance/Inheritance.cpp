// ============================================================================
// Version 6
//
// Topics Covered:
// - Hierarchical Inheritance
// - Constructor Calling Order
// - Destructor Calling Order
// ============================================================================

#include<bits/stdc++.h>
using namespace std;

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

    void bark()
    {
        cout << name << " says: Bark Bark!\n";
    }
};



class Cat : public Mammal
{
public:

    Cat()
    {
        cout << "Cat Constructor Called\n";
    }

    ~Cat()
    {
        cout << "Cat Destructor Called\n";
    }

    void meow()
    {
        cout << name << " says: Meow Meow!\n";
    }
};



class Horse : public Mammal
{
public:

    Horse()
    {
        cout << "Horse Constructor Called\n";
    }

    ~Horse()
    {
        cout << "Horse Destructor Called\n";
    }

    void neigh()
    {
        cout << name << " says: Neigh!\n";
    }
};



int main()
{
    cout << "========== DOG ==========\n";

    Dog dog;
    dog.setName("Bruno");
    dog.setAge(3);

    dog.eat();
    dog.sleep();
    dog.walk();
    dog.bark();


    cout << "\n========== CAT ==========\n";

    Cat cat;
    cat.setName("Kitty");
    cat.setAge(2);

    cat.eat();
    cat.sleep();
    cat.walk();
    cat.meow();


    cout << "\n========== HORSE ==========\n";

    Horse horse;
    horse.setName("Thunder");
    horse.setAge(5);

    horse.eat();
    horse.sleep();
    horse.walk();
    horse.neigh();
}



// ============================================================================
// Experiment 1 : Constructor Order
//
// Objective:
// Observe constructor execution for different derived classes.
//
// Steps:
//
// 1. Create Dog, Cat and Horse objects.
//
// Observation:
//
// Every object calls:
//
// Animal Constructor
// Mammal Constructor
// Derived Class Constructor
//
// independently.
//
// Conclusion:
//
// Every derived object constructs its own inheritance chain.
// ============================================================================



// ============================================================================
// Experiment 2 : Code Reusability
//
// Objective:
// Observe inherited members.
//
// Steps:
//
// 1. Notice Dog, Cat and Horse do not define:
//
// eat()
// sleep()
// walk()
//
// 2. Yet all objects successfully call them.
//
// Observation:
//
// Common functionality is written once in Mammal and Animal
// and reused by every derived class.
//
// Conclusion:
//
// Hierarchical Inheritance improves code reusability.
// ============================================================================



// ============================================================================
// Experiment 3 : Independent Objects
//
// Objective:
// Understand that derived classes are independent.
//
// Steps:
//
// 1. Remove class Cat.
//
// 2. Run the program.
//
// Observation:
//
// Dog and Horse continue working normally.
//
// Conclusion:
//
// In Hierarchical Inheritance, sibling classes do not depend on
// one another. They only depend on their common base class.
// ============================================================================