/* Algorithm name: partition_point

   Algorithm synopsis: returns an iterator such that all elements before this
   iterator return true for a predicate and all elements after this iterator
   return false for that predicate
   
   Complexity: logarithmic
*/

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
using namespace std;

auto print_seq = [](auto rem, auto first, auto last)
    {
        for (cout << rem; first != last; cout << *first++ << ' ') {}
        cout << endl;
    };

int main()
{
    array v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    auto is_even = [](int i) { return i % 2 == 0; };

    partition(v.begin(), v.end(), is_even);
    print_seq("After partitioning, v: ", v.cbegin(), v.cend());

    const auto pp = partition_point(v.cbegin(), v.cend(), is_even);
    const auto i = distance(v.cbegin(), pp);
    cout << "Partition point is at " << i << "; v[" << i << "] = " << *pp << endl;

    print_seq("First partition (all even elements): ", v.cbegin(), pp);
    print_seq("Second partition (all odd elements): ", pp, v.cend());
   
    return 0;
}