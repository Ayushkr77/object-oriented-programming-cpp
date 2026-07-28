# Module 5: Virtual Functions

## 🎯 Objective

By the end of this module, you should understand:

* What a Virtual Function is.
* Why Virtual Functions are needed.
* Runtime Polymorphism.
* Dynamic Dispatch.
* Virtual Table (VTable) – Conceptual Understanding.
* Virtual Pointer (VPtr) – Conceptual Understanding.
* Benefits and limitations of Virtual Functions.

---

# 1. What is a Virtual Function?

## Definition

A **Virtual Function** is a member function declared using the `virtual` keyword in the **Base Class**, allowing the **Derived Class** to override it so that the correct function is selected **at runtime** instead of compile time.

### ⭐ Notebook Definition

> **Virtual Function:** A Base Class function declared with the `virtual` keyword that enables Runtime Polymorphism by allowing the function call to be resolved during program execution.

---

# 2. Why do we need Virtual Functions?

Suppose we have

```text
Animal

↓

Dog

↓

Cat
```

Every animal makes a different sound.

Without Virtual Functions,

consider

```cpp
Animal* animal = new Dog();

animal->sound();
```

The compiler only knows

```text
Animal*
```

Therefore,

without `virtual`,

the compiler calls

```text
Animal::sound()
```

even though the object is actually

```text
Dog
```

This produces the wrong behavior.

Virtual Functions solve this problem by delaying the function selection until **runtime**.

---

# 3. Runtime Polymorphism

Runtime Polymorphism means

> The decision about **which function to execute** is made **while the program is running**, based on the **actual object type**, not the pointer type.

Example

```cpp
Animal* animal = new Dog();

animal->sound();
```

Pointer Type

```text
Animal*
```

Actual Object

```text
Dog
```

Output

```text
Bark
```

The compiler cannot determine this during compilation.

The decision is postponed until execution.

---

# 4. Why isn't Function Overriding alone enough?

Consider

```cpp
class Animal
{
public:

    void sound()
    {
        cout << "Animal Sound";
    }
};

class Dog : public Animal
{
public:

    void sound()
    {
        cout << "Bark";
    }
};
```

Now

```cpp
Animal* animal = new Dog();

animal->sound();
```

Output

```text
Animal Sound
```

Although the object is `Dog`,

the compiler uses the **pointer type** (`Animal*`).

Now add

```cpp
virtual void sound();
```

Output becomes

```text
Bark
```

Therefore,

Function Overriding provides a different implementation,

while **Virtual Functions make Runtime Polymorphism possible**.

---

# 5. Dynamic Dispatch

## Definition

**Dynamic Dispatch** is the process of selecting the appropriate overridden function **during runtime** based on the actual object type.

### ⭐ Notebook Definition

> **Dynamic Dispatch:** The runtime mechanism through which C++ determines which overridden virtual function should execute.

---

### Example

```cpp
Animal* animal;

animal = new Dog();

animal->sound();
```

Runtime

↓

Object is

```text
Dog
```

↓

Execute

```text
Dog::sound()
```

---

# 6. Virtual Table (VTable)

## Definition

A **Virtual Table (VTable)** is a compiler-generated lookup table containing the addresses of virtual functions.

Every class that contains at least one virtual function has its own VTable.

### ⭐ Notebook Definition

> **VTable:** A compiler-generated table that stores pointers (addresses) to a class's virtual functions.

---

### Conceptual Diagram

Suppose

```cpp
class Animal
{
public:

    virtual void sound();

    virtual void eat();
};
```

Conceptually,

the compiler creates

```text
Animal VTable

+----------------------+
| sound()              |
+----------------------+
| eat()                |
+----------------------+
```

Now suppose

```cpp
class Dog : public Animal
{
public:

    void sound() override;

    void eat() override;
};
```

Compiler creates

```text
Dog VTable

+----------------------+
| Dog::sound()         |
+----------------------+
| Dog::eat()           |
+----------------------+
```

Each class maintains its own VTable.

---

# 7. Virtual Pointer (VPtr)

## Definition

Every object of a class containing virtual functions stores a hidden pointer called the **Virtual Pointer (VPtr)**.

The VPtr points to that class's VTable.

### ⭐ Notebook Definition

> **VPtr:** A hidden compiler-generated pointer stored inside every object of a polymorphic class that points to the class's VTable.

---

### Conceptual Diagram

Suppose

```cpp
Dog dog;
```

Conceptually,

```text
Dog Object

+----------------------+
| vptr                 | ───────► Dog VTable
+----------------------+
| Data Members         |
+----------------------+
```

The programmer never writes

```cpp
vptr
```

It is automatically added by the compiler.

---

# 8. Internal Working

Suppose

```cpp
Animal* animal = new Dog();

animal->sound();
```

Internally,

