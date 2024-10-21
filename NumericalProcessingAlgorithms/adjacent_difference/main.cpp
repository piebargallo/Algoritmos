/* Algorithm name: adjacent_difference

   Algorithm synopsis: generates a new sequence in wich each element is the difference
   (or other binary operation) of the second and first of each adjacent pair of 
   elements in the source sequence
*/

#include <numeric>
#include <vector>
#include <iostream>
using namespace std;

template<class InputIt, class OutputIt>
constexpr // desde C++20
OutputIt adjacent_difference(InputIt first, InputIt last,
    OutputIt d_first)
{
    if (first == last) return d_first;

    typedef typename std::iterator_traits<InputIt>::value_type value_t;
    value_t acc = *first;
    *d_first = acc;
    while (++first != last) {
        value_t val = *first;
        *++d_first = val - std::move(acc); // std::move desde C++20
        acc = std::move(val);
    }
    return ++d_first;
}

auto imprimir = [](auto comentario, auto const& secuencia) {
    cout << comentario;
    for (const auto& n : secuencia)
        cout << n << ' ';
    cout << endl;
    };

int main()
{
    vector v{ 4, 6, 9, 13, 18, 19, 19, 15, 10 };
    imprimir("Inicialmente: v = ", v);
    std::adjacent_difference(v.begin(), v.end(), v.begin());
    imprimir("Modificada: v = ", v);

    return 0;
}