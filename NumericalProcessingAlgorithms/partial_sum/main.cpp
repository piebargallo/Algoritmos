/* Algorithm name: partial_sum

   Algorithm synopsis: generates a new sequence in wich each element is the sum
   (or other binary operation) of an element and all its preceding elements
   in the source sequence
*/

#include <numeric>
#include <vector>
#include <iostream>
using namespace std;

template<class InputIt, class OutputIt, class BinaryOperation>
constexpr // desde C++20
OutputIt partial_sum(InputIt first, InputIt last,
    OutputIt d_first, BinaryOperation op)
{
    if (first == last) return d_first;

    typename std::iterator_traits<InputIt>::value_type sum = *first;
    *d_first = sum;

    while (++first != last) {
        sum = op(std::move(sum), *first); // std::move desde C++20
        *++d_first = sum;
    }
    return ++d_first;
}

int main()
{
    setlocale(LC_ALL, "es-Es.utf8");
    vector<int> v{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 }; 

    cout << "Los primeros 10 números pares son: ";
    partial_sum(v.begin(), v.end(),
        ::ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}