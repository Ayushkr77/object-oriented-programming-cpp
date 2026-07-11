Excellent. Now that you know what a **class** is, the next logical step is to understand **objects**.

Think of it this way:

* **Class** → Blueprint 📋
* **Object** → Real thing 🏠

Without objects, a class is just a design.

---

# Module 6: Object

## 🎯 Deliverable

By the end of this module, you should be able to answer:

* What is an object?
* How is an object created?
* Can we create multiple objects from one class?
* How is memory allocated to objects?
* What is the lifetime of an object?

---

# 1. What is an Object?

## Definition

> **An object is an instance of a class.** It is a real entity created from a class that occupies memory and can access the class's data members and member functions.

### Key Points

* Object is an **instance** of a class.
* Object occupies memory.
* Object stores actual data.
* Object can call member functions.

---

# Understanding with an Example

Imagine a blueprint for a house.

```text
House Blueprint
```

Can you live in the blueprint?

❌ No.

Now build the house.

```text
House 1
```

Can you live in it?

✅ Yes.

Similarly,

```text
Student Class

↓

Student Object
```

The class is only the design.

The object is the actual entity.

---

# Another Example

Class

```text
Car
```

Objects

```text
Car BMW

Car Audi

Car Tesla
```

All three are different objects created from the same class.

---

# 2. Object Creation

Objects are created using the class name.

### Syntax

```cpp
ClassName objectName;
```

Example

```cpp
class Student
{
public:
    string name;
    int age;
};
```

Creating an object:

```cpp
Student s1;
```

Here,

```text
Student
```

→ Class

```text
s1
```

→ Object

---

Another example

```cpp
Student ayush;
Student rahul;
Student aman;
```

Three different objects.

One class.

---

# Visualization

```text
           Student Class

                 │

      -----------------------

      │         │          │

     s1        s2         s3
```

One class can create **many objects**.

---

# 3. Multiple Objects

One of the biggest advantages of classes is that we don't rewrite code.

Example

```cpp
Student s1;
Student s2;
Student s3;
Student s4;
```

Each object has its own copy of the data.

Suppose

```cpp
s1.name = "Ayush";
s2.name = "Rahul";
s3.name = "Aman";
```

Even though they belong to the same class,

their data is independent.

---

Visualization

```text
Student Class

↓

Object s1

Name = Ayush

Age = 21

-----------------

Object s2

Name = Rahul

Age = 22

-----------------

Object s3

Name = Aman

Age = 20
```

Each object stores its own values.

---

# 4. Object Memory

This is a very common interview question.

## Does every object occupy memory?

**Yes.**

Each object gets its own memory for **non-static data members**.

Example

```cpp
class Student
{
public:
    int age;
    float marks;
};
```

Create

```cpp
Student s1;
Student s2;
```

Memory

```text
s1

Age

Marks

------------

s2

Age

Marks
```

Each object has its own separate memory.

Changing `s1.age` does not affect `s2.age`.

---

## Important Rule

Class

```text
No object memory allocated.
```

Object

```text
Memory allocated.
```

---

## Non-static vs Static Members

Non-static member → Every object gets its own copy.
Static member → One copy is shared by all objects of the class.

---

# 5. Object Lifetime

Every object has a **lifetime**.

> **Object Lifetime:** The period from when an object is created until it is destroyed.

---

## Example 1: Local Object

```cpp
int main()
{
    Student s1;

    // use s1
}
```

When `main()` starts,

`s1` is created.

When `main()` ends,

`s1` is destroyed automatically.

---

Visualization

```text
Program Starts

↓

Object Created

↓

Object Used

↓

Program Ends

↓

Object Destroyed
```

---

## Example 2: Inside a Function

```cpp
void display()
{
    Student s1;

}
```

The object exists only inside `display()`.

When the function finishes,

the object is automatically destroyed.

---

## Types of Object Lifetime (Basic Idea)

For now, remember these two:

### Automatic Objects

Created inside functions.

Destroyed automatically when they go out of scope.

Example

```cpp
Student s1;
```

---

### Dynamic Objects

Created using

```cpp
new
```

Destroyed using

```cpp
delete
```

Example

```cpp
Student *s = new Student;
```

We'll study this in detail when we learn dynamic memory allocation.

---

# Class vs Object

| Class                           | Object                      |
| ------------------------------- | --------------------------- |
| Blueprint                       | Instance of a class         |
| Logical entity                  | Physical entity             |
| No object memory                | Occupies memory             |
| Defines properties and behavior | Stores actual data          |
| One class                       | Many objects can be created |

---

# Common Mistakes

### ❌ Thinking Class and Object are the same.

Wrong.

Class = Blueprint

Object = Actual instance.

---

### ❌ Thinking all objects share the same data.

Wrong.

Every object has its own copy of **non-static data members**.

---

### ❌ Thinking a class occupies object memory.

Only objects allocate memory for their non-static data members.

---

# Interview Questions

## 1. What is an object?

> An object is an instance of a class. It is a real entity that occupies memory and can access the data members and member functions defined in the class.

---

## 2. Can one class create multiple objects?

Yes.

One class can create any number of objects.

Each object has its own independent data.

---

## 3. Does every object have separate memory?

Yes.

Each object has its own memory for non-static data members.

---

## 4. What is the lifetime of an object?

The lifetime of an object is the duration from its creation until its destruction.

---

## 💡 Extra Understanding (Very Important)

A common statement is:

> **"An object is an instance of a class."**

That's correct, but it's not enough to build intuition.

A better way to think about it is:

* A **class** answers: *"What should something look like and what should it be able to do?"*
* An **object** answers: *"Here is one actual thing that follows that design."*

For example:

```cpp
class Student
{
public:
    string name;
    int age;
};
```

This does **not** represent any particular student.

When you write:

```cpp
Student ayush;
Student rahul;
```

Now you have **two different students**, each with its own `name` and `age`.

That's why we say:

> **Class defines the structure. Objects hold the actual state (data) and represent real entities.**