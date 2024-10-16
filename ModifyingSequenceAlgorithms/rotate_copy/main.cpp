// Algorithm name: rotate_copy

#include <iostream>
#include <vector>

template<class ForwardIt, class OutputIt>
OutputIt rotate_copy(ForwardIt first, ForwardIt n_first,
    ForwardIt last, OutputIt d_first)
{
    d_first = std::copy(n_first, last, d_first);
    return std::copy(first, n_first, d_first);
}


int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> result(numbers.size());

    rotate_copy(numbers.begin(), numbers.begin() + 3, numbers.end(), result.begin());

    for (int n : result) {
        std::cout << n << " ";
    }

    return 0;
}
