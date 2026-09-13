# Presentation 3 & Defense: Top 10 Viva Questions & Answers

**Course:** CSE 303 – Compiler Design &bull; Military Institute of Science and Technology (MIST)  
**Project:** LLVM Kaleidoscope Compiler Implementation  
**Presenters:**  
- **Md. Akhlak Ud Jaman** *(ID: 202414015)*  
- **Zubaer Islam Rafi** *(ID: 202414022)*  

---

## Part 1: Front-End & Semantic Questions (Speaker 1: Md. Akhlak Ud Jaman)

### 1. What does your Lexer do?
- **Examiner's Intent:** Verify understanding of character scanning and tokenization.
- **English Answer:**  
  > *"Our Lexer takes raw source code from standard input, skips whitespace and comments, and converts characters into discrete tokens such as keywords, numbers, identifiers, and operators. We recognize 13 distinct token types, converting numeric strings into IEEE-754 64-bit floating-point values."*
- **বাংলা অর্থ ও ব্যাখ্যা:** লেক্সার ক্যারেক্টারগুলোকে স্ক্যান করে স্পেস আর কমেন্ট বাদ দেয় এবং কোডকে ছোট ছোট অর্থপূর্ণ টোকেনে (কীওয়ার্ড, সংখ্যা, ভেরিয়েবল, অপারেটর) রূপান্তর করে।

---

### 2. What is Operator Precedence Climbing and why did you use it?
- **Examiner's Intent:** Verify how the parser solves operator precedence and associativity without backtracking.
- **English Answer:**  
  > *"Operator precedence climbing is an efficient $\mathcal{O}(N)$ algorithm used by our parser to resolve binary arithmetic expressions in correct mathematical order. For example, in `4 + 2 * 3`, multiplication has a higher precedence (40) than addition (20), so the climber groups and evaluates `2 * 3` before addition without backtracking."*
- **বাংলা অর্থ ও ব্যাখ্যা:** যোগ ও গুণের মধ্যে গুণের কাজ আগে করানোর জন্য পার্সার এই অ্যালগরিদম ব্যবহার করে। এতে রিকার্সিভ ডিসেন্টে কোনো ব্যাকট্র্যাকিং ছাড়াই সঠিক অর্ডারে AST তৈরি হয়।

---

### 3. What is an Abstract Syntax Tree (AST)?
- **Examiner's Intent:** Verify OOP hierarchy and memory ownership.
- **English Answer:**  
  > *"An AST is a hierarchical in-memory tree representation of the syntactic structure of the program. In our project, each syntax construct inherits from the polymorphic base class `ExprAST`, and node ownership is strictly managed using modern C++ `std::unique_ptr` to ensure zero memory leaks via RAII."*
- **বাংলা অর্থ ও ব্যাখ্যা:** কোডের গ্রামার এবং স্ট্রাকচারকে মেমোরিতে একটি গাছের মতো সাজিয়ে রাখাই হলো AST। আমরা স্মার্ট পয়েন্টার (`std::unique_ptr`) দিয়ে মেমোরি ম্যানেজ করেছি যাতে মেমোরি লিক না হয়।

---

### 4. How does your compiler handle Semantic Analysis?
- **Examiner's Intent:** Verify scoping, symbol table, and prototype arity validation.
- **English Answer:**  
  > *"We enforce semantic rules using a scoped symbol table called `NamedValues`. It tracks visible parameter bindings in the local function scope, halts compilation if an undeclared identifier is referenced, and validates function call arity to prevent argument count mismatches."*
- **বাংলা অর্থ ও ব্যাখ্যা:** `NamedValues` সিম্বল টেবিল চেক করে কোনো ভেরিয়েবল আগে ডিক্লেয়ার না করে ব্যবহার করা হয়েছে কিনা, কিংবা ফাংশন কলে আর্গুমেন্ট ভুল সংখ্যায় দেওয়া হয়েছে কিনা।

---

## Part 2: Backend, IR, Target Machine & Testing (Speaker 2: Zubaer Islam Rafi)

### 5. What is LLVM and why did you use it?
- **Examiner's Intent:** Understand the choice of backend framework.
- **English Answer:**  
  > *"LLVM is an industrial-strength compiler backend infrastructure. By emitting LLVM Intermediate Representation using `llvm::IRBuilder`, we gain access to LLVM's powerful target-independent optimizations, function verification passes, and native code generation for diverse CPU architectures like x86 and ARM."*
