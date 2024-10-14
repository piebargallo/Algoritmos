/* Algorithm name: fill_n()

   Algorithm synopsis: sets the first n elements in the sequence 
   to a new value
*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

template<class OutputIt, class Size, class T>
OutputIt fill_n(OutputIt first, Size count, const T& value)
{
    for (Size i = 0; i < count; i++)
        *first++ = value;
    return first;
}

int main()
{
    vector<int> v1{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::fill_n(v1.begin(), 5, -1);

    std::copy(begin(v1), end(v1), std::ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}