#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

namespace ranges = std::ranges;

struct all_of_fn {
    template< std::input_iterator I, std::sentinel_for<I> S, class Proj = std::identity,
        std::indirect_unary_predicate<std::projected<I, Proj>> Pred >
    constexpr bool operator()(I first, S last, Pred pred, Proj proj = {}) const
    {
        return ranges::find_if_not(first, last, std::ref(pred), std::ref(proj)) == last;
    }

    template< ranges::input_range R, class Proj = std::identity,
        std::indirect_unary_predicate<
        std::projected<ranges::iterator_t<R>, Proj>> Pred >
        constexpr bool operator()(R&& r, Pred pred, Proj proj = {}) const
    {
        return operator()(ranges::begin(r), ranges::end(r), std::ref(pred), std::ref(proj));
    }
};

inline constexpr all_of_fn all_of;

int main()
{
    setlocale(LC_ALL, "es-Es.utf8");
    vector<int> v(10, 2);
    
    if (all_of(v.cbegin(), v.cend(), [](int i) { return i % 2 == 0; })) {
        cout << "Todos los números son pares" << endl;
     }
    return 0;
}