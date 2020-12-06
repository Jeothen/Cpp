# Atomic Type



* Objects of atomic types are the only objects that are free from data races
* Modified by two threads concurretly or modified by one and read by another.



* `std::atomic` allows atomic access to a triviallycopyable type, It's implementation dependent if done through atomic operations or using locks.

* `std::atomic_flag`  is an atomic boolean type. Unlike all specializations of std::atomic, it is guaranteed to be lock-free





* Std::atomic

C++11

```c++
template< class T > 
struct atomic;
template< class U > 
struct atomic<U*>;
```

C++20

```c++
template< class U >
struct atomic<std::shared_ptr<U>>;

template< class U >
struct atomic<std::weak_ptr<U>>;
```

