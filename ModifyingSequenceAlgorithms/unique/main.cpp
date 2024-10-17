/* Algorithm name: unique

   Algorithm synopsis: renoves consecutive duplicates from the sequence,
   either in place or by copying results to a different sequence
*/

#include <iostream>
#include <vector>

template<class ForwardIt>
ForwardIt unique(ForwardIt first, ForwardIt last)
{
    if (first == last)
        return last;

    ForwardIt result = first;
    while (++first != last) {
        if (!(*result == *first)) {
            *(++result) = *first;
        }
    }
    return ++result;
}

int main() {
    std::vector<int> numbers{ 1, 1, 2, 3, 3, 4, 5, 5, 5, 6 };

    // Remove consecutive duplicates
    auto last = unique(numbers.begin(), numbers.end());

    // Erase the redundant elements
    numbers.erase(last, numbers.end());

    // Print the modified vector
    for (int n : numbers) {
        std::cout << n << " ";
    }

    return 0;
}
