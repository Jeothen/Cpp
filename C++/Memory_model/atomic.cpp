#include <thread>
#include <iostream>
#include <atomic>
#include <cassert>
#include <string>
#include <vector>

std::atomic<int> relax_cnt = {0};

// relaxed
void relaxed(){
    for (int n = 0; n < 200; ++n)
    {
        relax_cnt.fetch_add(1, std::memory_order_relaxed);
    }
}

std::atomic<std::string *> ptr;
int data;

std::atomic<int> flag = {0};
std::vector<int> vc;

// release
void release()
{
    std::string *p = new std::string("Hello");
    data = 11;
    ptr.store(p, std::memory_order_release);

    vc.push_back(22);
    flag.store(1, std::memory_order_release);
}

// acq_rel
void acq_rel()
{
    int expected = 1;
    while (!flag.compare_exchange_strong(expected, 2, std::memory_order_acq_rel))
    {
        expected = 1;
    }
}

// acquire
void acquire()
{
    std::string *p2;
    while (!(p2 = ptr.load(std::memory_order_acquire)));
    assert(*p2 == "Hello"); // never fires
    assert(data == 11);     // never fires

    while (flag.load(std::memory_order_acquire) < 2);
    assert(vc.at(0) == 22); // if not same - fires
}

// consume
void consumer()
{
    std::string *p2;
    while (!(p2 = ptr.load(std::memory_order_consume)));

    assert(*p2 == "Hello"); // never fires: *p2 carries dependency from ptr
    assert(data == 11);     // may or may not fire: data does not carry dependency from ptr
}

/*------------------------------------------------------------------------------------*/
// seq_cst
std::atomic<bool> x = {false};
std::atomic<bool> y = {false};
std::atomic<int> z = {0};

void write_x()
{
    x.store(true, std::memory_order_seq_cst);
}

void write_y()
{
    y.store(true, std::memory_order_seq_cst);
}

void read_x_then_y()
{
    while (!x.load(std::memory_order_seq_cst));
    if (y.load(std::memory_order_seq_cst))
    {
        ++z;
    }
}

void read_y_then_x()
{
    while (!y.load(std::memory_order_seq_cst));
    if (x.load(std::memory_order_seq_cst))
    {
        ++z;
    }
}
int main()
{
    // relaxed
    std::vector <std::thread> thread_vc;
    for (int n = 0; n < 3; ++n) thread_vc.emplace_back(relaxed);
    for (auto &p : thread_vc) p.join(); // called n times
    std::cout << "Final counter value is " << relax_cnt << '\n';

    // release
    std::thread t1(release);
    // acq_rel
    std::thread t2(acq_rel);
    // acquire
    std::thread t3(acquire);
    //consume
    std::thread t4(consumer);
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    // seq_cst
    std::thread a(write_x);
    std::thread b(write_y);
    std::thread c(read_x_then_y); // z.load()
    std::thread d(read_y_then_x); // z.load()
    a.join();
    b.join();
    c.join();
    d.join();
    std::cout << "z.load = " << z.load() << std::endl;
}