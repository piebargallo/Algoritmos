/* Algorithm name: iota

   Algorithm synopsis: fills a sequence with successively incrementing
   values starting with a given value
*/

//#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <vector>
using namespace std;

template<class ForwardIt, class T>
constexpr // since C++20
void iota(ForwardIt first, ForwardIt last, T value)
{
    while (first != last) {
        *first++ = value;
        ++value;
    }
}

int main()
{
    list<int> l(10);
    std::iota(l.begin(), l.end(), -4);

    vector<std::list<int>::iterator> v(l.size());
    std::iota(v.begin(), v.end(), l.begin());

    shuffle(v.begin(), v.end(), std::mt19937{ std::random_device{}() });

    cout << "Contenido de la lista: ";
    for (auto n : l) cout << n << ' ';
    cout << endl;

    cout << "Contenido de la lista, barajada: ";
    for (auto i : v) cout << *i << ' ';
    cout << endl;

    return 0;
}