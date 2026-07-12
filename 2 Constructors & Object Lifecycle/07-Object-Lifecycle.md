Excellent. This module is not introducing a new C++ feature. Instead, it's helping you understand **the complete life of an object**.

Think of it as answering:

> **"What exactly happens from the moment an object is created until it is destroyed?"**

---

# Module 7: Object Lifecycle

## 🎯 Objective

By the end of this module, you should understand:

* What an object lifecycle is.
* The stages an object goes through.
* When an object is created.
* When it is initialized.
* When it is destroyed.
* The lifetime of local and global objects.

---

# 1. What is an Object Lifecycle?

## Definition

The **Object Lifecycle** is the complete journey of an object from its **creation** until its **destruction**.

### ⭐ Notebook Definition

> **Object Lifecycle:** The complete journey of an object from creation, initialization, usage, and finally destruction.

---

# 2. Stages of an Object Lifecycle

Every object goes through **four stages**.

```text
Object Creation
       ↓
Initialization
       ↓
Usage
       ↓
Destruction
```

Let's understand each one.

---

# 3. Object Creation

An object is created when memory is allocated for it.

Example:

```cpp
Student s1;
```

At this point:

* Memory is allocated.
* The object now exists.

Think of this as the **birth** of the object.

---

# 4. Initialization

Immediately after creation, the constructor initializes the object.

Example:

```cpp
Student s1("Ayush", 23);
```

Conceptually:

```text
Memory Allocated
        ↓
Constructor Runs
        ↓
Object Initialized
```

Now the object is ready to use.

---

# 5. Usage

Once initialized, the object performs its work.

Example:

```cpp
s1.display();

s1.setAge(24);

s1.setName("Rahul");
```

This is the longest stage of the lifecycle.

The object is simply being used.

---

# 6. Destruction

When the object's lifetime ends,

the destructor is called,

and the memory is released.

Conceptually:

```text
Object No Longer Needed

↓

Destructor Runs

↓

Memory Released
```

We'll study destructors in detail later.

---

# Internal Working

Suppose:

```cpp
Student s1("Ayush", 23);
```

Conceptually:

```text
Create Object

↓

Allocate Memory

↓

Constructor Executes

↓

Object Ready

↓

Use Object

↓

Destructor Executes

↓

Memory Released
```

---

# 7. Lifetime of Local Objects

Local objects are created **inside a function**.

Example:

```cpp
int main()
{
    Student s1;
}
```

The lifetime of `s1` is:

```text
Enter main()

↓

Create s1

↓

Use s1

↓

Exit main()

↓

Destroy s1
```

When the function ends,

the local object is automatically destroyed.

---

# 8. Lifetime of Global Objects

Global objects are created **outside every function**.

Example:

```cpp
Student s1;

int main()
{
}
```

Their lifetime is different.

```text
Program Starts

↓

Create Global Object

↓

main() Executes

↓

Program Ends

↓

Destroy Global Object
```

Global objects live for the **entire duration of the program**.

---

# Local vs Global Objects

| Local Object                        | Global Object                   |
| ------------------------------------- | ---------------------------------- |
| Created inside a function           | Created outside all functions   |
| Lifetime is limited to the function | Lifetime is the entire program  |
| Destroyed when the function ends    | Destroyed when the program ends |

---

## Does the Program Start from `main()`?

✅ Yes, execution starts from `main()`.

But before `main()` runs, the C++ runtime initializes global objects.

```text
Program Starts
      ↓
Global Objects Created
      ↓
main() Starts
      ↓
Local Objects Created
      ↓
main() Ends
      ↓
Local Objects Destroyed
      ↓
Global Objects Destroyed
      ↓
Program Ends
```

**Key Point:** `main()` is where execution begins, not where all objects are created.

---

## Does the Program End When `main()` Ends?

❌ Not exactly.

After `main()` finishes, the runtime performs cleanup (like destroying global objects), and then the program terminates.

```text
main() Ends
      ↓
Global Objects Destroyed
      ↓
Program Ends
```

---

# Real-Life Analogy

Think of a student joining a college.

```text
Admission
        ↓
Orientation
        ↓
Studies
        ↓
Graduation
```

Similarly,

```text
Creation
        ↓
Initialization
        ↓
Usage
        ↓
Destruction
```

---

# Common Misconceptions

### ❌ Misconception 1

> Creating an object automatically initializes it.

Not always.

Creation allocates memory.

Initialization is performed by the constructor.

---

### ❌ Misconception 2

> Objects remain in memory forever.

Incorrect.

Local objects are destroyed when their scope ends.

---

### ❌ Misconception 3

> Local and global objects have the same lifetime.

Incorrect.

Their lifetimes are different.

---

# Interview Questions

### Q1

What is the object lifecycle?

**Answer**

The sequence of stages an object goes through: creation, initialization, usage, and destruction.

---

### Q2

When is an object initialized?

**Answer**

Immediately after creation, by the constructor.

---

### Q3

When is a local object destroyed?

**Answer**

When its scope (typically the function) ends.

---

### Q4

When is a global object destroyed?

**Answer**

When the program terminates.

---

# Important Connection with Our Student Project ⭐

Right now, we create objects like this:

```cpp
int main()
{
    Student s1;
    Student s2;
    Student s3;
}
```

Their lifecycle is:

```text
main() starts
      ↓
s1 created
s2 created
s3 created
      ↓
Constructors run
      ↓
Objects are used
      ↓
main() ends
      ↓
Destructors run
      ↓
Objects destroyed
```

When we implement constructors and destructors later in Day 2, you'll actually **see this sequence printed on the screen**, making the lifecycle very intuitive.

---

## 📌 One Important Clarification

An object's **lifetime** and **scope** are related but not identical.

* **Scope** determines **where** you can access an object in the code.
* **Lifetime** determines **how long** the object exists in memory.

For most local variables, they happen to begin and end together, which is why the two concepts often seem the same. As you study more advanced C++ topics (like dynamic memory and smart pointers), you'll see situations where an object's lifetime extends beyond the scope in which it was created. That's why it's useful to keep these concepts conceptually separate from the beginning.

---

## Scope vs Lifetime

**Scope:** Where an object/variable can be accessed in the code.

**Lifetime:** How long the object/variable exists in memory.

Example:

```cpp
int main()
{
    int x = 10;
}
```

* Scope of `x`: Only inside `main()`.
* Lifetime of `x`: From entering `main()` until `main()` ends.

---

## Easy Trick 🧠

```text
Scope    → Where can I use it?

Lifetime → How long does it exist?
```

---

## Why do Scope and Lifetime Seem the Same?

For most local variables, they start and end together, so they appear to be the same.

Later (with dynamic memory), you'll see cases where:

* Scope ends
* But the object's lifetime continues

That's when the difference becomes obvious.