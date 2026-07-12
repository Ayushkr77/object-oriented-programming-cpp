Excellent. Before learning **parameterized constructors**, we first need to master the **default constructor** because it's the foundation for everything that follows.

---

# Module 2: Default Constructor

## 🎯 Objective

By the end of this module, you should be able to answer:

* What is a default constructor?
* Who creates it?
* When is it called?
* Why does the compiler generate one?
* Can there be multiple default constructors?

---

# 1. What is a Default Constructor?

## Definition

A **default constructor** is a constructor that **can be called without passing any arguments**.

The simplest form is:

```cpp
Student()
{
}
```

Notice:

* Same name as the class.
* No return type.
* No parameters.

---

### ⭐ Notebook Definition

> **Default Constructor:** A constructor that can be invoked without any arguments.

**Notice I said "can be invoked without any arguments", not "has no parameters".**

This distinction becomes important later.

---

## Default Constructor (Precise Definition)

**Definition:**

A default constructor is a constructor that can be called without passing any arguments.

**Example 1 (No parameters):**

```cpp
Student()
{
}
```

```cpp
Student s1;   // ✔ No arguments passed
```

**Example 2 (Has parameter, but default value):**

```cpp
Student(int age = 18)
{
}
```

```cpp
Student s1;    // ✔ Calls Student(18)
Student s2(25);
```

**Key Point:** A default constructor doesn't necessarily have zero parameters. It just needs to be callable without arguments.

---

## Parameters vs Arguments

**Parameter:** Variable declared in the function/constructor definition.

**Argument:** Actual value passed during the function/constructor call.

Example:

```cpp
void setAge(int age)   // age → Parameter
{
}

setAge(23);            // 23 → Argument
```

**Easy Trick:**

* Function Definition → Parameters
* Function Call → Arguments

---

# 2. Why Do We Need a Default Constructor?

Imagine writing:

```cpp
Student s1;
```

No information is provided about the student.

But the object still needs to be initialized.

The default constructor tells the compiler:

> "Whenever someone creates an object without giving any data, initialize it in a default way."

For example:

```text
Name = Unknown
Age = 0
```

instead of leaving the object partially initialized.

---

# 3. Compiler-Generated Default Constructor

Suppose you write:

```cpp
class Student
{
private:
    string name;
    int age;
};
```

No constructor.

Now create:

```cpp
Student s1;
```

Question:

Who calls the constructor?

You never wrote one.

---

### Answer

The **compiler automatically generates** a default constructor.

Conceptually, it behaves like:

```cpp
Student()
{
}
```

You never see it,

but the compiler creates it for you.

---

## Important Clarification

The compiler-generated constructor is **not magical**.

It simply exists so object creation is valid.

It does **not** automatically assign meaningful values like:

```text
Name = "Unknown"
Age = 18
```

It only performs default initialization according to the rules of each member.

---

# 4. User-Defined Default Constructor

Instead of relying on the compiler,

we can write our own.

Example:

```cpp
Student()
{
    name = "Unknown";
    age = 0;
}
```

Now every object starts with predictable values.

Instead of

```text
Name :

Age : garbage
```

we get

```text
Name : Unknown

Age : 0
```

---

# 5. Compiler-Generated vs User-Defined

| Compiler-Generated                                            | User-Defined                                  |
| --------------------------------------------------------------- | ------------------------------------------------ |
| Created automatically                                         | Written by the programmer                     |
| Runs automatically                                            | Runs automatically                            |
| Usually performs only default initialization                  | Can initialize members with meaningful values |
| Exists only if you don't define constructors that suppress it | Gives full control over initialization        |

---

# 6. When is the Default Constructor Called?

Suppose:

```cpp
Student s1;
```

Immediately after object creation.

Conceptually:

```text
Memory Allocated

↓

Default Constructor Runs

↓

Object Ready
```

You never call it manually.

---

# 7. Multiple Objects

Suppose

```cpp
Student s1;
Student s2;
Student s3;
```

How many times does the constructor run?

Answer:

Three times.

Once for each object.

Conceptually:

```text
Create s1

↓

Constructor Runs

-------------------

Create s2

↓

Constructor Runs

-------------------

Create s3

↓

Constructor Runs
```

Every object gets initialized independently.

---

# 8. Memory Initialization

Suppose we have

```cpp
class Student
{
private:
    string name;
    int age;
};
```

and

```cpp
Student s1;
```

Memory:

```text
s1

-------------

name

age

-------------
```

If we write

```cpp
Student()
{
    name = "Unknown";
    age = 18;
}
```

Then immediately after creation:

```text
s1

-------------

name = Unknown

age = 18

-------------
```

The object is now ready for use.

---

# Internal Working

Without User-Defined Constructor

```text
Student s1;

↓

Compiler Generates Default Constructor

↓

Object Created
```

---

With User-Defined Constructor

```text
Student s1;

↓

Your Constructor Runs

↓

Members Initialized

↓

Object Ready
```

---

# Common Misconceptions

### ❌ Misconception 1

> The compiler always creates a default constructor.

Incorrect.

The compiler generates one **only under certain conditions**.

We'll study the exact rules later when parameterized constructors are introduced.

---

### ❌ Misconception 2

> A compiler-generated constructor initializes everything to zero.

Incorrect.

It performs **default initialization**, which depends on the type of each member.

---

### ❌ Misconception 3

> Constructors have to be called manually.

Incorrect.

They are invoked automatically when an object is created.

---

# Interview Questions

---

### Q1

What is a default constructor?

**Answer**

A constructor that can be called without any arguments.

---

### Q2

When does the compiler generate a default constructor?

**Answer**

When the class does not have a user-defined constructor that prevents the compiler from generating one. (We'll refine the exact rule after learning parameterized constructors.)

---

### Q3

When is the default constructor called?

**Answer**

Automatically whenever an object is created without constructor arguments.

---

### Q4

Can we have multiple default constructors?

**Answer**

❌ No.

A class can have only one constructor that can be called with no arguments.

For example:

```cpp
Student();
Student();
```

is invalid because the signatures are identical.

---

### Q5

How many times is the default constructor called?

**Answer**

Once for every object created.

---

# ⭐ Important Connection with Our Student Project

Remember this:

```cpp
Student s1;
```

Currently, your object is created, and later you manually call:

```cpp
s1.registerStudent();
```

Soon, we'll write:

```cpp
Student()
{
    studentCount++;
    name = "Unknown";
    age = 0;
}
```

Then simply writing:

```cpp
Student s1;
```

will automatically:

1. Increase `studentCount`.
2. Initialize `name`.
3. Initialize `age`.

No extra function calls.

That's the real power of constructors.

---

## 📌 One Small Correction to a Common Statement

Many books define a default constructor as:

> **"A constructor with no parameters."**

That's a simplification.

The more accurate definition is:

> **"A constructor that can be called without any arguments."**

You'll see why this wording matters when we discuss **default arguments** and **constructor overloading** later. Keeping this precise definition now will prevent confusion in future modules.