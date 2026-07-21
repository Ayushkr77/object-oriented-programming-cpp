This module extends **Single Inheritance** by introducing an inheritance **chain**. The idea is simple: a class can inherit from another derived class.

---

# Module 4: Multilevel Inheritance

## 🎯 Objective

By the end of this module, you should understand:

* What Multilevel Inheritance is.
* How an inheritance chain works.
* How members are inherited through multiple levels.
* Practical examples of Multilevel Inheritance.
* How it differs from Single Inheritance.

---

# 1. What is Multilevel Inheritance?

## Definition

**Multilevel Inheritance** is a type of inheritance in which **a class inherits from another derived class**, forming a chain of inheritance.

A derived class becomes the base class for another class.

### ⭐ Notebook Definition

> **Multilevel Inheritance:** A type of inheritance in which a class inherits from a derived class, forming a chain of inheritance.

---

# 2. Why do We Need Multilevel Inheritance?

Sometimes specialization happens in multiple stages.

Example:

```text id="w8skjh"
Person
   ▲
   │
Employee
   ▲
   │
Developer
```

Here,

* Every Developer is an Employee.
* Every Employee is a Person.

Instead of placing everything in one class, we gradually build specialized classes.

---

# 3. Chain of Inheritance

The inheritance relationship forms a chain.

Conceptually,

```text id="mjlwmu"
Base Class
     ▲
     │
Derived Class
     ▲
     │
Further Derived Class
```

Each class inherits all accessible members from the previous level.

---

# 4. Syntax

General syntax:

```cpp id="djjlwm"
class A
{
};

class B : public A
{
};

class C : public B
{
};
```

Here,

* `B` inherits from `A`.
* `C` inherits from `B`.

As a result, `C` indirectly inherits the accessible members of `A` as well.

---

# 5. Inheriting Through Multiple Levels

Consider:

```text id="nqg57l"
Person
   ▲
   │
Employee
   ▲
   │
Developer
```

Suppose:

* `Person` has `name`.
* `Employee` adds `employeeId`.
* `Developer` adds `programmingLanguage`.

A `Developer` object contains all three.

---

# Internal Working

Conceptually,

```text id="3vjfcp"
Developer Object

+----------------------+
| Person Part          |
+----------------------+
| Employee Part        |
+----------------------+
| Developer Part       |
+----------------------+
```

The `Developer` object contains the base class parts of **both Person and Employee**, followed by its own members.

---

# 6. Practical Examples

### Example 1

```text id="dkqdn5"
Animal
   ▲
   │
Mammal
   ▲
   │
Dog
```

Dog inherits:

* Animal features
* Mammal features
* Dog features

---

### Example 2

```text id="fslmy4"
Person
   ▲
   │
Employee
   ▲
   │
Manager
```

Manager inherits everything from both Person and Employee.

---

### Example 3

```text id="8ow0dv"
Vehicle
   ▲
   │
Car
   ▲
   │
SportsCar
```

SportsCar gets all accessible members from Vehicle and Car.

---

# Advantages of Multilevel Inheritance

### 1. Code Reusability

Common functionality is reused across multiple levels.

---

### 2. Better Organization

Classes become more specialized step by step.

---

### 3. Natural Hierarchy

Represents real-world relationships clearly.

---

# Limitations

### 1. Increased Complexity

Long inheritance chains are harder to understand.

---

### 2. Tight Coupling

Changes in upper-level classes can affect lower-level classes.

---

### 3. Deep Hierarchies

Very deep inheritance chains are difficult to maintain.

---

# Real-Life Analogy

Think of an organization.

```text id="bbuwtb"
Person
   ▲
   │
Employee
   ▲
   │
Developer
```

Every Developer is an Employee.

Every Employee is a Person.

Each level adds more specialized characteristics.

---

# Common Misconceptions

### ❌ Misconception 1

> Multilevel Inheritance means inheriting from multiple base classes.

Incorrect.

That is **Multiple Inheritance**.

Multilevel Inheritance forms a **chain**, not multiple parents.

---

### ❌ Misconception 2

> A derived class only inherits from its immediate parent.

Incorrect.

A derived class indirectly inherits the accessible members of all ancestor classes.

---

### ❌ Misconception 3

> Multilevel Inheritance is always better than Single Inheritance.

Incorrect.

Use it only when there is a natural hierarchy with multiple levels of specialization.

---

# Interview Questions

### Q1

What is Multilevel Inheritance?

**Answer**

Multilevel Inheritance is a type of inheritance in which a class inherits from another derived class, forming an inheritance chain.

---

### Q2

How does Multilevel Inheritance differ from Single Inheritance?

**Answer**

In **Single Inheritance**, one derived class inherits from one base class.

In **Multilevel Inheritance**, inheritance occurs through multiple levels, where a derived class becomes the base class for another class.

---

### Q3

Can the last derived class access members of the first base class?

**Answer**

Yes.

The last derived class indirectly inherits the accessible members of all ancestor classes.

---

# Important Connection with Previous Modules ⭐

In **Single Inheritance**, one derived class inherits from one base class.

```text id="5cphri"
Employee
     ▲
     │
Developer
```

In **Multiple Inheritance**, one derived class inherits from multiple base classes.

```text id="b7qcvf"
Printer      Scanner
      ▲      ▲
       \    /
      AllInOne
```

In **Multilevel Inheritance**, inheritance happens through a chain.

```text id="drjlwm"
Person
   ▲
   │
Employee
   ▲
   │
Developer
```

The key difference is that **Single Inheritance has one level**, while **Multilevel Inheritance extends inheritance across multiple levels**.

---

## 📌 One Important Clarification

**Multilevel Inheritance is about the depth of inheritance, not the number of parent classes.**

A class still inherits from **only one immediate base class**, but because that base class is itself derived from another class, inheritance forms a chain across multiple levels.