- **বাংলা অর্থ ও ব্যাখ্যা:** LLVM হলো একটি আধুনিক কম্পাইলার ব্যাক-এন্ড। আমরা LLVM IR তৈরি করি, আর LLVM স্বয়ংক্রিয়ভাবে অপ্টিমাইজ করে যেকোনো আর্কিটেকচারের জন্য মেশিন কোড তৈরি করে দেয়।

---

### 6. What is Static Single Assignment (SSA) form?
- **Examiner's Intent:** Verify knowledge of modern intermediate representation invariants.
- **English Answer:**  
  > *"In Static Single Assignment (SSA) form, every virtual register is assigned a value exactly once and remains immutable. Control flow joins are resolved using phi nodes. This simplifies optimization and guarantees explicit, unambiguous dataflow."*
- **বাংলা অর্থ ও ব্যাখ্যা:** SSA ফর্মে প্রতিটি ভার্চুয়াল রেজিস্টারে মান কেবল একবারই লেখা হয়। বারবার ওভাররাইট না হওয়ায় ডাটাফ্লো এবং অপ্টিমাইজেশন খুব সহজ হয়।

---

### 7. Explain the Quadruple Rule with an example.
- **Examiner's Intent:** Verify intermediate code representation knowledge.
- **English Answer:**  
  > *"A Quadruple is a four-field tuple: `(Operator, Argument 1, Argument 2, Result)`. For example, `a + b` translates to `(ADD, a, b, %addtmp)`, which directly maps to the LLVM instruction `fadd double %a, %b`."*
- **বাংলা অর্থ ও ব্যাখ্যা:** কোয়াড্রাপলে চারটি অংশ থাকে: অপারেটর, দুটি ইনপুট আর্গুমেন্ট এবং আউটপুট রেজাল্ট। যেমন `(ADD, a, b, %addtmp)`।

---

### 8. Why do you segregate standard output and standard error?
- **Examiner's Intent:** Verify runtime cleanliness and piping capabilities.
- **English Answer:**  
  > *"We separate channels so that user interactive prompts and calculation results go exclusively to `stdout`, while internal LLVM bytecode, Quadruple traces, and compiler diagnostics go to `stderr`. This ensures clean data piping without metadata corruption."*
- **বাংলা অর্থ ও ব্যাখ্যা:** ইউজারের উত্তরের সাথে যাতে কম্পাইলারের ভেতরের কোড বা এরর মেসেজ মিশে না যায়, সেজন্য `stdout` এবং `stderr` আলাদা রাখা হয়েছে।

---

### 9. How did you test your compiler?
- **Examiner's Intent:** Verify regression testing and quality assurance metrics.
- **English Answer:**  
  > *"We executed 150 automated regression test suites covering operator precedence, recursion like Fibonacci, foreign C library linking (`sin`, `cos`), and syntax error injection. Our compiler achieved a 100% pass rate with zero crashes and zero memory leaks."*
- **বাংলা অর্থ ও ব্যাখ্যা:** আমরা ১৫০টি অটোমেটেড টেস্ট কেস চালিয়েছি—সবগুলোতে পাস করেছে এবং কোনো ক্র্যাশ বা মেমোরি লিক ঘটেনি।

---

### 10. What are the limitations of your compiler?
- **Examiner's Intent:** Critical self-evaluation and future roadmap awareness.
- **English Answer:**  
  > *"Currently, our language supports only 64-bit floating-point numbers without integer or string types. It also uses a flat symbol table without nested block shadowing and lacks aggregate structures like arrays. In future work, we plan to implement multi-type inference and stack-allocated mutable variables via LLVM's `mem2reg`."*
- **বাংলা অর্থ ও ব্যাখ্যা:** বর্তমান সীমাবদ্ধতা হলো শুধুমাত্র float সংখ্যা সমর্থন করে (int বা string নেই) এবং অ্যারে নেই। ভবিষ্যতে টাইপ ইনফারেন্স ও লোকাল মিউটেবল ভেরিয়েবল যুক্ত করার পরিকল্পনা রয়েছে।
