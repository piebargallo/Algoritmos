/* Algorithm name: is_sorted

   Algorithm synopsis: checks if a sequence is sorted or wich
   subsequence is sorted
   
   Complexity: linear
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    const int N = 5;
    int digits[N] = { 3, 1, 4, 1, 5 };

    for (auto i : digits) cout << i << ' ';
    cout << ": is_sorted: " << is_sorted(digits, digits + N) << endl;

    sort(digits, digits + N);

    for (auto i : digits) cout << i << ' ';
    cout << ": is_sorted: " << is_sorted(digits, digits + N) << endl;

    return 0;
}