/* Algorithm name: fill()

   Algorithm synopsis: sets alls elements in the sequence to a new value
*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

template<class ForwardIt, class T>
void fill(ForwardIt first, ForwardIt last, const T& value)
{
    for (; first != last; ++first)
        *first = value;
}

int main()
{
    vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::fill(v.begin(), v.end(), -1);

    for (auto elem : v)
        cout << elem << ' ';
    cout << endl;
    return 0;
}