Excellent. This is one of the **most important OOP modules** because it introduces the concept of **data hiding**, which is the foundation of **Encapsulation** (one of the four pillars of OOP).

Almost every C++ interview asks questions related to access specifiers.

---

# Module 12: Access Specifiers

## 🎯 Deliverable

By the end of this module, you should know:

* What are access specifiers?
* What are `public`, `private`, and `protected`?
* What is visibility and accessibility?
* Default access in `class` and `struct`.
* When to use each access specifier.

---

# 1. What are Access Specifiers?

## Definition

> **Access specifiers are keywords that control the visibility and accessibility of class members (variables and functions).**

They determine:

* Who can access a member?
* From where can it be accessed?

The three access specifiers in C++ are:

* `public`
* `private`
* `protected`

---

# Why Do We Need Access Specifiers?

Imagine a bank account.

It has:

```text
Account Number
Balance
PIN
```

Should anyone be able to do this?

```cpp
account.balance = 1000000;
```

❌ No.

Only authorized functions like:

```text
deposit()

withdraw()

checkBalance()
```

should modify the balance.

Access specifiers help us protect important data.

---

# 2. `public`

## Definition

> Members declared as `public` can be accessed from **anywhere** in the program (provided the object is accessible).

---

## Example

```cpp
class Student
{
public:
    string name;
};
```

Create an object:

```cpp
Student s1;

s1.name = "Ayush";
```

This works because `name` is public.

---

## Visualization

```text
Anywhere

↓

Object

↓

Public Members

✓ Accessible
```

---

## When to Use

Use `public` for:

* Functions that users should call.
* Data that is intentionally public (rare in well-designed classes).

---

# 3. `private`

## Definition

> Members declared as `private` can be accessed **only from within the same class**.

---

## Example

```cpp
class Student
{
private:
    int marks;
};
```

Now,

```cpp
Student s1;

s1.marks = 95;
```

❌ Error.

Because `marks` is private.

---

But inside the class:

```cpp
class Student
{
private:
    int marks;

public:
    void setMarks(int m)
    {
        marks = m;
    }
};
```

This works.

The member function belongs to the same class.

---

## Visualization

```text
Outside Class

↓

Private Member

❌ Not Accessible

---------------------

Inside Class

↓

Private Member

✓ Accessible
```

---

## Why Use Private?

To protect data from unauthorized access or accidental modification.

This is called **Data Hiding**.

---

# 4. `protected` (Basic Introduction)

We'll study this properly with inheritance.

For now, remember:

> `protected` is similar to `private`, but it also allows **derived (child) classes** to access those members.

---

## Example

```cpp
class Student
{
protected:
    int rollNo;
};
```

Outside the class:

```cpp
Student s1;

s1.rollNo = 10;
```

❌ Error.

A derived class, however, can access `rollNo`.

We'll revisit this in the inheritance module.

---

# 5. Visibility

## What is Visibility?

Visibility answers:

> **Can this member be seen from here?**

Example:

```cpp
class Student
{
public:
    string name;

private:
    int marks;
};
```

Outside the class:

```cpp
Student s1;
```

Visible:

```text
name
```

Not visible:

```text
marks
```

---

# 6. Accessibility

Accessibility answers:

> **Even if I know the member exists, am I allowed to use it?**

Example:

```cpp
class Student
{
private:
    int marks;
};
```

You know `marks` exists.

But can you access it directly?

```cpp
s1.marks = 100;
```

❌ No.

It is not accessible.

---

# Easy Difference

| Visibility    | Accessibility |
| ------------- | -------------- |
| Can I see it? | Can I use it? |

In many beginner discussions, these terms are used interchangeably, but this distinction helps build intuition.

---

# 7. Default Access in `class`

Suppose:

```cpp
class Student
{
    int age;
};
```

No access specifier is written.

What is `age`?

Answer:

```cpp
private
```

By default,

**members of a class are private.**

