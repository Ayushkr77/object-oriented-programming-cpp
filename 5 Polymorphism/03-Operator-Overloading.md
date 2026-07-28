# Module 3: Operator Overloading

## 🎯 Objective

By the end of this module, you should understand:

* What Operator Overloading is.
* Why Operator Overloading is needed.
* Syntax of Operator Overloading.
* Overloading Unary Operators.
* Overloading Binary Operators.
* Member Function vs Friend Function.
* Operators that cannot be overloaded.
* Advantages and limitations of Operator Overloading.

---

# 1. What is Operator Overloading?

## Definition

**Operator Overloading** allows existing C++ operators to be given **new meanings for user-defined data types (classes and objects)**.

The operator itself remains the same,

but its behavior changes depending on the operands.

### ⭐ Notebook Definition

> **Operator Overloading:** A feature of Compile-Time Polymorphism that allows predefined operators to perform user-defined operations on objects.

---

# 2. Why do we need Operator Overloading?

Suppose we create a class

```cpp
class Complex
{
    int real;
    int imag;
};
```

Now create

```cpp
Complex c1, c2;
```

Can we write

```cpp
c1 + c2;
```

❌ No.

The compiler only knows how to add built-in data types.

It doesn't know what **adding two Complex numbers** means.

Without Operator Overloading,

we would have to write

```cpp
c3 = c1.add(c2);
```

or

```cpp
c3 = addComplex(c1, c2);
```

Instead,

we can overload

```cpp
+
```

and simply write

```cpp
c3 = c1 + c2;
```

which is much more natural and readable.

---

# 3. Real-Life Analogy

Suppose the symbol

```text
+
```

For integers,

```text
10 + 20

↓

30
```

For strings,

```text
"Hello" + "World"

↓

HelloWorld
```

The symbol is the same,

but the meaning changes depending on the operands.

Similarly,

for Complex Numbers,

```text
c1 + c2

↓

Add Real Parts

+

Add Imaginary Parts
```

Same operator.

Different implementation.

---

# 4. Syntax of Operator Overloading

General syntax

```cpp
returnType operator<operatorSymbol>(parameters)
{
    // implementation
}
```

Example

```cpp
Complex operator+(const Complex& other)
{
    Complex temp;

    temp.real = real + other.real;
    temp.imag = imag + other.imag;

    return temp;
}
```

Notice

```cpp
operator+
```

This is a special function name.

---

# 5. Types of Operator Overloading

Operators are mainly divided into two categories.

```text
            Operator Overloading
                    │
        ┌───────────┴───────────┐
        │                       │
Unary Operators          Binary Operators
```

---

# 6. Unary Operator Overloading

Unary operators operate on **one operand**.

Examples

```text
++

--

-

!

~
```

Example

```cpp
++obj;
```

Internally,

the compiler calls

```cpp
obj.operator++();
```

---

### Example

Suppose

```cpp
Counter c;

++c;
```

Instead of incrementing an integer,

we define what

```text
++
```

means for a `Counter` object.

---

# 7. Binary Operator Overloading

Binary operators operate on **two operands**.

Examples

```text
+

-

*

/

%

==


```

Example

```cpp
c1 + c2;
```

Internally,

the compiler converts it into

```cpp
c1.operator+(c2);
```

if implemented as a member function.

---

### Example

Complex Number

```cpp
Complex c3 = c1 + c2;
```

The compiler calls

```cpp
c1.operator+(c2);
```

which returns the resulting complex number.

---

# 8. Member Function vs Friend Function

Operator Overloading can be implemented in two ways.

---

## Member Function

Syntax

```cpp
class Complex
{
public:

    Complex operator+(const Complex& other)
    {
    }
};
```

Called as

```cpp
c1 + c2;
```

Internally

```cpp
c1.operator+(c2);
```

---

## Friend Function

Syntax

```cpp
class Complex
{
    friend Complex operator+(Complex, Complex);
};
```

Called as

```cpp
operator+(c1, c2);
```

The compiler internally translates

```cpp
c1 + c2;
```

to

```cpp
operator+(c1, c2);
```

---

# Member Function vs Friend Function

| Member Function                             | Friend Function                                |
| ---------------------------------------------- | -------------------------------------------------|
| Left operand must be an object of the class | Left operand may not be an object of the class |
| Accesses members using `this` pointer       | No `this` pointer                              |
| Simpler for unary operators                 | Useful for many binary operators               |
| Good when left operand belongs to the class | Good when left operand is not the class        |

---

# 9. Operators that Cannot be Overloaded

Not every operator in C++ can be overloaded.

The following operators **cannot** be overloaded.

