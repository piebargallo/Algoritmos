/* Algorithm name: none_of()

   Algorithm synopsys: returns true if a given predicate returns false for all
   the elements in the sequence is empty; false otherwise 
*/

#include <vector>
#include <iostream>
#include <functional>

template<class InputIt, class UnaryPredicate>
constexpr InputIt find_if(InputIt first, InputIt last, UnaryPredicate p)
{
    for (; first != last; ++first) {
        if (p(*first)) {
            return first;
        }
    }
    return last;
}

template< class InputIt, class UnaryPredicate >
constexpr bool none_of(InputIt first, InputIt last, UnaryPredicate p)
{
    return std::find_if(first, last, p) == last;
}

int main()
{
    std::vector<int> v{ 10, 2 };
    
    if (none_of(cbegin(v), cend(v), std::bind(std::modulus<>(),
        std::placeholders::_1, 2))) {
        std::cout << "Ninguno es non\n";
    }
    return 0;
}