/* Algorithm name: includes

   Algorithm synopsis: determines whether every element from one sorted
   sequence is in another sorted sequence
   
   Complexity: linear
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
    vector<char> v1{ 'a', 'b', 'c', 'f', 'h', 'x' };
    vector<char> v2{ 'a', 'b', 'c' };
    vector<char> v3{ 'a', 'c' };
    vector<char> v4{ 'g' };
    vector<char> v5{ 'a', 'c', 'g' };
    vector<char> v6;

    for (auto i : v1) cout << i << ' ';
    cout << endl;
    
    cout << "includes:" << endl;

    for (auto i : v2) cout << i << ' ';
    cout << ": " << includes(v1.begin(), v1.end(), v2.begin(), v2.end()) << endl;
    for (auto i : v3) cout << i << ' ';
    cout << ": " << includes(v1.begin(), v1.end(), v3.begin(), v3.end()) << endl;
    for (auto i : v4) cout << i << ' ';
    cout << ": " << includes(v1.begin(), v1.end(), v4.begin(), v4.end()) << endl;
    for (auto i : v5) cout << i << ' ';
    cout << ": " << includes(v1.begin(), v1.end(), v5.begin(), v5.end()) << endl;
    for (auto i : v6) cout << i << ' ';
    cout << ": " << includes(v1.begin(), v1.end(), v6.begin(), v6.end()) << endl;

    // bool cmp(const Type1 &a, const Type2 &b);
    auto cmp_nocase = [](const char &a, const char &b) {
        return tolower(a) < tolower(b);
        };
    
    vector<char> v7{ 'A', 'B', 'C' };
    for (auto i : v7) {
        cout << i << ' ';
        cout << ": "
            << includes(v1.begin(), v1.end(), v7.begin(), v7.end(), cmp_nocase)
            << endl;
    }
    return 0;
}