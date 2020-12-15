## Memory Model

* Due to the limitaitions of HW resources, the compiler optimizes with an appropritate memory model
* The memory Model is not determined by the application, but by the OS of HW
* Synchronization primitives such as mutex or critical section prevent data races, deadlock
* In C++11 there's a memory model such as atomic-operation and fence on Muti-thread environment 



## Atomic Operation

* The atomic Class is a template class that allows atomically perform arithmetic operations on Integer or pointer types.
  * ``std::atomic<unsigned>``  |  ``std::atomic<std::vector<foo> *>`` 
* On Template ``std::atomic<T>`` ,  Classes wrap values of type T, but loading and storing of objects is atomic



---



* std::memory_order_relaxed
  
* There are no synchronizations or order restrictions applied to other reads or writes. Only atomicity is guaranteed.
  
* std::memory_order_acquire
  
  * It performs a acquire operation from released operations on the affected memory location
* std::memory_order_release 
  
* It performs the memory order release operation. 
  
* std::memory_order_consume
  * It performs a consuming operation on the affected memory location
  * The dirrerence from memory_order_release-acquire is that after sequencing, only the load is consumed according to the value loaded by them during the load operation.

* std::memory_order_acq_rel
  
* Both acquire operation and release operation (load acquire and store-release)
  
* std::memory_order_seq_cst

  * If no memory order is defined, the order defaults to sequential consistency.  `std::memory_order_seq_cst`  can explicitly selected by specificifying an aciton tag.
  * Since memory operations occur before atomic operations, It interferes with optimizations that reorder memory after atomic operations.

  



## Fence

* Align memory operations between threads.
* There's a two fense, release fence and acquire fence
* Synchronization primitives such as atomic operations can be used to ensure the acquire fence to occur after the release fence has occured.
