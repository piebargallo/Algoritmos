/* Algorithm name: upper_bound

   Algorithm synopsis: finds the first element in a sequence greater than a given value
*/

#include <iostream>
#include <vector>

template<class ForwardIt, class T>
ForwardIt upper_bound(ForwardIt first, ForwardIt last,
    const T& value)
{
    ForwardIt it;
    std::iterator_traits<ForwardIt>::distance_type count, step;
    count = std::distance(first, last);

    while (count > 0) {
        it = first;
        step = count / 2;
        std::advance(it, step);
        if (!(value < *it)) {
            first = ++it;
            count -= step + 1;
        }
        else count = step;
    }
    return first;
}

template<class ForwardIt, class T>
ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value)
{
    ForwardIt it;
    std::iterator_traits<ForwardIt>::difference_type count, step;
    count = std::distance(first, last);

    while (count > 0) {
        it = first;
        step = count / 2;
        std::advance(it, step);
        if (*it < value) {
            first = ++it;
            count -= step + 1;
        }
        else count = step;
    }
    return first;
}

int main()
{
    std::vector<int> data = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6 };

    auto upper = std::upper_bound(data.begin(), data.end(), 4);
    auto lower = std::lower_bound(data.begin(), data.end(), 4);
   
    std::copy(lower, upper, std::ostream_iterator<int>(std::cout, " "));
    return 0;
}