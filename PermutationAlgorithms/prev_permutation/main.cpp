/* Algorithm name: prev_permutation

   Algorithm synopsis: modifies the sequence by transforming it into its previous
   lexicagraphical permutation. Successive calls to one or the other will permute
   the sequence into all possible permutations of its elements, if you start with
   a properly sorted sequence. This algorithm returns false if no more permutations
   exist
   
   Complexity: linear
*/

#include <algorithm>
#include <string>
#include <iostream>
#include <functional>
using namespace std;

int main()
{
    string s = "abc";
    sort(s.begin(), s.end(), greater<char>());
    do {
        std::cout << s << ' ';
    } while (prev_permutation(s.begin(), s.end()));
    cout << endl;
    return 0;
}