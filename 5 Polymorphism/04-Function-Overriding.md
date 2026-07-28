# Module 4: Function Overriding

## 🎯 Objective

By the end of this module, you should understand:

* What Function Overriding is.
* Why Function Overriding is needed.
* Requirements for Function Overriding.
* Base Class vs Derived Class.
* Signature Matching.
* Role of `virtual`.
* Best Practices.
* Difference between Function Overloading and Function Overriding.

---

# 1. What is Function Overriding?

## Definition

**Function Overriding** occurs when a **Derived Class provides its own implementation of a function that already exists in the Base Class**, using the **same function signature**.

The Derived Class implementation replaces (overrides) the Base Class implementation for that object.

### ⭐ Notebook Definition

> **Function Overriding:** A feature of Runtime Polymorphism where a Derived Class redefines a Base Class's virtual function using the same function signature.

---

# 2. Why do we need Function Overriding?

Suppose every animal makes a different sound.

Without overriding,

the Base Class might contain

```cpp
sound()
```

that prints

```text
Animal Sound
```

Now every derived class would also print

```text
Animal Sound
```

which is incorrect.

Instead,

each derived class provides its own implementation.

```text
Animal

↓

Dog

↓

Bark
```

```text
Animal

↓

Cat

↓

Meow
```

```text
Animal

↓

Cow

↓

Moo
```

Same function.

Different implementation.

---

# 3. Requirements for Function Overriding

For overriding to occur, the following conditions must be satisfied.

---

## Requirement 1: Inheritance

Function Overriding requires inheritance.

Example

```text
Animal

↓

Dog
```

Without inheritance,

overriding cannot occur.

---

## Requirement 2: Same Function Name

Base Class

```cpp
sound()
```

Derived Class

```cpp
sound()
```

Names must match.

---

## Requirement 3: Same Parameter List

Correct

```cpp
void sound();

void sound();
```

Incorrect

```cpp
void sound();

void sound(int volume);
```

Different parameter lists mean **Function Overloading**, not overriding.

---

## Requirement 4: Same Return Type

Generally,

the return type should be the same.

Example

```cpp
void sound();

void sound();
```

