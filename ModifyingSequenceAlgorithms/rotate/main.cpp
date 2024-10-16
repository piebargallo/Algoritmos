/*
   Algorithm name: rotate

   Algorithm synopsis: swaps the first and second "halves" of the sequence, either
   in place or by coping the results to a different sequence. The two subsequences
   to be swapped need not be equal in size
*/

#include <vector>
#include <iostream>
using namespace std;

template< class ForwardIt >
ForwardIt rotate(ForwardIt first, ForwardIt n_first, ForwardIt last)
{
    ForwardIt next = n_first;
    while (first != next) {
        std::swap(*first++, *next++);
        if (next == last) {
            next = n_first;
        }
        else if (first == n_first) {
            n_first = next;
        }
    }
}

int main()
{
    vector<int> v{ 2, 4, 2, 0, 5, 10, 7, 3, 7, 1 };

    cout << "before sort:      ";
    for (int n : v)
        cout << n << ' ';
    cout << endl;

    // insertion sort
    for (auto i = v.begin(); i != v.end(); ++i) {
        std::rotate(upper_bound(v.begin(), i, *i), i, i + 1);
    }

    cout << "after sort:       ";
    for (int n : v)
        cout << n << ' ';
    cout << endl;

    // simple rotation to the left
    std::rotate(v.begin(), v.begin() + 1, v.end());

    cout << "simple rotate left  : ";
    for (int n : v)
        cout << n << ' ';
    cout << endl;

    // simple rotation to the right
    std::rotate(v.rbegin(), v.rbegin() + 1, v.rend());

    cout << "simple rotate right : ";
    for (int n : v)
        cout << n << ' ';
    cout << endl;
    return 0;
}