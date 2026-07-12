Excellent. Now that you understand **why constructors exist** and **what a default constructor is**, the next logical question is:

> **"What if I already know the object's data while creating it?"**

That's exactly why **parameterized constructors** exist.

---

# Module 3: Parameterized Constructor

## 🎯 Objective

By the end of this module, you should be able to answer:

* What is a parameterized constructor?
* Why do we need it?
* How are arguments passed?
* Why is it better than creating an object first and assigning values later?

---

# 1. What is a Parameterized Constructor?

## Definition

A **parameterized constructor** is a constructor that **accepts one or more parameters** to initialize an object with user-provided values.

### ⭐ Notebook Definition

> **Parameterized Constructor:** A constructor that accepts parameters to initialize an object with specific values during object creation.

---

# 2. Why Do We Need It?

Suppose we create an object:

```cpp id="l3xk7m"
Student s1;
```

Then later:

```cpp id="uyukf3"
s1.setName("Ayush");
s1.setAge(23);
```

This takes **three steps**:

1. Create object
2. Set name
3. Set age

---

But what if we already know the data?

Why not do everything in **one step**?

Example:

```cpp id="9v8l4f"
Student s1("Ayush", 23);
```

Now the object is **fully initialized at the moment it is created**.

This is cleaner and safer.

---

# 3. Passing Arguments

Suppose we have:

```cpp id="s6ksso"
Student(string name, int age)
```

Here:

```cpp id="6tf8u8"
string name
int age
```

are **parameters**.

Now create:

```cpp id="bztkww"
Student s1("Ayush", 23);
```

Here:

```text id="gim83g"
"Ayush"
23
```

are **arguments**.

The arguments are copied into the constructor parameters.

---

# 4. Object Initialization

Without a parameterized constructor:

```text id="63vgd2"
Create Object

↓

Object Exists

↓

Call setName()

↓

Call setAge()

↓

Object Ready
```

---

With a parameterized constructor:

```text id="8moxw2"
Create Object

↓

Constructor Receives Values

↓

Object Ready
```

The object is initialized immediately.

---

# 5. Constructor Parameters

Suppose:

```cpp id="x8lxcf"
Student(string name, int age)
```

Then:

```cpp id="k2yjlwm"
Student s1("Ayush", 23);
```

Internally (conceptually):

```text id="k2cy9m"
Parameter name = "Ayush"

Parameter age = 23
```

The constructor then uses these values to initialize the object's members.

---

# 6. Benefits over Manual Assignment

### Manual Assignment

```cpp id="5g7hvs"
Student s1;

s1.setName("Ayush");
s1.setAge(23);
```

Problems:

* More code
* Object exists before being fully initialized
* Easy to forget a setter call

---

### Parameterized Constructor

```cpp id="8m9vpf"
Student s1("Ayush", 23);
```

Advantages:

* One step
* Cleaner syntax
* Object is initialized immediately
* Less chance of mistakes

---

# Internal Working

Suppose:

```cpp id="7gm6ew"
Student s1("Ayush", 23);
```

Conceptually:

```text id="g7wk1k"
Allocate Memory

↓

Constructor Receives

name = "Ayush"

age = 23

↓

Members Initialized

↓

Object Ready
```

---

# Default vs Parameterized Constructor

| Default Constructor    | Parameterized Constructor       |
| ----------------------- | -------------------------------- |
| No arguments needed    | Requires (or accepts) arguments |
| Default values         | User-provided values            |
| `Student s1;`          | `Student s1("Ayush", 23);`      |
| Generic initialization | Custom initialization           |

---

# Common Misconceptions

### ❌ Misconception 1

> A parameterized constructor is called manually.

Incorrect.

You don't write:

```cpp id="gkrjlwm"
s1.Student("Ayush", 23);
```

The constructor is still called **automatically**.

---

### ❌ Misconception 2

> A parameterized constructor replaces the default constructor.

Not always.

A class can have **both** (we'll see this when we study constructor overloading).

---

### ❌ Misconception 3

> Parameters and arguments are the same.

Incorrect.

```cpp id="4xq9m0"
Student(string name, int age)
```

Parameters.

```cpp id="o4kb0n"
Student s1("Ayush", 23);
```

Arguments.

---

# Interview Questions

### Q1

Why do we use parameterized constructors?

**Answer**

To initialize objects with user-provided values at the time of object creation, ensuring the object is ready for use immediately.

---

### Q2

Can constructors take default arguments?

**Answer**

✅ Yes.

Example:

```cpp id="njlwmv"
Student(int age = 18)
{
}
```

This constructor can be called as:

```cpp id="jvjlwm"
Student s1;
Student s2(25);
```

This is also why a default constructor is more accurately defined as **a constructor that can be called without arguments**.

---

### Q3

Is a parameterized constructor called automatically?

**Answer**

Yes.

Whenever an object is created using matching arguments.

---

### Q4

Can a class have both a default and a parameterized constructor?

**Answer**

✅ Yes.

That's called **constructor overloading**, which is the next module.

---

# Important Connection with Our Student Project ⭐

Currently, our project looks like:

```cpp id="4ofhxb"
Student s1;

s1.input();
```

Later, we'll be able to write:

```cpp id="i33fe7"
Student s1("Ayush", 23);
```

or even:

```cpp id="jlwmxh"
Student s1("Ayush", 23, 95.6);
```

(depending on how we expand the class).

Notice how much cleaner this is.

The object is **born with valid data** instead of being created empty and filled later.

---

## 📌 One Important Thought

Think of constructors like **birth**.

* A **default constructor** says: "Create a student with default information."
* A **parameterized constructor** says: "Create a student with the information I already have."

In both cases, the object is **fully initialized as soon as it comes into existence**, which is the primary purpose of constructors.