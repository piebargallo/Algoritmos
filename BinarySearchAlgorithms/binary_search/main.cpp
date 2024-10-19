/* Algorithm name: binary_search

   Algorithm synopsis: returns true if a given value is found in a sequence;
   false otherwise
*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

template<class ForwardIt, class T>
bool binary_search(ForwardIt first, ForwardIt last, const T& value)
{
    first = std::lower_bound(first, last, value);
    return (first != last && !(value < *first));
}

int main()
{
    vector<int> haystack{ 1, 3, 4, 5, 9 };
    vector<int> needles{ 1, 2, 3 };

    for (auto needle : needles) {
        cout << "Searching for " << needle << endl;
        if (binary_search(haystack.begin(), haystack.end(), needle)) {
            cout << "Found " << needle << endl;
        }
        else {
            cout << "No found!" << endl;
        }
    }
    return 0;
}