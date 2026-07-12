Excellent. This is the final major constructor-related topic for Day 2.

Think of a destructor as the **opposite of a constructor**.

* **Constructor** → Initializes an object when it's created.
* **Destructor** → Cleans up an object before it's destroyed.

---

# Module 9: Destructor

## 🎯 Objective

By the end of this module, you should understand:

* What a destructor is.
* Why we need it.
* When it is automatically called.
* What resource cleanup means.
* Compiler-generated destructors.

---

# 1. What is a Destructor?

## Definition

A **destructor** is a special member function that is **automatically called when an object is destroyed**.

Its main purpose is to **release resources and perform cleanup**.

### ⭐ Notebook Definition

> **Destructor:** A special member function that is automatically called when an object is destroyed to perform cleanup.

---

# 2. Syntax

```cpp id="xfjn8e"
class Student
{
public:
    ~Student()
    {
    }
};
```

Notice:

* Same name as the class.
* Prefixed with `~` (tilde).
* No return type.
* No parameters.

---

# 3. Automatic Invocation

Suppose:

```cpp id="hlnhh5"
int main()
{
    Student s1;
}
```

Conceptually:

```text id="p6t70k"
Create Object
      ↓
Constructor Runs
      ↓
Use Object
      ↓
Object Goes Out of Scope
      ↓
Destructor Runs Automatically
```

You never call it manually.

---

# 4. Resource Cleanup

Imagine your object owns resources like:

* Dynamic memory (`new`)
* File handles
* Network connections
* Database connections

When the object is destroyed, these resources should also be released.

Example:

```cpp id="6s1q5d"
delete ptr;
close(file);
close(connection);
```

This cleanup is typically done inside the destructor.

---

# 5. When is a Destructor Called?

### Local Object

```cpp id="pwxr3m"
int main()
{
    Student s1;
}
```

Destructor runs when `main()` ends.

---

### Heap Object

```cpp id="9lckb3"
Student* s1 = new Student();
```

Destructor runs when:

```cpp id="rjlwmx"
delete s1;
```

is executed.

---

### Global Object

```cpp id="jlwmxy"
Student s1;
```

Destructor runs when the program terminates.

---

# 6. Compiler-Generated Destructor

If you don't write a destructor,

the compiler automatically generates one.

Conceptually:

```cpp id="jlwmxz"
~Student()
{
}
```

For classes with simple members (like `int` and `std::string`), this is usually sufficient.

When managing resources manually (like raw pointers), you often need a user-defined destructor.

---

# Constructor vs Destructor

| Constructor                   | Destructor                      |
| -------------------------------- | ----------------------------------- |
| Called when object is created | Called when object is destroyed |
| Initializes object            | Cleans up object                |
| Same name as class            | Same name prefixed with `~`     |
| Can be overloaded             | Cannot be overloaded            |

---

# Internal Working

Suppose:

```cpp id="jlwmy0"
Student s1;
```

Conceptually:

```text id="jlwmy1"
Object Created
      ↓
Constructor Runs
      ↓
Object Used
      ↓
Scope Ends
      ↓
Destructor Runs
      ↓
Memory/Resources Released
```

---

# Common Misconceptions

### ❌ Misconception 1

> We must call the destructor manually.

Incorrect.

It is automatically invoked when the object's lifetime ends (or when `delete` is used for heap objects).

---

### ❌ Misconception 2

> Destructor deletes the object itself.

Not exactly.

The destructor performs cleanup.

The object's memory is then reclaimed according to how it was allocated.

---

### ❌ Misconception 3

> Every class must have a user-defined destructor.

Incorrect.

If the class doesn't manage resources manually, the compiler-generated destructor is usually enough.

---

# Interview Questions

### Q1

What is a destructor?

**Answer**

A special member function automatically called when an object is destroyed to perform cleanup.

---

### Q2

Why do we need destructors?

**Answer**

To release resources such as dynamically allocated memory, file handles, or network connections before an object is destroyed.

---

### Q3

Can a destructor be overloaded?

**Answer**

❌ No.

A class can have only **one** destructor because it takes no parameters.

---

### Q4

Can a destructor be virtual?

**Answer**

✅ Yes.

Virtual destructors are used in inheritance and polymorphism.

We'll study them in **Day 5**.

---

### Q5

When is a destructor called?

**Answer**

* Local object → When its scope ends.
* Heap object → When `delete` is called.
* Global object → When the program terminates.

---

# Important Connection with Our Student Project ⭐

Soon, we'll add:

```cpp id="jlwmy2"
~Student()
{
    cout << "Destructor Called\n";
}
```

Then we'll observe:

```cpp id="jlwmy3"
int main()
{
    Student s1;
    Student s2;
}
```

Output:

```text id="jlwmy4"
Constructor Called
Constructor Called

Destructor Called
Destructor Called
```

This will help you visualize the complete object lifecycle:

```text id="jlwmy5"
Object Created
      ↓
Constructor
      ↓
Object Used
      ↓
Destructor
      ↓
Object Destroyed
```

---

## 📌 One Important Clarification

A destructor **does not normally free stack memory directly**.

For a stack object:

```cpp id="jlwmy6"
Student s1;
```

the runtime automatically reclaims the stack memory when the scope ends. The destructor's job is to clean up any resources owned by the object **before** that memory is reclaimed.

For a heap object:

```cpp id="jlwmy7"
Student* s1 = new Student();
delete s1;
```

`delete` first calls the destructor to perform cleanup, and then releases the heap memory.

This distinction becomes much clearer when we implement destructors and work with dynamically allocated memory during the Day 2 coding session.