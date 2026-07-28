# Module 1: Introduction to Polymorphism

## 🎯 Objective

By the end of this module, you should understand:

* What Polymorphism is.
* Why Polymorphism is needed.
* Why it is one of the four pillars of OOP.
* The different types of Polymorphism.
* Compile-Time Polymorphism.
* Runtime Polymorphism.
* Real-world examples.
* Benefits of Polymorphism.

---

# 1. What is Polymorphism?

## Definition

The word **Polymorphism** comes from two Greek words:

```text
Poly  → Many

Morph → Forms
```

So,

> **Polymorphism means "One Interface, Many Forms."**

or

> **The same interface can perform different actions depending on the object using it.**

In Object-Oriented Programming,

Polymorphism allows **the same function or interface to behave differently for different objects.**

### ⭐ Notebook Definition

> **Polymorphism:** The ability of the same interface (function, method, or operator) to exhibit different behaviors depending on the object or context.

---

# 2. Why do we need Polymorphism?

Imagine there was **no Polymorphism**.

Suppose we have different shapes.

Instead of writing

```cpp
draw();
```

we would need

```cpp
drawCircle();

drawRectangle();

drawTriangle();

drawPolygon();
```

Every time a new shape is introduced,

we would have to create another function.

As the application grows,

this becomes difficult to maintain.

Instead,

we simply write

```cpp
draw();
```

Each object decides **how** it should be drawn.

This makes programs:

* Flexible
* Reusable
* Easy to Extend
* Easy to Maintain

---

# 3. Why is Polymorphism one of the Four Pillars of OOP?

The four pillars of Object-Oriented Programming are:

```text
Encapsulation

↓

Abstraction

↓

Inheritance

↓

Polymorphism
```

Notice something interesting.

Runtime Polymorphism depends on **Inheritance**.

Inheritance establishes the relationship between classes,

while Polymorphism allows those related classes to provide different behaviors for the same interface.

Without Inheritance,

Runtime Polymorphism cannot exist.

That is why we studied Inheritance before Polymorphism.

---

# 4. Real-Life Analogy

Suppose there is a button named

```text
Start
```

On different devices,

pressing **Start** performs different actions.

### Washing Machine

```text
Start

↓

Starts Washing Clothes
```

---

### Microwave

```text
Start

↓

Starts Heating Food
```

---

### Car

```text
Start

↓

Starts the Engine
```

The interface is the same.

```text
Start
```

The behavior is different.

This is Polymorphism.

---

# 5. Another Real-Life Example

Suppose there is a function

```cpp
draw();
```

Different objects implement it differently.

```text
Circle

↓

draw()

↓

Draw Circle
```

---

```text
Rectangle

↓

draw()

↓

Draw Rectangle
```

---

```text
Triangle

↓

draw()

↓

Draw Triangle
```

Same function.

Different behavior.

---

Another example:

```text
Payment
```

Different payment methods.

```text
Payment

↓

Credit Card

↓

Process Payment
```

---

```text
Payment

↓

UPI

↓

Process Payment
```

---

```text
Payment

↓

Net Banking

↓

Process Payment
```

The user simply performs

```text
Pay
```

The internal implementation changes depending on the payment method.

---

# 6. Types of Polymorphism

C++ supports two major types.

```text
                 Polymorphism
                       │
         ┌─────────────┴─────────────┐
         │                           │
Compile-Time                 Runtime
Polymorphism               Polymorphism
```

---

## 6.1 Compile-Time Polymorphism

Also called

```text
Static Polymorphism

or

Early Binding
```

The compiler decides which function to execute **during compilation**.

Examples:

* Function Overloading
* Operator Overloading

Example

```cpp
add(5, 10);

add(2.5, 3.8);

add("Hello", "World");
```

The function name is the same,

but the parameter list differs.

The compiler selects the correct function.

---

## 6.2 Runtime Polymorphism

Also called

```text
Dynamic Polymorphism

or

Late Binding
```

The decision is made **while the program is running**.

Runtime Polymorphism uses

* Inheritance
* Virtual Functions
* Base Class Pointer or Reference

Example

```cpp
Animal* animal = new Dog();

animal->sound();
```

Output

```text
Bark
```

Although the pointer type is

```text
Animal*
```

the object actually belongs to

```text
Dog
```

The decision is made during execution.

We will study this in detail later.

---

# 7. Compile-Time vs Runtime Polymorphism

| Compile-Time Polymorphism          | Runtime Polymorphism                      |
| -------------------------------------| --------------------------------------------|
| Also called Static Polymorphism    | Also called Dynamic Polymorphism          |
| Early Binding                      | Late Binding                              |
| Decision made during compilation   | Decision made during execution            |
| Faster                             | Slightly slower due to runtime dispatch   |
| Does not require virtual functions | Requires virtual functions                |
| Function Overloading               | Function Overriding                       |
| Operator Overloading               | Base Pointer/Reference + Virtual Function |

---

