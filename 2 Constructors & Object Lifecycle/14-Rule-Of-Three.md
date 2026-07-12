Excellent. This is the last conceptual module of Day 2, and it ties together everything you've learned:

* Constructors
* Copy Constructor
* Destructor
* Shallow Copy
* Deep Copy

Don't worry if it doesn't fully click yet. Since it depends on the previous topics (especially shallow/deep copy), we'll also revisit it during implementation.

---

# Module 14: Rule of Three

## 🎯 Objective

By the end of this module, you should understand:

* What the Rule of Three is.
* Why these three functions are related.
* When you should implement them.
* Why it's important for classes managing dynamic memory.

---

# 1. What is the Rule of Three?

## Definition

The **Rule of Three** states:

> **If a class defines any one of the following, it should usually define all three:**
>
> * Copy Constructor
> * Copy Assignment Operator
> * Destructor

These three functions work together to correctly manage resources like dynamic memory.

---

### ⭐ Notebook Definition

> **Rule of Three:** If a class requires a user-defined destructor, copy constructor, or copy assignment operator, it usually requires all three.

---

# 2. The Three Functions

### 1. Copy Constructor

Creates a **new object** by copying an existing object.

```cpp
Student s2 = s1;
```

---

### 2. Copy Assignment Operator (Introduction)

Copies data into an **already existing object**.

```cpp
Student s2;
s2 = s1;
```

We'll study this in detail later.

---

### 3. Destructor

Releases the resources owned by the object before it is destroyed.

---

# 3. Why These Three Go Together?

Imagine your class owns heap memory.

If you write:

* a custom **destructor** (to free memory),

then you must also think about:

* **How copying should happen** (copy constructor),
* **How assignment should happen** (copy assignment operator).

Otherwise, multiple objects may incorrectly share the same memory.

---

# 4. Classes Managing Dynamic Memory

Suppose:

```cpp
class Student
{
    int* marks;
};
```

Now the class owns heap memory.

If you rely on the compiler-generated copy operations,

both objects may point to the same memory (shallow copy).

This can lead to:

* Double deletion
* Dangling pointers
* Memory leaks

That's why the Rule of Three exists.

---

# Internal Working

Suppose:

```cpp
Student s1;

Student s2 = s1;

Student s3;
s3 = s1;
```

Conceptually:

```text
Create s1

↓

Copy Constructor (s2)

↓

Copy Assignment Operator (s3)

↓

Destructor (cleanup)
```

All three functions must cooperate correctly.

---

# Common Misconceptions

### ❌ Misconception 1

> Every class should implement the Rule of Three.

Incorrect.

Most classes **do not need** it.

It's mainly required for classes that manage resources manually (like raw pointers).

---

### ❌ Misconception 2

> Rule of Three applies to every copy operation.

Incorrect.

If your class only contains types like `int` and `std::string`, the compiler-generated functions are usually sufficient.

---

# Interview Questions

### Q1

What is the Rule of Three?

**Answer**

If a class defines a custom destructor, copy constructor, or copy assignment operator, it usually needs to define all three.

---

### Q2

Why does it exist?

**Answer**

To ensure resources such as dynamically allocated memory are copied and released safely, preventing shallow-copy-related bugs.

---

### Q3

When should we implement it?

**Answer**

When a class manages resources manually, such as dynamic memory, file handles, sockets, or other owned resources.

---

# Important Connection with Our Student Project ⭐

Our current `Student` class contains:

```cpp
string name;
int age;
```

So the compiler-generated copy constructor, assignment operator, and destructor are generally sufficient.

If we later change it to:

```cpp
int* marks;
```

then we'll likely need to follow the **Rule of Three** by implementing:

* A custom copy constructor (deep copy),
* A custom copy assignment operator,
* A custom destructor.

---

## 📌 One Important Clarification

At your current stage, **don't try to memorize the Rule of Three**.

Instead, remember the reason behind it:

> **If your class owns a resource, then copying it and destroying it must be handled carefully.**

The Rule of Three is simply a guideline that reminds you to implement all three related functions together when manual resource management is involved.

