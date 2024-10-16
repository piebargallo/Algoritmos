/* 
   Algorithm name : shift_right 

   Algorithm synopsis: Shifts the elements in a sequence left or right by a given number
   of positions. Elements are moved to their new position. Elements that fall of either
   end of the sequence are removed. shift_left() returns an iterator to the end of the 
   new sequence; shit_right() returns an iterator to the beginning of the new sequence 
*/

#include <iostream>
#include <vector>

template <typename ForwardIterator>
ForwardIterator shift_right(ForwardIterator first, ForwardIterator last, typename std::iterator_traits<ForwardIterator>::difference_type n) {
    if (n <= 0) return last;

    auto mid = std::next(first, std::max(std::distance(first, last) - n, 0L));
    return std::move_backward(first, mid, last);
}

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Shift elements to the right by 3 positions
    shift_right(numbers.begin(), numbers.end(), 3);

    // Print the shifted vector
    for (int n : numbers) {
        std::cout << n << " ";
    }

    return 0;
}
