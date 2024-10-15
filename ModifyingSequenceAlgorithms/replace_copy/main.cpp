// Algorithm name: replace_copy

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

template<class InputIt, class OutputIt, class T>
OutputIt replace_copy(InputIt first, InputIt last, OutputIt d_first,
    const T& old_value, const T& new_value)
{
    for (; first != last; ++first) {
        *d_first++ = (*first == old_value) ? new_value : *first;
    }
    return d_first;
}

int main() {
    vector<int> numbers{ 1, 2, 3, 4, 5, 3, 6, 7, 3, 8, 9, 10 };
    vector<int> result(numbers.size());

    replace_copy(numbers.begin(), numbers.end(), result.begin(), 3, 99);

    for (int n : result) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
