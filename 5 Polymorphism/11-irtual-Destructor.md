# Module 11: Virtual Destructor

# 🎯 Objective

By the end of this module, you should understand:

* What a Virtual Destructor is.
* Why Virtual Destructors are needed.
* What happens when a Base Class pointer deletes a Derived Class object.
* How Virtual Destructors prevent resource leaks.
* Best practices.
* Common interview questions.

---

# 1. What is a Virtual Destructor?

## Definition

A **Virtual Destructor** is a destructor declared using the `virtual` keyword in the Base Class.

It ensures that when a Derived Class object is deleted through a Base Class pointer, **both the Derived Class destructor and the Base Class destructor execute in the correct order**.

### ⭐ Notebook Definition

> **Virtual Destructor:** A Base Class destructor declared using the `virtual` keyword that ensures proper destruction of Derived Class objects when deleted through Base Class pointers.

---

# 2. Why do we need Virtual Destructors?

Suppose

```text
Animal

↓

Dog
```

Now

```cpp
Animal* animal = new Dog();
```

Later,

```cpp
delete animal;
```

Question:

Which destructor should execute?

```text
Animal Destructor

?

or

Dog Destructor
```

Correct answer:

```text
Dog Destructor

↓

Animal Destructor
```

because the object is actually

```text
Dog
```

Without a Virtual Destructor,

only

```text
Animal Destructor
```

may execute,

leaving the Derived Class resources uncleaned.

---

# 3. Problem Without Virtual Destructor

Suppose

```cpp
class Animal
{
public:

    ~Animal()
    {
        cout << "Animal Destructor\n";
    }
};

class Dog : public Animal
{
public:

    ~Dog()
    {
        cout << "Dog Destructor\n";
    }
};
```

Now

```cpp
Animal* animal = new Dog();

delete animal;
```

Possible Output

```text
Animal Destructor
```

Notice

```text
Dog Destructor
```

never executes.

Therefore,

any resources owned by

```text
Dog
```

are not released properly.

---

# 4. Solution: Virtual Destructor

Now

```cpp
class Animal
{
public:

    virtual ~Animal()
    {
        cout << "Animal Destructor\n";
    }
};
```

Now

```cpp
Animal* animal = new Dog();

delete animal;
```

Output

```text
Dog Destructor

Animal Destructor
```

Correct cleanup occurs.

---

# 5. Base Pointer Deleting Derived Object

This is the most important situation.

Suppose

```cpp
Animal* animal = new Dog();
```

Memory

```text
Animal Pointer

↓

Dog Object
```

Now

```cpp
delete animal;
```

If destructor is virtual,

Runtime

↓

Find Actual Object

↓

```text
Dog
```

↓

Execute

```text
Dog Destructor
```

↓

Execute

```text
Animal Destructor
```

Everything is cleaned properly.

---

# 6. Memory Leak Prevention

Suppose

```cpp
class Dog : public Animal
{
private:

    int* data;

public:

    Dog()
    {
        data = new int[100];
    }

    ~Dog()
    {
        delete[] data;
    }
};
```

Now

```cpp
Animal* animal = new Dog();

delete animal;
```

Without Virtual Destructor,

```text
Dog Destructor
```

never executes.

Therefore,

```text
delete[] data;
```

never runs.

Result

```text
Memory Leak
```

---

With Virtual Destructor

```text
Dog Destructor

↓

delete[] data

↓

Animal Destructor
```

Everything is released properly.

---

# 7. Internal Working

Suppose

```cpp
Animal* animal = new Dog();

delete animal;
```

Conceptually,

```text
delete

↓

Base Pointer

↓

Actual Object

↓

VPtr

↓

Dog VTable

↓

Dog Destructor

↓

Animal Destructor
```

Notice

Even destructors participate in Runtime Polymorphism when declared virtual.

---

# Destructor Execution Flow

```text
delete BasePointer

↓

Actual Object

↓

Derived Destructor

↓

Base Destructor
```

This ensures proper cleanup.

---

# 8. Destructor Order

Creation

```text
Animal Constructor

↓

Dog Constructor
```

Destruction

```text
Dog Destructor

↓

Animal Destructor
```

Always remember

> **Construction happens from Base to Derived.**

> **Destruction happens from Derived to Base.**

---

# 9. Virtual Destructor vs Normal Destructor

| Normal Destructor                    | Virtual Destructor                       |
| ---------------------------------------| --------------------------------------------|
| No Runtime Polymorphism              | Supports Runtime Polymorphism            |
| May skip Derived Destructor          | Calls Derived then Base Destructor       |
| Unsafe with Base Pointers            | Safe with Base Pointers                  |
| Can cause resource leaks             | Prevents resource leaks                  |
| Suitable for non-polymorphic classes | Recommended for polymorphic base classes |

---

