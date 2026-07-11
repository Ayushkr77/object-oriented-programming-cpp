Excellent. This module is important because it teaches **where variables live, who owns them, and how memory is managed**. Many interview questions revolve around this.

You'll notice that there are **three kinds of variables** in this module:

1. **Member Variables (belong to an object)**
2. **Local Variables (belong to a function)**
3. **Static Variables / Static Data Members (belong to the class)**

Understanding the **owner** of each variable makes everything much easier.

---

# Module 8: Variables inside a Class

## 🎯 Deliverable

By the end of this module, you should know:

* What are member variables?
* What are local variables?
* What are static data members?
* How memory is allocated for each?
* Which variables are shared?
* Their scope and lifetime.

---

# 1. Member Variables

## Definition

> **Member variables** (also called **data members** or **instance variables**) are variables declared inside a class but outside any member function. They store the data of an object.

---

## Example

```cpp
class Student
{
public:
    string name;
    int age;
};
```

Here,

* `name` → Member Variable
* `age` → Member Variable

---

## Memory Allocation

Memory is allocated **when an object is created**, **not** when the class is defined.

Example:

```cpp
Student s1;
Student s2;
```

Memory:

```text
s1
---------
name
age
---------

s2
---------
name
age
---------
```

Each object gets **its own copy**.

---

## Access

Member variables are accessed using the **dot (`.`) operator**.

Example:

```cpp
s1.name = "Ayush";
s1.age = 22;
```

---

# Summary

| Property              | Member Variable        |
| --------------------- | ---------------------- |
| Declared Inside Class | ✅ Yes                  |
| Belongs To            | Object                 |
| Memory Allocated      | When object is created |
| Shared?               | ❌ No                   |

---

# 2. Local Variables

## Definition

> **Local variables** are variables declared inside a function or block. They exist only while that function or block is executing.

---

## Example

```cpp
class Student
{
public:
    void display()
    {
        int marks = 90;
    }
};
```

`marks` is a **local variable**.

It is **not** a member variable.

---

## Scope

A local variable can be used **only inside the function** where it is declared.

Example:

```cpp
void display()
{
    int marks = 90;
}
```

`marks` cannot be used outside `display()`.

---

## Lifetime

A local variable is created when the function starts.

It is destroyed automatically when the function ends.

---

## Storage

Local variables are generally stored in the **stack memory**.

*(You'll learn about stack and heap in memory management.)*

---

# Summary

| Property                 | Local Variable            |
| ------------------------ | -------------------------- |
| Declared Inside Function | ✅ Yes                     |
| Belongs To               | Function                  |
| Scope                    | Only inside that function |
| Lifetime                 | Until the function ends   |
| Shared?                  | ❌ No                      |

---

# 3. Static Variables (Static Data Members)

This is the most interesting part of the module.

---

## Problem Without Static

Suppose we want to count how many students have been created.

```cpp
class Student
{
public:
    int totalStudents;
};
```

Now,

```cpp
Student s1;
Student s2;
```

Memory:

```text
s1
--------
totalStudents
--------

s2
--------
totalStudents
--------
```

Each object has its own `totalStudents`.

That's not what we want.

We want **one counter shared by every object**.

---

# Static Data Member

Definition:

> A **static data member** belongs to the **class itself**, not to individual objects.

---

## Example

```cpp
class Student
{
public:
    static int totalStudents;
};
```

Now,

```cpp
Student s1;
Student s2;
Student s3;
```

Memory:

```text
            totalStudents
                  ↑
      ┌───────────┼───────────┐
      │           │           │
     s1          s2          s3
```

There is only **one copy**.

All objects share it.

---

## Shared Memory

If

```cpp
Student::totalStudents = 5;
```

Then,

* `s1` sees `5`
* `s2` sees `5`
* `s3` sees `5`

because there is only **one shared variable**.

---

# Static Initialization

Unlike normal member variables, a static data member must be **defined outside the class**.

Example:

```cpp
class Student
{
public:
    static int totalStudents;
};

int Student::totalStudents = 0;
```

Here,

```cpp
int Student::totalStudents = 0;
```

creates and initializes the shared variable.

---

# Why?

Because the static variable belongs to the class, not to any object.

There is only **one copy** in the program.

---

# Use Cases

### 1. Count Objects

```text
Student Count
Employee Count
Car Count
```

---

### 2. Company Information

Every employee belongs to the same company.

```cpp
static string companyName;
```

All employees share the same company name.

---

### 3. Common Settings

```text
Tax Rate

Currency Symbol

Application Version
```

These values are common to all objects.

---

# Comparison

| Feature        | Member Variable | Local Variable     | Static Data Member |
| -------------- | --------------- | ------------------- | ------------------- |
| Belongs To     | Object          | Function            | Class                |
| Memory Created | Object creation | Function call       | Once for the class   |
| Shared?        | ❌ No            | ❌ No                | ✅ Yes                |
| Lifetime       | Object lifetime | Function execution  | Entire program        |

---

# Memory Visualization

```text
Student Class

Member Variables
---------------
name
age

↓

Student s1
---------------
name = Ayush
age = 22

Student s2
---------------
name = Rahul
age = 20

Shared by All
---------------
static totalStudents = 2
```

---

# Common Mistakes

### ❌ Thinking static variables belong to objects.

They belong to the **class**.

---

### ❌ Thinking local variables are member variables.

Local variables exist only inside functions.

---

### ❌ Thinking every object gets a copy of a static variable.

There is only **one shared copy**.

---

# Interview Questions

### 1. What is a member variable?

> A member variable is a variable declared inside a class but outside any member function. It stores the data of an object.

---

### 2. What is a local variable?

> A local variable is declared inside a function and exists only while that function executes.

---

### 3. What is a static data member?

> A static data member belongs to the class rather than individual objects. Only one copy exists, and it is shared by all objects.

---

### 4. Why do we use static data members?

> Static data members are used to store information that should be common to all objects of a class, such as counters, configuration values, or shared settings.

---

## 💡 One Important Clarification

You'll notice that **member variables** and **instance variables** were discussed in the previous module. They are **the same thing**:

* **Member Variable**
* **Instance Variable**
* **Data Member**

These terms are commonly used interchangeably in C++.

Similarly, don't confuse a **static data member** with a **local static variable** (a `static` variable declared inside a function). Both use the `static` keyword, but they have different meanings. In this module, when we say **static variable**, we're specifically referring to a **static data member of a class**. You'll encounter local static variables later when studying storage classes and function scope.