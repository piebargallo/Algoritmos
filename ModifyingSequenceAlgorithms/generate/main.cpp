/* Algorithm name: generate()

   Algorithm synopsis: calls a specified function to generate a new 
   value for each element in the sequence
*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

template<class ForwardIt, class Generator>
constexpr //< desde C++20
void generate(ForwardIt first, ForwardIt last, Generator g)
{
    for (; first != last; ++first)
        *first = g();
}

void println(std::string_view fmt, auto const& v)
{
    for (cout << fmt; auto const& e : v)
        cout << e << ' ';
    cout << endl;
};


int f()
{
    static int i;
    return ++i;
}

int main()
{
    vector<int> v(5);

    generate(v.begin(), v.end(), f);
    println("v: ", v);

    // Inicializar con valores predeterminados 0,1,2,3,4 desde una función lambda
    // Equivalente a std::iota(v.begin(), v.end(), 0);
    generate(v.begin(), v.end(), [n = 0]() mutable { return n++; });
    println("v: ", v);
    return 0;
}