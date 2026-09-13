# Presentation 3: 4-Minute Defense Speech Script

**Course:** CSE 303 – Compiler Design &bull; Military Institute of Science and Technology (MIST)  
**Project:** Design and Development of the Kaleidoscope Compiler (LLVM-Based)  
**Slide Reference:** [`Presentation_3.pdf`](Presentation_3.pdf) *(16 Slides &bull; 15-Mark Rubric)*  
**Total Target Duration:** 4 Minutes *(2 Minutes per Speaker &bull; ~130 words per minute)*  

---

## Part 1: Front-End Design & Semantic Analysis
**Speaker 1:** Md. Akhlak Ud Jaman *(ID: 202414015)*  
**Allocated Time:** 0:00 – 2:00 *(~270 Words)*  
**Slides to Display:** Slide 1 to Slide 8  

Good morning, respected teachers and examiners. I am **Md. Akhlak Ud Jaman**, and together with my partner **Zubaer Islam Rafi**, we are presenting our compiler project for the **Kaleidoscope** language, built using the modern **LLVM** framework. Today, we will explain how our compiler takes raw source code and turns it into real, working machine instructions.

As shown in our **Pipeline Flowchart on Slide 3**, our compiler processes code through five clear, decoupled stages: Lexical Analysis, Parsing, AST construction, Semantic Validation, and LLVM Code Generation.

First, our **Lexer** reads the code character by character. It skips spaces and comments, and breaks the code into meaningful pieces called **tokens**. It recognizes keywords like `def` and `extern`, numbers, variable names, and math symbols. We support thirteen token types, and numbers are automatically converted into 64-bit floating-point values.

Next is the **Parser**. We built a recursive-descent parser with **operator precedence climbing**. This solves a common math problem: order of operations. In an expression like `4 + 2 * 3`, multiplication has a higher priority of 40, while addition has 20. Our parser easily groups `2 * 3` first before adding 4, without any confusion or slow backtracking.

The parser then builds the **Abstract Syntax Tree (AST)** in memory. We use clean C++ object-oriented design and modern smart pointers (`std::unique_ptr`). This ensures our program never leaks memory. 

Finally, our **Semantic Analysis** checks that the code makes sense before compiling. It uses a symbol table called `NamedValues` to remember variable names. If you use a variable that was never declared, or pass the wrong number of arguments to a function, the compiler stops and shows a clear error message instead of crashing. 

Now, my partner **Zubaer** will explain code generation, testing, and our live demonstration.

---

## Part 2: Code Generation, Testing & Demonstration
**Speaker 2:** Zubaer Islam Rafi *(ID: 202414022)*  
**Allocated Time:** 2:00 – 4:00 *(~270 Words)*  
**Slides to Display:** Slide 9 to Slide 17  

Thank you, Akhlak. Good morning, everyone. I am **Zubaer Islam Rafi**, and I will explain our back-end pipeline, testing, and live execution.

Once the syntax tree is verified, our compiler converts it into **LLVM Intermediate Representation (IR)** using `llvm::IRBuilder`. We follow the **Static Single Assignment (SSA)** rule, where every virtual register is assigned only once. We also strictly implement the academic **Quadruple Rule**, which breaks every operation into four parts: the operator, two inputs, and one result. For example, `a + b` becomes `(ADD, a, b, %addtmp)`, which turns into the LLVM instruction `fadd`.

For **Executable Generation**, our compiler configures the target machine for the host computer, such as x86-64. It organizes code into standard memory segments: machine code goes into the **Text Segment**, constants go into the **Data Segment**, and function parameters run on the **Stack**. We also keep our outputs clean: user answers appear on `stdout`, while compiler IR and diagnostic messages go to `stderr`.

For **Testing**, we built a four-tier error handling system that catches bad tokens, syntax mistakes, and invalid variables. We ran **150 automated test suites**, and our compiler achieved a **100% pass rate** with zero crashes and zero memory leaks.

In our **Live Demonstration**, you can type math directly into the interactive prompt. An expression like `4 + 2 * 3` evaluates immediately to `10.0`. We can also define functions like `average(a, b)` and run recursive Fibonacci. In addition, our compiler supports foreign function linking, so we can call external C math functions like `sin` and `cos` directly.

In conclusion, our compiler provides a complete, reliable translation pipeline from source code to native execution. Thank you very much for your time, and we are now happy to answer your questions.

---

## Quick Delivery Guide

| Time Window | Speaker | Key Topics | Slides |
| :--- | :--- | :--- | :--- |
| **0:00 – 2:00** | **Md. Akhlak Ud Jaman** | Introduction &bull; Pipeline Flowchart &bull; Lexer & Tokens &bull; Parser & Precedence &bull; Polymorphic AST &bull; Semantic Scoping | **Slides 1–8** |
| **2:00 – 4:00** | **Zubaer Islam Rafi** | LLVM SSA & Quadruples &bull; Target Memory Segments &bull; 4-Tier Testing (100% Pass) &bull; Live REPL & FFI &bull; Q&A | **Slides 9–17** |
