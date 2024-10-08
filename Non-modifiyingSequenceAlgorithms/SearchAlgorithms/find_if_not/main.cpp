/* Algorithm name: find_if_not()

   Algorithm synopsis: Finds the first element that causes a predicate
   to return false.
   
   Complexity: O(N)
*/

#include <iostream>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;

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

int main()
{
    vector<int> v{ 1, 2, 3, 4 };
    
    auto es_par = [](int i) { return i % 2 != 0; };

    auto result = find_if_not(begin(v), end(v), es_par);

    (result != std::end(v))
        ? cout << "v contiene nombre par: " << *result << endl
        : cout << "v no contiene nombres pares" << endl;
    return 0;
}