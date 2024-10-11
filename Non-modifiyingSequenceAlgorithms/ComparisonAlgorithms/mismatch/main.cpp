/* Algorithm name: mismatch()

   Algorithm synopsis: returns the first element in each sequence that
   does not match the element in the same location in the other sequence
*/

#include <iostream>
#include <vector>
#include <utility> // para std::pair
using std::cout;
using std::endl;
using std::vector;

template <typename InputIt1, typename InputIt2>
std::pair<InputIt1, InputIt2> my_mismatch(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
    while (first1 != last1 && *first1 == *first2) {
        ++first1;
        ++first2;
    }
    return std::make_pair(first1, first2);
}

int main() {
    vector<int> vec1 = { 1, 2, 3, 4, 5 };
    vector<int> vec2 = { 1, 2, 0, 4, 5 };

    auto result = my_mismatch(begin(vec1), end(vec1), begin(vec2));

    if (result.first != end(vec1)) {
        cout << "Primer elemento diferente: " << *result.first <<
            " en vec1 y " << *result.second << " en vec2" << endl;
    }
    else {
        cout << "Todos los elementos coinciden" << endl;
    }

    return 0;
}
