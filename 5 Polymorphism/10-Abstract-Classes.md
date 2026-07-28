# Module 10: Abstract Classes (Revision)

## 🎯 Objective

By the end of this module, you should understand:

* What an Abstract Class is.
* Why we need Abstract Classes.
* Restrictions of Abstract Classes.
* Designing Interfaces using Abstract Classes.
* Practical use cases.
* Relationship with Pure Virtual Functions and Runtime Polymorphism.

---

# 1. What is an Abstract Class?

## Definition

An **Abstract Class** is a class that **cannot be instantiated (objects cannot be created)** because it contains **at least one Pure Virtual Function**.

It serves as a **base class** that defines a common interface for its derived classes.

### ⭐ Notebook Definition

> **Abstract Class:** A class containing at least one Pure Virtual Function. Objects of an Abstract Class cannot be created, and it is intended to be inherited.

---

# 2. Why do we need Abstract Classes?

Suppose we have

```text
Animal
```

Can a generic

```text
Animal
```

actually make a sound?

Not really.

Only specific animals can.

```text
Dog

↓

Bark
```

```text
Cat

↓

Meow
```

```text
Cow

↓

Moo
```

Instead of allowing

```cpp
Animal animal;
```

we force programmers to create

```cpp
Dog dog;

Cat cat;

Cow cow;
```

The Base Class simply defines

**what operations exist**,

while the Derived Classes decide

**how those operations are performed**.

---

# 3. Relationship with Pure Virtual Functions

Suppose

```cpp
class Animal
{
public:

    virtual void sound() = 0;
};
```

Because

```cpp
sound()
```

is Pure Virtual,

```text
Animal
```

automatically becomes

```text
Abstract Class
```

Therefore,

```cpp
Animal animal;
```

❌ Compile Error

But

```cpp
Animal* animal;
```

✔ Valid

The pointer can refer to

```text
Dog

Cat

Cow
```

---

# 4. Restrictions of Abstract Classes

Abstract Classes have several important restrictions.

---

## Restriction 1

Objects cannot be created.

```cpp
Animal animal;
```

❌ Invalid

---

## Restriction 2

Pointers are allowed.

```cpp
Animal* animal;
```

✔ Valid

---

## Restriction 3

References are allowed.

```cpp
Animal& animal = dog;
```

✔ Valid

---

## Restriction 4

Derived Classes must implement all inherited Pure Virtual Functions before they become concrete.

Otherwise,

they also remain Abstract.

---

# 5. Designing Interfaces

One of the biggest purposes of Abstract Classes is to design **interfaces**.

Suppose we are building a payment application.

Instead of writing

```text
Payment

↓

Credit Card Logic
```

inside the Base Class,

we define only

```cpp
processPayment() = 0;
```

Then

```text
Payment

↓

CreditCard

↓

processPayment()
```

```text
Payment

↓

UPI

↓

processPayment()
```

```text
Payment

↓

NetBanking

↓

processPayment()
```

The Base Class defines

**what every payment method must do**.

Derived Classes define

**how they do it**.

---

# 6. Runtime Polymorphism with Abstract Classes

Suppose

```cpp
Animal* animal = new Dog();

animal->sound();
```

Compilation

↓

Compiler knows

```text
Animal*
```

Execution

↓

Object is

```text
Dog
```

↓

Dynamic Dispatch

↓

```text
Dog::sound()
```

Notice

The Base Class object never exists.

Only the interface exists.

Runtime Polymorphism still works exactly the same.

---

# 7. Internal Working

Conceptually,

```text
Animal Pointer

↓

Dog Object

↓

Hidden VPtr

↓

Dog VTable

↓

Dog::sound()

↓

Execute
```

Even though

```text
Animal
```

is Abstract,

its interface is still used through pointers and references.

---

# Interface Flow

```text
Abstract Class

↓

Common Interface

↓

Derived Class

↓

Implementation

↓

Runtime Polymorphism
```

---

# 8. Practical Use Cases

### Example 1 — Payment System

```text
Payment

↓

processPayment()
```

Derived Classes

```text
Credit Card
```

```text
UPI
```

```text
Net Banking
```

---

### Example 2 — Shape

```text
Shape

↓

draw()
```

Derived Classes

```text
Circle
```

```text
Rectangle
```

```text
Triangle
```

---

### Example 3 — Vehicle

```text
Vehicle

↓

start()
```

Derived Classes

```text
Car
```

```text
Bike
```

```text
Bus
```

Each derived class provides its own implementation.

---

# 9. Abstract Class vs Concrete Class

| Abstract Class                              | Concrete Class                                  |
| -----------------------------------------------| ---------------------------------------------------|
| Cannot create objects                       | Objects can be created                          |
| Contains at least one Pure Virtual Function | Implements all inherited Pure Virtual Functions |
| Defines interface                           | Provides implementation                         |
| Intended for inheritance                    | Intended for object creation                    |

