This is the counterpart of the previous module. If constructors execute **Base → Derived**, then destructors execute in the **exact opposite order: Derived → Base**.

---

# Module 9: Destructor Calling Order

## 🎯 Objective

By the end of this module, you should understand:

* How destructors execute in an inheritance hierarchy.
* The Reverse Order Principle.
* Why the Derived Class destructor executes before the Base Class destructor.
* How resources are cleaned up correctly.
* Why this order is necessary.

---

# 1. Destructor Execution in Inheritance

When a derived class object is destroyed, **both the derived class and base class destructors execute**.

However, unlike constructors, destructors execute in the **reverse order**.

### ⭐ Notebook Definition

> **Destructor Calling Order:** When a derived class object is destroyed, the Derived Class destructor executes first, followed by the Base Class destructor.

---

# 2. Why are Destructors Executed in Reverse Order?

Suppose we have:

```text
Person
   ▲
   │
Employee
```

When creating an object:

```cpp
Employee emp;
```

Construction happens as:

```text
Person Constructor

↓

Employee Constructor
```

Therefore, destruction must happen in reverse:

```text
Employee Destructor

↓

Person Destructor
```

This ensures the specialized part is cleaned up before the common base part is destroyed.

---

# 3. Destructor Calling Order

Example:

```cpp
class Person
{
public:
    ~Person()
    {
        cout << "Person Destructor\n";
    }
};

class Employee : public Person
{
public:
    ~Employee()
    {
        cout << "Employee Destructor\n";
    }
};
```

```cpp
Employee emp;
```

Output (when `emp` goes out of scope):

```text
Employee Destructor
Person Destructor
```

The Derived Class destructor always executes first.

---

# 4. Reverse Order Principle

A simple rule to remember:

```text
Construction

Base

↓

Derived
```

```text
Destruction

Derived

↓

Base
```

Think of it like stacking books.

```text
Put books on table

Book A

↓

Book B

↓

Book C
```

To remove them:

```text
Book C

↓

Book B

↓

Book A
```

The last thing created is the first thing destroyed.

---

# 5. Resource Cleanup

Derived classes often own resources that depend on the base class.

Example:

```text
Person
   ▲
Employee
```

Suppose:

* `Person` manages basic information.
* `Employee` manages a database connection.

When destroying the object:

```text
Close Database Connection

↓

Destroy Employee

↓

Destroy Person
```

Destroying the base class first could leave the derived class with invalid resources.

That's why reverse order is necessary.

---

# Internal Working

Suppose:

```text
Person
   ▲
Employee
   ▲
Developer
```

Creating:

```cpp
Developer dev;
```

Construction:

```text
Person Constructor

↓

Employee Constructor

↓

Developer Constructor
```

Destruction:

```text
Developer Destructor

↓

Employee Destructor

↓

Person Destructor
```

---

# Real-Life Analogy

Think of building a house.

Construction:

```text
Foundation

↓

Walls

↓

Roof
```

Demolition:

```text
Roof

↓

Walls

↓

Foundation
```

You remove the roof before breaking the foundation.

Similarly:

```text
Derived

↓

Base
```

---

# Common Misconceptions

### ❌ Misconception 1

> Constructors and destructors execute in the same order.

Incorrect.

Constructors execute from Base → Derived.

Destructors execute from Derived → Base.

---

### ❌ Misconception 2

> The Base Class destructor should execute first.

Incorrect.

Doing so could destroy resources needed by the derived class.

---

### ❌ Misconception 3

> Destructor chaining must be written manually.

Incorrect.

Destructor chaining happens automatically in reverse order.

---

# Interview Questions

### Q1

Which destructor is called first?

**Answer**

The Derived Class destructor is called first, followed by the Base Class destructor.

---

### Q2

Why are destructors executed in reverse order?

**Answer**

Because the derived class may depend on the base class. The derived class must clean up its own resources before the base class is destroyed.

---

### Q3

What is the destructor calling order in multilevel inheritance?

**Answer**

Destructors execute from the most derived class back to the base class.

Example:

```text
Developer Destructor

↓

Employee Destructor

↓

Person Destructor
```

---

# Important Connection with Previous Module ⭐

In **Module 8**, we learned that constructors execute from the **Base Class to the Derived Class**.

```text
Person()

↓

Employee()

↓

Developer()
```

Now, destruction happens in the exact opposite direction.

```text
Developer Destructor

↓

Employee Destructor

↓

Person Destructor
```

This reverse order ensures that objects are cleaned up safely and correctly.

---

## 📌 One Important Clarification

The **destructor body** of the derived class executes **before** the base class destructor.

This allows the derived class to release any resources it owns while the base class is still valid. Only after the derived class finishes does C++ automatically invoke the base class destructor, completing the cleanup process in reverse construction order.