/* Algorithm name: partial_sort

   Algorithm synopsis: partially sorts the sequence: the first n elements
   (specified by iterators) are sorted; the rest are not. They are sorted
   either in place or by copying them to a new sequence
   
   Complexity: linear logarithmic
*/

#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
using namespace std;

void print(const auto& s, int middle)
{
    for (int a : s)
        cout << a << ' ';
    cout << endl;
    if (middle > 0)
    {
        while (middle-- > 0)
            cout << "--";
        cout << '^';
    }
    else if (middle < 0)
    {
        for (auto i = s.size() + middle; --i; cout << "  ")
        {
        }

        for (cout << '^'; middle++ < 0; cout << "--")
        {
        }
    }
    cout << endl;
};

int main()
{
    array<int, 10> s{ 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };
    print(s, 0);
    partial_sort(s.begin(), s.begin() + 3, s.end());
    print(s, 3);
    partial_sort(s.rbegin(), s.rbegin() + 4, s.rend());
    print(s, -4);
    partial_sort(s.rbegin(), s.rbegin() + 5, s.rend(), greater{});
    print(s, -5);
    return 0;
}