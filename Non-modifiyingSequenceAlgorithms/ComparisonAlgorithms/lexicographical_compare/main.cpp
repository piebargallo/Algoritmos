/* 
   Algorithm name: lexicographical_compare()

   Algorithm synopsis: compares two sequences to determine their
   "lexicographical" ordeding. This algorithm compares each element 
   of the first sequence with is equivalent element in the second. if
   one element is less than the other, that sequence is lexicographically
   first. If the elements are equal, it compares the next elements in order.
*/

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

template<class InputIt1, class InputIt2>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
    InputIt2 first2, InputIt2 last2)
{
    for (; (first1 != last1) && (first2 != last2); first1++, first2++) {
        if (*first1 < *first2) return true;
        if (*first2 < *first1) return false;
    }
    return (first1 == last1) && (first2 != last2);
}

int main() {
    setlocale(LC_ALL, "es-Es.utf8");
    vector<int> vec1 = { 1, 2, 3, 4, 5 };
    vector<int> vec2 = { 1, 2, 3, 4, 6 };

    bool result = std::lexicographical_compare(begin(vec1), end(vec1), begin(vec2), end(vec2));

    if (result) {
        cout << "vec1 es lexicográficamente menor que vec2." << endl;
    }
    else {
        cout << "vec1 no es lexicográficamente menor que vec2." << endl;
    }

    return 0;
}


