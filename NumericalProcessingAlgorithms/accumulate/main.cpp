/* Algorithm name: accumulate

   Algorithm synopsis: accumulates the values of all elements in a sequence. 
   The default behavior is to sum the elements, but the caller can suply a 
   different binary function instead*/

#include <iostream>
#include <vector>
#include <numeric>
#include <string>
using namespace std;

template<class InputIt, class T>
constexpr // desde C++20
T accumulate(InputIt first, InputIt last, T init)
{
    for (; first != last; ++first) {
        init = std::move(init) + *first; 
    }
    return init;
}

int main()
{
    vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());

    cout << "Producto: " << product << endl;
    return 0;
}