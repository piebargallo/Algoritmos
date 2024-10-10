/* Algorithm name: find_first_of()

   Clgorithm synopsis: like find, but searches for one of several elements
   at the same time
   
   Complexity: O(N*M) 
*/

#include <iostream>
#include <vector>
using std::cout;

template<class InputIt, class ForwardIt>
InputIt find_first_of(InputIt first, InputIt last,
    ForwardIt s_first, ForwardIt s_last)
{
    for (; first != last; ++first) {
        for (ForwardIt it = s_first; it != s_last; ++it) {
            if (*first == *it) {
                return first;
            }
        }
    }
    return last;
}

auto imprimir_secuencia = [](auto const id, auto const& secuencia, int pos = -1) {
    cout << id << "{ ";
    for (int i{}; auto const& e : secuencia) {
        const bool marca{ i == pos };
        cout << (i++ ? ", " : "");
        cout << (marca ? ">> " : "") << e << (marca ? " <<" : "");
    }
    cout << " }\n";
    };

int main()
{
    setlocale(LC_ALL, "es-Es.utf8");
    const std::vector<int> v{ 0, 2, 3, 25, 5 };
    const auto t1 = { 19, 10, 3, 4 };
    const auto t2 = { 1, 6, 7, 9 };

    auto cualquiera_de = [](const auto& v, const auto& t) {
        const auto resultado = find_first_of(begin(v), end(v),
            begin(t), end(t));
        if (resultado == end(v)) {
            cout << "Ningún elemento de v es igual a ningún elemento de ";
            imprimir_secuencia("t = ", t);
            imprimir_secuencia("v = ", v);
        }
        else {
            const auto pos = distance(begin(v), resultado);
            cout << "Se encontró una coincidencia (" << *resultado << ") en la posición " << pos;
            imprimir_secuencia(", donde t = ", t);
            imprimir_secuencia("v = ", v, pos);
        }
    };

    cualquiera_de(v, t1);
    cualquiera_de(v, t2);
}