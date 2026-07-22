#include <bits/stdc++.h>
using namespace std;

// Little bit confusion in this code file, especially in case 3, 3b, 5

/*
====================================================================
   TOPIC: Variable Hiding, Function Hiding, and Function Overriding
====================================================================
This file walks through each case one by one, exactly in the order
they're usually explained. Each case is wrapped in its own namespace
so that classes named "Animal" / "Dog" can be reused in every case
without redefinition errors, while keeping everything in one file.
====================================================================
*/


// ====================================================================
// CASE 1: Base and Derived have the SAME VARIABLE
// ====================================================================
namespace Case1
{
    class Animal
    {
    public:
        string name = "Animal";
    };

    class Dog : public Animal
    {
    public:
        // Same variable name as the base class.
        // This does NOT override the base variable - variables can't
        // be overridden in C++. It simply HIDES the base variable.
        string name = "Dog";
    };

    void run()
    {
        cout << "\n===== Case 1: Variable Hiding =====\n";

        Dog dog;

        // dog.name resolves to Dog::name because it hides Animal::name
        cout << "dog.name           = " << dog.name << endl;   // Dog

        // Use Scope Resolution Operator (::) to access the hidden
        // base class variable explicitly.
        cout << "dog.Animal::name   = " << dog.Animal::name << endl; // Animal
    }
}


// ====================================================================
// CASE 2: Base and Derived have the SAME FUNCTION (non-virtual)
// ====================================================================
namespace Case2
{
    class Animal
    {
    public:
        void sound()
        {
            cout << "Animal Sound";
        }
    };

    class Dog : public Animal
    {
    public:
        // Same function name, same signature, NOT virtual.
        // This HIDES Animal::sound() - it does not override it.
        void sound()
        {
            cout << "Dog Bark";
        }
    };

    void run()
    {
        cout << "\n===== Case 2: Function Hiding =====\n";

        Dog dog;

        cout << "dog.sound()          -> ";
        dog.sound();               // Dog Bark
        cout << endl;

        // Access the hidden base version using Scope Resolution.
        cout << "dog.Animal::sound()  -> ";
        dog.Animal::sound();       // Animal Sound
        cout << endl;
    }
}


// ====================================================================
// CASE 3: Function Hiding vs Function Overriding
// ====================================================================
namespace Case3
{
    class Animal
    {
    public:
        // NOT virtual -> Dog::sound() will HIDE this, not override it.
        void sound()
        {
            cout << "Animal";
        }
    };

    class Dog : public Animal
    {
    public:
        void sound()
        {
            cout << "Dog";
        }
    };

    void run()
    {
        cout << "\n===== Case 3: Function Hiding vs Function Overriding =====\n";

        // Since sound() is NOT virtual, calling it through a base
        // class pointer resolves at COMPILE TIME using the POINTER
        // TYPE (Animal), not the actual object type (Dog).
        Animal* ptr = new Dog();

        cout << "ptr->sound() (non-virtual) -> ";
        ptr->sound();     // Prints "Animal", NOT "Dog"
        cout << endl;

        delete ptr;

        cout << "(This proves it's Function Hiding, not Overriding,\n"
                " because 'virtual' was not used in the base class.)\n";
    }
}


// ====================================================================
// CASE 3B: The SAME example, but made virtual -> now it's Overriding
// ====================================================================
namespace Case3B
{
    class Animal
    {
    public:
        // virtual -> enables Runtime Polymorphism.
        virtual void sound()
        {
            cout << "Animal";
        }
    };

    class Dog : public Animal
    {
    public:
        // override is optional but recommended - the compiler checks
        // that this really does override a virtual base function.
        void sound() override
        {
            cout << "Dog";
        }
    };

    void run()
    {
        cout << "\n===== Case 3B: Function Overriding (with virtual) =====\n";

        Animal* ptr = new Dog();

        // Because sound() is virtual, this resolves at RUNTIME based
        // on the ACTUAL object type (Dog), not the pointer type.
        cout << "ptr->sound() (virtual) -> ";
        ptr->sound();      // Prints "Dog"
        cout << endl;

        delete ptr;

        cout << "(This is Runtime Polymorphism - studied in the\n"
                " Polymorphism chapter.)\n";
    }
}


