# Module 8: Dynamic Dispatch

## 🎯 Objective

By the end of this module, you should understand:

* What Dynamic Dispatch is.
* Why Dynamic Dispatch is needed.
* Base Class Pointer.
* Derived Class Object.
* Runtime Function Selection.
* Importance of Dynamic Dispatch in OOP.
* Relationship between Virtual Functions, Late Binding, and Dynamic Dispatch.

---

# 1. What is Dynamic Dispatch?

## Definition

**Dynamic Dispatch** is the runtime mechanism through which C++ determines **which overridden virtual function should execute based on the actual object type**, rather than the pointer or reference type.

In simple words,

Dynamic Dispatch is the **process** that makes Runtime Polymorphism possible.

### ⭐ Notebook Definition

> **Dynamic Dispatch:** The runtime process of selecting and invoking the correct overridden virtual function based on the actual object type.

---

# 2. Why do we need Dynamic Dispatch?

Suppose we have

```text
Animal

↓

Dog

↓

Cat
```

Now,

```cpp
Animal* animal;
```

At compile time,

the compiler only knows

```text
Animal*
```

It does **not** know whether

```text
animal
```

will point to

```text
Dog

Cat

Cow
```

That decision happens only while the program is running.

Therefore,

the function call must also be decided at runtime.

This runtime decision-making process is called **Dynamic Dispatch**.

---

# 3. Base Class Pointer

Dynamic Dispatch always begins with a **Base Class Pointer** (or Base Class Reference).

Example

```cpp
Animal* animal;
```

Notice

The pointer type is

```text
Animal*
```

not

```text
Dog*
```

This allows one pointer to refer to different derived objects.

Example

```cpp
animal = new Dog();

animal = new Cat();

animal = new Cow();
```

Same pointer.

Different objects.

---

# 4. Derived Class Object

Suppose

```cpp
Animal* animal = new Dog();
```

Here,

Pointer Type

```text
Animal*
```

Actual Object

```text
Dog
```

Although the pointer type is

```text
Animal
```

the object actually belongs to

```text
Dog
```

Dynamic Dispatch uses the **actual object type**.

---

# 5. Runtime Function Selection

Suppose

```cpp
Animal* animal = new Dog();

animal->sound();
```

Compilation

↓

Compiler knows

```text
Animal*
```

Execution

↓

Object is

```text
Dog
```

↓

Runtime selects

```text
Dog::sound()
```

instead of

```text
Animal::sound()
```

The function is selected **during execution**.

---

# 6. How does Dynamic Dispatch work?

Conceptually,

suppose we write

```cpp
Animal* animal = new Dog();

animal->sound();
```

The following steps occur.

### Step 1

Compiler sees

```cpp
animal->sound();
```

---

### Step 2

Compiler notices

```cpp
sound()
```

is virtual.

Therefore,

it does **not** fix the function call.

---

### Step 3

Program starts running.

---

### Step 4

The Base Pointer points to

```text
Dog Object
```

---

### Step 5

The object's hidden

```text
VPtr
```

points to

```text
Dog VTable
```

---

### Step 6

Runtime looks inside

```text
Dog VTable
```

---

### Step 7

Finds

```text
Dog::sound()
```

---

### Step 8

Executes

```text
Dog::sound()
```

This entire runtime lookup process is called **Dynamic Dispatch**.

---

# Internal Working

```text
Animal* Pointer

↓

Dog Object

↓

Hidden VPtr

↓

Dog VTable

↓

Dog::sound()

↓

Execute Function
```

Notice

The compiler never directly calls

```text
Dog::sound()
```

Instead,

it follows

```text
Pointer

↓

Object

↓

VPtr

↓

VTable

↓

Correct Function
```

---

# Dynamic Dispatch Flow

```text
Virtual Function Call

↓

Base Pointer / Reference

↓

Actual Object

↓

VPtr

↓

VTable

↓

Correct Overridden Function

↓

Execution
```

---

# 7. Relationship Between Virtual Function, Late Binding and Dynamic Dispatch

Many students confuse these three terms.

They are related,

but **not the same**.

| Concept          | Meaning                                              |
| ------------------| -------------------------------------------------------|
| Virtual Function | Language feature (`virtual` keyword)                 |
| Late Binding     | Concept of delaying function selection until runtime |
| Dynamic Dispatch | Runtime process that selects the correct function    |

Think of them like this.

```text
Virtual Function

↓

Enables

↓

Late Binding

↓

Implemented Through

↓

Dynamic Dispatch
```

---

# 8. Importance in OOP

Dynamic Dispatch is one of the most important mechanisms in Object-Oriented Programming.

It allows

### Code Reusability

One Base Class interface.

Many Derived Class implementations.

---

### Extensibility

New Derived Classes can be added without changing existing client code.

---

### Loose Coupling

Code depends on interfaces,

