> **Note:** This module introduces concepts that depend on **inheritance**. We'll study inheritance in detail on **Day 4**, so for now we'll build only the conceptual understanding. The implementation will become much clearer after learning inheritance.

---

# Module 6: Pure Virtual Functions

## 🎯 Objective

By the end of this module, you should understand:

* What a virtual function is (basic idea).
* What a pure virtual function is.
* The syntax (`= 0`).
* Why pure virtual functions are used.
* How they enforce implementation in derived classes.
* Why they help achieve abstraction.

---

# 1. What is a Virtual Function? (Brief Introduction)

A **Virtual Function** is a member function that can be **overridden** by derived classes.

It allows a derived class to provide its own implementation.

***A class is abstract if it has at least one pure virtual function that has not been implemented.***

For now, just remember:

```text
Base Class

↓

Virtual Function

↓

Derived Class provides its own implementation
```

We'll study virtual functions in detail on **Day 5 (Polymorphism)**.

---

# 2. What is a Pure Virtual Function?

## Definition

A **Pure Virtual Function** is a virtual function that **has no implementation in the base class** and **must be implemented by every derived class.**

### ⭐ Notebook Definition

> **Pure Virtual Function:** A virtual function declared using `= 0` that forces derived classes to provide their own implementation.

---

Example:

```cpp
class Shape
{
public:

    virtual void draw() = 0;
};
```

Notice:

```cpp
= 0
```

This makes `draw()` a **Pure Virtual Function**.

---

# 3. Syntax (`= 0`)

General syntax:

```cpp
virtual return_type functionName(parameters) = 0;
```

Example:

```cpp
virtual void display() = 0;
```

The `= 0` does **not** mean the function returns zero.

It simply tells the compiler:

> **"This function has no implementation here and must be implemented by derived classes."**

---

# 4. Purpose

Suppose we have a base class:

```text
Animal
```

Every animal makes a sound.

But...

Should the base class decide the sound?

No.

A dog barks.

A cat meows.

A cow moos.

So instead of writing:

```cpp
sound()
```

inside the base class,

we simply declare:

```cpp
virtual void sound() = 0;
```

and let each derived class define its own behavior.

---

# Internal Working

Conceptually,

```text
Base Class

↓

Pure Virtual Function

↓

Derived Class

↓

Own Implementation
```

The base class only defines **what** should exist.

The derived class defines **how** it works.

---

# 5. Why Use Pure Virtual Functions?

### 1. Enforce a Common Interface

Every derived class must provide the required function.

Example:

```text
Shape

↓

draw()

↓

Circle

Rectangle

Triangle
```

Every shape knows how to draw itself.

---

### 2. Achieve Abstraction

The base class defines only the required functionality.

Implementation remains hidden inside derived classes.

---

### 3. Prevent Incomplete Classes

Without pure virtual functions,

a programmer might forget to implement an important function.

The compiler catches this mistake.

---

### 4. Improve Code Consistency

Every derived class follows the same interface.

This makes programs easier to understand and maintain.

---

# 6. Enforcing Implementation in Derived Classes

Suppose:

```cpp
class Animal
{
public:

    virtual void sound() = 0;
};
```

Now,

```cpp
class Dog : public Animal
{
};
```

This is **not complete** because `sound()` is missing.

The derived class must implement:

```cpp
void sound()
{
    cout << "Bark";
}
```

Only then is the class complete.

---

# Real-world Examples

## Shape

```text
Shape

↓

draw()

↓

Circle

Rectangle

Triangle
```

Each shape draws itself differently.

---

## Vehicle

```text
Vehicle

↓

start()

↓

Car

Bike

Truck
```

Every vehicle starts differently.

---

## Payment System

```text
Payment

↓

pay()

↓

Credit Card

UPI

Net Banking
```

Each payment method has its own implementation.

---

## Employee

```text
Employee

↓

calculateSalary()

↓

Manager

Developer

Intern
```

Salary calculation differs for every role.

---

# Common Misconceptions

### ❌ Misconception 1

> `= 0` means the function returns zero.

Incorrect.

It means the function is **pure virtual**.

---

### ❌ Misconception 2

> Pure virtual functions have an implementation inside the base class.

Incorrect.

They are intended to be implemented by derived classes.

(We'll later see that C++ technically allows giving a definition outside the class in some situations, but that doesn't change the fact that the function remains pure virtual.)

---

### ❌ Misconception 3

> Pure virtual functions can exist without inheritance.

Incorrect.

Their purpose is to be overridden by derived classes.

Without inheritance, they have no practical use.

---

# Interview Questions

### Q1

What is a Pure Virtual Function?

**Answer**

A pure virtual function is a virtual function declared using `= 0` that has no implementation in the base class and forces derived classes to implement it.

---

### Q2

Why do we declare a function as `= 0`?

**Answer**

To indicate that the base class provides only the function declaration and requires every derived class to provide its own implementation.

---

### Q3

Can a Pure Virtual Function have a definition?

**Answer**

Yes.

Although a pure virtual function is declared using `= 0`, C++ still allows it to have a definition outside the class. However, it remains a pure virtual function and the class is still considered abstract.

---

## 📌 One Important Clarification

A **virtual function** and a **pure virtual function** are not the same.

```text
Virtual Function

↓

May have an implementation

↓

Derived class may override it

--------------------------------

Pure Virtual Function

↓

Declared using = 0

↓

Derived class must implement it
```

We'll revisit this topic after learning **Inheritance (Day 4)** and **Polymorphism (Day 5)**. At that point, you'll implement pure virtual functions yourself and see why they are one of the strongest tools for achieving abstraction in C++.