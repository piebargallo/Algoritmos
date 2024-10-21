/* Algorithm name: max()

   Algorithm synopsis: returns the maximum of two or more values
*/

#include <iostream>
using std::cout;
using std::endl;

template<class T>
const T& max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}

int main()
{
    cout << "smaller of 1 and 9999: " << max(1, 9999) << endl;
    cout << "smaller of 'a' and 'b': " << max('a', 'b') << endl;
    cout << "smaller of 3.5 and 2.5: " << max(3.5, 2.5) << endl;
    return 0;
}