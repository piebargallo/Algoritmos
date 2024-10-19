/* Algorithm name: partition copy

   Algorithm synopsis: copies elements from one sequence to two different sequences.
   The target sequence is selected based on the result of a predicate, either 
   true or false
   
   Complexity: linear
*/

#include <iostream>
using namespace std;

template<class InputIt, class OutputIt1,
    class OutputIt2, class UnaryPredicate>
std::pair<OutputIt1, OutputIt2>
partition_copy(InputIt first, InputIt last,
    OutputIt1 d_first_true, OutputIt2 d_first_false,
    UnaryPredicate p)
{
    while (first != last) {
        if (p(*first)) {
            *d_first_true = *first;
            ++d_first_true;
        }
        else {
            *d_first_false = *first;
            ++d_first_false;
        }
        ++first;
    }
    return std::pair<OutputIt1, OutputIt2>(d_first_true, d_first_false);
}

int main()
{
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int true_arr[5] = { 0 };
    int false_arr[5] = { 0 };

    partition_copy(begin(arr), end(arr), begin(true_arr), begin(false_arr),
        [](int i) {return i > 5; });

    cout << "true_arr: ";
    for (auto it = begin(true_arr); it != end(true_arr); ++it) {
        cout << *it << ' ';
    }
    cout << endl;;

    cout << "false_arr: ";
    for (auto it = begin(false_arr); it != end(false_arr); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}