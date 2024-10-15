/* Algorithm name: replace

   Algorithm synopsis: replaces all elements matching a value or that cause a predicate
   to return true with a new element, either in place or by copying the results to a
   different sequence
*/

#include <vector>
#include <iostream>
using namespace std;

template<class ForwardIt, class T>
void replace(ForwardIt first, ForwardIt last,
    const T& old_value, const T& new_value)
{
    for (; first != last; ++first) {
        if (*first == old_value) {
            *first = new_value;
        }
    }
}

int main()
{
    vector<int> s{ 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };

    replace(s.begin(), s.end(), 8, 88);

    for (int a : s) {
        cout << a << " ";
    }
    cout << endl;
   
    return 0;
}