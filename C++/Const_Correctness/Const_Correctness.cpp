#include <iostream>

class ConstCorrectClass
{
    int x;
public:
    int getX() const { return x; } // Function is const: Doesn't modify instance.
    void setX(int i) { x = i; }    // can modifies instance.
};

int const_correct_reader(const ConstCorrectClass& c)
{
    return c.getX();
}

// Parameter isn't const: Modifies parameter.
void const_correct_writer(ConstCorrectClass &c)
{
    c.setX(42);
}

const ConstCorrectClass invariant; // Instance is const: Can't be modified.
ConstCorrectClass variant;         // Instance isn't const: Can be modified.

// ...


int main() {
    const_correct_reader(invariant); // Good.   Calling non-modifying function on const instance.
    const_correct_reader(variant);   // Good.   Calling non-modifying function on modifiable instance.

    const_correct_writer(variant);   // Good.   Calling modifying function on modifiable instance.
    const_correct_writer(invariant); // Error.  Calling modifying function on const instance.
}