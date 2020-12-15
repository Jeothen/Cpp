#include <thread>
#include <iostream>
#include <atomic>
#include <cassert>
#include <string>
#include <vector>

int x, y;
std::atomic<bool> ready{false};

void init()
{
    x = 2;
    y = 3;
    atomic_thread_fence(std::memory_order_release);  // release fence occured before acquire fence, making the writes to x, y
    ready.store(true, std::memory_order_relaxed);
}

void use()
{
    if (ready.load(std::memory_order_relaxed))
    {
        atomic_thread_fence(std::memory_order_acquire);  // acquire fence occured after relased fence
        std::cout << x + y;
    }
    else std::cout << "Not relaxed" << std::endl;
}

void block_and_use()
{
    while (!ready.load(std::memory_order_relaxed)); // blocking
    atomic_thread_fence(std::memory_order_acquire); // acquire fence occured after relased fence
    std::cout << x + y;
}

int main(){
//    init();
    
    use();

//    block_and_use();
}