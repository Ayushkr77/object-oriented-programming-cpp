Excellent. This is one of the most important interview topics in C++.

Many students memorize:

> **"A copy constructor copies an object."**

But the real question is:

> **Why does C++ need a special constructor just for copying?**

Let's understand it from first principles.

---

# Module 6: Copy Constructor

## 🎯 Objective

By the end of this module, you should understand:

* What a copy constructor is.
* Why C++ provides one.
* Why it takes a reference.
* When it is called.
* How it's different from the assignment operator.

---

# 1. What is a Copy Constructor?

## Definition

A **copy constructor** is a constructor that creates a **new object** by copying the contents of an **existing object**.

### ⭐ Notebook Definition

> **Copy Constructor:** A constructor that initializes a new object using an existing object of the same class.

---

# 2. Why Do We Need a Copy Constructor?

Suppose we already have:

```cpp id="5sgmbj"
Student s1("Ayush", 23);
```

Now we want another student with exactly the same data.

Without a copy constructor, we'd have to write:

```cpp id="gmjlwm"
Student s2;

s2.setName(s1.getName());
s2.setAge(s1.getAge());
```

Too much work.

Instead:

```cpp id="jlwma1"
Student s2 = s1;
```

One line.

The copy constructor performs the copying.

---

# 3. Syntax

General syntax:

```cpp id="jlwma2"
ClassName(const ClassName& obj)
{
}
```

Example:

```cpp id="jlwma3"
Student(const Student& obj)
{
}
```

Notice:

* Same name as class.
* No return type.
* Takes an object of the same class **by reference**.

---

# 4. Default Copy Constructor

Suppose you never write one.

Example:

```cpp id="jlwma4"
class Student
{
private:
    string name;
    int age;
};
```

Then:

```cpp id="jlwma5"
Student s1("Ayush", 23);

Student s2 = s1;
```

The compiler automatically generates a **default copy constructor**.

It performs a **member-by-member copy**.

Conceptually:

```text id="jlwma6"
s1

name = Ayush

age = 23

↓

Copy

↓

s2

name = Ayush

age = 23
```

---

# 5. User-Defined Copy Constructor

Sometimes the default copy isn't enough.

Then we write our own.

Example:

```cpp id="jlwma7"
Student(const Student& obj)
{
    name = obj.name;
    age = obj.age;
}
```

Here, we explicitly decide how copying should happen.

---

# 6. Why Pass by Reference?

This is one of the most common interview questions.

Suppose we write:

```cpp id="jlwma8"
Student(Student obj)
{
}
```

Question:

How is `obj` created?

To create `obj`, the compiler must **copy** the original object.

But copying requires...

the copy constructor!

So the compiler tries to call:

```cpp id="jlwma9"
Student(Student obj)
```

again...

which again needs another copy...

and so on.

Conceptually:

```text id="jlwmb0"
Copy Constructor

↓

Needs copy

↓

Calls Copy Constructor

↓

Needs copy

↓

Calls Copy Constructor

↓

Infinite recursion
```

Therefore,

the parameter must be a **reference**.

Reference means:

No new object is created.

No extra copy is required.

---

# 7. When is it Invoked?

The copy constructor is called whenever a **new object** is created from an existing object.

Example:

```cpp id="jlwmb1"
Student s1("Ayush", 23);

Student s2 = s1;
```

Copy constructor runs.

---

Another example:

```cpp id="jlwmb2"
Student s3(s1);
```

Copy constructor also runs.

---

Important:

```cpp id="jlwmb3"
Student s2;

s2 = s1;
```

This **does not** call the copy constructor.

We'll discuss why next.

---

# 8. Copy Constructor vs Assignment Operator (Introduction)

These two look similar.

But they're different.

### Copy Constructor

```cpp id="jlwmb4"
Student s2 = s1;
```

A **new object** is being created.

Copy constructor is called.

---

### Assignment Operator

```cpp id="jlwmb5"
Student s2;

s2 = s1;
```

`s2` already exists.

Only its contents are updated.

Assignment operator is used.

---

Easy way to remember:

```text id="jlwmb6"
New Object?

↓

Yes → Copy Constructor

↓

No

↓

Assignment Operator
```

---

# Internal Working

Suppose:

```cpp id="jlwmb7"
Student s1("Ayush", 23);

Student s2 = s1;
```

Conceptually:

```text id="jlwmb8"
Create s2

↓

Copy Constructor Receives s1

↓

Copy Data

↓

s2 Ready
```

---

# Common Misconceptions

### ❌ Misconception 1

> Copy constructor copies pointers only.

Incorrect.

The default copy constructor performs **member-wise copying**.

---

### ❌ Misconception 2

> `=` always calls the assignment operator.

Incorrect.

```cpp id="jlwmb9"
Student s2 = s1;
```

calls the **copy constructor** because a new object is being created.

---

### ❌ Misconception 3

> Copy constructor parameter should be passed by value.

Incorrect.

That causes infinite recursive copying.

Always pass by reference.

---

# Interview Questions

### Q1

What is a copy constructor?

**Answer**

A constructor that initializes a new object using an existing object of the same class.

---

### Q2

Why is it passed by reference?

**Answer**

Passing by value would require another copy constructor call to copy the parameter, leading to infinite recursion.

---

### Q3

When is a copy constructor called?

**Answer**

Whenever a new object is created from an existing object.

Examples:

```cpp id="jlwmc0"
Student s2 = s1;

Student s3(s1);
```

---

### Q4

Does this call the copy constructor?

```cpp id="jlwmc1"
Student s2;

s2 = s1;
```

**Answer**

❌ No.

This uses the assignment operator because `s2` already exists.

---

# Important Connection with Our Student Project ⭐

Imagine we have:

```cpp id="jlwmc3"
Student s1("Ayush", 23);
```

Now we want another student with identical details.

Instead of manually copying every field, we'll simply write:

```cpp id="jlwmc4"
Student s2 = s1;
```

The copy constructor will create `s2` with the same data as `s1`.

Later, when we add dynamic memory (like pointers), you'll see why the compiler-generated copy constructor is sometimes **not enough**, and why writing your own copy constructor becomes essential.

---

## 📌 One Important Clarification

At this stage, the **compiler-generated copy constructor is usually sufficient** because our `Student` class contains simple members like `std::string` and `int`.

The real need for a **user-defined copy constructor** appears when a class manages resources such as dynamically allocated memory, file handles, or other objects that require special copying behavior.

We'll revisit this topic when we study pointers, dynamic memory, and the **Rule of Three**, where the importance of copy constructors becomes much more apparent.