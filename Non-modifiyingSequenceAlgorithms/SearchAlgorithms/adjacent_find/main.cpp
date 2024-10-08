/* Algorithm name: adjacent_find

   algorithm synopsis: Finds the first instance of two consecutive elements
   that are equal to each other or are equivalent to each other as specifier
   by a predicate
   
   Complexity: O(N)
*/

#include <functional>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

template<class ForwardIt>
ForwardIt adjacent_find(ForwardIt first, ForwardIt last)
{
    if (first == last)
        return last;

    ForwardIt next = first;
    ++next;

    for (; next != last; ++next, ++first)
        if (*first == *next)
            return first;

    return last;
}

int main()
{
    vector<int> v{ 0, 1, 2, 3, 40, 40, 41, 41, 5 };

    auto it = adjacent_find(begin(v), end(v));

    (it == std::end(v))
        ? cout << "No se encuentran elementos adyacentes coincidentes" << endl
        : cout << "El primer par de elementos adyacentes iguales se encuentra en "
        << std::distance(begin(v), it) << ", *it = "
        << *it << endl;
    return 0;
}