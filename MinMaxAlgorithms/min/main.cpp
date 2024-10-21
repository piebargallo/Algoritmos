/* Algorithm name: min()

   Algorithm synopsis: returns the minimum of two or more values
*/

#include <iostream>
using std::cout;
using std::endl;

template<class T>
const T& min(const T& a, const T& b)
{
    return (a < b) ? a : b;
}

int main()
{
    cout << "smaller of 1 and 9999: " << min(1, 9999) << endl;
    cout << "smaller of 'a' and 'b': " << min('a', 'b') << endl;
    cout << "smaller of 3.5 and 2.5: " << min(3.5, 2.5) << endl;
    return 0;
}