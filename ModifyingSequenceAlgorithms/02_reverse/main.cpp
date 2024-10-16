#include <vector>
#include <iostream>
using namespace std;

template<class BidirIt>
void reverse(BidirIt first, BidirIt last)
{
    while ((first != last) && (first != --last)) {
        std::swap(*first++, *last);
    }
}

int main(int argc, char** argv)
{
    int a[] = { 4, 5, 6, 7 };
    std::reverse(&a[0], &a[4]);
    cout << a[0] << a[1] << a[2] << a[3] << '\n';
    return 0;
}