/* Algorithm name: copy_if

   Algorithm synopsis: copies elements for which a predicate returns
   true from one sequence to another
*/

#include <iostream>
#include <numeric>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

template<class InputIt, class OutputIt>
OutputIt copy(InputIt first, InputIt last,
    OutputIt d_first)
{
    for (; first != last; (void)++first, (void)++d_first)
        *d_first = *first;

    return d_first;
}

template<class InputIt, class OutputIt, class UnaryPredicate>
OutputIt copy_if(InputIt first, InputIt last,
    OutputIt d_first, UnaryPredicate pred)
{
    for (; first != last; ++first)
    {
        if (pred(*first))
        {
            *d_first = *first;
            ++d_first;
        }
    }

    return d_first;
}

int main()
{
    setlocale(LC_ALL, "es-Es.utf8");
    vector<int> from_vector(10);
    std::iota(from_vector.begin(), from_vector.end(), 0);

    vector<int> to_vector;
    std::copy(from_vector.begin(), from_vector.end(), to_vector.begin());
    
    cout << "to_vector contiene: ";

    std::copy(to_vector.begin(), to_vector.end(),
        std::ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "Los números impares en to_vector son: ";

    copy_if(to_vector.begin(), to_vector.end(),
        std::ostream_iterator<int>(cout, " "),
        [](int x) { return x % 2 != 0; });
    cout << endl;

    return 0;
}