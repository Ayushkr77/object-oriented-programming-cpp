This is the third major inheritance structure. Here, **multiple derived classes inherit from the same base class**.

---

# Module 5: Hierarchical Inheritance

## 🎯 Objective

By the end of this module, you should understand:

* What Hierarchical Inheritance is.
* How one base class can have multiple derived classes.
* Common use cases of Hierarchical Inheritance.
* Practical examples.
* When Hierarchical Inheritance should be used.

---

# 1. What is Hierarchical Inheritance?

## Definition

**Hierarchical Inheritance** is a type of inheritance in which **multiple derived classes inherit from a single base class**.

Each derived class gets the common properties and behaviors of the base class while adding its own specialized features.

### ⭐ Notebook Definition

> **Hierarchical Inheritance:** A type of inheritance in which multiple derived classes inherit from one common base class.

---

# 2. Why do We Need Hierarchical Inheritance?

Often, several classes share common characteristics but represent different specialized entities.

Example:

```text
Employee
   ▲
  /|\
 / | \
Developer  Manager  Tester
```

All employees have:

* Name
* Employee ID
* Salary

But each role has its own additional features.

Instead of rewriting common members, all derived classes inherit from `Employee`.

---

# 3. One Base Class, Multiple Derived Classes

Conceptually,

```text
          Base Class
          /    |    \
         /     |     \
        ▼      ▼      ▼
   Derived1 Derived2 Derived3
```

Each derived class inherits the accessible members of the same base class independently.

---

# 4. Syntax

General syntax:

```cpp
class Base
{
};

class Derived1 : public Base
{
};

class Derived2 : public Base
{
};

class Derived3 : public Base
{
};
```

Each derived class has the same base class but can define its own members and functions.

---

# 5. Internal Working

Suppose

```text
Employee
   ▲
  / \
Developer Manager
```

Creating a `Developer` object:

```text
+----------------------+
| Employee Part        |
+----------------------+
| Developer Part       |
+----------------------+
```

Creating a `Manager` object:

```text
+----------------------+
| Employee Part        |
+----------------------+
| Manager Part         |
+----------------------+
```

Notice:

* Developer does **not** contain Manager's members.
* Manager does **not** contain Developer's members.
* Both independently contain the Employee part.

---

# 6. Practical Examples

### Example 1

```text
           Animal
          /      \
        Dog      Cat
```

Both inherit:

* eat()
* sleep()

Dog adds:

* bark()

Cat adds:

* meow()

---

### Example 2

```text
            Vehicle
           /   |    \
         Car Bike Truck
```

All inherit:

* start()
* stop()

Each adds its own specialized features.

---

### Example 3

```text
           Employee
         /     |      \
 Developer  Manager  Tester
```

All inherit:

* name
* employeeId
* salary

Each adds role-specific functionality.

---

# Advantages of Hierarchical Inheritance

### 1. Code Reusability

Common functionality is written once in the base class.

---

### 2. Reduced Duplication

All derived classes reuse the same base implementation.

---

### 3. Better Organization

Common features remain in one place while specialized behavior stays in derived classes.

---

### 4. Easy Maintenance

Updating the base class automatically benefits all derived classes.

---

# Limitations

### 1. Tight Coupling

All derived classes depend on the base class.

---

### 2. Changes Affect Everyone

Modifying the base class may impact every derived class.

---

### 3. Poor Base Class Design

If the base class is designed poorly, all derived classes inherit those design issues.

---

# Real-Life Analogy

Think of a university.

```text
           Person
         /    |     \
    Student Teacher Staff
```

Everyone is a Person.

Each role has additional responsibilities.

---

# Common Misconceptions

### ❌ Misconception 1

> Hierarchical Inheritance means classes inherit from each other.

Incorrect.

Each derived class inherits **only from the common base class**, not from the other derived classes.

---

### ❌ Misconception 2

> Derived classes share each other's members.

Incorrect.

Each derived class inherits only the base class members and its own members.

---

### ❌ Misconception 3

> All derived classes must be identical.

Incorrect.

They only share common features from the base class.

Each derived class can add its own unique data members and member functions.

---

# Interview Questions

### Q1

What is Hierarchical Inheritance?

**Answer**

Hierarchical Inheritance is a type of inheritance in which multiple derived classes inherit from a single base class.

---

### Q2

Where is Hierarchical Inheritance commonly used?

**Answer**

It is commonly used when several related classes share common functionality but also have their own specialized features.

Examples include:

* Employee → Developer, Manager, Tester
* Vehicle → Car, Bike, Truck
* Animal → Dog, Cat

---

### Q3

Do derived classes inherit from each other?

**Answer**

No.

Each derived class inherits only from the common base class.

---

# Important Connection with Previous Modules ⭐

We've now studied three inheritance structures:

### Single Inheritance

```text
Base
 ▲
 │
Derived
```

One base → One derived.

---

### Multiple Inheritance

```text
Base1   Base2
   ▲     ▲
    \   /
   Derived
```

Multiple bases → One derived.

---

### Hierarchical Inheritance

```text
       Base
     /  |  \
    ▼   ▼   ▼
   D1  D2  D3
```

One base → Multiple derived.

Each structure represents a different way of organizing relationships between classes depending on the application's requirements.

---

## 📌 One Important Clarification

**Hierarchical Inheritance is about sharing one common base class, not about communication between derived classes.**

The derived classes are **siblings**, not parent and child. They inherit common functionality from the same base class but remain independent of one another.