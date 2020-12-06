# Attributes



* C++11 : [[noreturn]]
  * the function does not return to the caller by either executing a return statement, or by reaching the end of statement. 
    *  this does not apply to void functions, since they do return to the caller, they just do not return any value
  * function may end by calling `std::terminate` or `std::exit`, or by throwing an exception. It is also worth noting that such a function can return by executing longjmp



* C++14 : [[deprecated]]

  * Indicate that a function is deprecated. 
  * [[deprecated("reason")]] allows adding a specific reason which can be shown by the compiler.
  * When compiling, the sentense defined in clog is recorded in the output the moment the deprecated function is called.

  

* C++17 : [[fallthrough]]
  * A fallthrough statement may only be used in a switch statement, where the next statement to be executed is a statement with a case or default label for that switch statement. If the fallthrough statement is inside a loop, the next (labeled) statement must be part of the same iteration of that loop.
  * Indicates that the fall through from the previous case label is intentional and should not be diagnosed by a compiler that warns on fallthrough.



* C++17 : [[nodiscard]]
  * Indicate that the return value of a function shouldn't be ignored when you do a function call. If the return value is ignored, the compiler should give a warning on this.



* C++17 : [[maybe_unused]]
  * If the compiler issues warnings on unused entities, that warning is suppressed for any entity declared maybe_unused.