// algorithm name: shift_left

#include <iostream>
#include <vector>

template <typename ForwardIterator>
ForwardIterator shift_left(ForwardIterator first, ForwardIterator last, typename std::iterator_traits<ForwardIterator>::difference_type n) {
    if (n <= 0) return first;

    auto mid = std::next(first, std::min(n, std::distance(first, last)));
    return std::move(mid, last, first);
}

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Shift elements to the left by 3 positions
    shift_left(numbers.begin(), numbers.end(), 3);

    // Print the shifted vector
    for (int n : numbers) {
        std::cout << n << " ";
    }

    return 0;
}
