// algorithm name: unique

#include <string>
#include <iostream>
#include <iterator>
using std::cout;
using std::endl;
using std::string;

template<class ForwardIt, class OutputIt, class BinaryPredicate>
ForwardIt unique_copy(ForwardIt first, ForwardIt last,
    OutputIt d_first, BinaryPredicate p)
{

    if (first == last)
        return d_first;

    *d_first = *first;
    while (++first != last) {
        if (!p(*result, *first)) {
            *(++d_first) = *first;
        }
    }
    return ++d_first;
}

int main()
{
    string s1 = "The      string    with many       spaces!";
    cout << "before: " << s1 << endl;

    string s2;
    unique_copy(s1.begin(), s1.end(), std::back_inserter(s2),
        [](char c1, char c2) { return c1 == ' ' && c2 == ' '; });

    cout << "after:  " << s2 << endl;
    return 0;
}