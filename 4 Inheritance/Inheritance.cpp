// note that in this file, many commits will be there, those are versions which represents the learning progress how we learnt each thing one by one. Try to see all the commits of this file. Also, see every block, every comment, and every change carefully.


#include<bits/stdc++.h>
using namespace std;

// ============================================================================
// Version 1
//
// Topics Covered:
// - Introduction to Inheritance
// - Single Inheritance
// - Base Class
// - Derived Class
// - IS-A Relationship
// - Code Reusability
// ============================================================================



// ============================================================================
// Base Class
//
// Animal is the Base Class (also called Parent Class or Super Class).
// It contains the common properties and behaviors that can be reused
// by other classes.
// ============================================================================
class Animal
{
public:

    string name;
    int age;

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
// Derived Class
//
// Dog is the Derived Class (also called Child Class or Sub Class).
//
// Dog IS-A Animal.
//
// Therefore, Dog automatically inherits:
//
// • name
// • age
// • eat()
// • sleep()
//
// and only adds its own specialized members.
//
// This demonstrates Code Reusability.
// ============================================================================
class Dog : public Animal
{
public:

    string breed;

    void bark()
    {
        cout << name << " says: Bark Bark!\n";
    }
};



int main()
{
    Dog dog;

    // Members inherited from Animal
    dog.name = "Bruno";
    dog.age = 3;

    // Member belonging to Dog
    dog.breed = "Golden Retriever";


    cout << "Dog Details\n\n";

    cout << "Name  : " << dog.name << endl;
    cout << "Age   : " << dog.age << endl;
    cout << "Breed : " << dog.breed << endl;

    cout << endl;

    // Functions inherited from Animal
    dog.eat();
    dog.sleep();

    // Function belonging to Dog
    dog.bark();
}