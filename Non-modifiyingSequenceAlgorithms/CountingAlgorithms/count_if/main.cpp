/* Algorithm name: count_if

   Algorithm synopsys: counts the number of elements matching a value or that
   cause a predicate to return true
*/

#include <iostream>
#include <iterator>
#include <vector>
using std::cout;
using std::endl;
using std::iterator_traits;
using std::vector;

template<class InputIt, class UnaryPredicate>
typename iterator_traits<InputIt>::difference_type
count_if(InputIt first, InputIt last, UnaryPredicate p)
{
    typename iterator_traits<InputIt>::difference_type ret = 0;
    for (; first != last; ++first) {
        if (p(*first)) {
            ret++;
        }
    }
    return ret;
}

int main()
{
    setlocale(LC_ALL, "es-Es.utf8");
    vector v{ 1, 2, 3, 4, 4, 3, 7, 8, 9, 10 };
   
    int cuenta_div4 = count_if(begin(v), end(v), [](int i) {return i % 4 == 0; });
    cout << "números divisible por cuatro: " << cuenta_div4 << endl;

    return 0;
}