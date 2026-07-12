Excellent. This module is the foundation for **dynamic memory**, **copy constructors**, **destructors**, **Rule of Three**, **smart pointers**, etc.

So understanding it now will make many future topics much easier.

---

# Module 8: Stack vs Heap Objects

## 🎯 Objective

By the end of this module, you should understand:

* What is Stack Memory?
* What is Heap Memory?
* How objects are created on the stack and heap.
* Why `new` and `delete` exist.
* Advantages and disadvantages of each.

---

# 1. What is Stack Memory?

## Definition

**Stack memory** is automatically managed memory where local variables and local objects are created.

The compiler/runtime automatically allocates and deallocates this memory.

### ⭐ Notebook Definition

> **Stack Memory:** Memory used for local variables and local objects. It is automatically allocated and deallocated.

---

# Example

```cpp id="dudmq0"
int main()
{
    Student s1;
}
```

Here,

```cpp id="wm99e0"
Student s1;
```

is created on the **stack**.

When `main()` ends,

`s1` is automatically destroyed.

No cleanup is needed from the programmer.

---

# 2. What is Heap Memory?

## Definition

**Heap memory** is dynamically allocated memory that is managed manually by the programmer.

Objects are created using `new` and released using `delete`.

### ⭐ Notebook Definition

> **Heap Memory:** Dynamically allocated memory managed manually using `new` and `delete`.

---

# Example

```cpp id="j1m86j"
Student* s1 = new Student();
```

Now the object is created on the **heap**.

Notice:

`s1` is only a **pointer**.

The actual object lives in heap memory.

---

# 3. Stack Object Creation

Example:

```cpp id="pjlmke"
Student s1;
```

Conceptually:

```text id="mlvq0o"
Stack

-----------

s1

-----------
```

When the function ends:

```text id="ys5jzb"
s1 destroyed automatically
```

---

# 4. Heap Object Creation using `new`

Example:

```cpp id="i4mynr"
Student* s1 = new Student();
```

Memory:

```text id="h4y9e3"
Stack

--------

s1 (Pointer)

--------

       │
       ▼

Heap

--------------

Student Object

--------------
```

Notice:

The pointer is on the stack.

The object is on the heap.

---

# 5. Manual Memory Management using `delete`

Suppose:

```cpp id="1ktvhv"
Student* s1 = new Student();
```

Will the object disappear automatically?

❌ No.

You must write:

```cpp id="il1k1s"
delete s1;
```

Now:

```text id="tczk5m"
Heap Memory Released
```

If you forget:

Memory leak.

---

# Heap Allocation (Short Notes)

### 1. Integer

```cpp
int* x = new int(10);
delete x;
```

### 2. Character

```cpp
char* ch = new char('A');
delete ch;
```

### 3. Float / Double

```cpp
float* f = new float(3.14);
double* d = new double(99.99);

delete f;
delete d;
```

### 4. Object

```cpp
Student* s = new Student();
delete s;
```

### 5. Array

```cpp
int* arr = new int[5];
delete[] arr;
```

### 6. Array of Objects

```cpp
Student* students = new Student[5];
delete[] students;
```

### 7. String

```cpp
string* str = new string("Ayush");
delete str;
```

### 8. Structure

```cpp
Employee* emp = new Employee();
delete emp;
```

## 📌 General Syntax

Single Variable / Object

```cpp
Type* ptr = new Type(...);
delete ptr;
```

Array

```cpp
Type* ptr = new Type[size];
delete[] ptr;
```

## ⭐ Important Note

When you write:

```cpp
int* p = new int(10);
```

* `new int(10)` creates the integer on the heap.
* `p` is a pointer variable (usually stored on the stack) that stores the address of the heap memory.
* `delete p;` frees the heap memory (the pointer variable itself is destroyed automatically if it's a local variable).

---

# 6. Advantages & Disadvantages

## Stack

### Advantages

* Fast allocation.
* Automatic cleanup.
* No memory leaks (under normal use).
* Simpler to use.

### Disadvantages

* Limited memory.
* Lifetime tied to scope.
* Cannot manually extend the object's lifetime.

---

## Heap

### Advantages

* Larger memory.
* Lifetime controlled by the programmer.
* Useful when objects must outlive a function.

### Disadvantages

* Slower allocation.
* Must use `delete`.
* Risk of memory leaks.
* More complex to manage.

---

# Internal Working

## Stack

```text id="5ts4zh"
Enter Function

↓

Create Object

↓

Use Object

↓

Exit Function

↓

Object Destroyed Automatically
```

---

## Heap

```text id="a6pkv5"
new

↓

Allocate Heap Memory

↓

Use Object

↓

delete

↓

Memory Released
```

---

# Stack vs Heap

| Stack                       | Heap                          |
| ------------------------------ | -------------------------------- |
| Automatic memory management | Manual memory management      |
| Local objects               | Dynamically allocated objects |
| Fast                        | Slower                        |
| Destroyed automatically     | Must call `delete`            |
| Smaller memory              | Larger memory                 |

---

# Real-Life Analogy

Think of renting a hotel room.

### Stack

You check in.

You leave.

Room is automatically cleaned.

---

### Heap

You buy a house.

You own it.

You must decide when to sell it.

No one cleans it automatically.

---

# Common Misconceptions

### ❌ Misconception 1

> `new` creates a pointer.

Incorrect.

`new` creates an **object on the heap** and returns its address.

---

### ❌ Misconception 2

> `delete` deletes the pointer.

Incorrect.

`delete` destroys the **heap object**.

The pointer variable itself still exists (it becomes a dangling pointer unless set to `nullptr`).

---

### ❌ Misconception 3

> Heap objects disappear when the function ends.

Incorrect.

Only the pointer (if it's local) goes out of scope.

The heap object remains until `delete` is called.

---

# Interview Questions

### Q1

What is the difference between stack and heap memory?

**Answer**

Stack memory is automatically managed and used for local variables and objects. Heap memory is dynamically allocated using `new` and must be manually released using `delete`.

---

### Q2

When should you allocate an object on the heap?

**Answer**

When the object's lifetime needs to extend beyond the current scope, when its size or lifetime is determined at runtime, or when shared ownership/dynamic allocation is required.

---

### Q3

What happens if you forget `delete`?

**Answer**

The heap memory remains allocated, causing a **memory leak**.

---

### Q4

Which is faster?

**Answer**

Stack allocation is generally faster than heap allocation.

---

# Important Connection with Our Student Project ⭐

Until now, we've created students like this:

```cpp id="dgh3p2"
Student s1;
```

This creates a **stack object**.

Later, we'll also create students like:

```cpp id="fzb1mb"
Student* s1 = new Student();
```

This creates a **heap object**.

At that point, we'll compare:

```cpp id="wxkp6o"
delete s1;
```

vs automatic destruction, and you'll actually observe the difference in object lifetime and destructor calls.

---

## 📌 One Important Clarification

For **modern C++**, the general recommendation is:

> **Prefer stack allocation by default.**

Use heap allocation **only when you genuinely need dynamic lifetime or dynamic ownership**.

In real-world modern C++ code, raw `new` and `delete` are used much less than they were in older C++ because **smart pointers** (`std::unique_ptr`, `std::shared_ptr`) manage heap memory automatically.

However, it's still essential to understand `new` and `delete` first, because smart pointers are built on top of these concepts.