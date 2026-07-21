This module introduces one of the most debated inheritance concepts in C++. It's powerful, but it also introduces challenges like ambiguity and the diamond problem (which we'll study later).

---

# Module 3: Multiple Inheritance

## 🎯 Objective

By the end of this module, you should understand:

* What Multiple Inheritance is.
* The syntax of Multiple Inheritance.
* How a derived class inherits from multiple base classes.
* How to access members from different base classes.
* The advantages and disadvantages of Multiple Inheritance.
* Why it can lead to ambiguity.

---

# 1. What is Multiple Inheritance?

## Definition

**Multiple Inheritance** is a type of inheritance in which **one derived class inherits from two or more base classes**.

The derived class acquires the properties and behaviors of all its base classes.

### ⭐ Notebook Definition

> **Multiple Inheritance:** A type of inheritance in which one derived class inherits from two or more base classes.

---

# 2. Why do We Need Multiple Inheritance?

Sometimes an object naturally combines features from multiple independent classes.

Example:

A **SmartPhone** is:

* A Phone
* A Camera
* A Music Player

Instead of rewriting all their functionalities, we can inherit from all three.

```text
        Phone
          ▲
          │
Camera ◄──┼──► MusicPlayer
          │
          ▼
      SmartPhone
```

---

# 3. Syntax

General syntax:

```cpp
class Base1
{
};

class Base2
{
};

class Derived : public Base1, public Base2
{
};
```

Here,

* `Base1` and `Base2` are base classes.
* `Derived` inherits from both.

---

# 4. Accessing Members from Multiple Base Classes

The derived class can access the accessible members of **both** base classes.

Example:

```cpp
class Printer
{
public:
    void print()
    {
        cout << "Printing...\n";
    }
};

class Scanner
{
public:
    void scan()
    {
        cout << "Scanning...\n";
    }
};

class AllInOne : public Printer, public Scanner
{
};

int main()
{
    AllInOne device;

    device.print();
    device.scan();
}
```

Output:

```text
Printing...
Scanning...
```

The derived class inherits both functionalities.

---

# Internal Working

Conceptually,

```text
        Printer

            ▲
            │
            │
AllInOne Object
            │
            │
            ▼
        Scanner
```

Memory layout (conceptually):

```text
+----------------------+
| Printer Part         |
+----------------------+
| Scanner Part         |
+----------------------+
| AllInOne Part        |
+----------------------+
```

The derived object contains the base class parts of **all** inherited classes.

---

## Internal Working (Multiple Inheritance)

When a derived class inherits from multiple base classes, its object contains the base class parts of all inherited classes, followed by its own members.

Example:

```cpp
class Printer {};
class Scanner {};

class AllInOne : public Printer, public Scanner {};
```

```cpp
AllInOne device;
```

Conceptually:

```text
+----------------------+
| Printer Part         |
+----------------------+
| Scanner Part         |
+----------------------+
| AllInOne Part        |
+----------------------+
```

Therefore, `device` can access members of both `Printer` and `Scanner`, along with its own members.

**Note:** This is a conceptual memory layout to understand inheritance. The actual memory layout is compiler-dependent.

---

# 5. Advantages of Multiple Inheritance

### 1. Code Reusability

Reuse functionality from multiple classes.

---

### 2. Better Modularity

Each base class can represent one independent feature.

---

### 3. Flexible Design

A derived class can combine different capabilities.

---

# 6. Disadvantages of Multiple Inheritance

### 1. Increased Complexity

Understanding relationships becomes harder as more base classes are added.

---

### 2. Ambiguity

If two base classes contain members with the same name, the compiler cannot determine which one to use.

---

### 3. Diamond Problem

Multiple Inheritance can lead to the **Diamond Problem**, where the same base class is inherited through multiple paths.

We'll study this separately under **Virtual Inheritance**.

---

# 7. Ambiguity Problem

Suppose:

```cpp
class A
{
public:
    void display()
    {
        cout << "A\n";
    }
};

class B
{
public:
    void display()
    {
        cout << "B\n";
    }
};

class C : public A, public B
{
};

int main()
{
    C obj;

    obj.display();      // ❌ Compile Error
}
```

Why?

Both `A` and `B` contain a function named `display()`.

The compiler doesn't know which one to call.

This is called the **Ambiguity Problem**.

---

## Resolving Ambiguity

Use the scope resolution operator.

```cpp
obj.A::display();
obj.B::display();
```

Now the compiler knows exactly which function to call.

---

# Real-World Examples

### Example 1

```text
Printer        Scanner
      ▲        ▲
       \      /
        \    /
       AllInOne Printer
```

---

### Example 2

```text
Phone      Camera
      ▲    ▲
       \  /
    SmartPhone
```

---

### Example 3

```text
Teacher      Researcher
        ▲    ▲
         \  /
       Professor
```

A Professor can teach and conduct research.

---

# Common Misconceptions

### ❌ Misconception 1

> Multiple Inheritance means multiple levels of inheritance.

Incorrect.

Multiple Inheritance means **one class inherits from multiple base classes**.

---

### ❌ Misconception 2

> Multiple Inheritance always causes ambiguity.

Incorrect.

Ambiguity occurs only when multiple base classes contain members with the same name.

---

### ❌ Misconception 3

> Multiple Inheritance should always be avoided.

Incorrect.

It is useful when modeling genuine multiple-role relationships.

However, it should be used carefully because it increases complexity.

---

# Interview Questions

### Q1

What is Multiple Inheritance?

**Answer**

Multiple Inheritance is a type of inheritance in which one derived class inherits from two or more base classes.

---

### Q2

Why is Multiple Inheritance considered complex?

**Answer**

Because it can introduce ambiguity when multiple base classes contain members with the same name and can also lead to the Diamond Problem.

---

### Q3

How can ambiguity be resolved?

**Answer**

By using the scope resolution operator (`::`) to explicitly specify the base class.

Example:

```cpp
obj.A::display();
obj.B::display();
```

---

# Important Connection with Module 2 ⭐

In **Single Inheritance**, a derived class inherited from **one** base class.

```text
Employee
     ▲
     │
Developer
```

In **Multiple Inheritance**, a derived class inherits from **multiple** base classes.

```text
Printer      Scanner
      ▲      ▲
       \    /
      AllInOne
```

The core idea remains the same—**reusing existing functionality**—but Multiple Inheritance allows a class to combine features from multiple independent sources.

---

## 📌 One Important Clarification

**Multiple Inheritance is not the same as Multiple Objects.**

It does **not** mean creating multiple instances of a class.

It simply means that **one derived class inherits from multiple base classes**, allowing it to reuse functionality from each of them.