// Algorithm name: replace_if

#include <vector>
#include <iostream>
#include <functional>
using namespace std;

template<class ForwardIt, class UnaryPredicate, class T>
void replace_if(ForwardIt first, ForwardIt last,
    UnaryPredicate p, const T& new_value)
{
    for (; first != last; ++first) {
        if (p(*first)) {
            *first = new_value;
        }
    }
}

int main()
{
    vector<int> s{ 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };

    replace_if(s.begin(), s.end(),
        bind(std::less<int>(), placeholders::_1, 5), 55);
    
    for (int a : s) {
        cout << a << " ";
    }
    cout << endl;
    
    return 0;
}