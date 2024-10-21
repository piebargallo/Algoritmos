/* Algorithm name: is_permutation

   Algorithm synopsis: returns true if the elements in one range are a permutation
   of the elements in another range
   
   Synopsis: quadratic
*/

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v1{ 1,2,3,4,5 };
    vector<int> v2{ 3,5,4,1,2 };
    cout << "3,5,4,1,2 is a permutation of 1,2,3,4,5? "
        << boolalpha
        << is_permutation(v1.begin(), v1.end(), v2.begin()) << endl;

    vector<int> v3{ 3,5,4,1,1 };
    cout << "3,5,4,1,1 is a permutation of 1,2,3,4,5? "
        << boolalpha
        << is_permutation(v1.begin(), v1.end(), v3.begin()) << endl;
    return 0;
}