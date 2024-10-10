/* Algorithm name: find_end()

   Algorithm synopsis: Finds the last subsequence in a sequence that matches another
   sequence or whose elements are equivalent, as specified by a predicate
   
   Complexity: O(M*(N-M)) 
*/

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

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

template<class ForwardIt1, class ForwardIt2>
ForwardIt1 find_end(ForwardIt1 first, ForwardIt1 last,
    ForwardIt2 s_first, ForwardIt2 s_last)
{
    if (s_first == s_last)
        return last;
    ForwardIt1 result = last;
    while (true) {
        ForwardIt1 new_result = search(first, last, s_first, s_last);
        if (new_result == last) {
            break;
        }
        else {
            result = new_result;
            first = result;
            ++first;
        }
    }
    return result;
}

int main()
{
    setlocale(LC_ALL, "es-Es.utf8");
    vector<int> v{ 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4 };
    vector<int>::iterator result;

    auto check = [&] {
        result == end(v)
            ? cout << "No se encontró la secuencia." << endl
            : cout << "La última ocurrencia se encuentra en: "
            << std::distance(begin(v), result) << endl;
        };

    vector<int> t1{ 1, 2, 3 };
    result = find_end(begin(v), end(v), begin(t1), end(t1));
    check();

    std::vector<int> t2{ 4, 5, 6 };
    result = find_end(begin(v), end(v), begin(t2), end(t2));
    check();

    return 0;
}