not concrete implementations.

---

### Runtime Flexibility

The same pointer can work with many different object types.

---

### Better Maintainability

New behavior is added through overriding instead of modifying existing code.

---

# 9. Real-World Example

Suppose

```text
Payment
```

Different payment methods.

```text
Payment*

↓

CreditCard
```

↓

```text
processPayment()
```

---

```text
Payment*

↓

UPI
```

↓

```text
processPayment()
```

---

```text
Payment*

↓

NetBanking
```

↓

```text
processPayment()
```

The client always calls

```cpp
payment->processPayment();
```

Dynamic Dispatch decides which implementation executes.

---

Another example

```text
Animal*

↓

Dog

↓

sound()

↓

Bark
```

```text
Animal*

↓

Cat

↓

sound()

↓

Meow
```

Same interface.

Different runtime behavior.

---

# 10. Dynamic Dispatch vs Late Binding

| Dynamic Dispatch             | Late Binding                            |
| --------------------------------| --------------------------------------------|
| Runtime mechanism            | Runtime concept                         |
| Selects the correct function | Delays function selection until runtime |
| Uses VTable and VPtr         | Achieved through Virtual Functions      |
| Happens during execution     | Happens during execution                |

---

# 11. Advantages

### 1. Enables Runtime Polymorphism

Different objects respond differently to the same function call.

---

### 2. Supports Extensibility

Adding new Derived Classes requires no changes to client code.

---

### 3. Loose Coupling

Client code depends only on the Base Class interface.

---

### 4. Cleaner Design

No large

```cpp
if

else if

else
```

chains.

---

### 5. Better Maintainability

Behavior is extended through overriding.

---

# 12. Limitations

* Slight runtime overhead due to VTable lookup.
* Hidden VPtr increases object size slightly.
* Requires Virtual Functions.
* Requires Base Class Pointer or Reference.
* More complex than Early Binding.

---

# 13. Common Misconceptions

### ❌ Misconception 1

> Dynamic Dispatch and Virtual Functions are the same.

Incorrect.

Virtual Functions enable Dynamic Dispatch.

Dynamic Dispatch is the runtime mechanism.

---

### ❌ Misconception 2

> Dynamic Dispatch works without inheritance.

Incorrect.

Inheritance is required.

---

### ❌ Misconception 3

> Dynamic Dispatch happens for every function call.

Incorrect.

It only happens for **virtual function calls** through a **Base Class pointer or reference**.

---

### ❌ Misconception 4

> VTable is searched during compilation.

Incorrect.

The lookup occurs during program execution.

---

# 14. Interview Questions

### Q1

What is Dynamic Dispatch?

**Answer**

Dynamic Dispatch is the runtime mechanism that selects the correct overridden virtual function based on the actual object type.

---

### Q2

How does Dynamic Dispatch work with Virtual Functions?

**Answer**

When a virtual function is called through a Base Class pointer or reference, the object's hidden VPtr points to its class's VTable. The runtime uses the VTable to locate and invoke the correct overridden function.

---

### Q3

What are the requirements for Dynamic Dispatch?

**Answer**

* Inheritance
* Virtual Function
* Base Class Pointer or Reference

---

### Q4

Does Dynamic Dispatch work with normal functions?

**Answer**

No.

Normal functions use Early Binding.

Only virtual function calls through a Base Class pointer or reference use Dynamic Dispatch.

---

### Q5

What is the role of the VPtr in Dynamic Dispatch?

**Answer**

The VPtr points to the class's VTable, allowing the runtime to locate the correct virtual function implementation.

---

# 15. Key Takeaways

* **Dynamic Dispatch** is the runtime mechanism that selects the correct overridden virtual function.
* It works only with:

  * Inheritance
  * Virtual Functions
  * Base Class Pointer or Reference
* The runtime uses the **VPtr** to access the **VTable**, which contains addresses of virtual functions.
* Dynamic Dispatch is the implementation mechanism behind **Late Binding** and **Runtime Polymorphism**.

---

# Important Connection with Previous Module ⭐

In **Module 7**, we learned that **Late Binding** delays function selection until runtime.

This module explains **how** that delayed selection is actually performed.

* **Late Binding** answers **"When is the function selected?"** → At runtime.
* **Dynamic Dispatch** answers **"How is the function selected?"** → Using the object's VPtr and the class's VTable.

---

## 📌 One Important Clarification

These three terms are closely related but not interchangeable:

```text
virtual
```

→ tells the compiler to enable runtime resolution.

```text
Late Binding
```

→ is the concept of postponing function selection until execution.

```text
Dynamic Dispatch
```

→ is the runtime mechanism (using VPtr and VTable) that performs that selection.

Think of it like this:

* **Virtual Function** = the feature.
* **Late Binding** = the idea.
* **Dynamic Dispatch** = the actual implementation process.