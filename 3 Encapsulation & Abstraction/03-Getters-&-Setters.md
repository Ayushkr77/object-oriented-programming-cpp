# Module 3: Getters & Setters

## 🎯 Objective

By the end of this module, you should understand:

* What getter functions are.
* What setter functions are.
* Why variables should not usually be made public.
* How setters perform validation.
* What read-only and write-only properties are.
* Best practices for using getters and setters.

---

# 1. What are Getter Functions?

## Definition

A **Getter** is a **public member function used to read (access) the value of a private data member.**

### ⭐ Notebook Definition

> **Getter:** A public member function that returns the value of a private data member.

---

Example:

```cpp
class Student
{
private:
    string name;

public:

    string getName()
    {
        return name;
    }
};
```

Usage:

```cpp
Student s;

cout << s.getName();
```

Instead of accessing:

```cpp
cout << s.name;      // ❌ Error
```

---

# 2. What are Setter Functions?

## Definition

A **Setter** is a **public member function used to update the value of a private data member.**

### ⭐ Notebook Definition

> **Setter:** A public member function that modifies the value of a private data member.

---

Example:

```cpp
class Student
{
private:
    int age;

public:

    void setAge(int age)
    {
        this->age = age;
    }
};
```

Usage:

```cpp
Student s;

s.setAge(23);
```

Instead of:

```cpp
s.age = 23;      // ❌ Error
```

---

# 3. Why not Make Variables Public?

Suppose:

```cpp
class Student
{
public:
    int age;
};
```

Now anyone can write:

```cpp
Student s;

s.age = -50;
```

The object enters an invalid state.

Using private variables:

```cpp
private:
    int age;
```

and

```cpp
void setAge(int age)
{
    if(age >= 0)
        this->age = age;
}
```

prevents invalid values.

---

# 4. Validation using Setters

One of the biggest advantages of setters is validation.

Example:

```cpp
void setMarks(int marks)
{
    if(marks >= 0 && marks <= 100)
        this->marks = marks;
}
```

Invalid values are rejected.

Similarly,

```cpp
void setSalary(double salary)
{
    if(salary >= 0)
        this->salary = salary;
}
```

The object always remains valid.

---

# Internal Working

Suppose we have:

```cpp
Student s;
```

Without setters:

```text
Outside Code

↓

Private Data

(No Validation)
```

With setters:

```text
Outside Code

↓

Setter Function

↓

Validation

↓

Private Data Updated
```

---

# 5. Read-only Properties

Sometimes users should **only read** a value, not modify it.

Example:

```cpp
class Employee
{
private:
    int employeeId;

public:

    int getEmployeeId()
    {
        return employeeId;
    }
};
```

No setter is provided.

The property becomes **read-only**.

Users can view it but cannot change it.

---

# 6. Write-only Properties

Sometimes users should **only write** a value.

Example:

```cpp
class Account
{
private:
    string password;

public:

    void setPassword(string password)
    {
        this->password = password;
    }
};
```

No getter is provided.

The password can be updated but not read.

Although possible, **write-only properties are uncommon** in practice.

---

# 7. Best Practices

### ✅ Keep data members private.

```cpp
private:
    int age;
```

---

### ✅ Validate input inside setters.

```cpp
if(age >= 0)
```

---

### ✅ Don't create setters unnecessarily.

If a value should never change,

don't provide a setter.

---

### ✅ Don't expose sensitive information.

For example,

avoid getters for:

* Passwords
* Secret Keys
* PINs

---

### ✅ Getters should not modify object data.

They should simply return information.

---

# Real-world Example

## Bank Account

```text
Private

Balance

Public

deposit()

withdraw()

getBalance()
```

Notice:

There is **no**

```cpp
setBalance()
```

Otherwise anyone could write:

```cpp
account.setBalance(1000000);
```

which breaks the logic of the application.

---

# Common Misconceptions

### ❌ Misconception 1

> Every private variable must have a getter and a setter.

Incorrect.

Only provide them when needed.

---

### ❌ Misconception 2

> Getters and setters automatically improve design.

Incorrect.

Poorly designed getters and setters can expose too much of the internal implementation.

---

### ❌ Misconception 3

> Getters can modify object data.

Incorrect.

A getter should only return information.

---

# Interview Questions

### Q1

Why do we use Getters and Setters?

**Answer**

To provide controlled access to private data members, allowing validation and protecting the object's state.

---

### Q2

Can every variable have a Setter?

**Answer**

Yes, but it is not always a good idea.

If a variable should never change after initialization (for example, an employee ID), a setter should not be provided.

---

### Q3

How do Setters improve data integrity?

**Answer**

Setters validate input before updating data, preventing invalid values and ensuring the object always remains in a valid state.

---

## 📌 One Important Clarification

Getters and setters are **tools**, not a requirement.

Many beginners think:

```text
Private Variable

↓

Always Create Getter

↓

Always Create Setter
```

This is **not** a rule.

A better approach is:

* Create a **getter** only if external code needs to read the value.
* Create a **setter** only if external code should be allowed to modify the value.
* If a value should never be modified or exposed, don't provide a setter or getter.

Good encapsulation is about exposing **only what is necessary**, not automatically creating getters and setters for every data member.