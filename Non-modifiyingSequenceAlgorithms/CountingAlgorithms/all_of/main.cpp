/* Algorithm name: all_of

   Algorithm synopsis: returns true if a given predicate return true for all
   the elements in the sequence or the if the sequence is empty; false otherwise
*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;

template<class InputIt, class UnaryPredicate>
constexpr InputIt find_if_not(InputIt first, InputIt last, UnaryPredicate p)
{
    for (; first != last; ++first) {
        if (!p(*first)) {
            return first;
        }
    }
    return last;
}

template< class InputIt, class UnaryPredicate >
constexpr bool all_of(InputIt first, InputIt last, UnaryPredicate p)
{
    return find_if_not(first, last, p) == last;
}

int main() {
    std::vector<int> numeros = { 1, 2, 3, 4, 5 };

    if (all_of(cbegin(numeros), cend(numeros), [](int i) { return i > 0; })) {
        cout << "Todos los elementos son positivos." << endl;
    }
    else {
        cout << "No todos los elementos son positivos." << endl;
    }

    return 0;
}
