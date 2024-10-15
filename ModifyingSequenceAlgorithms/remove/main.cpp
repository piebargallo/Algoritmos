/* Algorithm name: remove()

   Algorithm synopsis: removes all elements that match a given value or that cause
   a predicate to return true, either in place or by copying the results to a 
   different sequence
*/

#include <cctype>
#include <iostream>
#include <string>
#include <string_view>

template<class ForwardIt, class T>
ForwardIt remove(ForwardIt first, ForwardIt last, const T& value)
{
    first = std::find(first, last, value);
    if (first != last)
        for (ForwardIt i = first; ++i != last;)
            if (!(*i == value))
                *first++ = std::move(*i);
    return first;
}

int main()
{
    setlocale(LC_ALL, "es-Es.utf8");
    std::string str1{ "Texto con algunos   espacios" };

    auto noSpaceEnd = std::remove(str1.begin(), str1.end(), ' ');

    // Los espacios se eliminan de la cadena solo lógicamente.
    // Usamos una vista sobre cadena, la cadena original aún no se ha reducido:
    std::cout << std::string_view(str1.begin(), noSpaceEnd)
        << " tamaño: " << str1.size() << '\n';

   str1.erase(noSpaceEnd, str1.end());
   return 0;
}