> **Note:** Like the previous module, **Abstract Classes** depend on **inheritance**. We'll study their implementation in detail after learning inheritance (Day 4). For now, focus on the concept and purpose.

---

# Module 7: Abstract Classes

## 🎯 Objective

By the end of this module, you should understand:

* What an abstract class is.
* Why abstract classes are needed.
* Their characteristics.
* Why objects of abstract classes cannot be created.
* The responsibilities of derived classes.
* Practical use cases of abstract classes.

---

# 1. What is an Abstract Class?

## Definition

An **Abstract Class** is a class that **cannot be instantiated (cannot create objects)** and is mainly used as a **base class** for other classes.

A class becomes abstract if it contains **at least one pure virtual function**.

### ⭐ Notebook Definition

> **Abstract Class:** A class containing at least one pure virtual function (`= 0`) that cannot be instantiated and serves as a blueprint for derived classes.

---

Example:

```cpp id="h4gr3n"
class Shape
{
public:

    virtual void draw() = 0;
};
```

Since `draw()` is a pure virtual function,

`Shape` becomes an **Abstract Class**.

---

# 2. Why do We Need Abstract Classes?

Suppose we have:

```text id="brgwr0"
Shape
```

Can a generic shape be drawn?

Not really.

Only specific shapes can be drawn.

For example:

* Circle
* Rectangle
* Triangle

Instead of creating a meaningless object like:

```cpp id="t2qnn0"
Shape s;
```

we create:

```text id="ml4kvg"
Circle

Rectangle

Triangle
```

The abstract class simply defines a common blueprint.

---

# 3. Characteristics of an Abstract Class

### 1. Contains at least one Pure Virtual Function

Example:

```cpp id="89g7bl"
virtual void draw() = 0;
```

---

### 2. Cannot Create Objects

The following is illegal:

```cpp id="j6bkbo"
Shape s;      // ❌ Error
```

---

### 3. Can Contain Normal Functions

Abstract classes are **not limited** to pure virtual functions.

Example:

```cpp id="tx1j5y"
class Shape
{
public:

    void display()
    {
        cout << "Shape";
    }

    virtual void draw() = 0;
};
```

---

### 4. Can Contain Data Members

Example:

```cpp id="jh61qd"
protected:

    string color;
```

---

### 5. Used as Base Classes

Their main purpose is to provide a common interface for derived classes.

---

# 4. Object Creation Restriction

Since an abstract class represents a general concept,

objects cannot be created.

Example:

```cpp id="r88smv"
Shape s;      // ❌ Error
```

Instead,

derived classes create objects.

Conceptually,

```text id="l5qmwu"
Abstract Class

↓

Cannot Create Object

↓

Derived Class

↓

Object Created
```

---

# 5. Derived Class Responsibilities

Suppose we have:

```cpp id="mk77m7"
class Shape
{
public:

    virtual void draw() = 0;
};
```

Now,

```cpp id="87oj7t"
class Circle : public Shape
{
};
```

This class is still incomplete.

The derived class must implement:

```cpp id="qdbwub"
void draw()
{
    ...
}
```

Only then can objects of `Circle` be created.

---

# Internal Working

Conceptually,

```text id="56c76m"
Abstract Class

↓

Defines Common Interface

↓

Derived Class

↓

Implements Missing Functions

↓

Objects Created
```

The abstract class defines **what** must exist.

Derived classes define **how** it works.

---

# 6. Practical Use Cases

## Shape

```text id="4g2i7i"
Abstract Class

Shape

↓

Circle

Rectangle

Triangle
```

---

## Vehicle

```text id="g6j2lo"
Vehicle

↓

Car

Bike

Truck
```

---

## Payment

```text id="umjlwm"
Payment

↓

UPI

Credit Card

Net Banking
```

---

## Employee

```text id="kkqu3u"
Employee

↓

Developer

Manager

Intern
```

The abstract class defines common behavior,

while derived classes provide specific implementations.

---

# Common Misconceptions

### ❌ Misconception 1

> Every class with a virtual function is abstract.

Incorrect.

Only classes containing **at least one pure virtual function (`= 0`)** become abstract.

---

### ❌ Misconception 2

> Abstract classes cannot contain implemented functions.

Incorrect.

They can contain:

* Normal functions
* Constructors
* Data members
* Static members

Only the pure virtual function remains unimplemented.

---

### ❌ Misconception 3

> Abstract classes are useless because we cannot create objects.

Incorrect.

Their purpose is **not** object creation.

They provide a common blueprint and enforce a consistent interface for derived classes.

---

# Interview Questions

### Q1

What is an Abstract Class?

**Answer**

An abstract class is a class containing at least one pure virtual function. It cannot be instantiated and serves as a blueprint for derived classes.

---

### Q2

Can we create an object of an Abstract Class?

**Answer**

No.

Objects of abstract classes cannot be created because the class contains at least one pure virtual function that has no implementation.

---

### Q3

Why are Abstract Classes useful?

**Answer**

They provide a common interface, enforce implementation in derived classes, promote abstraction, and improve code consistency and reusability.

---

## 📌 One Important Clarification

Many students confuse **Pure Virtual Functions** and **Abstract Classes**.

The relationship is:

```text id="k5q6hp"
Pure Virtual Function

↓

Makes the Class

↓

Abstract
```

In other words:

* A **Pure Virtual Function** is a **member function** declared using `= 0`.
* An **Abstract Class** is a **class** that contains at least one pure virtual function.

So, the pure virtual function is the **cause**, and the abstract class is the **result**.

We'll implement both together after learning **Inheritance (Day 4)**, where you'll see how derived classes complete the missing functionality and why abstract classes are one of the most powerful tools for designing extensible object-oriented systems.