Excellent. This is the module where the **copy constructor finally starts making sense**.

Until now, you might have wondered:

> *"Why do we even need a user-defined copy constructor if the compiler already generates one?"*

**This module answers that question.**

---

# Module 12: Shallow Copy

## 🎯 Objective

By the end of this module, you should understand:

* What a shallow copy is.
* How the compiler performs the default copy.
* Why shallow copying becomes a problem with dynamic memory.
* What double deletion, dangling pointers, and memory leaks are.

---

# 1. What is Shallow Copy?

## Definition

A **shallow copy** copies the values of all data members **as they are**.

If a member is a pointer, **only the pointer's address is copied**, **not** the actual data it points to.

### ⭐ Notebook Definition

> **Shallow Copy:** Copies all member values directly. For pointer members, only the address is copied, not the data.

---

# 2. Default Copy Behavior

Suppose:

```cpp id="jlwmsh1"
Student s1("Ayush", 23);

Student s2 = s1;
```

If you don't write a copy constructor,

the compiler generates one automatically.

It performs a **member-by-member copy**.

For normal members like:

```cpp id="jlwmsh2"
string name;
int age;
```

this usually works perfectly.

---

# 3. Problems with Dynamic Memory

Now suppose the class contains:

```cpp id="jlwmsh3"
int* marks;
```

Imagine:

```text id="jlwmsh4"
s1

marks ─────► Heap Memory
```

Now the compiler performs a shallow copy.

Result:

```text id="jlwmsh5"
s1

marks ──┐
         │
         ▼
      Heap Memory
         ▲
         │
s2

marks ───┘
```

Both objects point to **the same heap memory**.

This is where problems begin.

---

# 4. Double Deletion

Suppose:

```cpp id="jlwmsh6"
delete marks;
```

is called when `s1` is destroyed.

The heap memory is freed.

Later,

`s2` is also destroyed.

It tries:

```cpp id="jlwmsh7"
delete marks;
```

again.

But that memory has already been deleted.

This is called **double deletion**.

It leads to **undefined behavior**.

---

# 5. Dangling Pointer

After deleting heap memory,

the pointer still stores the old address.

Example:

```text id="jlwmsh8"
marks

↓

Old Memory Address
```

But the memory no longer exists.

Such a pointer is called a **dangling pointer**.

---

# 6. Memory Leak

Suppose:

```cpp id="jlwmsh9"
marks = new int[5];
```

Later:

```cpp id="jlwmsh10"
marks = new int[10];
```

Without deleting the first allocation,

the original heap memory becomes unreachable.

No pointer points to it anymore.

This is a **memory leak**.

---

# Internal Working

Shallow Copy:

```text id="jlwmsh11"
s1

Pointer ───► Heap Data

↓

Copy

↓

s2

Pointer ───► Same Heap Data
```

Notice:

Only the pointer is copied.

The heap data is **not duplicated**.

---

# Why is This a Problem?

Because now:

* Two objects share one heap allocation.
* Either object can modify it.
* Either object can delete it.
* Bugs become difficult to track.

---

# Common Misconceptions

### ❌ Misconception 1

> Shallow copy copies the entire heap memory.

Incorrect.

It copies only the pointer value (the address).

---

### ❌ Misconception 2

> Shallow copy is always bad.

Incorrect.

For classes without dynamic memory (like our current `Student` with `std::string` and `int`), the compiler-generated copy constructor is usually sufficient.

Problems arise when the class manages raw dynamic memory.

---

### ❌ Misconception 3

> The compiler-generated copy constructor is always safe.

Incorrect.

It performs a shallow, member-wise copy, which may be unsafe for classes owning dynamic resources.

---

# Interview Questions

### Q1

What is a shallow copy?

**Answer**

A shallow copy copies member values directly. For pointer members, it copies only the address, not the data.

---

### Q2

Why is shallow copy dangerous?

**Answer**

Multiple objects end up sharing the same dynamically allocated memory, which can lead to double deletion, dangling pointers, and other resource-management bugs.

---

### Q3

When is the compiler-generated copy constructor not sufficient?

**Answer**

When a class manages resources like dynamically allocated memory, file handles, sockets, or other ownership-based resources.

---

# Important Connection with Our Student Project ⭐

Right now, our `Student` class contains:

```cpp id="jlwmsh12"
string name;
int age;
```

The compiler-generated copy constructor works fine.

Later, if we change it to:

```cpp id="jlwmsh13"
int* marks;
```

the default copy constructor will perform a **shallow copy**, causing both students to point to the same heap memory.

This is the motivation for writing a **user-defined copy constructor** (and eventually learning about **deep copy**).

---

## 📌 One Important Clarification

This module is **closely tied to pointers and dynamic memory**.

Without seeing actual code and memory diagrams, terms like:

* Shallow Copy
* Double Deletion
* Dangling Pointer
* Memory Leak

can feel abstract.