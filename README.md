# ceng444-spring2024
resource repository for ceng444 language processors course @metu, 2023-2024 spring.

## logistics

**schedule:** fridays, 14.40-17.30, BMB5  
**instructor:** Erkan İnan  
**TA:** Aslı Umay Öztürk  
**platform for discussions & announcements:** mail group 

! please email the TA if you cannot access the mail group.

**prerequisites:** ceng242, ceng280, and ceng331 knowledge is expected, but no official prerequisites.

## recommended textbooks
- *Compilers: Principles, Techniques and Tools (Second Edition) by Aho, A.V, Ullman J.D, Sethi R., Lam M.S.* (a.k.a. the Dragon Book)
- *Engineering a Compiler (Second Edition) by Cooper, K.D., Torczon, L.*

## topics
- **lexical analysis:** tokens, regular expressions, NFA – DFA generators and recognizers
- **syntactic analysis:** context free grammars, parse trees, AST, parsing strategies and algorithms
- **semantic analysis:** meaning in common imperative languages, type systems, SDD, representation of meaning
- **back end implementation:** target architectures, optimizations, register allocation, compiler runtime, x64 code generation

## grading
**10%** Project I (Take Home - syntax analysis using Flex + Bison)  
**15%** Project II (Take Home - scoped variables, type arithmetic)  
**30%** Project III (Take Home - complete language processor test case)  
**20%** Midterm  
**25%** Final 

## tools
- Flex for scanner implementation.
- Bison in combination with Flex for parser experiments
- Antlr as an alternative tool for scanning + parsing
- Eclipse for C++ for generating experimental executables with support of language processor runtime, which will also be developed by the student
- Nasm for assembly processing and code inspection.
