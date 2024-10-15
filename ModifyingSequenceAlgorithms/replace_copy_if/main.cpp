// Algorithm name: replace_copy_if

#include <vector>
#include <iostream>
using namespace std;

template<class InputIt, class OutputIt,
    class UnaryPredicate, class T>
OutputIt replace_copy_if(InputIt first, InputIt last, OutputIt d_first,
    UnaryPredicate p, const T& new_value)
{
    for (; first != last; ++first) {
        *d_first++ = (p(*first)) ? new_value : *first;
    }
    return d_first;
}

int main()
{
    vector<int> v{ 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };
    replace_copy_if(v.begin(), v.end(),
        ostream_iterator<int>(std::cout, " "),
        [](int n) {return n > 5; }, 99);
    cout << endl;

    return 0;
}
