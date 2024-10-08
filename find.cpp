/* Algorithm name: find()
 
   Algorithm synopsis:Finds the first element thtat matches
   a value or causes a predicate to return true.
   
   Complexity: O(N)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;

template<class InputIt, class T>
constexpr InputIt find(InputIt first, InputIt last, const T& value)
{
    for (; first != last; ++first) {
        if (*first == value) {
            return first;
        }
    }
    return last;
}

int main()
{
    vector<int> v{ 1, 2, 3, 4 };
    int n1 = 3;
    
    auto result = std::find(begin(v), end(v), n1);
    (result != std::end(v))
        ? cout << "v contiene " << n1 << endl
        : cout << "v no contiene " << n1 << endl;
    return 0;
}