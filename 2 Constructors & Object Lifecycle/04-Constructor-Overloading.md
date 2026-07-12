Perfect. Now we've reached one of the most important constructor topics.

You already know:

* **Default Constructor** → Create objects with default values.
* **Parameterized Constructor** → Create objects with user-provided values.

Now the question is:

> **"Can a class have both?"**

The answer is **yes**, and that's called **Constructor Overloading**.

---

# Module 4: Constructor Overloading

## 🎯 Objective

By the end of this module, you should be able to answer:

* What is constructor overloading?
* Why do we need multiple constructors?
* How does the compiler choose which one to call?
* What are valid and invalid constructor signatures?

---

# 1. What is Constructor Overloading?

## Definition

**Constructor Overloading** means having **multiple constructors in the same class with different parameter lists (signatures).**

Each constructor provides a different way to create an object.

---

### ⭐ Notebook Definition

> **Constructor Overloading:** Defining multiple constructors in the same class with different parameter lists to initialize objects in different ways.

---

# 2. Why Do We Need It?

Imagine our `Student` class.

Sometimes we know **nothing** about the student:

```cpp id="7vwe4n"
Student s1;
```

Sometimes we know only the name:

```cpp id="ab56q0"
Student s2("Ayush");
```

Sometimes we know both name and age:

```cpp id="axlz3w"
Student s3("Ayush", 23);
```

Should we create three different classes?

❌ No.

Instead, we create **multiple constructors**.

---

# 3. Multiple Ways of Object Initialization

Suppose our class has:

```cpp id="f8xhgf"
Student()
```

```cpp id="pb6uqq"
Student(string name)
```

```cpp id="3m2epx"
Student(string name, int age)
```

Now all these are valid:

```cpp id="0gyh6h"
Student s1;

Student s2("Ayush");

Student s3("Ayush", 23);
```

Same class.

Three different ways to create an object.

---

# 4. Function Signature Rules

How does the compiler know which constructor to call?

It looks at the **function signature**.

A constructor's signature is determined by:

* Number of parameters
* Types of parameters
* Order of parameters

---

### Valid Overloading

```cpp id="jlwmmb"
Student()

Student(string name)

Student(string name, int age)

Student(int age)
```

All have different signatures.

---

### Invalid Overloading

```cpp id="ewhthe"
Student()

Student()
```

Same signature.

Compilation error.

---

Another invalid example:

```cpp id="6tn4vc"
Student(int age)

Student(int marks)
```

Still invalid.

Why?

Because parameter **names** don't matter.

Only the **types and order** matter.

Both signatures are:

```text id="twl0sk"
Student(int)
```

---

# 5. Choosing the Appropriate Constructor

Suppose we have:

```cpp id="l0m3kk"
Student()

Student(string)

Student(string, int)
```

Now:

```cpp id="s2w7aq"
Student s1;
```

Compiler chooses:

```cpp id="jlwmyt"
Student()
```

---

```cpp id="bltgor"
Student s2("Ayush");
```

Compiler chooses:

```cpp id="jlwmzo"
Student(string)
```

---

```cpp id="a0gtdv"
Student s3("Ayush", 23);
```

Compiler chooses:

```cpp id="jlwmzp"
Student(string, int)
```

The compiler simply matches the constructor whose parameter list best fits the arguments provided.

---

# Internal Working

Suppose:

```cpp id="0w8n8i"
Student s3("Ayush", 23);
```

Conceptually:

```text id="5n9th2"
Object Created

↓

Arguments Checked

↓

Best Matching Constructor Found

↓

Constructor Runs

↓

Object Ready
```

---

# Real-Life Analogy

Imagine ordering coffee.

The café offers:

```text id="bm8jxg"
Coffee()

Coffee(Size)

Coffee(Size, Sugar)
```

Now:

```text id="jlwmzq"
Coffee()
```

→ Default coffee

---

```text id="jlwmzr"
Coffee("Large")
```

→ Large coffee

---

```text id="jlwmzs"
Coffee("Large", 2)
```

→ Large coffee with 2 spoons of sugar

Same product.

Different ways to order it.

---

# Function Overloading

## Definition

**Function Overloading** means defining multiple functions with the same name but different parameter lists (signatures).

## Example

```cpp
class Calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    double add(double a, double b)
    {
        return a + b;
    }

    int add(int a, int b, int c)
    {
        return a + b + c;
    }
};
```

```cpp
Calculator c;

c.add(2, 3);        // Calls add(int, int)
c.add(2.5, 3.5);    // Calls add(double, double)
c.add(1, 2, 3);     // Calls add(int, int, int)
```

## Important Rule

Function overloading depends on the function signature, which includes:

* ✅ Number of parameters
* ✅ Types of parameters
* ✅ Order of parameters

It does not depend on:

* ❌ Return type
* ❌ Parameter names

## Invalid Example (Return Type Alone)

```cpp
int sum(int a, int b)
{
    return a + b;
}

double sum(int a, int b)
{
    return a + b;
}
```

❌ Error: Both functions have the same signature `sum(int, int)`. The compiler cannot distinguish them based only on the return type.

---

# Function Overloading vs Constructor Overloading

| Function Overloading                                                              | Constructor Overloading                         |
| ------------------------------------------------------------------------------------ | -------------------------------------------------- |
| Multiple functions with same name but different signatures                        | Multiple constructors with different signatures |
| Can have different return types? ❌ Return type alone cannot distinguish overloads | Constructors have no return type                |
| Called manually                                                                   | Called automatically during object creation     |

---

# Common Misconceptions

### ❌ Misconception 1

> Constructor names must be different.

Incorrect.

All constructors have the **same name** as the class.

Only their **parameter lists** differ.

---

### ❌ Misconception 2

> Parameter names make constructors different.

Incorrect.

```cpp id="jlwmzt"
Student(int age)

Student(int marks)
```

Same signature.

Compilation error.

---

### ❌ Misconception 3

> Return type can distinguish overloaded constructors.

Incorrect.

Constructors **never have a return type**.

---

# Interview Questions

### Q1

What is constructor overloading?

**Answer**

Defining multiple constructors in the same class with different parameter lists to provide multiple ways of initializing objects.

---

### Q2

How does the compiler decide which constructor to call?

**Answer**

It matches the arguments provided during object creation with the constructor whose parameter list (signature) best matches.

---

### Q3

Can we overload constructors?

**Answer**

✅ Yes.

As long as their parameter lists are different.

---

### Q4

Can two constructors differ only in parameter names?

Example:

```cpp id="jlwmzu"
Student(int age);

Student(int marks);
```

**Answer**

❌ No.

Parameter names are ignored.

Both have the same signature.

---

### Q5

Can we have both a default constructor and a parameterized constructor?

**Answer**

✅ Yes.

This is one of the most common examples of constructor overloading.

---

# Important Connection with Our Student Project ⭐

Soon, our `Student` class may have:

```cpp id="jlwmzv"
Student()

Student(string name)

Student(string name, int age)
```

Then we can create students in different ways:

```cpp id="jlwmzw"
Student s1;

Student s2("Ayush");

Student s3("Ayush", 23);
```

This is much more flexible than forcing every object to be created in the same way.

---

## 📌 One Important Clarification

Notice what constructor overloading is really doing.

It's **not** creating different kinds of objects.

Every object is still a `Student`.

The only difference is **how much information is available at the time of creation**.

That's why constructor overloading exists—to let users of the class create objects conveniently based on the data they have available.