/* Algorithm name: generate_n()

   Algorithm synopsis: calls a specified function to generate a new value
   for the first n elements in the sequence
*/
#include <functional>
#include <iostream>
#include <iterator>
#include <random>

template<class OutputIt, class Size, class Generator>
constexpr // desde C++20
OutputIt  // void hasta C++11
generate_n(OutputIt first, Size count, Generator g)
{
    for (Size i = 0; i < count; ++i, ++first)
        *first = g();

    return first;
}

int main()
{
    std::mt19937 rng; // construido por defecto, sembrado con una semilla fija
    std::generate_n(std::ostream_iterator<std::mt19937::result_type>(std::cout, " "),
        5, std::ref(rng));
    std::cout << std::endl;
    return 0;
}