# Module 9: Pure Virtual Functions (Revision)

## 🎯 Objective

By the end of this module, you should understand:

* What a Pure Virtual Function is.
* Why we use `= 0`.
* How Pure Virtual Functions enforce implementation.
* Relationship with Runtime Polymorphism.
* Relationship with Abstract Classes.
* Whether a Pure Virtual Function can have a body.

---

# 1. What is a Pure Virtual Function?

## Definition

A **Pure Virtual Function** is a virtual function that has **no implementation in the Base Class** and **must be implemented by every concrete Derived Class**.

It is declared by assigning **`= 0`** in its declaration.

### ⭐ Notebook Definition

> **Pure Virtual Function:** A virtual function declared using `= 0` that has no implementation requirement in the base interface and forces derived classes to provide their own implementation.

---

# 2. Why do we need Pure Virtual Functions?

Suppose we have

```text
Animal
```

Every animal makes a sound.

But what should

```text
Animal::sound()
```

actually do?

Should it print

```text
Animal Sound
```

Not really.

Every animal has its own sound.

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

Instead of giving a meaningless default implementation,

we force every derived class to define its own.

That is exactly why Pure Virtual Functions exist.

---

# 3. Syntax (`= 0`)

General syntax

```cpp
virtual returnType functionName(parameters) = 0;
```

Example

```cpp
class Animal
{
public:

    virtual void sound() = 0;
};
```

Notice

```cpp
= 0;
```

This makes

```cpp
sound()
```

a **Pure Virtual Function**.

---

# 4. Why do we use `= 0`?

Many beginners think

```cpp
= 0
```

means

```text
Function returns zero
```

❌ Incorrect.

It simply tells the compiler:

> **This function is intentionally left without a usable implementation in the class interface and must be overridden by concrete derived classes.**

Conceptually,

```text
Animal

↓

sound()

↓

No Implementation

↓

Derived Class Must Implement
```

---

# 5. Enforcing Implementation

Suppose

```cpp
class Animal
{
public:

    virtual void sound() = 0;
};
```

Now

```cpp
class Dog : public Animal
{
};
```

Compiler Error.

Why?

Because

```cpp
Dog
```

has not implemented

```cpp
sound()
```

Now

```cpp
class Dog : public Animal
{
public:

    void sound() override
    {
        cout << "Bark";
    }
};
```

Now

```text
Dog
```

becomes a concrete class,

and objects can be created.

---

# 6. Relationship with Runtime Polymorphism

Pure Virtual Functions are still

```text
Virtual Functions
```

Therefore,

they fully participate in Runtime Polymorphism.

Example

```cpp
Animal* animal = new Dog();

animal->sound();
```

Compilation

↓

Pointer Type

```text
Animal*
```

Runtime

↓

Actual Object

```text
Dog
```

↓

Execute

```text
Dog::sound()
```

Runtime Polymorphism still works exactly as with normal virtual functions.

The only difference is that the Base Class provides **no concrete implementation** for that function.

---

# 7. Relationship with Abstract Classes

This is the most important relationship.

Whenever a class contains

**at least one Pure Virtual Function**

it automatically becomes an

```text
Abstract Class
```

Example

```cpp
class Animal
{
public:

    virtual void sound() = 0;
};
```

Now

```cpp
Animal animal;
```

❌ Compile Error

Objects of an Abstract Class cannot be created.

Only pointers and references are allowed.

Example

```cpp
Animal* animal;
```

✔ Valid

---

# 8. Internal Working

Suppose

```cpp
Animal* animal = new Dog();

animal->sound();
```

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

Notice

Even though the Base Class function is Pure Virtual,

Dynamic Dispatch still works exactly the same way.

The runtime simply finds the Derived Class implementation.

---

# Runtime Flow

```text
Pure Virtual Function Call

↓

Base Pointer

↓

Derived Object

↓

VPtr

↓

VTable

↓

Derived Implementation

↓

Execution
```

---

# 9. Pure Virtual Function vs Virtual Function

| Virtual Function                                                    | Pure Virtual Function                                             |
| -----------------------------------------------------------------------| ---------------------------------------------------------------------|
| May have implementation                                             | Declared with `= 0`                                               |
| Derived class may override                                          | Derived class should provide an implementation to become concrete |
| Base class can be instantiated (if no pure virtual functions exist) | Makes the class Abstract                                          |
| Supports Runtime Polymorphism                                       | Supports Runtime Polymorphism                                     |

---

# 10. Real-World Example

Suppose

```text
Payment
```

Every payment method processes payment differently.

Instead of writing

```text
Process Payment
```

inside

```text
Payment
```

we declare

```cpp
processPayment() = 0;
```

