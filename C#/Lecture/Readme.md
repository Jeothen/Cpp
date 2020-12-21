#### **It is the contents of codenuri's c# lecture**

* To organize what I have learned, just write the following article.

---



# Background

* Unlike C/C++, which works only in a specific environment, Java generates byte code and translates it into machine code suitable for the OS in the JVM.
* In the changing OS environment, Java doesn't operate recompiled
* But at the first executing time, translating through virtual machine has a some time. So, Java slower than C/C++

---

* Like Java, C# translated to IL(Intermediate Language, like java bytecode).
* Like other language such as C++ / VB  can translate IL through .net Complier.
  * C++ compiler and .net compiler can be selected. If C++ compile is selected, it is translated into machine language immediately, and if .net is used, it is translated in IL.
* After IL, there's a Virtual Machine operation. In terms of .net framework, Virtual machine doesn't refered but called CLR (Common Language Runtime) - Various Language

---

#### Terms

* These are same term as IL (Intermediate Language)
  * MSIL (Microsoft Intermediate language -> Multi-Language Support Intermediate Language)
  * CIL (Common Intermediate Language)

* CTS (Common Type System)
  * Since data types of various languages must be compatible in CLR(Common Languega Runtime), change them to common data types.

* FCL (Framework Class Library)
  * Libraries are provided by the CLR rather than language support
  * Changes the library grammar used in various languages to be compatible





## Characteristic

* **Object-oriented** 
* language Support the concepts of **functional languages** 
* **Garbage collection**



* Unline other language like C++, C# offers additional function such as pattern matching, property...