#include <iostream>

class MyClass
{
private:
    int myInt_;

public:
    MyClass() { myInt_ = 1; }
    int myInt() const { return myInt_; }
    void setMyInt(int myInt) { myInt_ = myInt; }
};

class Student
{
public:
    char &GetScore(bool midterm)
    {
        std::cout << "non - const\n";
        // call const member function
        return const_cast<char &>(const_cast<const Student *>(this)->GetScore(midterm)); // const_casting needed
    }

    const char &GetScore(bool midterm) const  // const qualifier can be overloaded
    {
        if (midterm)
        {
            std::cout << "midterm\n";
            return midtermScore;
        }
        else
        {
            std::cout << "not mid\n";
            return finalScore;
        }
    }
private:
    char midtermScore;
    char finalScore;
};

int main(){
    // pointer class not create constructor
    MyClass *ptr; 
    const MyClass* ptr1; // this has no setMyInt() member function
    std::cout << ptr->myInt() << std::endl;  // compiler emit but warning. there's a const member function
    std::cout << ptr1->myInt() << std::endl;  // 0

    Student s;
    s.GetScore(true) = 'B';
    std::cout << "\n";
    s.GetScore(false) = 'A';
    std::cout << "\n";

    // const object
    const Student cs(s);
    std::cout << cs.GetScore(true) << "///"<< cs.GetScore(false) << '\n';

    // const basic
    const int a = 10;
    int n = 10;
    const int a1 = 15;
    int n1 = 5;

    int& b = a;
    int& b1 = n;
    const int& c = a;
    const int& c1 = n;

    int* d = &a;
    int* d1 = &n; // not const
    *d1 = &a; // const
    *d1 = n1;

// const pointer
    const int* e = &n;  // pointer-to-const
    int* const e1 = &n;  // const pointer
    const int* const e2 = &n; // const pointer-to-const

    e = &n1;
    *e = n1; // int can not assign to const reference
    e = &n1;

    *e1 = n1;
    e1 = &n1; // int ref. can not assign to const pointer

    *e2 = n1; // 
    e2 = &n1  // int ref. can not assign to const pointer
}

