Excellent. This is exactly the right place to start because **every
language feature in C++ makes much more sense once you understand *why*
programming paradigms evolved.**

------------------------------------------------------------------------

# Module 1: Programming Paradigms

## 🎯 Deliverable

By the end of this module, you should be able to answer:

-   What is a programming paradigm?
-   Why do different paradigms exist?
-   Why wasn't one paradigm enough?
-   What are POP, OOP, Functional Programming, and Generic Programming?
-   Which paradigms does C++ support?
-   Which paradigm should be used in which situation?

------------------------------------------------------------------------

# 1. Why Do We Even Need Programming Paradigms?

Let's begin with a simple question.

Imagine five people want to travel from Delhi to Bangalore.

One person chooses:

-   Flight ✈️

Another chooses:

-   Train 🚆

Another chooses:

-   Car 🚗

Another chooses:

-   Bike 🏍️

Another chooses:

-   Bus 🚌

All of them reach Bangalore.

But...

They chose different **approaches**.

Programming is exactly like this.

There isn't only one way to solve a problem.

Different programmers solve problems differently.

Different applications need different styles.

That style is called a **Programming Paradigm**.

------------------------------------------------------------------------

# Definition

A **Programming Paradigm** is a style or approach to writing programs.

It defines

-   how a program is organized
-   how data is handled
-   how problems are solved
-   how code is structured

Think of it as a **philosophy of programming**.

Instead of asking

> "How do I write code?"

It asks

> "How should I think while writing code?"

------------------------------------------------------------------------

## Real Life Analogy

Suppose you're building a house.

There are multiple approaches.

Approach 1

Hire different workers separately.

    Electrician
    Painter
    Carpenter
    Plumber

Everyone does one task.

------------------------------------------------------------------------

Approach 2

Divide the house into rooms.

Each room contains

-   furniture
-   electricity
-   paint
-   plumbing

Everything related to a room stays together.

------------------------------------------------------------------------

Both methods build a house.

But the organization is different.

Programming paradigms work similarly.

------------------------------------------------------------------------

# Why Were Programming Paradms Created?

As software became larger, older approaches started showing limitations.

Let's look at the evolution.

------------------------------------------------------------------------

## Stage 1

Programs were tiny.

Example

    Add two numbers

    Find factorial

    Print marks

Only 20--50 lines of code.

No problem.

------------------------------------------------------------------------

## Stage 2

Programs became larger.

    Payroll Software

    Library System

    Hospital Software

    Airline Reservation

Thousands of lines.

Now problems started.

------------------------------------------------------------------------

People noticed:

❌ difficult to modify

❌ difficult to debug

❌ lots of repeated code

❌ impossible to manage teams

❌ difficult to reuse code

So...

New programming styles were invented.

Each one solved a different problem.

------------------------------------------------------------------------

# Different Programming Paradigms

The major paradigms are:

    Programming Paradigms
    │
    ├── Procedural Programming (POP)
    │
    ├── Object-Oriented Programming (OOP)
    │
    ├── Functional Programming
    │
    ├── Generic Programming
    │
    └── (Many others)

For interviews, these four are the most important in the context of C++.

------------------------------------------------------------------------

# 2. Procedural Programming (POP)

This was one of the earliest and most popular paradigms.

The main idea is

> Break the problem into functions (procedures).

Everything revolves around **functions**.

------------------------------------------------------------------------

## Example

Suppose you're building

    ATM Software

You may write

    login()

    withdraw()

    deposit()

    checkBalance()

    logout()

Each function performs one task.

------------------------------------------------------------------------

### Visualization

    Program

          |
     ---------------------
     |    |    |    |
    Login Deposit Withdraw Exit

Everything is a function.

------------------------------------------------------------------------

## Characteristics of POP

-   Program is divided into functions.
-   Functions operate on data.
-   Data is often shared globally or passed between functions.
-   Execution follows a sequence of instructions.

------------------------------------------------------------------------

## Small Example

``` cpp
#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int main()
{
    cout << add(5, 7);
}
```

Everything revolves around functions.

------------------------------------------------------------------------

## Advantages

✔ Easy for small programs

✔ Simple to understand

✔ Fast to develop

✔ Less memory overhead

------------------------------------------------------------------------

## Disadvantages

As software grows:

Imagine

    Hospital Management System

50,000 lines of code.

Problems begin.

    Patient Data

    Doctor Data

    Medicine Data

    Billing

    Appointments

Everything is accessed by many functions.

Changing one thing can accidentally break another.

This makes maintenance difficult.

------------------------------------------------------------------------

# 3. Object-Oriented Programming (OOP)

OOP was introduced to solve many of the problems of POP.

Instead of focusing on **functions**, OOP focuses on **objects**.

------------------------------------------------------------------------

Think about a hospital.

