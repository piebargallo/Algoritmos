/* Algorithm name: any_of()

   Algorithm sinopsys: returns true if a given predicate returns true for at 
   least one element in the sequence; false otherwise
*/

#include <vector>
#include <iostream>

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
constexpr bool any_of(InputIt first, InputIt last, UnaryPredicate p)
{
    return std::find_if(first, last, p) != last;
}

int main()
{
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    struct DivisibleBy
    {
        const int d;
        DivisibleBy(int n) : d(n) {}
        bool operator()(int n) const { return n % d == 0; }
    };

    if (any_of(cbegin(v), cend(v), DivisibleBy(7))) {
        std::cout << "Al menos un nombrre es divisible por 7" << std::endl;
    }
    return 0;
}