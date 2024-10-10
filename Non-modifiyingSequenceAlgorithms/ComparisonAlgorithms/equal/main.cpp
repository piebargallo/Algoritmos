/* 
   Algorithm name: equal()

   Algorithm synopsis: Determines wheter two sequences are equal by checking
   whether parallel elements are equal or match a predicate 
*/

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

template<class InputIt1, class InputIt2, class BinaryPredicate>
bool equal(InputIt1 first1, InputIt1 last1,
    InputIt2 first2, BinaryPredicate p)
{
    for (; first1 != last1; ++first1, ++first2) {
        if (!p(*first1, *first2)) {
            return false;
        }
    }
    return true;
}

bool mypredicate(int i, int j) {
    return (i == j);
}

int main() {
    int myints[] = { 20, 40, 60, 80, 100 }; 
    vector<int> myvector(myints, myints + 5); 

    if (equal(begin(myvector), end(myvector), myints)) {
        cout << "Los contenidos de ambas secuencias son iguales." << endl;
    }
    else {
        cout << "Los contenidos de ambas secuencias son diferentes." << endl;
    }

    myvector[3] = 81; 

    if (std::equal(begin(myvector), end(myvector), myints, mypredicate)) {
        cout << "Los contenidos de ambas secuencias son iguales." << endl;
    }
    else {
        cout << "Los contenidos de ambas secuencias son diferentes." << endl;
    }

    return 0;
}
