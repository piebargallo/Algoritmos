// Algorithm name: reverse_copy

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template<class BidirIt, class OutputIt>
OutputIt reverse_copy(BidirIt first, BidirIt last, OutputIt d_first)
{
    while (first != last) {
        *(d_first++) = *(--last);
    }
    return d_first;
}

int main()
{
    vector<int> v({ 1,2,3 });
    for_each(begin(v), end(v),
        [&](int value) { cout << value << " "; });
    cout << endl;

    vector<int> destiny(3);
    std::reverse_copy(begin(v), end(v), begin(destiny));
    for_each(begin(destiny), end(destiny),
        [&](int value) { cout << value << " "; });
    cout << endl;
    return 0;
}