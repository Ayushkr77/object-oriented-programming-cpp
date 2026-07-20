# Module 5: Interface vs Implementation

## 🎯 Objective

By the end of this module, you should understand:

* What an interface is.
* What an implementation is.
* The difference between "What" and "How".
* Why separating interface and implementation is important.
* Real-world examples of this separation.
* How to design clean APIs.

---

# 1. What is an Interface?

## Definition

An **Interface** is the **set of publicly available functions through which users interact with an object.**

It defines **what** an object can do.

The interface does **not** reveal how the task is performed internally.

### ⭐ Notebook Definition

> **Interface:** The publicly accessible functions of a class that define what operations an object can perform.

---

Example:

```cpp
class BankAccount
{
public:
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance();
};
```

The user only sees:

* `deposit()`
* `withdraw()`
* `getBalance()`

This is the **interface**.

---

# 2. What is an Implementation?

## Definition

The **Implementation** is the actual code that performs the work behind the interface.

It defines **how** the object performs its operations.

### ⭐ Notebook Definition

> **Implementation:** The internal logic that performs the operations exposed through the interface.

---

Example:

```cpp
void BankAccount::deposit(double amount)
{
    if(amount > 0)
        balance += amount;
}
```

The user doesn't need to know this logic.

They simply call:

```cpp
account.deposit(5000);
```

---

# 3. Separating "What" from "How"

One of the biggest goals of OOP is separating:

```text
What the user wants to do

from

How the object performs it.
```

Conceptually:

```text
User

↓

deposit()

↓

Internal Logic

↓

Balance Updated
```

The user only knows:

```cpp
deposit();
```

They don't need to know:

* Validation
* Calculations
* Database updates
* Logging
* Error handling

---

# 4. Advantages of Separation

### 1. Easier to Use

Users only learn the interface.

They don't need to understand the implementation.

---

### 2. Easier Maintenance

The implementation can change without affecting user code.

Example:

Today:

```cpp
balance += amount;
```

Tomorrow:

```cpp
Update Database

↓

Log Transaction

↓

Update Balance
```

The user still writes:

```cpp
deposit(5000);
```

No changes are required.

---

### 3. Better Security

Sensitive implementation details remain hidden.

Users cannot directly modify internal data.

---

### 4. Better Flexibility

Developers can improve the implementation without changing the interface.

---

### 5. Cleaner Code

Programs become easier to understand because users focus only on the available functionality.

---

# Internal Working

Suppose the user writes:

```cpp
account.withdraw(1000);
```

Conceptually,

```text
User

↓

withdraw()

↓

Check Balance

↓

Validate Amount

↓

Update Balance

↓

Store Transaction

↓

Return Result
```

Only the first step is visible.

Everything else is implementation.

---

# 5. Real-world Examples

## ATM

```text
Interface

Withdraw
Deposit
Check Balance

--------------------------

Implementation

PIN Verification
Database Access
Transaction Processing
Cash Dispensing
```

---

## Car

```text
Interface

Start
Accelerate
Brake

--------------------------

Implementation

Engine
Fuel Injection
Gearbox
Cooling System
```

---

## Mobile Phone

```text
Interface

Call
Camera
Internet
Music

--------------------------

Implementation

Operating System
Memory Management
CPU Scheduling
Battery Optimization
```

---

## TV Remote

```text
Interface

Power
Volume
Channel

--------------------------

Implementation

Signal Transmission
Hardware Communication
Display Driver
```

---

# 6. Designing Clean APIs

An API (Application Programming Interface) is simply a well-designed interface that exposes only the necessary functionality.

Good APIs:

* Simple
* Easy to understand
* Hide unnecessary complexity
* Prevent misuse

Example:

```cpp
account.deposit(5000);

account.withdraw(1000);

account.getBalance();
```

Better than exposing:

```cpp
account.balance = 5000;

account.transactionCount++;

account.databaseConnection...
```

The interface should expose **only what the user needs**.

---

# Common Misconceptions

### ❌ Misconception 1

> Interface means only abstract classes.

Incorrect.

Even a normal class with public member functions provides an interface.

---

### ❌ Misconception 2

> Interface and implementation should always be in different files.

Incorrect.

They can be in the same file or different files.

The important idea is the **conceptual separation**, not the physical location.

---

### ❌ Misconception 3

> Users should know how functions work internally.

Incorrect.

Users should only know how to use the interface.

The implementation can change without affecting them.

---

# Interview Questions

### Q1

What is the difference between Interface and Implementation?

**Answer**

The interface defines **what** operations are available to the user, while the implementation defines **how** those operations are performed internally.

---

### Q2

Why should implementation details be hidden?

**Answer**

Hiding implementation reduces complexity, improves security, simplifies maintenance, and allows internal changes without affecting user code.

---

## 📌 One Important Clarification

**Interface**, **Abstraction**, and **Encapsulation** are closely related but focus on different aspects of object-oriented design.

```text
Interface

↓

What operations are available?

----------------------------

Abstraction

↓

Hide unnecessary implementation details.

----------------------------

Encapsulation

↓

Protect data and control access.
```

A simple way to remember them is:

* **Interface** → **What can I do?**
* **Abstraction** → **I don't need to know how it works.**
* **Encapsulation** → **I shouldn't access or modify internal data directly.**

Together, they help build classes that are easy to use, safe to modify, and simple to maintain.