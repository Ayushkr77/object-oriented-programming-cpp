#include<bits/stdc++.h>
using namespace std;

// ============================================================================
// Version 2
//
// Topics Covered:
//
// - Function Overloading
// - Compile-Time Polymorphism
// - Function Signature
// - Overload Resolution
// ============================================================================



// ============================================================================
// Calculator
//
// All functions have the SAME name.
//
// Only their parameter lists are different.
//
// This is called Function Overloading.
// ============================================================================
class Calculator
{
public:

    void add(int a, int b)
    {
        cout << "add(int,int) called" << endl;
        cout << "Result = " << a + b << endl;
    }

    void add(double a, double b)
    {
        cout << "add(double,double) called" << endl;
        cout << "Result = " << a + b << endl;
    }

    void add(int a, int b, int c)
    {
        cout << "add(int,int,int) called" << endl;
        cout << "Result = " << a + b + c << endl;
    }
};



int main()
{
    Calculator calculator;

    calculator.add(10,20);

    cout << endl;

    calculator.add(10.5,20.5);

    cout << endl;

    calculator.add(10,20,30);
}



// ============================================================================
// Experiment 1 : Different Parameter Types
//
// Objective:
//
// Observe compiler overload resolution.
//
// Try:
//
// calculator.add(5,6);
//
// calculator.add(5.5,6.5);
//
// Observation:
//
// Compiler automatically chooses the correct function.
//
// Conclusion:
//
// Parameter types decide overload selection.
// ============================================================================



// ============================================================================
// Experiment 2 : Different Number of Parameters
//
// Objective:
//
// Observe overload based on parameter count.
//
// Try:
//
// calculator.add(1,2);
//
// calculator.add(1,2,3);
//
// Observation:
//
// Both functions have the same name.
//
// Compiler distinguishes them using
// the number of parameters.
// ============================================================================



// ============================================================================
// Experiment 3 : Return Type Only
//
// Objective:
//
// Observe why return type alone
// cannot overload functions.
//
// Try creating:
//
// int multiply(int,int);
//
// double multiply(int,int);
//
// Observation:
//
// Compilation Error.
//
// Conclusion:
//
// Return type is NOT part of
// the function signature.
// ============================================================================



// ============================================================================
// Experiment 4 : Implicit Conversion
//
// Objective:
//
// Observe overload resolution.
//
// Try:
//
// calculator.add('A','B');
//
// Observation:
//
// Characters are promoted to int.
//
// Therefore,
//
// add(int,int)
//
// gets selected.
// ============================================================================



// ============================================================================
// Experiment 5 : Ambiguous Overload
//
// Objective:
//
// Observe ambiguity.
//
// Create:
//
// void fun(int,double);
//
// void fun(double,int);
//
//
//
// Call:
//
// fun(10,10);
//
// Observation:
//
// Compilation Error:
//
// call is ambiguous
//
// Conclusion:
//
// Compiler cannot decide
// which overload is a better match.
// ============================================================================



// ============================================================================
// Important Observation
//
// This is REAL Polymorphism.
//
// But it is Compile-Time Polymorphism.
//
// The compiler selects the correct function
// before the program runs.
//
// No:
//
// • virtual
// • Base Pointer
// • Dynamic Dispatch
// • Runtime Decision
// ============================================================================