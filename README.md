# Machine Code Generation 

---

## 🎯 Aim

To develop a compiler phase that converts a given infix arithmetic expression into:
1. Postfix notation (Reverse Polish Notation),
2. Quadruples (Intermediate Code Representation),
3. Three-Address / Machine Code.

---

## 🧠 Explanation

This program simulates the backend phase of a compiler, which is responsible for generating intermediate and target code from a high-level expression. It performs:

- **Conversion from infix to postfix** using operator precedence and a stack.
- **Generation of quadruples**, a standard intermediate representation in compilers using temporary variables.
- **Creation of Three-Address Code (TAC)** or **Machine code-like instructions** for arithmetic operations.

This process mirrors how a real compiler breaks down high-level arithmetic into machine-executable code.

---

## 🔁 Logic

### Step-by-step Process:
1. **Infix to Postfix Conversion**:
   - Use a stack to manage operators and apply precedence rules to form the postfix expression.

2. **Quadruple Generation**:
   - Traverse the postfix expression.
   - For each operator, pop the top two operands, apply the operation, and store the result in a temporary variable `t1, t2...`.

3. **Three-Address Code (TAC) / Machine Code Generation**:
   - For each operation, generate equivalent low-level instructions:
     - Use `MOV`, `ADD`, `MUL`, and `POW` instructions for computation.
     - Results are stored in temporaries and finally assigned to a variable `a`.

---

## 📥 Sample Input & Output

### ✅ Input
```cpp
Input an expression: a+b*c
```

### 🔁 Output
```cpp
Postfix Expression: abc*+

Quadruples:
(+, a, t1, t2)
(*, b, c, t1)

Three-Address Code/Machine Code:
MOV b, R0
MUL c, R0
MOV R0, t1
MOV a, R0
ADD t1, R0
MOV R0, t2
MOV t2, a
```

---

## 🌐 Real-World Applications

- **Compiler Construction**: Forms the core of backend phases in compilers like GCC or Clang.
- **Virtual Machines**: Used in interpreters like Python (CPython) or JVM to generate bytecode.
- **Code Optimisation Tools**: Intermediate representations, such as quadruples, are used for optimisation passes.
- **Static Analysis Tools**: These tools utilise such representations to detect bugs, inefficiencies, or vulnerabilities.

---