Now

```text
CreditCard

↓

Implements processPayment()
```

```text
UPI

↓

Implements processPayment()
```

```text
NetBanking

↓

Implements processPayment()
```

Every payment method is forced to define its own behavior.

---

Another example

```text
Shape

↓

draw() = 0;
```

Derived classes

```text
Circle

↓

draw()
```

```text
Rectangle

↓

draw()
```

```text
Triangle

↓

draw()
```

The Base Class only defines the interface.

Derived classes provide the implementation.

---

# 11. Advantages

### 1. Forces Implementation

Every concrete Derived Class must provide its own implementation.

---

### 2. Supports Runtime Polymorphism

Pure Virtual Functions participate fully in Dynamic Dispatch.

---

### 3. Defines Common Interfaces

The Base Class specifies **what** operations exist,

not **how** they are performed.

---

### 4. Better Design

Prevents meaningless default implementations.

---

### 5. Encourages Extensibility

New Derived Classes simply implement the required interface.

---

# 12. Limitations

* Objects of an Abstract Class cannot be created.
* Every concrete Derived Class must implement all inherited Pure Virtual Functions.
* Slight runtime overhead due to Virtual Function mechanism.

---

# 13. Common Misconceptions

### ❌ Misconception 1

> `= 0` means the function returns zero.

Incorrect.

It marks the function as **Pure Virtual**.

---

### ❌ Misconception 2

> Pure Virtual Functions cannot participate in Runtime Polymorphism.

Incorrect.

They are Virtual Functions,

so they fully support Runtime Polymorphism.

---

### ❌ Misconception 3

> Every Derived Class must immediately implement every Pure Virtual Function.

Partially Incorrect.

If a Derived Class does not implement it,

that Derived Class simply becomes **Abstract** as well.

Only a **concrete** class must implement all inherited Pure Virtual Functions before its objects can be created.

---

### ❌ Misconception 4

> A Pure Virtual Function can never have a body.

This is a common interview trick.

A Pure Virtual Function **can** have a body, but it **must still be declared with `= 0`** inside the class.

Example

```cpp
class Animal
{
public:
    virtual void sound() = 0;
};

void Animal::sound()
{
    cout << "Common implementation";
}
```

Even with this definition,

`Animal` remains an **Abstract Class** because the declaration contains `= 0`.

This technique is uncommon but valid.

---

# 14. Interview Questions

### Q1

What is a Pure Virtual Function?

**Answer**

A Pure Virtual Function is a virtual function declared using `= 0` that forces Derived Classes to provide their own implementation and makes the Base Class abstract.

---

### Q2

Why do we use `= 0`?

**Answer**

`= 0` marks a function as Pure Virtual, indicating that the Base Class is only defining the interface and that concrete Derived Classes must provide an implementation.

---

### Q3

Can a Pure Virtual Function have a body?

**Answer**

Yes.

A Pure Virtual Function can have a definition outside the class, but the function must still be declared with `= 0`, and the class remains abstract.

---

### Q4

Does a Pure Virtual Function support Runtime Polymorphism?

**Answer**

Yes.

It is still a Virtual Function and therefore participates fully in Runtime Polymorphism.

---

### Q5

What happens if a Derived Class does not implement a Pure Virtual Function?

**Answer**

The Derived Class also becomes an Abstract Class, and its objects cannot be created.

---

# 15. Key Takeaways

* A **Pure Virtual Function** is declared using **`= 0`**.
* It defines an interface and forces concrete Derived Classes to provide an implementation.
* Any class containing at least one Pure Virtual Function becomes an **Abstract Class**.
* Pure Virtual Functions fully support **Runtime Polymorphism**.
* A Pure Virtual Function **can have a body** outside the class, but the class still remains abstract.
* If a Derived Class does not implement all inherited Pure Virtual Functions, it also becomes an **Abstract Class**.

---

# Important Connection with Previous Module ⭐

In **Module 8**, we learned how **Dynamic Dispatch** selects the correct overridden function at runtime.

A **Pure Virtual Function** uses the **same runtime mechanism**.

The only difference is that the Base Class **does not provide a usable implementation**, making it an interface-like contract for Derived Classes.

---

## 📌 One Important Clarification

Many students confuse these three concepts:

| Concept                   | Meaning                                                                       |
| ----------------------------| ----------------------------------------------------------------------------------|
| **Virtual Function**      | May have a default implementation in the Base Class.                          |
| **Pure Virtual Function** | Declared using `= 0`; intended to be implemented by concrete Derived Classes. |
| **Abstract Class**        | Any class containing at least one Pure Virtual Function.                      |

These are related, but they are **not the same thing**.