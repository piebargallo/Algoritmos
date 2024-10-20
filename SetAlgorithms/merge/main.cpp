/* Algorithm name: merge

   Algorithm synopsys: merges two sorted sequences by copying therm 
   to a new sequence
   
   Complexity: linear
*/

#include <iostream>
#include <iterator>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    const size_t items = 10;

    vector<int> v1, v2, dst;

    // fill the vectors
    for (size_t idx = 0; idx < items; ++idx) {
        v1.push_back(rand() % items);
        v2.push_back(rand() % items);
    }

    // sort
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    // output v1
    cout << "v1 : ";
    copy(v1.begin(), v1.end(),
        ostream_iterator<int>(cout, " "));
    cout << endl;

    // output v2
    cout << "v2 : ";
    copy(v2.begin(), v2.end(),
        ostream_iterator<int>(cout, " "));
    cout << endl;

    // merge
    merge(v1.begin(), v1.end(),
        v2.begin(), v2.end(),
        back_inserter(dst));

    // output
    cout << "dst: ";
    copy(dst.begin(), dst.end(),
        ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}