/* Algorithm name: copy_backward

   Algorithm synopsis: copies elements from one sequence to another
*/

#include <iostream>
#include <numeric>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

template<class BidirIt1, class BidirIt2>
BidirIt2 copy_backward(BidirIt1 first, BidirIt1 last, BidirIt2 d_last)
{
    while (first != last)
        *(--d_last) = *(--last);

    return d_last;
}

int main()
{
    vector<int> source(4);
    std::iota(source.begin(), source.end(), 1); 

    vector<int> destination(6);

    std::copy_backward(source.begin(), source.end(), destination.end());

    cout << "El destino contiene: ";
    for (auto i : destination)
        cout << i << ' ';
    cout << endl;
    return 0;
}