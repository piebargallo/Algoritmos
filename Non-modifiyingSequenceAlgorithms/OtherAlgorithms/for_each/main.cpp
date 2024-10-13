#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

template<class InputIt, class UnaryFunction>
constexpr UnaryFunction for_each(InputIt first, InputIt last, UnaryFunction f)
{
    for (; first != last; ++first) {
        f(*first);
    }
    return f; // movimiento implícito desde C++11
}

struct Suma
{
    void operator()(int n) { suma += n; }
    int suma{ 0 };
};

int main()
{
    setlocale(LC_ALL, "es-Es.utf8");
    vector<int> nums{ 3, 4, 2, 8, 15, 267 };

    auto imprimir = [](const int& n) { cout << " " << n; };

    cout << "antes:";
    for_each(nums.cbegin(), nums.cend(), imprimir);
    cout << endl;

    for_each(nums.begin(), nums.end(), [](int& n) { n++; });

    Suma s = for_each(nums.begin(), nums.end(), Suma());

    cout << "después: ";
    for_each(nums.cbegin(), nums.cend(), imprimir);
    cout << endl;
    cout << "suma: " << s.suma << endl;

    return 0;
}