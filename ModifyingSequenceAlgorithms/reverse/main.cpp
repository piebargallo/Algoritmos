/* 
    Algorithm name: reverse

   Algorithm synopsys: reverses the order of the elements in the sequence, either
   in place or by copying the results to a different sequence
*/

#include <iostream>
#include <vector>
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
    std::vector<int> v({ 1,2,3 });
    std::reverse(std::begin(v), std::end(v));
    std::cout << v[0] << v[1] << v[2] << '\n';
    return 0;
}