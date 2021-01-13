# Copy Elision 



* function's return is operated as follows. Internally the object is initialized, then copied/moved to the return value object, and then the temporary is destroyed.



* to initialize objects, they are copied or moved. Copy elision is an optimization that allows the compiler to avoid copying or moving.

* C++17, there's a prvalue expression like `return std::string("AA");`
* Copy Elision is a rule that allows the C++ compiler to ignore temporary copy create/copy/remove operations.







