# Module 2: Single Inheritance

## 🎯 Objective

By the end of this module, you should understand:

* What Single Inheritance is.
* The syntax of Single Inheritance.
* What Base and Derived classes are.
* How a derived class accesses members of the base class.
* Real-world examples of Single Inheritance.
* When Single Inheritance should be used.

---

# 1. What is Single Inheritance?

## Definition

**Single Inheritance** is the simplest form of inheritance in which a **derived class inherits from exactly one base class**.

There is only one parent class and one child class.

### ⭐ Notebook Definition

> **Single Inheritance:** A type of inheritance in which one derived class inherits the properties and behaviors of one base class.

---

# 2. Why do We Need Single Inheritance?

Suppose we have an Employee class.

Every employee has:

* Name
* Employee ID
* Salary

Now we create a Developer class.

A Developer also has:

* Name
* Employee ID
* Salary

plus

* Programming Language

Without inheritance we'd write:

```text
Employee
---------
Name
Employee ID
Salary

Developer
---------
Name
Employee ID
Salary
Programming Language
```

Notice the duplication.

Single inheritance removes this duplication.

---

# 3. Structure of Single Inheritance

Conceptually,

```text
        Base Class
             ▲
             │
             │
      Derived Class
```

The derived class automatically gets the accessible members of the base class.

---

# 4. Syntax

General syntax:

```cpp
class Base
{
};

class Derived : public Base
{
};
```

Here,

* `Base` is the parent class.
* `Derived` is the child class.
* `public` specifies the inheritance mode (we'll study inheritance modes in the next module).

---

## Inheritance Mode (Short Definition)

**Inheritance Mode** determines how the public and protected members of a base class are inherited by a derived class. It decides the access level of inherited members in the derived class.

### Example

```cpp
class Employee
{
public:
    string name;

protected:
    int salary;

private:
    int password;
};
```

Now inherit it:

```cpp
class Developer : public Employee
{
};
```

Here, `public` is the inheritance mode.

It decides how `name` and `salary` will appear inside `Developer`.

### Three Inheritance Modes

```cpp
class Developer : public Employee      // Public Inheritance
class Developer : protected Employee   // Protected Inheritance
class Developer : private Employee     // Private Inheritance
```

### Difference Between Access Specifier and Inheritance Mode

**Access Specifier** (`public`, `protected`, `private`)

* Controls access inside a class.

```cpp
class Employee
{
public:
protected:
private:
};
```

**Inheritance Mode** (`public`, `protected`, `private`)

* Controls how inherited members appear inside the derived class.

```cpp
class Developer : public Employee
{
};
```

**Easy way to remember:**

* Access Specifier → Controls access within a class.
* Inheritance Mode → Controls access after inheritance in the derived class.

---

# 5. Base Class

A **Base Class** is the class whose properties and behaviors are inherited by another class.

It contains the common functionality.

Example:

```cpp
class Employee
{
public:
    string name;
    int employeeId;
    double salary;
};
```

Here,

`Employee` is the Base Class.

---

# 6. Derived Class

A **Derived Class** inherits all accessible members of the base class and can also define its own members.

Example:

```cpp
class Developer : public Employee
{
public:
    string programmingLanguage;
};
```

Now `Developer` has:

Inherited:

* name
* employeeId
* salary

Own member:

* programmingLanguage

---

# 7. Accessing Base Class Members

The derived class can directly access all **accessible** members of the base class.

Example:

```cpp
class Employee
{
public:
    string name;
};

class Developer : public Employee
{
public:
    void display()
    {
        cout << name;
    }
};
```

Here,

`name` belongs to `Employee`.

But `Developer` can access it because it inherited from `Employee`.

---

# Internal Working

Suppose

```cpp
Developer dev;
```

Conceptually,

```text
Developer Object

+------------------------+
| Employee Part          |
|------------------------|
| name                   |
| employeeId             |
| salary                 |
+------------------------+
| Developer Part         |
|------------------------|
| programmingLanguage    |
+------------------------+
```

A derived object contains both:

* the Base Class part
* its own Derived Class part

This is why a derived object can use base class members.

---

# 8. Real-World Examples

### Example 1

```text
Animal
   ▲
   │
Dog
```

Dog inherits:

* eat()
* sleep()

Adds:

* bark()

---

### Example 2

```text
Vehicle
     ▲
     │
Car
```

Car inherits:

* start()
* stop()

Adds:

* openSunroof()

---

### Example 3

```text
Employee
        ▲
        │
Developer
```

Developer inherits:

* name
* employeeId
* salary

Adds:

* programmingLanguage

---

# Advantages of Single Inheritance

### 1. Code Reusability

Common functionality is written once.

---

### 2. Reduced Duplication

No need to rewrite common members.

---

### 3. Easier Maintenance

Changes in the base class automatically become available to derived classes.

---

### 4. Better Organization

Common members stay in one place.

Derived classes only contain specialized members.

---

# Limitations

### 1. Tight Coupling

The derived class depends on the base class.

---

### 2. Incorrect Design

Single inheritance should only be used when an IS-A relationship exists.

---

### 3. Changes in Base Class

Major changes in the base class may affect all derived classes.

---

# Real-Life Analogy

Think of a company.

```text
Employee
      ▲
      │
Developer
```

Every developer is an employee.

Every developer has:

* Name
* Employee ID
* Salary

Additionally,

a developer has:

* Programming Language

This is exactly what Single Inheritance models.

---

# Common Misconceptions

### ❌ Misconception 1

> A derived class copies the base class.

Incorrect.

The derived class **inherits** the accessible members of the base class. The base portion becomes part of the derived object's memory layout.

---

### ❌ Misconception 2

> Single Inheritance means only one object can be created.

Incorrect.

It simply means one derived class inherits from one base class.

You can create any number of objects.

---

### ❌ Misconception 3

> A derived class can access every member of the base class.

Incorrect.

Only the members accessible according to the inheritance mode and access specifiers can be accessed.

Private members remain inaccessible directly.

---

# Interview Questions

### Q1

What is Single Inheritance?

**Answer**

Single Inheritance is the type of inheritance in which one derived class inherits from exactly one base class.

---

### Q2

What is the difference between a Base Class and a Derived Class?

**Answer**

A Base Class provides common properties and behaviors, while a Derived Class inherits those members and can add its own specialized features.

---

### Q3

Can a derived class access base class members?

**Answer**

Yes.

A derived class can access the accessible members of the base class according to the inheritance mode and access specifiers.

---

### Q4

When should Single Inheritance be used?

**Answer**

Single Inheritance should be used when there is a clear **IS-A relationship** between two classes and the derived class needs to reuse and extend the functionality of the base class.

---

# Important Connection with Module 1 ⭐

In **Module 1**, we learned **why** inheritance is useful.

In this module, we learned **the simplest way to implement it**.

From the next modules onward, we'll explore more advanced inheritance structures:

* Multiple Inheritance
* Multilevel Inheritance
* Hierarchical Inheritance
* Hybrid Inheritance

Each one is simply a different way of connecting classes based on the relationships required by the application.

---

## 📌 One Important Clarification

**Single Inheritance describes the inheritance structure, not the complexity of the classes.**

A base class or derived class can be simple or highly complex. The term *Single Inheritance* only means that **one derived class inherits from exactly one base class**. It says nothing about how many data members, member functions, or objects the classes contain.