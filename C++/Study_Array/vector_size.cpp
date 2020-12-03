#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int int_from(std::istream &input)
{
    int x;
    input >> x;
    return x;
}

int main()
{
    vector<int> a; // ← Zero size by default.

    while (cin)
    {
        cout << "One number, please, or indicate EOF: ";
        int const x = int_from(cin);
        if (!cin.fail())
        {
            a.push_back(x);
        } // Expands as necessary.
    }

    sort(a.begin(), a.end());
    int const n = a.size();
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
}