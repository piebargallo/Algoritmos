/* Algorithm name: next_permutation

   Algorithm synopsis: modifies the sequence by transforming it into its next
   lexicographical permutation. Successive calls to one or the other will permute
   the sequence into all possible permutations of its elements, if you start with
   a properly sorted sequence. This algorithm returns false if no more 
   permutations exist
   
   Complexity: linear
*/

#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    string s = "aba";
    sort(s.begin(), s.end());
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    return 0;
}