| Operator | Purpose             |
| ---------- | ---------------------|
| `::`     | Scope Resolution    |
| `.`      | Member Access       |
| `.*`     | Pointer-to-member   |
| `?:`     | Ternary Conditional |
| `sizeof` | Size Operator       |
| `typeid` | Type Identification |

These operators have fixed meanings defined by the language.

Allowing them to be overloaded would make the language ambiguous and difficult to understand.

---

# 10. Internal Working

Suppose we write

```cpp
c1 + c2;
```

Compiler internally converts it to

```cpp
c1.operator+(c2);
```

if using a member function.

OR

```cpp
operator+(c1, c2);
```

if using a friend function.

Everything is resolved **during compilation**.

---

# Operator Overloading Flow

```text
Operator Used

↓

Compiler Finds Matching operator Function

↓

Calls Corresponding Function

↓

Returns Result
```

---

# 11. Operator Overloading vs Function Overloading

| Function Overloading      | Operator Overloading                                  |
| ---------------------------| ---------------------------------------------------------|
| Same function name        | Same operator                                         |
| Different parameter lists | Different object behavior                             |
| Compile-Time Polymorphism | Compile-Time Polymorphism                             |
| Uses normal functions     | Uses `operator` keyword                               |
| Improves code reuse       | Makes user-defined objects behave like built-in types |

---

# 12. Advantages

### 1. Improves Readability

Expressions become natural.

```cpp
c1 + c2;
```

instead of

```cpp
addComplex(c1, c2);
```

---

### 2. Makes Objects Behave Like Built-in Types

Objects can use familiar operators.

---

### 3. Code Reusability

One operator can work for user-defined objects.

---

### 4. Cleaner Syntax

Programs become easier to understand.

---

### 5. Compile-Time Resolution

No runtime overhead.

---

# 13. Limitations

* Cannot create new operators.
* Cannot change operator precedence.
* Cannot change operator associativity.
* Cannot overload every operator.
* Poorly designed overloading can reduce code readability.

---

# 14. Common Misconceptions

### ❌ Misconception 1

> Operator Overloading creates a new operator.

Incorrect.

It only changes the behavior of an existing operator for user-defined types.

---

### ❌ Misconception 2

> Every operator can be overloaded.

Incorrect.

Several operators such as `::`, `.`, `?:`, and `sizeof` cannot be overloaded.

---

### ❌ Misconception 3

> Operator Overloading changes operator precedence.

Incorrect.

Operator precedence and associativity are fixed by the C++ language.

---

### ❌ Misconception 4

> Operator Overloading is Runtime Polymorphism.

Incorrect.

It is **Compile-Time Polymorphism** because the compiler resolves the overloaded operator function during compilation.

---

# 15. Interview Questions

### Q1

What is Operator Overloading?

**Answer**

Operator Overloading allows predefined operators to perform user-defined operations on objects.

---

### Q2

Why is Operator Overloading useful?

**Answer**

It improves readability by allowing user-defined objects to behave like built-in data types, making expressions more intuitive and maintainable.

---

### Q3

Which operators cannot be overloaded?

**Answer**

* `::`
* `.`
* `.*`
* `?:`
* `sizeof`
* `typeid`

---

### Q4

Can we create a new operator using Operator Overloading?

**Answer**

No.

Operator Overloading only allows redefining the behavior of existing operators.

---

### Q5

Can Operator Overloading change operator precedence?

**Answer**

No.

Operator precedence and associativity are fixed by the language.

---

### Q6

When should we use a Friend Function instead of a Member Function?

**Answer**

Friend functions are useful when the left operand is not an object of the class or when symmetric access to private members of multiple objects is needed.

---

# 16. Key Takeaways

* Operator Overloading is a form of **Compile-Time Polymorphism**.
* It allows existing operators to work with user-defined objects.
* Operators can be overloaded using **member functions** or **friend functions**.
* Unary operators work on one operand, while binary operators work on two operands.
* Some operators (`::`, `.`, `?:`, `sizeof`, etc.) cannot be overloaded.
* Operator Overloading improves readability but should be used carefully to preserve intuitive behavior.

---

# Important Connection with Previous Module ⭐

In **Module 2**, we learned that **Function Overloading** allows multiple functions with the same name but different parameter lists.

Operator Overloading follows the same compile-time principle, but instead of overloading **function names**, we overload **operators**.

Both are examples of **Compile-Time Polymorphism**, where the compiler decides which implementation to invoke before the program executes.

---

## 📌 One Important Clarification

**Operator Overloading changes the behavior of operators only for user-defined types.**

It **does not** change how operators work for built-in types.

For example,

```cpp
10 + 20
```

will always perform integer addition.

Overloading `+` in a `Complex` class does not affect integer addition.