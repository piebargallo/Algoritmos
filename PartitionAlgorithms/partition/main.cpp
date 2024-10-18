/* Algorithm name: partition

   Algorithm synopsis: sorts the sequence such that all elements for which a predicate
   returns true are before all elements for which it returns false, without preserving
   the original order of the elements within each parition
   
   Complexity: linear */

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::copy;
using std::vector;

template<class BidirIt, class UnaryPredicate>
BidirIt partition(BidirIt first, BidirIt last, UnaryPredicate p)
{
    while (1) {
        while ((first != last) && p(*first)) {
            ++first;
        }
        if (first == last--) break;
        while ((first != last) && !p(*last)) {
            --last;
        }
        if (first == last) break;
        std::swap(*first++, *last);
    }
    return first;
}

int main()
{
    std::vector<int> v;
    for (int i = 0; i < 10; ++i) v.push_back(i);

    cout << "Original vector: " << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    // Partition the vector
    vector<int>::iterator p =
        partition(v.begin(), v.end(), [](int x) { return x % 2 == 0; });

    cout << "\nPartitioned vector:\n    ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << "\nBefore partition:\n    ";
    copy(v.begin(), p, ostream_iterator<int>(cout, " "));
    cout << "\nAfter partition:\n    ";
    copy(p, v.end(), ostream_iterator<int>(cout, " "));
    return 0;
}