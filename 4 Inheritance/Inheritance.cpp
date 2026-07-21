// note that in this file, many commits will be there, those are versions which represents the learning progress how we learnt each thing one by one. Try to see all the commits of this file. Also, see every block, every comment, and every change carefully.

#include<bits/stdc++.h>
using namespace std;

// ============================================================================
// Version 4
//
// Topics Covered:
// - Constructor Calling Order
// - Destructor Calling Order
// - Constructor Chaining
// - Destructor Chaining
// - Reverse Order Principle
// ============================================================================



// ============================================================================
// Base Class
// ============================================================================
class Animal
{
protected:

    string name;
    int age;

public:

    // Base Class Constructor
    Animal()
    {
        cout << "Animal Constructor Called\n";
    }

    // Base Class Destructor
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



// ============================================================================
// Derived Class
// ============================================================================
class Dog : public Animal
{
public:

    // Derived Class Constructor
    Dog()
    {
        cout << "Dog Constructor Called\n";
    }

    // Derived Class Destructor
    ~Dog()
    {
        cout << "Dog Destructor Called\n";
    }

    string breed;

    void bark()
    {
        cout << name << " says: Bark Bark!\n";
    }

    void displayDetails()
    {
        cout << "Dog Details\n\n";

        cout << "Name  : " << name << endl;
        cout << "Age   : " << age << endl;
        cout << "Breed : " << breed << endl;

        cout << endl;
    }
};



int main()
{
    Dog dog;

    dog.setName("Bruno");
    dog.setAge(3);
    dog.breed = "Golden Retriever";

    dog.displayDetails();

    dog.eat();
    dog.sleep();
    dog.bark();

    // When main() finishes, the object 'dog' goes out of scope.
    // C++ automatically calls the destructors in reverse order.
}