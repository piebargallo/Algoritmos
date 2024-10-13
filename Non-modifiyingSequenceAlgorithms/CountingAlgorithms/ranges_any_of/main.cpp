#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
namespace ranges = std::ranges;

struct any_of_fn {
    template< std::input_iterator I, std::sentinel_for<I> S, class Proj = std::identity,
        std::indirect_unary_predicate<std::projected<I, Proj>> Pred >
    constexpr bool operator()(I first, S last, Pred pred, Proj proj = {}) const
    {
        return ranges::find_if(first, last, std::ref(pred), std::ref(proj)) != last;
    }

    template< ranges::input_range R, class Proj = std::identity,
        std::indirect_unary_predicate<
        std::projected<ranges::iterator_t<R>, Proj>> Pred >
        constexpr bool operator()(R&& r, Pred pred, Proj proj = {}) const
    {
        return operator()(ranges::begin(r), ranges::end(r), std::ref(pred), std::ref(proj));
    }
};

inline constexpr any_of_fn any_of;

int main()
{
    setlocale(LC_ALL, "es-Es.utf8");
    vector<int> v(10, 7);
    
auto DivisiblePor = [](int d)
        {
            return [d](int m) { return m % d == 0; };
        };

    if (ranges::any_of(v, DivisiblePor(7))) {
        cout << "Al menos un número es divisible por 7" << endl;
    }
    return 0;
}