---

# 8. Default Access in `struct`

Suppose:

```cpp
struct Student
{
    int age;
};
```

No access specifier.

What is `age`?

Answer:

```cpp
public
```

By default,

**members of a struct are public.**

---

# Easy Trick

```text
class

↓

Default = private

-------------------

struct

↓

Default = public
```

This is a very common interview question.

---

# 9. When to Use Each

## Use `public`

For:

* Functions users should call.
* Interfaces to the class.

Example:

```text
deposit()

withdraw()

display()
```

---

## Use `private`

For:

* Sensitive data.
* Internal implementation details.

Example:

```text
Balance

Password

PIN

Salary
```

---

## Use `protected`

For:

* Data or functions that should be available to derived classes but hidden from the outside world.

You'll understand this better during inheritance.

---

# Comparison Table

| Access Specifier | Inside Class | Outside Class | Derived Class |
| ----------------- | -------------- | --------------- | --------------- |
| `public`         | ✅            | ✅             | ✅             |
| `private`        | ✅            | ❌             | ❌             |
| `protected`      | ✅            | ❌             | ✅             |

> **Note:** The "Derived Class" column becomes fully meaningful when you study inheritance.

---

# Real-Life Example

Think of a mobile phone.

### Public

```text
Power Button

Volume Button

Camera
```

Anyone can use these.

---

### Private

```text
Processor Registers

Encryption Keys

Internal Memory Management
```

Users should never access these directly.

---

### Protected

Think of this as features meant for the **manufacturer or specialized system components**, not ordinary users.

---

# Common Mistakes

### ❌ Thinking private means "cannot be accessed."

Wrong.

Private members **can** be accessed by **member functions of the same class**.

---

### ❌ Thinking protected is the same as public.

Wrong.

Protected members are **not accessible from outside the class**.

---

### ❌ Forgetting the default access.

Remember:

* `class` → private
* `struct` → public

---

# Interview Questions

### 1. What are access specifiers?

> Access specifiers are keywords that control the visibility and accessibility of class members.

---

### 2. What is the default access specifier in a class?

> `private`

---

### 3. What is the default access specifier in a struct?

> `public`

---

### 4. Why do we use private members?

> To protect data from unauthorized access and support data hiding and encapsulation.

---

### 5. Difference between public and private?

> Public members can be accessed from anywhere through an object, whereas private members can only be accessed from within the class (or by friends, which you'll learn later).

---

## 💡 One Important Clarification

Many beginners think:

> **"Everything should be private because it's more secure."**

That's not good design.

A well-designed class usually follows this idea:

* Keep **data** (`balance`, `marks`, `salary`, etc.) **private**.
* Expose **operations** (`deposit()`, `withdraw()`, `display()`, etc.) as **public**.

For example, in a bank account:

```cpp
class BankAccount
{
private:
    double balance;

public:
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance();
};
```

The user **cannot directly modify** `balance`, but they can interact with it through controlled public functions.

This is one of the main ideas behind **Encapsulation**, which you'll study next.

---

## ❓ Common Doubts

### Doubt 1: Are access specifiers only for variables?

**Answer:** No. Access specifiers apply to all class members, i.e., both data members (variables) and member functions (methods).

---

### Doubt 2: Why make functions private?

**Answer:** Private functions are internal helper functions that should only be used by the class itself, not by code outside the class.

---

### Doubt 3: If a public function accesses a private variable, isn't the private variable still accessible?

**Answer:** Yes, but it's controlled access, not direct access. The public function decides how, when, and whether the private data can be accessed or modified.

---

### Doubt 4: Why not make the variable public directly?

**Answer:** A public variable can be changed to any value, even invalid ones. A private variable ensures all changes go through validation and business rules.

---

## Core OOP Philosophy (Most Important)

`private` does not mean "no access"; it means "no uncontrolled direct access." The object controls its own data through carefully designed public member functions.