# 8. Internal Working

## Without Polymorphism

```text
User

↓

if(type == Circle)

↓

drawCircle()

↓

else if(type == Rectangle)

↓

drawRectangle()

↓

else if(type == Triangle)

↓

drawTriangle()
```

The programmer manually decides which function to call.

---

## With Polymorphism

```text
User

↓

draw()

↓

Object

↓

Correct Implementation Executes
```

The object decides which implementation should execute.

No manual checking.

---

# 9. Benefits of Polymorphism

### 1. Code Reusability

One interface can support multiple implementations.

---

### 2. Extensibility

New classes can be added without changing existing code.

---

### 3. Loose Coupling

Client code depends on a common interface instead of specific implementations.

---

### 4. Better Maintainability

New functionality can be added with minimal changes to existing code.

---

### 5. Cleaner Design

Instead of

```cpp
if(type=="Dog")

else if(type=="Cat")

else if(type=="Horse")
```

we simply write

```cpp
animal->sound();
```

Each object determines its own behavior.

---

### 6. Scalability

Applications become easier to grow as new object types are introduced.

---

# 10. Advantages

* Reduces code duplication.
* Encourages reusable code.
* Simplifies maintenance.
* Improves scalability.
* Supports the Open/Closed Principle (Open for Extension, Closed for Modification).
* Makes applications easier to extend.

---

# 11. Limitations

### Compile-Time Polymorphism

* Less flexible because the decision is fixed during compilation.
* Cannot adapt to object types determined at runtime.

---

### Runtime Polymorphism

* Slight performance overhead due to dynamic dispatch.
* Requires inheritance and virtual functions.
* Internally uses mechanisms such as **VTable** and **VPtr**, which add a small amount of memory and runtime overhead.
* Slightly more complex to understand.

---

# 12. Common Misconceptions

### ❌ Misconception 1

> Polymorphism only means Function Overloading.

Incorrect.

Function Overloading is only one form of **Compile-Time Polymorphism**.

---

### ❌ Misconception 2

> Runtime Polymorphism works without Inheritance.

Incorrect.

Runtime Polymorphism requires:

* Inheritance
* Virtual Functions
* Base Class Pointer or Reference

---

### ❌ Misconception 3

> Every Polymorphism uses `virtual`.

Incorrect.

Only Runtime Polymorphism uses `virtual`.

Compile-Time Polymorphism does not.

---

### ❌ Misconception 4

> Compile-Time and Runtime Polymorphism are implemented the same way.

Incorrect.

Compile-Time Polymorphism is resolved by the compiler.

Runtime Polymorphism is resolved during execution using dynamic dispatch.

---

# 13. Interview Questions

### Q1

What is Polymorphism?

**Answer**

Polymorphism is the ability of the same interface to perform different actions depending on the object involved.

---

### Q2

Why is Polymorphism needed?

**Answer**

It improves flexibility, code reusability, maintainability, scalability, and extensibility by allowing multiple implementations behind a common interface.

---

### Q3

What are the two types of Polymorphism?

**Answer**

* Compile-Time Polymorphism
* Runtime Polymorphism

---

### Q4

Give examples of Compile-Time Polymorphism.

**Answer**

* Function Overloading
* Operator Overloading

---

### Q5

Give examples of Runtime Polymorphism.

**Answer**

* Function Overriding
* Virtual Functions
* Base Class Pointer or Reference pointing to Derived Class Objects

---

### Q6

Which type of Polymorphism is faster?

**Answer**

Compile-Time Polymorphism because function resolution happens during compilation.

---

### Q7

Which type of Polymorphism uses `virtual`?

**Answer**

Runtime Polymorphism.

---

# 14. Key Takeaways

* **Polymorphism** means **One Interface, Many Forms**.
* The same interface can behave differently for different objects.
* It is one of the four pillars of Object-Oriented Programming.
* There are two major types:

  * **Compile-Time Polymorphism** (Function Overloading, Operator Overloading)
  * **Runtime Polymorphism** (Function Overriding, Virtual Functions)
* Runtime Polymorphism depends on **Inheritance** and **Virtual Functions**.
* Compile-Time Polymorphism is resolved during compilation, while Runtime Polymorphism is resolved during execution.

---

# Important Connection with Previous Modules ⭐

In **Day 4 (Inheritance)**, we learned how one class can inherit properties and behaviors from another class.

```text
Animal

↓

Dog
```

Inheritance establishes the **IS-A relationship**.

Polymorphism builds on this relationship by allowing derived classes to provide different implementations of the same interface.

Without Inheritance, Runtime Polymorphism cannot exist.

---

## 📌 One Important Clarification

**Polymorphism is a concept, not a single C++ feature.**

Different C++ language features implement different forms of Polymorphism:

* Function Overloading → Compile-Time Polymorphism
* Operator Overloading → Compile-Time Polymorphism
* Virtual Functions → Runtime Polymorphism
* Function Overriding → Runtime Polymorphism
