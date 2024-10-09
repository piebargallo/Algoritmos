/* Algorithm name: search_n()

   Algorithm synopsis: Finds the first instance of n consecutive elements
   that are equal to a given value or relate to that value according to a
   predicate
   
   Complexy: O(N)
*/

#include <iostream>
#include <string_view>
#include <vector>
using namespace std::literals;
using std::string_view;
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

bool contains(const auto& cont, string_view s)
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
        << contains(str, "consectetur") << endl  
        << contains(str, "consictetur") << endl; 

    const vector vec(begin(str), end(str));
    cout << contains(vec, "consectetur") << endl 
        << contains(vec, "consictetur") << endl; 

    return 0;
}

/* Output:
 true
 false
 true
 false */