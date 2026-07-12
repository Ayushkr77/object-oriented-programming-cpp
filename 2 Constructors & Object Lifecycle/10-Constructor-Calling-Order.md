Excellent. This is an interview-favorite topic, but there's one important thing to note.

⚠️ **Part of this module depends on inheritance**, which you haven't studied yet.

So we'll divide it into two parts:

* ✅ What you can understand now.
* ⏳ What we'll revisit on **Day 5 (Inheritance)**.

---

# Module 10: Constructor Calling Order

## 🎯 Objective

By the end of this module, you should understand:

* Constructor order in a single class.
* Member object initialization order.
* Constructor order in inheritance (basic idea).
* Base vs Derived constructor order.

---

# 1. Constructor Order in a Single Class

Suppose:

```cpp id="x4l1hf"
Student s1;
Student s2;
Student s3;
```

What happens?

Conceptually:

```text id="xitn54"
Create s1
↓

Constructor of s1

↓

Create s2
↓

Constructor of s2

↓

Create s3
↓

Constructor of s3
```

Each object's constructor runs **immediately after that object is created**.

---

# 2. Constructor Order in Inheritance (Basic Idea)

Suppose:

```text id="jlwmd1"
Person

↓

Student
```

Question:

When creating a `Student`, which constructor runs first?

Answer:

```text id="jlwmd2"
Base Class Constructor

↓

Derived Class Constructor
```

Reason:

A derived class **depends on** the base class.

The base part must be initialized first.

We'll study this in detail on **Day 5**.

---

# 3. Member Object Initialization Order

Suppose:

```cpp id="jlwmd3"
class Student
{
    Address address;
    LibraryCard card;
};
```

Both `Address` and `LibraryCard` are objects.

When a `Student` object is created,

its member objects are also constructed.

Important rule:

> **Member objects are initialized in the order they are declared in the class, not the order written in the initialization list.**

We'll see this in code later.

---

# Example

Suppose:

```cpp id="jlwmd4"
class Student
{
    Address address;
    LibraryCard card;

public:
    Student()
        : card(), address()
    {
    }
};
```

Even though the initialization list says:

```text id="jlwmd5"
card

↓

address
```

Actual order is:

```text id="jlwmd6"
address

↓

card
```

because that's the declaration order.

---

# 4. Base Class Constructor

Base constructor always executes first.

Conceptually:

```text id="jlwmd7"
Create Student

↓

Create Person Part

↓

Person Constructor

↓

Student Constructor
```

---

# 5. Derived Class Constructor

The derived constructor runs only **after** the base constructor finishes.

Conceptually:

```text id="jlwmd8"
Base Constructor

↓

Derived Constructor
```

---

# Internal Working

Suppose:

```cpp id="jlwmd9"
Student s1;
```

Conceptually:

```text id="jlwmda"
Allocate Memory

↓

Initialize Member Objects

↓

Run Constructor

↓

Object Ready
```

For inheritance:

```text id="jlwmdb"
Allocate Memory

↓

Base Constructor

↓

Derived Constructor

↓

Object Ready
```

---

# Common Misconceptions

### ❌ Misconception 1

> Derived constructor runs first.

Incorrect.

The **base constructor** always runs first.

---

### ❌ Misconception 2

> Member objects follow the initialization list order.

Incorrect.

They follow the **order of declaration inside the class**.

---

### ❌ Misconception 3

> Constructors of all objects run together.

Incorrect.

Each object's constructor runs when that object is created.

---

# Interview Questions

### Q1

Which constructor executes first: Base or Derived?

**Answer**

The **Base class constructor** executes first, followed by the **Derived class constructor**.

---

### Q2

Does member initialization follow the initialization list order?

**Answer**

❌ No.

Members are initialized in the **order they are declared in the class**, regardless of the order in the initialization list.

---

### Q3

When are member objects initialized?

**Answer**

Before the constructor body executes.

---

# Important Connection with Our Student Project ⭐

At the moment, our `Student` class only contains simple data members:

```cpp id="jlwmdc"
string name;
int age;
```

So constructor order is straightforward.

Later, when we introduce:

* Constructors with initialization lists,
* Member objects,
* Inheritance,

you'll see the full constructor call sequence in action.

---

## 📌 One Important Clarification

For **your current level**, the only part you really need to remember is:

1. A constructor runs when its object is created.
2. Member objects are initialized before the constructor body.
3. **Base class constructor runs before the derived class constructor** (we'll fully understand this after studying inheritance).
4. Member initialization order depends on the **declaration order**, not the order in the initialization list.

The inheritance-related details will become much more intuitive on **Day 5**, once you've learned what base and derived classes actually are. For now, it's enough to know the rule without trying to memorize the underlying implementation.