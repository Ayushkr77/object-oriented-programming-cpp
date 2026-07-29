#include<bits/stdc++.h>
using namespace std;

// ============================================================================
// Version 3
//
// Topics Covered:
//
// - Operator Overloading
// - Binary Operator
// - Member Function Overloading
// - Compile-Time Polymorphism
// ============================================================================



// ============================================================================
// Point
//
// Represents a point in 2D space.
//
// We will overload the + operator.
//
// Meaning:
//
// (x1,y1) + (x2,y2)
//
// =
//
// (x1+x2 , y1+y2)
// ============================================================================
class Point
{
private:

    int x;
    int y;

public:

    Point(int x,int y)
    {
        this->x = x;
        this->y = y;
    }

    void display()
    {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }

    // ========================================================================
    // Operator Overloading
    //
    // This function overloads the + operator.
    //
    // Whenever we write:
    //
    // p1 + p2
    //
    // the compiler internally converts it into:
    //
    // p1.operator+(p2)
    // ========================================================================
    Point operator+(const Point &other)
    {
        Point temp(x + other.x,
                   y + other.y);

        return temp;
    }
};



int main()
{
    Point p1(2,3);

    Point p2(4,5);

    Point p3 = p1 + p2;

    Point p4 = p1 + p2 + p3;

    cout<<"Point 1 : ";
    p1.display();

    cout<<"Point 2 : ";
    p2.display();

    cout<<"Point 3 : ";
    p3.display();

    cout<<"Point 4 : ";
    p4.display();
}



// ============================================================================
// Experiment 1 : Observe Compiler Translation
//
// Objective:
//
// Understand what actually happens.
//
// Replace:
//
// Point p3 = p1 + p2;
//
// Conceptually with:
//
// Point p3 = p1.operator+(p2);
//
// Observation:
//
// Same output.
//
// Conclusion:
//
// Operators internally become function calls.
// ============================================================================



// ============================================================================
// Experiment 2 : Change the Meaning
//
// Objective:
//
// Observe that we define the operator's behavior.
//
// Modify:
//
// return Point(x + other.x,
//              y + other.y);
//
// to
//
// return Point(x - other.x,
//              y - other.y);
//
// Observation:
//
// '+' now performs subtraction.
//
// Conclusion:
//
// The symbol remains '+',
// but the meaning is defined by us.
// ============================================================================



// ============================================================================
// Experiment 3 : Chained Addition
//
// Objective:
//
// Observe multiple operator calls.
//
// Try:
//
// Point p4 = p1 + p2 + p3;
//
// Observation:
//
// Compiler performs:
//
// p1.operator+(p2)
//
// then
//
// result.operator+(p3)
//
// Conclusion:
//
// Every '+' invokes operator+().
// ============================================================================



// ============================================================================
// Experiment 4 : Built-in vs User-defined
//
// Objective:
//
// Compare built-in types.
//
// int a = 10;
// int b = 20;
//
// cout << a + b;
//
// Observation:
//
// Built-in operators already have predefined meanings.
//
// Our Point class required us to define one.
// ============================================================================



// ============================================================================
// Experiment 5 : Invalid Operator
//
// Objective:
//
// Remove operator+().
//
// Then write:
//
// Point p3 = p1 + p2;
//
// Observation:
//
// Compilation Error:
//
// no match for operator+
//
// Conclusion:
//
// The compiler cannot invent
// the meaning of '+' for user-defined classes.
// ============================================================================



// ============================================================================
// Important Observation
//
// Operator Overloading does NOT create new operators.
//
// It only gives existing operators
// a meaning for user-defined types.
//
// Operators such as:
//
// +
// -
// *
// ==
//
// already exist.
//
// We simply define how they behave
// for our own classes.
//
// This decision is made entirely during compilation.
//
// Therefore,
// this is Compile-Time Polymorphism.
// ============================================================================