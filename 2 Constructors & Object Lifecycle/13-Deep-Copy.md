Perfect. This module is the **solution** to the problem introduced in Module 12.

* **Module 12** → Problem (**Shallow Copy**)
* **Module 13** → Solution (**Deep Copy**)

Again, we'll understand the real importance during implementation, but let's first build the theory.

---

# Module 13: Deep Copy

## 🎯 Objective

By the end of this module, you should understand:

* What a deep copy is.
* How it differs from a shallow copy.
* Why new memory must be allocated.
* How a custom copy constructor implements deep copy.

---

# 1. What is Deep Copy?

## Definition

A **deep copy** creates a **completely independent copy** of an object by allocating new memory for dynamic resources and copying the actual data.

### ⭐ Notebook Definition

> **Deep Copy:** Creates a new copy of dynamically allocated data by allocating separate memory and copying the contents.

---

# 2. Allocating New Memory

Suppose:

```cpp id="jlwmdp1"
int* marks;
```

Instead of copying the pointer:

```text id="jlwmdp2"
marks ─────► Same Memory
```

Deep copy does:

```text id="jlwmdp3"
Object 1

marks ───► Heap Memory A

-------------------------

Object 2

marks ───► Heap Memory B
```

Each object owns **its own memory**.

---

# 3. Copying Dynamic Resources

Deep copy copies the **actual data**, not just the address.

Conceptually:

```text id="jlwmdp4"
Original Heap

95
96
98

↓

Allocate New Heap

95
96
98
```

Now the two objects are completely independent.

---

# 4. Preventing Double Deletion

Since each object owns its own heap memory,

each destructor deletes only its own memory.

Example:

```text id="jlwmdp5"
Object 1

delete Heap A

-------------------

Object 2

delete Heap B
```

No conflict.

No double deletion.

---

# 5. Implementing a Custom Copy Constructor

The compiler-generated copy constructor performs a shallow copy.

To perform a deep copy,

we write our own copy constructor.

Conceptually:

```text id="jlwmdp6"
Allocate New Memory

↓

Copy Data

↓

Store New Address
```

This ensures the new object has its own independent copy of the resource.

---

# Internal Working

### Shallow Copy

```text id="jlwmdp7"
Object A

Pointer ───► Heap

↓

Copy

↓

Object B

Pointer ───► Same Heap
```

---

### Deep Copy

```text id="jlwmdp8"
Object A

Pointer ───► Heap A

↓

Copy

↓

Allocate Heap B

↓

Copy Data

↓

Object B

Pointer ───► Heap B
```

---

# Shallow Copy vs Deep Copy

| Shallow Copy                          | Deep Copy                                           |
| ---------------------------------------- | ------------------------------------------------------- |
| Copies member values directly         | Allocates new memory and copies the data            |
| Pointer members share the same memory | Pointer members point to different memory           |
| Can cause double deletion             | Prevents double deletion                            |
| Usually compiler-generated            | Usually implemented using a custom copy constructor |

---

# Common Misconceptions

### ❌ Misconception 1

> Deep copy copies only the pointer.

Incorrect.

It copies the **data** into **newly allocated memory**.

---

### ❌ Misconception 2

> Deep copy is needed for every class.

Incorrect.

It's mainly needed for classes that **own dynamic resources** (like raw pointers).

---

### ❌ Misconception 3

> Deep copy and copy constructor are the same.

Incorrect.

A **copy constructor** is a constructor.

A **deep copy** is one possible implementation of that constructor.

---

# Interview Questions

### Q1

What is the difference between shallow copy and deep copy?

**Answer**

A shallow copy copies pointer addresses, causing multiple objects to share the same memory. A deep copy allocates new memory and copies the actual data, making each object independent.

---

### Q2

Why is deep copy necessary?

**Answer**

To avoid problems like shared ownership of dynamic memory, double deletion, dangling pointers, and unintended modifications.

---

### Q3

When should you implement a deep copy?

**Answer**

When your class owns dynamically allocated resources and the compiler-generated shallow copy is not sufficient.

---

# Important Connection with Our Student Project ⭐

Right now, our `Student` class doesn't need a deep copy because it only contains:

```cpp id="’winidp9"
string name;
int age;
```

Later, when we introduce a raw pointer like:

```cpp id="qhubdp0"
int* marks;
```

we'll first observe the incorrect behavior of the compiler-generated copy constructor (shallow copy), then implement our own copy constructor to perform a deep copy and make each `Student` own its own memory safely.