(C++ does allow **covariant return types** for pointers/references to classes, but that is an advanced topic and we'll cover it later if needed.)

---

## Requirement 5: Base Function Should Be Virtual

Example

```cpp
virtual void sound();
```

Without `virtual`,

the Derived Class function merely **hides** the Base Class function.

Runtime Polymorphism will **not** occur.

---

# 4. Base Class vs Derived Class

Suppose

```cpp
class Animal
{
public:

    virtual void sound();
};
```

Derived Class

```cpp
class Dog : public Animal
{
public:

    void sound();
};
```

The Base Class defines a **common interface**.

The Derived Class provides a **specific implementation**.

---

# 5. Signature Matching

The function signature must match exactly.

Correct

```cpp
void sound();
```

↓

```cpp
void sound();
```

---

Incorrect

```cpp
void sound();
```

↓

```cpp
void sound(int volume);
```

This becomes **Function Overloading**, not overriding.

---

# 6. Role of `virtual`

The keyword

```cpp
virtual
```

tells the compiler

> "Do not decide the function call during compilation."

Instead,

the decision should be made

**during program execution**.

Without

```cpp
virtual
```

the compiler performs **Early Binding**.

With

```cpp
virtual
```

the compiler enables **Late Binding (Dynamic Dispatch)**.

We'll study the internal mechanism (VTable and VPtr) in the next modules.

---

# 7. Internal Working (High Level)

Without `virtual`

```text
Base Pointer

↓

Compiler

↓

Base Function
```

Compiler decides during compilation.

---

With `virtual`

```text
Base Pointer

↓

Runtime

↓

Actual Object

↓

Derived Function
```

Decision happens during execution.

---

# 8. Function Overloading vs Function Overriding

| Function Overloading        | Function Overriding                         |
| ------------------------------| -----------------------------------------------|
| Compile-Time Polymorphism   | Runtime Polymorphism                        |
| Same Class                  | Base and Derived Classes                    |
| Different Parameter Lists   | Same Function Signature                     |
| Inheritance Not Required    | Inheritance Required                        |
| `virtual` Not Required      | `virtual` Required for Runtime Polymorphism |
| Resolved During Compilation | Resolved During Execution                   |

---

# 9. Real-World Example

Suppose every employee receives a salary.

Base Class

```text
Employee

↓

calculateSalary()
```

Derived Classes

```text
Manager

↓

calculateSalary()
```

```text
Developer

↓

calculateSalary()
```

```text
Intern

↓

calculateSalary()
```

The interface is identical.

Each role computes salary differently.

---

Another example

```text
Animal

↓

sound()
```

Dog

↓

```text
Bark
```

Cat

↓

```text
Meow
```

Cow

↓

```text
Moo
```

Same interface.

Different behavior.

---

# 10. Best Practices

### ✔ Always use `override`

Instead of

```cpp
void sound();
```

prefer

```cpp
void sound() override;
```

The compiler will report an error if the function does not actually override a Base Class function.

---

### ✔ Make Base Functions Virtual

If runtime polymorphism is intended,

declare the Base Class function as `virtual`.

---

### ✔ Keep Function Signatures Identical

Even a small difference in parameters creates a different function instead of overriding the existing one.

---

### ✔ Avoid Unnecessary Overriding

Only override when the Derived Class genuinely needs different behavior.

---

# 11. Advantages

* Enables Runtime Polymorphism.
* Supports extensibility.
* Allows different implementations behind a common interface.
* Improves code maintainability.
* Promotes the Open/Closed Principle.

---

# 12. Limitations

* Requires inheritance.
* Runtime dispatch introduces a small performance overhead.
* Signature mismatches result in Function Hiding instead of Overriding.
* More complex than Compile-Time Polymorphism.

---

# 13. Common Misconceptions

### ❌ Misconception 1

> Same function name means Function Overriding.

Incorrect.

The function signature must also match.

---

### ❌ Misconception 2

> Function Overriding works without `virtual`.

Partially Incorrect.

The Derived Class can redefine the function, but **Runtime Polymorphism does not occur** without `virtual`.

---

### ❌ Misconception 3

> Function Overloading and Function Overriding are the same.

Incorrect.

They are different concepts with different requirements.

---

### ❌ Misconception 4

> Static member functions can be overridden.

Incorrect.

Static member functions belong to the class, not to objects. Since Runtime Polymorphism works on objects, **static functions cannot be overridden**.

---

# 14. Interview Questions

### Q1

What is Function Overriding?

**Answer**

Function Overriding is when a Derived Class provides its own implementation of a Base Class's virtual function using the same function signature.

---

### Q2

What are the requirements for Function Overriding?

**Answer**

* Inheritance
* Same Function Name
* Same Parameter List
* Compatible Return Type
* Base function should be `virtual` for Runtime Polymorphism

---

### Q3

What is the difference between Function Overloading and Function Overriding?

**Answer**

Function Overloading uses different parameter lists within the same class and is resolved at compile time.

Function Overriding uses the same function signature in a Derived Class and is resolved at runtime (when using virtual functions).

---

### Q4

Can static functions be overridden?

**Answer**

No.

Static member functions belong to the class rather than individual objects, so they cannot participate in Runtime Polymorphism.

---

### Q5

Why is the `override` keyword recommended?

**Answer**

It allows the compiler to verify that the function actually overrides a Base Class virtual function, preventing accidental mistakes.

---

# 15. Key Takeaways

* Function Overriding is the foundation of **Runtime Polymorphism**.
* A Derived Class redefines a Base Class's function using the **same signature**.
* Inheritance is mandatory.
* The Base Class function should be declared `virtual` for Runtime Polymorphism.
* Using `override` is considered best practice.
* Static member functions cannot be overridden.

---

# Important Connection with Previous Module ⭐

In **Module 3**, we completed **Compile-Time Polymorphism** through:

* Function Overloading
* Operator Overloading

Those decisions were made by the **compiler**.

Function Overriding marks the beginning of **Runtime Polymorphism**, where the function to execute may be chosen **during program execution** instead of during compilation.

---

## 📌 One Important Clarification

**Function Overriding alone does not guarantee Runtime Polymorphism.**

Consider:

```cpp
class Animal
{
public:
    void sound();
};

class Dog : public Animal
{
public:
    void sound();
};
```

Here, `Dog::sound()` hides/redefines `Animal::sound()`, but without `virtual`, calls through a base pointer will still invoke the base version.

Runtime Polymorphism requires **both**:

* A `virtual` function in the Base Class.
* A Base Class pointer or reference referring to a Derived Class object.

---

## 📌 Base Pointer to Derived Object — Worked Example

In short:

* `Dog::sound()` hides (redefines) `Animal::sound()` because both have the same function name.
* `Animal* ptr = &d;` or `Animal* p = new Dog();` both mean a base class pointer is pointing to a derived class (`Dog`) object.
* If `sound()` is not `virtual`, a call through the base pointer uses the base class version.

Example:

```cpp
class Animal {
public:
    void sound();
};

class Dog : public Animal {
public:
    void sound();
};

Dog d;
Animal* ptr = &d;   // Base class pointer pointing to a Dog object
// Same meaning as: Animal* p = new Dog();

ptr->sound();       // Calls Animal::sound() because sound() is not virtual.
```

* If `sound()` is declared `virtual` in `Animal`, C++ uses runtime polymorphism (dynamic binding) and calls the derived version.

```cpp
class Animal {
public:
    virtual void sound();
};

class Dog : public Animal {
public:
    void sound();
};

Dog d;
Animal* ptr = &d;   // Base class pointer pointing to a Dog object
// Same meaning as: Animal* p = new Dog();

ptr->sound();       // Calls Dog::sound()
```

**Rule to remember:**

* Without `virtual` → Base pointer calls Base function (static binding).
* With `virtual` → Base pointer calls Derived function (dynamic binding/runtime polymorphism).