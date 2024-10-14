/* Algorithm name: copy()

   Algorithm synopsis: copies elements from one sequence to another
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

int main()
{
    vector<int> from_vector(10);
    std::iota(from_vector.begin(), from_vector.end(), 0);

    vector<int> to_vector;
    std::copy(from_vector.begin(), from_vector.end(),
        std::back_inserter(to_vector));
    
    cout << "to_vector contiene: ";

    std::copy(to_vector.begin(), to_vector.end(),
        std::ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}