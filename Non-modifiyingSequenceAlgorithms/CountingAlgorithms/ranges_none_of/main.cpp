#include <vector>
#include <iostream>
#include <functional>
using namespace std;
namespace ranges = std::ranges;

struct none_of_fn {
    template< std::input_iterator I, std::sentinel_for<I> S, class Proj = std::identity,
        std::indirect_unary_predicate<std::projected<I, Proj>> Pred >
    constexpr bool operator()(I first, S last, Pred pred, Proj proj = {}) const
    {
        return ranges::find_if(first, last, std::ref(pred), std::ref(proj)) == last;
    }

    template< ranges::input_range R, class Proj = std::identity,
        std::indirect_unary_predicate<
        std::projected<ranges::iterator_t<R>, Proj>> Pred >
        constexpr bool operator()(R&& r, Pred pred, Proj proj = {}) const
    {
        return operator()(ranges::begin(r), ranges::end(r), std::ref(pred), std::ref(proj));
    }
};

inline constexpr none_of_fn none_of;

int main()
{
    vector<int> v(10, 2);
    
    if (none_of(v, bind(std::modulus<int>(), placeholders::_1, 2))) {
        cout << "Ninguno es non" << endl;
    }

    return 0;
}