Instead of writing

    admitPatient()

    dischargePatient()

    checkPatient()

    updatePatient()

You think about

    Patient

    Doctor

    Medicine

    Room

    Nurse

These are **objects**.

Each object contains

    Data

    +

    Functions

Together.

------------------------------------------------------------------------

Visualization

    Patient

    ---------------
    Name

    Age

    Disease

    Room

    ---------------

    admit()

    discharge()

    update()

Everything related to a patient stays inside the patient object.

This makes programs much easier to manage.

------------------------------------------------------------------------

## Characteristics

-   Program is divided into objects.
-   Data and functions stay together.
-   Real-world modeling.
-   Better code organization.
-   Easier maintenance.
-   Better security.
-   High code reusability.

------------------------------------------------------------------------

Example

``` cpp
class Student
{
public:

    string name;

    int age;

    void display()
    {
        cout << name;
    }
};
```

Notice how

Data

    name

    age

and

Function

    display()

stay together.

------------------------------------------------------------------------

# Why is OOP Better for Large Software?

Imagine

    Facebook
    Amazon
    WhatsApp
    Uber

Millions of users.

Thousands of developers.

Millions of lines of code.

Managing everything using only functions becomes extremely difficult.

Objects naturally represent entities such as User, Order, Product,
Driver, or Message, making collaboration and maintenance much easier.

------------------------------------------------------------------------

# 4. Functional Programming (Basic Idea)

This paradigm is completely different.

Instead of changing data repeatedly,

Functional Programming prefers

> Functions that take input and produce output **without changing
> external state**.

Example:

    Input

    ↓

    Function

    ↓

    Output

The function does not modify anything outside itself.

------------------------------------------------------------------------

Simple example

    5

    ↓

    Square

    ↓

    25

The original value remains unchanged.

------------------------------------------------------------------------

### Why?

Because

-   easier testing
-   fewer unexpected side effects
-   easier parallel programming
-   more predictable behavior

------------------------------------------------------------------------

Languages

-   Haskell
-   Lisp
-   F#
-   Scala

Modern C++ also supports some functional programming features (such as
lambda expressions), but you'll learn those later.

------------------------------------------------------------------------

# 5. Generic Programming (Basic Idea)

Imagine writing this function.

``` cpp
int add(int a, int b)
```

Now you need

    double

    float

    long

    char

You might end up writing many similar functions.

That is repetitive.

Generic Programming solves this problem by writing code that works with
**many data types**.

------------------------------------------------------------------------

Example

``` cpp
template <typename T>

T add(T a, T b)
{
    return a + b;
}
```

Now

    int

    double

    float

    long

all work with the same function template.

This reduces duplication and improves code reuse.

------------------------------------------------------------------------

C++ is famous for supporting Generic Programming through templates.

The entire **Standard Template Library (STL)** is built on this idea.

------------------------------------------------------------------------

# Comparison of Paradigms

  ---------------------------------------------------------------------------
  Feature       POP           OOP           Functional         Generic
  ------------- ------------- ------------- ------------------ --------------
  Main Focus    Functions     Objects       Pure functions     Reusable
                                                               templates

  Data          Separate from Bundled with  Immutable/prefer   Independent of
                functions     functions     not to mutate      data type

  Best For      Small         Large         Predictable        Reusable
                programs      software      transformations    libraries
                              systems                          

  Reusability   Moderate      High          High               Very High

  Real-world    Poor          Excellent     Limited            Not its
  Modeling                                                     primary goal
  ---------------------------------------------------------------------------

------------------------------------------------------------------------

# Which Paradigms Does C++ Support?

One of the biggest strengths of C++ is that it is **multi-paradigm**.

It supports:

-   ✅ Procedural Programming
-   ✅ Object-Oriented Programming
-   ✅ Generic Programming
-   ✅ Functional Programming (partially, through features like lambdas
    and algorithms)

This means you're not restricted to a single style. You can choose the
approach that best fits the problem, and many real-world C++ projects
combine multiple paradigms.

------------------------------------------------------------------------

# Interview Questions

### 1. What is a programming paradigm?

A programming paradigm is a style or philosophy of programming that
determines how programs are structured and how problems are approached.

------------------------------------------------------------------------

### 2. Why do we need different paradigms?

Because different types of problems have different requirements. A style
that works well for a small script may become difficult to maintain in a
large software system.

------------------------------------------------------------------------

### 3. Why was OOP introduced?

To address the limitations of procedural programming, especially for
large, complex applications. OOP improves organization, reusability,
maintainability, and scalability by combining data and behavior into
objects.

------------------------------------------------------------------------

### 4. Is C++ an OOP language?

Not exclusively. C++ is a **multi-paradigm language** that supports
procedural, object-oriented, generic, and functional programming.

------------------------------------------------------------------------
