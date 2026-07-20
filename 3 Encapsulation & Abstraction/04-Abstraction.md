# Module 4: Abstraction

## 🎯 Objective

By the end of this module, you should understand:

* What abstraction is.
* Why abstraction is needed.
* How abstraction hides implementation details.
* How only essential features are exposed to users.
* Real-world examples of abstraction.
* How abstraction is achieved in C++.

---

# 1. What is Abstraction?

## Definition

**Abstraction** is the process of **hiding unnecessary implementation details and exposing only the essential features required by the user.**

***A class is abstract if it has at least one pure virtual function that has not been implemented.***

The user knows **what** an object does, but not **how** it does it.

### ⭐ Notebook Definition

> **Abstraction:** The process of hiding implementation details while exposing only the essential functionality to the user.

---

# 2. Why do We Need Abstraction?

Imagine driving a car.

You use:

* Steering
* Brake
* Accelerator

You don't need to know:

* How fuel is injected
* How combustion happens
* How the gearbox works internally

The complexity is hidden.

Only the required functionality is exposed.

Similarly, in programming,

users of a class should focus on **what the class can do**, not **how it performs the task internally**.

---

# 3. Hiding Complexity

Without abstraction,

users would need to understand every internal detail.

With abstraction,

they simply use the provided interface.

Example:

```cpp id="cbjlwm"
class BankAccount
{
public:

    void deposit(double amount);

    void withdraw(double amount);

    double getBalance();
};
```

The user calls:

```cpp id="8jop2k"
account.deposit(5000);
```

The user does **not** know:

* How the balance is updated.
* How validation is performed.
* How transactions are stored.

All these details remain hidden.

---

# 4. Showing Only Essential Features

Abstraction exposes only the operations that users actually need.

Example:

```text id="a31xzz"
Mobile Phone

Visible

Call()
Camera()
Music()
Settings()

Hidden

CPU Scheduling
Memory Management
Battery Optimization
```

Users interact only with useful features.

The internal implementation remains hidden.

---

# Internal Working

Suppose we have:

```cpp id="jkqob0"
account.withdraw(1000);
```

Conceptually,

```text id="3bd3vz"
User

↓

withdraw()

↓

Internal Logic

↓

Balance Updated
```

The user sees only the function call.

The implementation remains hidden inside the class.

---

# 5. Real-world Examples

## ATM

```text id="s6l5qk"
Visible

Withdraw
Deposit
Check Balance

Hidden

PIN Verification
Database Access
Transaction Processing
```

---

## Car

```text id="ic60sq"
Visible

Start
Accelerate
Brake

Hidden

Engine
Gearbox
Fuel Injection
Cooling System
```

---

## Television

```text id="ab6xpa"
Visible

Power
Volume
Channel

Hidden

Circuit Design
Signal Processing
Display Driver
```

---

## Mobile Phone

```text id="scik56"
Visible

Call
Camera
Internet
Messages

Hidden

Operating System
Memory Allocation
CPU Scheduling
Battery Management
```

---

# 6. Abstraction in C++

Abstraction can be achieved using:

* Classes
* Public Member Functions
* Abstract Classes (later)
* Pure Virtual Functions (later)

At this stage, we mainly achieve abstraction using **classes**.

Example:

```cpp id="xv7j0o"
class Car
{
public:

    void start();

    void stop();
};
```

The user simply writes:

```cpp id="5vt4u8"
car.start();
```

without knowing how `start()` is implemented internally.

---

# Common Misconceptions

### ❌ Misconception 1

> Abstraction and Encapsulation are the same.

Incorrect.

Encapsulation bundles data and functions together while controlling access.

Abstraction hides unnecessary implementation details and exposes only essential functionality.

---

### ❌ Misconception 2

> Abstraction hides all information.

Incorrect.

Only unnecessary implementation details are hidden.

Essential functionality remains accessible.

---

### ❌ Misconception 3

> Abstraction is achieved only through abstract classes.

Incorrect.

Even a simple class with well-designed public functions provides abstraction by hiding internal implementation.

---

# Interview Questions

### Q1

What is Abstraction?

**Answer**

Abstraction is the process of hiding implementation details while exposing only the essential functionality required by the user.

---

### Q2

Why is Abstraction important in software development?

**Answer**

It reduces complexity, improves usability, hides implementation details, and allows developers to use objects without understanding their internal working.

---

### Q3

Give real-world examples of Abstraction.

**Answer**

Examples include:

* ATM
* Car
* Mobile Phone
* Television
* Washing Machine

In each case, users interact only with the essential controls while the internal implementation remains hidden.

---

## 📌 One Important Clarification

Although **Encapsulation** and **Abstraction** are closely related, they answer different questions.

```text id="u4r2ny"
Encapsulation

↓

How do we protect the data?

----------------------------

Abstraction

↓

What functionality should the user see?
```

A simple way to remember the difference is:

```text id="u7cfvo"
Encapsulation

↓

Protects Data

----------------------------

Abstraction

↓

Hides Complexity
```

In practice, **encapsulation often helps implement abstraction**.

For example, a class keeps its data private (**encapsulation**) and exposes only meaningful public functions like `deposit()` or `withdraw()` (**abstraction**). Together, they make software safer, simpler, and easier to use.