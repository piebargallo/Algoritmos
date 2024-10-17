/* 
   Algorithm name: transform

   Algorithm synopsis: calls a unary function on each element of a sequence or a 
   binari function on parallel elements of two sequences, and stores the results 
   in a destination sequence. If the source and destination sequences are the 
   same, the transformation happens in-place
*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

template<class InputIt, class OutputIt, class UnaryOp>
constexpr //< since C++20
OutputIt transform(InputIt first1, InputIt last1,
    OutputIt d_first, UnaryOp unary_op)
{
    for (; first1 != last1; ++d_first, ++first1)
        *d_first = unary_op(*first1);

    return d_first;
}

int main() {
    vector<int> numbers{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> result(numbers.size());

    // Using transform to square each element
    transform(begin(numbers), end(numbers), begin(result), [](int n) { return n * n; });

    // Print the result vector
    for (int n : result) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
