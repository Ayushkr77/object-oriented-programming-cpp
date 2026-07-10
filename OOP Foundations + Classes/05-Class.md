
# Module 5: Class

## 🎯 Deliverable

By the end of this module, you should be able to answer:

* What is a class?
* Why do we need classes?
* What is the syntax of a class?
* Does a class occupy memory?
* What is the blueprint concept?
* What are access specifiers?

---

# 1. What is a Class?

## Definition

A **class** is a **user-defined data type** that acts as a **blueprint or template** for creating objects. It groups **data (variables)** and **functions (methods)** into a single unit.

### Key Points

* A class is a **template**, not a real object.
* It defines **what an object will have** (data) and **what it can do** (functions).
* Objects are created using a class.

---

# 2. Why Do We Need Classes?

Imagine you're building a **Student Management System**.

Without classes:

```text
Student1_Name
Student1_Age
Student1_Marks

Student2_Name
Student2_Age
Student2_Marks

Student3_Name
Student3_Age
Student3_Marks
```

This quickly becomes repetitive and difficult to manage.

Instead, define the structure once:

```text
Student

↓

Name

Age

Marks

display()

calculatePercentage()
```

Now create as many students (objects) as needed from the same class.

This improves:

* Organization
* Reusability
* Maintainability

---

# 3. Syntax of a Class

```cpp
class Student
{
public:
    string name;
    int age;

    void display()
    {
        cout << name << " " << age;
    }
};
```

### Breakdown

```cpp
class Student
```

* `class` → Keyword used to define a class.
* `Student` → Name of the class.

```cpp
{
```

Start of the class body.

```cpp
public:
```

Access specifier.

Members under `public` are accessible from outside the class.

(More on this shortly.)

```cpp
string name;
int age;
```

These are **data members** (attributes).

They store information about a student.

```cpp
void display()
{
    cout << name << " " << age;
}
```

This is a **member function** (method).

It defines the behavior of the class.

```cpp
};
```

Every class definition **must end with a semicolon (`;`)**.

This is a common beginner mistake.

---

# 4. Memory of a Class

## Does a Class Occupy Memory?

**No.**

A class is only a **blueprint**.

It defines the structure of objects.

Memory is allocated **only when objects are created**.

### Example

```cpp
class Student
{
public:
    string name;
    int age;
};
```

At this point:

```text
Memory Used = 0 bytes (for objects)
```

No object exists yet.

Now:

```cpp
Student s1;
Student s2;
```

Memory is allocated for `s1` and `s2`.

### Important Rule

> **Class → No object memory allocated.**  
> **Object → Memory allocated.**

---

# 5. Blueprint Concept

## Real-Life Analogy: House Blueprint

Before building a house, an architect creates a blueprint.

The blueprint contains:

* Number of rooms
* Kitchen
* Doors
* Windows

But can you live inside the blueprint?

❌ No.

It's only a design.

When you build the actual house:

✅ Now it exists physically.

Similarly:

```text
Class
↓
Blueprint
↓
Objects
↓
Actual Houses
```

### Another Example: Car Factory

The factory has one design.

From that design, it manufactures thousands of cars.

```text
Car Class
↓
Car1
Car2
Car3
Car1000
```

One class can create many objects.

---

# 6. Access Specifiers (Overview)

Access specifiers control **who can access the members of a class**.

There are three access specifiers in C++:

| Access Specifier | Accessible From Outside the Class? |
| ---------------- | ---------------------------------- |
| `public` | ✅ Yes |
| `private` | ❌ No |
| `protected` | ⚠️ Used mainly with inheritance |

We'll study each one in detail later.

## Example

```cpp
class Student
{
public:
    string name;

private:
    int marks;
};
```

Here:

* `name` can be accessed from outside the class.
* `marks` cannot be accessed directly from outside the class.

This helps protect data.

---

# Summary

```text
Class
↓
Blueprint
↓
Contains
├── Data Members
└── Member Functions
↓
Used to Create
↓
Objects
```

---

# Common Beginner Mistakes

### ❌ Thinking a class is an object

A class is only a blueprint.

Objects are created from it.

### ❌ Forgetting the semicolon

Wrong:

```cpp
class Student
{
}
```

Correct:

```cpp
class Student
{
};
```

### ❌ Thinking a class occupies memory

Memory is allocated for **objects**, not for the class itself.

---

# Interview Questions

### 1. What is a class?

> A class is a user-defined data type that acts as a blueprint for creating objects. It groups data members and member functions into a single unit.

### 2. Why do we need classes?

> Classes help organize related data and functions together, making code reusable, maintainable, and easier to model real-world entities.

### 3. Does a class occupy memory?

> No. A class itself does not allocate memory for objects. Memory is allocated only when objects of the class are created.

### 4. Why is a class called a blueprint?

> Because it defines the structure and behavior of objects but does not create them. Objects are the actual instances created from the class.

---

## 💡 One Important Clarification

You may hear someone say:

> **"A class does not occupy memory."**

This is **conceptually true** for interview purposes, meaning a class definition by itself doesn't create storage for object data.

However, technically:

- The **class definition** exists in the compiled program as type information.
- **Static data members** (which you'll learn later) are stored separately and do occupy memory even without creating an object.

So the more precise statement is:

> **Non-static data members occupy memory only when an object is created.**

For now, remember the interview-friendly version:

> **Class = Blueprint (no object memory). Objects = Actual instances (memory allocated).**

