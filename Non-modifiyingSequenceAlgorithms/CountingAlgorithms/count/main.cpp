/* Algorithm name: count()

   Algorithm sinopsys: counts the number of elements matching a value or that
   cause a predicate to return true
*/

#include <iostream>
#include <iterator>
#include <vector>
using std::cout;
using std::endl;
using std::iterator_traits;
using std::vector;

template< class InputIt, class T >
constexpr typename iterator_traits<InputIt>::difference_type
count(InputIt first, InputIt last, const T& value)
{
    typename iterator_traits<InputIt>::difference_type ret = 0;
    for (; first != last; ++first) {
        if (*first == value) {
            ret++;
        }
    }
    return ret;
}

int main()
{
    setlocale(LC_ALL, "es-Es.utf8");
    vector v{ 1, 2, 3, 4, 4, 3, 7, 8, 9, 10 };
    
    for (const int objetivo : {3, 4, 5}) {
        const int num_items = std::count(cbegin(v), cend(v), objetivo);
        cout << "número: " << objetivo << ", cuenta: " << num_items << '\n';
    }
    return 0;
}