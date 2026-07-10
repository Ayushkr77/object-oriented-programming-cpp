This module is actually one of the shortest in OOP because **"instance" and "object" are almost the same thing**. Many books and interviewers use them interchangeably.

---

# Module 7: Instance

## 🎯 Deliverable

By the end of this module, you should be able to answer:

* What is an instance?
* Is an instance different from an object?
* What are instance variables?
* What are instance methods?

---

# 1. What is an Instance?

## Definition

> An **instance** is a specific object created from a class.

The word **instance** emphasizes that the object is a **particular occurrence** of a class.

---

## Example

Suppose we have a class:

```cpp
class Student
{
public:
    string name;
    int age;
};
```

Now create objects:

```cpp
Student s1;
Student s2;
```

Here,

* `Student` → Class
* `s1` → Instance (Object)
* `s2` → Instance (Object)

Each object is an **instance** of the `Student` class.

---

# Why Do We Use the Word "Instance"?

Imagine a blueprint for a chair.

```text
Chair Blueprint
```

Now the factory makes three chairs.

```text
Chair 1
Chair 2
Chair 3
```

Each chair is an **instance** of that blueprint.

Similarly,

```text
Student Class

↓

s1

s2

s3
```

Each object is one **instance** of the class.

---

# 2. Instance vs Object

This is the most common confusion.

### Short Answer

> **In C++, an instance and an object refer to the same thing.**

The difference is only in **emphasis**.

* **Object** → Focuses on the actual entity.
* **Instance** → Focuses on the fact that it was created from a class.

---

### Example

```cpp
Student s1;
```

You can say:

* "`s1` is an object of the `Student` class."
* "`s1` is an instance of the `Student` class."

Both statements are correct.

---

### Easy Way to Remember

Think of this:

```text
Class = Cookie Cutter

↓

Cookie = Object

↓

Cookie = Instance of Cookie Cutter
```

Object and instance are describing the **same cookie**.

---

# 3. Instance Variables

## Definition

> **Instance variables are the non-static data members of a class.** Every object gets its own separate copy of these variables.

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

* `name` → Instance variable
* `age` → Instance variable

Now create two objects:

```cpp
Student s1;
Student s2;
```

Assign values:

```cpp
s1.name = "Ayush";
s2.name = "Rahul";
```

Memory:

```text
s1
---------
name = Ayush
age
---------

s2
---------
name = Rahul
age
---------
```

Each object has its **own copy** of `name` and `age`.

---

# 4. Instance Methods

## Definition

> **Instance methods are member functions that operate on a specific object.**

They work with that object's data.

---

## Example

```cpp
class Student
{
public:
    string name;

    void display()
    {
        cout << name;
    }
};
```

`display()` is an **instance method**.

Now,

```cpp
Student s1;
Student s2;

s1.name = "Ayush";
s2.name = "Rahul";

s1.display();
s2.display();
```

Output:

```text
Ayush
Rahul
```

The same method behaves differently because it works on the object that calls it.

---

# Visualization

```text
Student Class

Instance Variables
------------------
name
age

Instance Method
---------------
display()

        ↓

Objects

s1 -----------------
name = Ayush
age = 22
display()

s2 -----------------
name = Rahul
age = 20
display()
```

Each object has:

* Its own instance variables.
* Access to the instance methods.

---

# Important Points

* One class can have many instances.
* Every instance is an object.
* Instance variables are unique for every object.
* Instance methods operate on the object that calls them.

---

# Common Misconceptions

### ❌ Instance and Object are different.

No.

In C++, they refer to the same thing.

---

### ❌ Instance variables are shared.

No.

Each object has its own copy.

---

### ❌ Instance methods are copied for every object.

No.

The **code** for the method exists only once. Different objects call the same function code, but each call operates on that object's data.

---

# Interview Questions

### 1. What is an instance?

> An instance is a specific object created from a class.

---

### 2. What is the difference between an instance and an object?

> In C++, there is no practical difference. An object is an instance of a class. The term "instance" emphasizes that the object was created from a class.

---

### 3. What are instance variables?

> Instance variables are non-static data members. Each object has its own separate copy.

---

### 4. What are instance methods?

> Instance methods are member functions that operate on a specific object's data.

---

## 💡 One Important Clarification

This topic often appears as a separate module, but don't let that make it seem like a brand-new concept.

You've already learned:

* **Class** → Blueprint
* **Object** → Real entity created from the class

Now simply add this:

* **Instance** → Another word for that same object, especially when highlighting that it was created from a class.

So if someone asks:

> "How many instances of `Student` are there?"

and you have:

```cpp
Student s1;
Student s2;
Student s3;
```

The answer is:

> **There are 3 instances (3 objects) of the `Student` class.**