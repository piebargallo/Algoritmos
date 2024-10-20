// Algorithm name: set_difference, complexity: linear

#include <iostream>
#include <vector>
using namespace std;

template<class InputIt1, class InputIt2, class OutputIt>
OutputIt set_difference(InputIt1 first1, InputIt1 last1,
    InputIt2 first2, InputIt2 last2, OutputIt d_first)
{
    while (first1 != last1)
    {
        if (first2 == last2)
            return std::copy(first1, last1, d_first);

        if (*first1 < *first2)
            *d_first++ = *first1++;
        else
        {
            if (!(*first2 < *first1))
                ++first1;
            ++first2;
        }
    }
    return d_first;
}

void println(const std::vector<int>& v)
{
    for (int i : v)
        cout << i << ' ';
    cout << endl;
}

int main()
{
    vector<int> v1, v2, dest;

    v1 = { 1, 2, 3, 4, 5 };
    v2 = { 3, 4, 5, 6, 7 };

    set_difference(v1.cbegin(), v1.cend(),
        v2.cbegin(), v2.cend(),
        back_inserter(dest));
    println(dest);

    dest.clear();

    v1 = { 1, 2, 3, 4, 5, 5, 5 };
    v2 = { 3, 4, 5, 6, 7 };

    set_difference(v1.cbegin(), v1.cend(),
        v2.cbegin(), v2.cend(),
        back_inserter(dest));
    println(dest);

    return 0;
}