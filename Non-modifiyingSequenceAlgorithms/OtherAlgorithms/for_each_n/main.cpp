#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

template<class InputIt, class Size, class UnaryFunction>
InputIt for_each_n(InputIt first, Size n, UnaryFunction f)
{
    for (Size i = 0; i < n; ++first, (void) ++i) {
        f(*first);
    }
    return first;
}

int main()
{
    vector<int> ns{ 1, 2, 3, 4, 5 };
    for (auto n : ns) cout << n << ", ";
    cout << endl;
    for_each_n(ns.begin(), 3, [](auto& n) { n *= 2; });
    for (auto n : ns) cout << n << ", ";
    cout << endl;
    return 0;
}