# Module 6: Early Binding (Static Binding)

## 🎯 Objective

By the end of this module, you should understand:

* What Early Binding is.
* Why it is called Static Binding.
* How Compile-Time Resolution works.
* Which functions use Early Binding.
* Advantages and Limitations of Early Binding.
* Real-world examples.

---

# 1. What is Early Binding?

## Definition

**Early Binding** is the process in which the compiler determines **which function to call during compilation**.

Since the function call is resolved before the program runs, it is also called **Compile-Time Binding** or **Static Binding**.

### ⭐ Notebook Definition

> **Early Binding (Static Binding):** The process of resolving a function call during compilation, before the program starts executing.

---

# 2. Why is it called Static Binding?

It is called **Static Binding** because the decision is **fixed (static)** at compile time.

Once the program is compiled,

the function call **cannot change** during execution.

Example

```cpp
display();
```

The compiler already knows exactly which

```cpp
display()
```

function should be called.

There is no further decision during runtime.

---

# 3. Why do we need Early Binding?

Most programs call ordinary functions.

Example

```cpp
add(10, 20);

print();

display();
```

The compiler already knows everything about these functions.

There is no need to wait until runtime.

Resolving the call during compilation makes execution faster.

---

# 4. Compile-Time Resolution

Suppose we have

```cpp
class Animal
{
public:

    void sound()
    {
        cout << "Animal Sound";
    }
};
```

Now

```cpp
Animal animal;

animal.sound();
```

During compilation,

the compiler immediately determines

```text
animal.sound()

↓

Animal::sound()
```

The generated executable already contains the address of the function.

No runtime lookup is required.

---

# 5. Internal Working

Suppose we write

```cpp
animal.sound();
```

Compiler

↓

Finds

```cpp
Animal::sound()
```

↓

Generates machine code

↓

Program executes

Conceptually,

```text
Function Call

↓

Compiler

↓

Exact Function Found

↓

Machine Code Generated

↓

Execution
```

Everything happens **before the program starts running**.

---

# 6. Which Functions Use Early Binding?

The following are resolved using Early Binding.

### Normal Functions

```cpp
display();
```

---

### Non-Virtual Member Functions

```cpp
animal.sound();
```

where

```cpp
sound()
```

is **not virtual**.

---

### Function Overloading

```cpp
add(10, 20);

add(2.5, 4.5);
```

Compiler chooses the correct overloaded function during compilation.

---

### Operator Overloading

```cpp
c1 + c2;
```

Compiler resolves the overloaded operator during compilation.

---

### Static Member Functions

```cpp
Student::countStudents();
```

Static functions belong to the class,

so they are resolved during compilation.

---

# 7. Real-World Example

Suppose you have a printed railway timetable.

You already know:

* Train Number
* Platform
* Departure Time

There is no need to ask anyone at the station.

Everything has already been decided.

This is similar to **Early Binding**.

The compiler has already determined the correct function before execution begins.

---

Another example

Suppose

```cpp
Calculator calculator;

calculator.add(10, 20);
```

The compiler knows

```text
Object Type

↓

Calculator

↓

Function

↓

add(int, int)
```

No runtime decision is necessary.

---

# 8. Early Binding vs Late Binding

| Early Binding             | Late Binding               |
| ---------------------------| -----------------------------|
| Static Binding            | Dynamic Binding            |
| Compile-Time Resolution   | Runtime Resolution         |
| Compiler decides          | Runtime decides            |
| Faster                    | Slightly slower            |
| No Virtual Function       | Uses Virtual Function      |
| No VTable                 | Uses VTable                |
| No VPtr                   | Uses VPtr                  |
| Used for Normal Functions | Used for Virtual Functions |

---

# 9. Advantages

### 1. Faster Execution

No runtime lookup is required.

---

### 2. Better Performance

The compiler directly generates the function call.

---

### 3. Simpler Implementation

No VTable or VPtr is needed.

---

### 4. Less Memory Overhead

Objects do not require a hidden VPtr.

---

### 5. Easier Optimization

Since the compiler knows the exact function,

it can perform aggressive optimizations such as **function inlining**.

---

# 10. Limitations

* Cannot support Runtime Polymorphism.
* Function behavior cannot change dynamically.
* Less flexible for object-oriented designs where different objects should behave differently.

---

# 11. Common Misconceptions

### ❌ Misconception 1

> Early Binding means ordinary functions only.

Incorrect.

It also includes:

* Function Overloading
* Operator Overloading
* Non-Virtual Member Functions
* Static Member Functions

---

### ❌ Misconception 2

> Early Binding is always better than Late Binding.

Incorrect.

Early Binding is faster,

but Late Binding provides flexibility through Runtime Polymorphism.

---

### ❌ Misconception 3

> Every member function uses Early Binding.

Incorrect.

Only **non-virtual** member functions use Early Binding.

Virtual functions use Late Binding.

---

# 12. Interview Questions

### Q1

What is Early Binding?

**Answer**

Early Binding is the process of resolving function calls during compilation before the program starts executing.

---

### Q2

Why is it called Static Binding?

**Answer**

Because the compiler fixes the function call during compilation, and it cannot change during runtime.

---

### Q3

Which functions use Early Binding?

**Answer**

* Normal Functions
* Non-Virtual Member Functions
* Function Overloading
* Operator Overloading
* Static Member Functions

---

### Q4

Why is Early Binding faster?

**Answer**

Because the compiler already knows the exact function to call, eliminating the need for runtime lookup.

---

### Q5

Does Early Binding support Runtime Polymorphism?

**Answer**

No.

Runtime Polymorphism requires Late Binding using Virtual Functions.

---

# 13. Key Takeaways

* **Early Binding**, **Static Binding**, and **Compile-Time Binding** all refer to the same concept.
* The compiler determines the function to execute before the program runs.
* It is used by normal functions, non-virtual member functions, function overloading, operator overloading, and static member functions.
* Early Binding is faster because no runtime lookup is required.
* It cannot support Runtime Polymorphism because the function call is fixed during compilation.

---

# Important Connection with Previous Module ⭐

In **Module 5**, we studied **Virtual Functions** and learned that Runtime Polymorphism delays function selection until execution.

Early Binding is the **opposite** approach.

Instead of waiting until runtime, the compiler resolves the function call immediately during compilation.

Understanding this contrast makes it easier to appreciate why **Virtual Functions** require mechanisms like **VTable** and **VPtr**.

---

## 📌 One Important Clarification

A common misunderstanding is that **all member functions participate in Runtime Polymorphism**.

This is **not true**.

Consider:

```cpp
class Animal
{
public:
    void eat();          // Early Binding
    virtual void sound(); // Late Binding
};
```

* `eat()` is resolved during **compilation** (Early Binding).
* `sound()` is resolved during **execution** (Late Binding).

Whether a function uses Early or Late Binding depends on whether it is declared **virtual**.