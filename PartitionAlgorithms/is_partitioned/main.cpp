/* 
   Algorithm name: is_partitioned

   Algorithm synopsis: returns true if all elements for wich a predicate
   returns true are before all elements for wich it returns false
   
   Complexity: linear
*/

#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

template< class InputIt, class UnaryPredicate >
bool is_partitioned(InputIt first, InputIt last, UnaryPredicate p)
{
    for (; first != last; ++first)
        if (!p(*first))
            break;
    for (; first != last; ++first)
        if (p(*first))
            return false;
    return true;
}

int main()
{
    vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    auto is_even = [](int i) { return i % 2 == 0; };
    cout.setf(std::ios_base::boolalpha);
    cout << is_partitioned(v.begin(), v.end(), is_even) << ' ';
    cout << endl;

    return 0;
}