// ====================================================================
// CASE 4: No Conflict - different names, so nothing gets hidden
// ====================================================================
namespace Case4
{
    class Animal
    {
    public:
        void eat()
        {
            cout << "Eat";
        }

        void sleep()
        {
            cout << "Sleep";
        }
    };

    class Dog : public Animal
    {
    public:
        // Completely new function name - no relation to Animal's names.
        void bark()
        {
            cout << "Bark";
        }
    };

    void run()
    {
        cout << "\n===== Case 4: No Conflict (different names) =====\n";

        Dog dog;

        // All three work perfectly - no hiding occurs because there
        // is no name collision between base and derived.
        cout << "dog.eat()   -> "; dog.eat();   cout << endl;
        cout << "dog.sleep() -> "; dog.sleep(); cout << endl;
        cout << "dog.bark()  -> "; dog.bark();  cout << endl;
    }
}


// ====================================================================
// CASE 5: Parameter Difference - hides the ENTIRE base overload set
// ====================================================================
namespace Case5
{
    class Animal
    {
    public:
        // Base class version takes NO parameters.
        void display()
        {
            cout << "Animal";
        }
    };

    class Dog : public Animal
    {
    public:
        // Derived class version takes an int parameter - a DIFFERENT
        // signature, but the SAME function name "display".
        //
        // SURPRISING RULE: defining display(int) in Dog hides ALL
        // overloads of "display" from Animal - even display() with
        // zero parameters, which doesn't even exist in Dog.
        void display(int age)
        {
            cout << age;
        }
    };

    void run()
    {
        cout << "\n===== Case 5: Parameter Difference Hides Entire Overload Set =====\n";

        Dog dog;

        // dog.display();   // <-- Uncommenting this line = COMPILE ERROR
        // Reason: Dog::display(int) hides Animal::display() completely.

        cout << "dog.display(10) -> ";
        dog.display(10);     // Works - matches Dog::display(int)
        cout << endl;

        cout << "(dog.display() with no arguments would NOT compile here)\n";
    }
}


// ====================================================================
// CASE 6: Fixing Case 5 using the 'using' declaration
// ====================================================================
namespace Case6
{
    class Animal
    {
    public:
        void display()
        {
            cout << "Animal";
        }
    };

    class Dog : public Animal
    {
    public:
        // This "un-hides" every overload of Animal::display,
        // bringing them back into scope alongside Dog's own version.
        using Animal::display;

        void display(int age)
        {
            cout << age;
        }
    };

    void run()
    {
        cout << "\n===== Case 6: Fixing Overload Hiding with 'using' =====\n";

        Dog dog;

        // Now BOTH versions are visible and callable.
        cout << "dog.display()   -> "; dog.display();   cout << endl; // Animal
        cout << "dog.display(10) -> "; dog.display(10); cout << endl; // 10
    }
}


// ====================================================================
//                              MAIN
// ====================================================================
int main()
{
    Case1::run();
    Case2::run();
    Case3::run();
    Case3B::run();
    Case4::run();
    Case5::run();
    Case6::run();

    return 0;
}

/*
====================================================================
                       QUICK REFERENCE SUMMARY
====================================================================
Situation                                    | Concept              | Access Base Version
----------------------------------------------------------------------------------------------
Same variable name                           | Variable Hiding      | obj.Base::variable
Same non-virtual function                    | Function Hiding      | obj.Base::function()
Same virtual function                        | Function Overriding  | Base pointer/ref -> actual type wins (runtime)
Different params, same function name         | Function Hiding      | using Base::function;  (brings back ALL overloads)
Completely different names                   | No Hiding            | Just call normally - no conflict

Key takeaways:
  1. Hiding = compile-time, based on matching NAMES (variables and
     non-virtual functions).
  2. Overriding = runtime, only applies to VIRTUAL functions, resolved
     using the actual object type.
  3. One matching name in the derived class hides ALL base overloads
     of that name - use `using Base::name;` to bring them all back.
====================================================================
*/