---

# 10. Abstract Class vs Interface

> **Important Note:** C++ does not have a separate `interface` keyword like Java or C#.

An Abstract Class with only Pure Virtual Functions is commonly used as an interface.

| Abstract Class                      | Interface (C++ Style)                     |
| ---------------------------------------| ---------------------------------------------|
| May contain data members            | Usually contains no data members          |
| May contain normal member functions | Usually only Pure Virtual Functions       |
| May contain constructors            | Usually minimal or protected constructors |
| Can provide partial implementation  | Only defines required operations          |

---

# 11. Advantages

### 1. Defines Common Interfaces

All Derived Classes follow the same contract.

---

### 2. Prevents Invalid Objects

Generic Base Class objects cannot be created.

---

### 3. Supports Runtime Polymorphism

Works naturally with Base Class pointers and references.

---

### 4. Encourages Better Design

Separates

```text
What to do
```

from

```text
How to do it
```

---

### 5. Improves Extensibility

New Derived Classes can easily be added.

---

# 12. Limitations

* Objects cannot be created.
* Every concrete Derived Class must implement all inherited Pure Virtual Functions.
* Slight runtime overhead because of Virtual Functions.
* More complex than ordinary classes.

---

# 13. Common Misconceptions

### ❌ Misconception 1

> An Abstract Class cannot contain normal functions.

Incorrect.

It can contain normal member functions.

Example

```cpp
void eat()
{
    cout << "Eating";
}
```

---

### ❌ Misconception 2

> An Abstract Class cannot have data members.

Incorrect.

It can contain data members.

Example

```cpp
protected:

string name;
```

---

### ❌ Misconception 3

> An Abstract Class cannot have constructors.

Incorrect.

Abstract Classes **can** have constructors.

Although objects of the Abstract Class cannot be created directly,

its constructor executes whenever a Derived Class object is created.

Example

```cpp
class Animal
{
public:

    Animal()
    {
        cout << "Animal Constructor";
    }

    virtual void sound() = 0;
};
```

When

```cpp
Dog dog;
```

is created,

the

```text
Animal Constructor
```

runs first,

followed by

```text
Dog Constructor
```

---

### ❌ Misconception 4

> Every Abstract Class contains only Pure Virtual Functions.

Incorrect.

An Abstract Class may contain:

* Normal member functions
* Virtual functions
* Pure Virtual Functions
* Constructors
* Destructors
* Data members

The only requirement is that it contains **at least one Pure Virtual Function**.

---

# 14. Interview Questions

### Q1

What is an Abstract Class?

**Answer**

An Abstract Class is a class containing at least one Pure Virtual Function. Objects of an Abstract Class cannot be created, and it is intended to be used as a base class.

---

### Q2

Why do we need Abstract Classes?

**Answer**

They define common interfaces, enforce implementation in derived classes, prevent meaningless base-class objects, and support Runtime Polymorphism.

---

### Q3

Can an Abstract Class have constructors?

**Answer**

Yes.

Abstract Classes can have constructors. Their constructors execute whenever a Derived Class object is created.

---

### Q4

Can an Abstract Class contain normal member functions?

**Answer**

Yes.

An Abstract Class can contain normal functions, virtual functions, data members, constructors, destructors, and Pure Virtual Functions.

---

### Q5

Can we create an object of an Abstract Class?

**Answer**

No.

Objects of an Abstract Class cannot be created because it contains at least one Pure Virtual Function.

---

# 15. Key Takeaways

* An **Abstract Class** contains at least one **Pure Virtual Function**.
* Objects of an Abstract Class cannot be created.
* Abstract Classes define **interfaces (contracts)** for Derived Classes.
* They fully support **Runtime Polymorphism** through Base Class pointers and references.
* Abstract Classes **can** contain constructors, destructors, data members, normal functions, and virtual functions.
* Only **concrete** classes (those that implement all inherited Pure Virtual Functions) can have objects created.

---

# Important Connection with Previous Module ⭐

In **Module 9**, we learned that a **Pure Virtual Function** forces Derived Classes to provide their own implementation.

As soon as a class contains **at least one** Pure Virtual Function, it automatically becomes an **Abstract Class**.

Therefore:

```text
Pure Virtual Function

↓

Abstract Class
```

The Pure Virtual Function defines the contract, and the Abstract Class groups that contract into a reusable base type.

---

## 📌 One Important Clarification

Many students think an **Abstract Class** is just a class that cannot create objects.

That is only **one consequence**.

Its real purpose is to **define a common interface and shared behavior** for related classes while allowing Runtime Polymorphism through Base Class pointers and references.