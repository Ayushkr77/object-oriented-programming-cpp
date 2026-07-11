Excellent! This is one of the most fundamental OOP topics. By the end of this module, you'll understand **how objects actually perform actions**.

Think of it this way:

* **Member Variables** = What an object **has** (properties/data)
* **Member Functions** = What an object **does** (behavior/actions)

For example:

```text
Student

Has:
------
Name
Age
Marks

Can Do:
-------
Study
Display Details
Calculate Percentage
```

`Name`, `Age`, `Marks` → Member Variables

`Study()`, `Display()`, `CalculatePercentage()` → Member Functions

---

# Module 9: Member Functions

## 🎯 Deliverable

By the end of this module, you should know:

* What are member functions?
* How to define them inside a class.
* How to define them outside a class.
* How to call them.
* How they access member variables.

---

# 1. What are Member Functions?

## Definition

> **Member functions are functions declared inside a class that define the behavior (actions) of an object.**

Simply put,

* Variables → Store data.
* Functions → Perform operations on that data.

---

## Example

```cpp
class Student
{
public:
    string name;
    int age;

    void display()
    {
        cout << name << " " << age;
    }
};
```

Here,

* `name`, `age` → Member Variables
* `display()` → Member Function

---

## Real-Life Example

Think of a **Car**.

### Data (Member Variables)

```text
Brand

Color

Speed
```

### Actions (Member Functions)

```text
start()

stop()

accelerate()

brake()
```

A car doesn't just have information—it can perform actions.

Similarly, an object contains both **data** and **behavior**.

---

# 2. Defining Member Functions Inside the Class

This is the simplest method.

Example:

```cpp
class Student
{
public:
    string name;
    int age;

    void display()
    {
        cout << name << endl;
        cout << age << endl;
    }
};
```

Here,

`display()` is completely defined inside the class.

---

### Visualization

```text
Student

---------------------

name

age

display()

---------------------
```

Everything is inside one place.

---

## Advantages

* Simple
* Easy to read
* Good for small programs

---

## Disadvantages

If a class has many functions,

the class becomes very large and difficult to read.

---

# 3. Defining Member Functions Outside the Class

In real projects,

we usually declare the function inside the class

and define it outside.

---

Example

```cpp
class Student
{
public:
    string name;
    int age;

    void display();
};
```

Only the declaration is inside.

Now define it outside.

```cpp
void Student::display()
{
    cout << name << endl;
    cout << age << endl;
}
```

---

## What is `Student::display()`?

This is called the **Scope Resolution Operator (`::`)**.

It tells the compiler:

> "The function `display()` belongs to the `Student` class."

---

### Visualization

```text
Student Class

↓

display();

↓

Outside

↓

Student::display()
```

---

## Why Define Functions Outside?

Imagine a class with

* 30 variables
* 50 functions

If everything is inside the class,

the class becomes huge.

Separating declarations and definitions makes the code cleaner and easier to maintain.

---

# 4. Calling Member Functions

Objects call member functions using the **dot (`.`) operator**.

Example:

```cpp
Student s1;

s1.display();
```

Here,

* `s1` → Object
* `display()` → Member Function

---

### Visualization

```text
Student Object

↓

display()
```

The object is telling itself to perform an action.

---

# 5. Accessing Member Variables

One of the biggest advantages of member functions is that they can directly access the object's member variables.

Example:

```cpp
class Student
{
public:
    string name;
    int age;

    void display()
    {
        cout << name;
        cout << age;
    }
};
```

Notice:

We write

```cpp
cout << name;
```

Not

```cpp
cout << s1.name;
```

Why?

Because inside the class,

the function already knows which object's data it should use.

---

## Example

```cpp
Student s1;
Student s2;

s1.name = "Ayush";
s2.name = "Rahul";
```

Now,

```cpp
s1.display();
```

prints

```text
Ayush
```

and

```cpp
s2.display();
```

prints

```text
Rahul
```

The **same function** works for different objects because it automatically operates on the object that called it.

---

# Memory Concept

Suppose

```cpp
Student s1;
Student s2;
```

Memory

```text
s1

Name = Ayush

Age = 22

↓

display()

--------------------

s2

Name = Rahul

Age = 20

↓

display()
```

The code for `display()` exists only **once** in the program.

Both objects call that same function code.

What changes is **which object's data the function works on**.

---

# Comparison

| Function Defined Inside      | Function Defined Outside               |
| ----------------------------- | ---------------------------------------- |
| Entire function inside class  | Declaration inside, definition outside  |
| Simpler                       | Better for large projects               |
| Good for learning             | Used in professional projects           |

---

# Common Mistakes

### ❌ Forgetting `Student::`

Wrong:

```cpp
void display()
{
}
```

Correct:

```cpp
void Student::display()
{
}
```

---

### ❌ Calling a member function without an object

Wrong:

```cpp
display();
```

Correct:

```cpp
Student s1;

s1.display();
```

---

### ❌ Using `s1.name` inside the class

Inside a member function,

simply write:

```cpp
name
```

The function automatically accesses the current object's data.

---

# Interview Questions

### 1. What is a member function?

> A member function is a function declared inside a class that defines the behavior of its objects and can access the class's member variables.

---

### 2. Why define functions outside the class?

> Defining member functions outside the class improves code readability, organization, and maintainability, especially in large projects.

---

### 3. What is the Scope Resolution Operator (`::`)?

> The scope resolution operator (`::`) is used to define or access members that belong to a particular class or namespace. When defining a member function outside the class, it specifies which class the function belongs to.

---

### 4. Can a member function access private variables?

Yes.

A member function can access **all** members of its own class, including `private`, `protected`, and `public` members.

---

## 💡 One Important Clarification

Many beginners think:

> **"Each object has its own copy of the member functions."**

That's **incorrect**.

Suppose you create:

```cpp
Student s1;
Student s2;
Student s3;
```

There are:

* ✅ Three separate copies of the **member variables** (`name`, `age`, etc.).
* ❌ Not three copies of `display()`.

The **machine code** for `display()` is stored **once**, and each object uses that same code. The function automatically knows which object's data to work with (through a hidden pointer called `this`, which you'll learn in a later module).

**Easy rule to remember:**

* **Data is per object.**
* **Function code is shared by all objects.**