# 10. Real-World Example

Suppose

```text
Employee

↓

Manager
```

Manager opens

* Database Connection
* File
* Network Socket

When

```cpp
Employee* employee = new Manager();

delete employee;
```

Without Virtual Destructor,

the Manager's cleanup code never executes.

Resources remain allocated.

With Virtual Destructor,

Manager cleans up first,

then Employee cleans up.

---

Another example

```text
Shape

↓

Circle
```

Circle allocates dynamic memory.

Deleting

```cpp
Shape* shape = new Circle();

delete shape;
```

must execute

```text
Circle Destructor

↓

Shape Destructor
```

---

# 11. Benefits

### 1. Proper Resource Cleanup

Ensures Derived resources are released.

---

### 2. Prevents Memory Leaks

Dynamic memory is correctly freed.

---

### 3. Safe Polymorphic Deletion

Objects can safely be deleted through Base Class pointers.

---

### 4. Supports Runtime Polymorphism

Destructor selection occurs dynamically.

---

### 5. Better Object-Oriented Design

Base Classes become safe for inheritance.

---

# 12. Limitations

* Slight runtime overhead because destructors use the VTable.
* Every polymorphic object contains a hidden VPtr.
* Unnecessary if the class is never intended to be used polymorphically.

---

# 13. Best Practices

### ✔ Declare the Base Class destructor as `virtual`

If a class is intended to be inherited **and** may be deleted through a Base Class pointer, always declare its destructor virtual.

---

### ✔ Let Derived Classes clean up their own resources

Each Derived Class should release the resources it owns.

---

### ✔ Don't make every destructor virtual unnecessarily

If the class is **not** intended to be a polymorphic base class, a virtual destructor may be unnecessary.

---

# 14. Common Misconceptions

### ❌ Misconception 1

> Constructors can be virtual.

Incorrect.

Constructors **cannot** be virtual.

Only destructors can.

---

### ❌ Misconception 2

> Every class should have a virtual destructor.

Incorrect.

Only classes intended to be used as **polymorphic base classes** generally need a virtual destructor.

---

### ❌ Misconception 3

> Virtual Destructors are only needed when dynamic memory is used.

Incorrect.

Any Derived Class that owns resources (memory, files, sockets, database connections, etc.) benefits from proper destructor dispatch.

---

### ❌ Misconception 4

> Virtual Destructors change the order of destruction.

Incorrect.

The order remains

```text
Derived Destructor

↓

Base Destructor
```

Virtual simply ensures the **correct Derived Destructor is selected first**.

---

# 15. Interview Questions

### Q1

Why should a Base Class destructor be virtual?

**Answer**

A virtual destructor ensures that deleting a Derived Class object through a Base Class pointer correctly invokes both the Derived and Base destructors, preventing incomplete cleanup and resource leaks.

---

### Q2

What happens if the destructor is not virtual?

**Answer**

Deleting a Derived Class object through a Base Class pointer may invoke only the Base Class destructor, causing the Derived Class destructor to be skipped and potentially leading to resource leaks or undefined behavior.

---

### Q3

When should we declare a virtual destructor?

**Answer**

Whenever a class is intended to act as a polymorphic Base Class and objects may be deleted through Base Class pointers or references.

---

### Q4

Can constructors be virtual?

**Answer**

No.

Constructors cannot be virtual because an object must exist before virtual dispatch can occur.

---

### Q5

Can destructors be virtual?

**Answer**

Yes.

Virtual destructors enable correct runtime destruction of Derived Class objects.

---

# 16. Key Takeaways

* A **Virtual Destructor** is a Base Class destructor declared using the `virtual` keyword.
* It ensures that deleting a Derived Class object through a Base Class pointer invokes **both** the Derived and Base destructors.
* Virtual Destructors prevent incomplete cleanup and resource leaks.
* Constructors cannot be virtual, but destructors can.
* Virtual destructors are recommended for **polymorphic Base Classes**, not necessarily for every class.

---

# Important Connection with Previous Module ⭐

In **Module 10**, we learned that **Abstract Classes** are typically used as polymorphic Base Classes.

These classes are often manipulated through Base Class pointers:

```cpp
Animal* animal = new Dog();
```

When such an object is deleted:

```cpp
delete animal;
```

the same **Runtime Polymorphism** mechanism (using **VPtr** and **VTable**) is used to select the correct destructor.

So, **Virtual Destructors are another application of Dynamic Dispatch**, but instead of choosing the correct **member function**, the runtime chooses the correct **destructor**.

---

## 📌 One Important Clarification

Many students think:

> **"If my class has virtual functions, I don't need a virtual destructor."**

This is **incorrect**.

If your class is intended to be used polymorphically (i.e., through Base Class pointers or references), the destructor should generally be **virtual** to ensure correct destruction of Derived Class objects.