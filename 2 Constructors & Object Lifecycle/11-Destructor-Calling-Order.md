Perfect. This module is essentially the **mirror image of Module 10**.

Just as constructors have an order of execution, destructors also have an order.

Again, **part of this module depends on inheritance**, so we'll separate what you need now from what we'll revisit on Day 5.

---

# Module 11: Destructor Calling Order

## 🎯 Objective

By the end of this module, you should understand:

* Destructor order in a single class.
* Reverse order principle.
* Destructor order in inheritance (basic idea).
* Base vs Derived destructor order.

---

# 1. Destructor Order in a Single Class

Suppose:

```cpp
Student s1;
Student s2;
Student s3;
```

Creation order:

```text
s1
↓

s2
↓

s3
```

When the scope ends,

destruction happens in **reverse order**.

```text
s3
↓

s2
↓

s1
```

This is called the **Reverse Order Principle**.

---

# 2. Destructor Order in Inheritance (Basic Idea)

Suppose:

```text
Person

↓

Student
```

Creation:

```text
Person Constructor

↓

Student Constructor
```

Destruction:

```text
Student Destructor

↓

Person Destructor
```

The **derived class** is destroyed first,

then the **base class**.

We'll study this properly on **Day 5**.

---

# 3. Reverse Order Principle

Rule:

> **Objects are destroyed in the reverse order of their creation.**

Example:

Creation:

```text
s1

↓

s2

↓

s3
```

Destruction:

```text
s3

↓

s2

↓

s1
```

---

# Why Reverse Order?

Imagine building a house.

```text
Foundation

↓

Walls

↓

Roof
```

To demolish it:

```text
Roof

↓

Walls

↓

Foundation
```

Similarly,

objects are cleaned up in the reverse order they were built.

This ensures that objects depending on earlier-created objects are cleaned up safely.

---

# 4. Base Class and Derived Class Destruction

Creation:

```text
Base Constructor

↓

Derived Constructor
```

Destruction:

```text
Derived Destructor

↓

Base Destructor
```

Reason:

The derived part may depend on the base part.

So the derived part is destroyed first.

We'll revisit this on **Day 5**.

---

# Internal Working

Single class:

```text
Create s1
↓

Create s2
↓

Create s3
↓

Destroy s3
↓

Destroy s2
↓

Destroy s1
```

Inheritance:

```text
Base Constructor
↓

Derived Constructor

----------------

Derived Destructor
↓

Base Destructor
```

---

# Common Misconceptions

### ❌ Misconception 1

> Destructors execute in the same order as constructors.

Incorrect.

Constructors:

```text
First → Last
```

Destructors:

```text
Last → First
```

---

### ❌ Misconception 2

> Base destructor executes first.

Incorrect.

Derived destructor executes first.

---

# Interview Questions

### Q1

Which destructor executes first?

**Answer**

For objects in the same scope, the **last created object** is destroyed first.

In inheritance, the **derived class destructor** executes before the **base class destructor**.

---

### Q2

Why is destruction performed in reverse order?

**Answer**

To safely clean up objects and dependencies in the opposite order of their creation.

---

# Important Connection with Our Student Project ⭐

When we add a destructor like:

```cpp
~Student()
{
    cout << "Destructor Called\n";
}
```

and create:

```cpp
Student s1;
Student s2;
Student s3;
```

We'll observe:

```text
Constructor Called
Constructor Called
Constructor Called

Destructor Called (s3)
Destructor Called (s2)
Destructor Called (s1)
```

This will clearly demonstrate the reverse order principle during implementation.

---

## 📌 One Important Clarification

For **Day 2**, the key takeaway is:

* Constructors → **Creation Order**
* Destructors → **Reverse Creation Order**

The inheritance-related destructor order (Derived → Base) depends on concepts from **Day 5 (Inheritance)**, so we'll revisit that once you've learned base and derived classes.

---

## 📌 Status (Same as Module 10)

We'll cover in **Day 2 implementation**:

* ✅ Destructor Order in a Single Class
* ✅ Reverse Order Principle

We'll **postpone until Day 5**:

* Destructor Order in Inheritance
* Base Class and Derived Class Destruction

That way, you're learning each concept only after you have the necessary foundation, rather than memorizing rules without context.