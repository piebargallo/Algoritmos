/* Algorithm name: search()

   Algorithm synopsis: Finds the first subsequence in a sequence that matches
   another sequence or whose elements are equivalent, as specifier by a predicate
   
   Complexity: O(N*M) 
*/

#include <iostream>
#include <string_view>
#include <vector>
using namespace std::literals;
using std::endl;
using std::cout;
using std::vector;

template<class ForwardIt1, class ForwardIt2>
constexpr ForwardIt1 search(ForwardIt1 first, ForwardIt1 last,
    ForwardIt2 s_first, ForwardIt2 s_last)
{
    while (true)
    {
        ForwardIt1 it = first;
        for (ForwardIt2 s_it = s_first; ; ++it, ++s_it)
        {
            if (s_it == s_last)
                return first;
            if (it == last)
                return last;
            if (!(*it == *s_it))
                break;
        }
        ++first;
    }
}

bool contains(const auto& cont, std::string_view s)
{
    return search(begin(cont), end(cont), begin(s), end(s)) != cont.end();
}

int main()
{
    constexpr auto str
    {
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed "
        "do eiusmod tempor incididunt ut labore et dolore magna aliqua"sv
    };
    
    cout << std::boolalpha
        << contains(str, "labore") << endl     
        << contains(str, "labores") << endl; 

    const vector vec(begin(str), end(str));
    cout << contains(vec, "dolore") << endl     
        << contains(vec, "dolores") << endl; 

    return 0;
}

/* Output:
    true
    false
    true
    false
*/