```text
Animal Pointer

↓

Dog Object

↓

vptr

↓

Dog VTable

↓

Dog::sound()

↓

Execute Dog Function
```

Notice

The compiler does **not** directly call

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

This process is called **Dynamic Dispatch**.

---

# Runtime Dispatch Flow

```text
Base Pointer

↓

Actual Object

↓

VPtr

↓

VTable

↓

Correct Virtual Function

↓

Execution
```

---

# 9. Virtual Function vs Normal Function

| Normal Function         | Virtual Function             |
| --------------------------| --------------------------------|
| Compile-Time Binding    | Runtime Binding              |
| Early Binding           | Late Binding                 |
| Compiler decides        | Runtime decides              |
| No VTable               | Uses VTable                  |
| No VPtr                 | Uses VPtr                    |
| Faster                  | Slightly slower              |
| No Runtime Polymorphism | Enables Runtime Polymorphism |

---

# 10. Benefits of Virtual Functions

### 1. Enables Runtime Polymorphism

The correct overridden function executes automatically.

---

### 2. Supports Dynamic Dispatch

Function selection happens during execution.

---

### 3. Improves Extensibility

New derived classes can be added without changing client code.

---

### 4. Promotes Loose Coupling

Code depends on the Base Class interface instead of specific implementations.

---

### 5. Better Maintainability

Behavior can be extended by overriding functions instead of modifying existing code.

---

# 11. Limitations

* Slight runtime overhead because of VTable lookup.
* Every polymorphic object stores a hidden VPtr.
* Slight increase in object size due to the VPtr.
* Slightly more complex than normal function calls.

---

# 12. Common Misconceptions

### ❌ Misconception 1

> Virtual Functions and Function Overriding are the same.

Incorrect.

Virtual Functions enable Runtime Polymorphism.

Function Overriding simply provides a different implementation.

---

### ❌ Misconception 2

> Every function in a class becomes virtual.

Incorrect.

Only functions explicitly declared with the `virtual` keyword are virtual.

---

### ❌ Misconception 3

> VTable and VPtr are written by programmers.

Incorrect.

They are generated automatically by the compiler.

---

### ❌ Misconception 4

> VTable is stored inside every object.

Incorrect.

Each **class** has one VTable.

Each **object** has one hidden VPtr pointing to its class's VTable.

---

### ❌ Misconception 5

> Virtual Functions are always slower.

Partially Incorrect.

There is a small overhead due to VTable lookup, but in most applications it is negligible compared to the flexibility gained.

---

# 13. Interview Questions

### Q1

What is a Virtual Function?

**Answer**

A Virtual Function is a Base Class function declared with the `virtual` keyword that allows Derived Classes to override it and enables Runtime Polymorphism.

---

### Q2

Why are Virtual Functions required?

**Answer**

They allow the correct overridden function to be selected at runtime instead of compile time, enabling Runtime Polymorphism and Dynamic Dispatch.

---

### Q3

What is a VTable?

**Answer**

A VTable is a compiler-generated table containing pointers to a class's virtual functions. It is used during runtime to determine which function should execute.

---

### Q4

What is a VPtr?

**Answer**

A VPtr is a hidden pointer stored inside every object of a class containing virtual functions. It points to the class's VTable.

---

### Q5

What is Dynamic Dispatch?

**Answer**

Dynamic Dispatch is the runtime mechanism of selecting the correct overridden virtual function based on the actual object type.

---

### Q6

Does every class have a VTable?

**Answer**

No.

Only classes containing at least one virtual function have a VTable.

---

### Q7

Does every object have a VPtr?

**Answer**

Only objects of classes that contain virtual functions have a hidden VPtr.

---

# 14. Key Takeaways

* A **Virtual Function** is declared using the `virtual` keyword in the Base Class.
* Virtual Functions enable **Runtime Polymorphism**.
* **Dynamic Dispatch** selects the correct overridden function during execution.
* Every **polymorphic class** has a **VTable**.
* Every **object** of a polymorphic class contains a hidden **VPtr**.
* The **VPtr** points to the class's **VTable**.
* The VTable stores addresses of virtual functions.
* Runtime Polymorphism introduces a small runtime and memory overhead but provides great flexibility.

---

# Important Connection with Previous Module ⭐

In **Module 4**, we learned **Function Overriding**.

However, overriding alone does **not** produce Runtime Polymorphism.

```cpp
Animal* animal = new Dog();
```

will still call the Base Class function unless it is declared `virtual`.

Virtual Functions are what make Runtime Polymorphism actually work.

---

## 📌 One Important Clarification

**Do not confuse Function Overriding with Runtime Polymorphism.**

* **Function Overriding** means a Derived Class provides its own implementation of a Base Class function.
* **Runtime Polymorphism** happens only when:

  1. The Base Class function is declared `virtual`.
  2. A Base Class pointer or reference refers to a Derived Class object.

Without both conditions, dynamic dispatch does not occur.