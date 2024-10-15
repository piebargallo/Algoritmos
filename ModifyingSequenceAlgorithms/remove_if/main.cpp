// Algorithm name: remove_if

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

template<class ForwardIt, class UnaryPredicate>
ForwardIt remove_if(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    first = std::find_if(first, last, p);
    if (first != last)
        for (ForwardIt i = first; ++i != last;)
            if (!p(*i))
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

    // Los espacios se eliminan de la cadena físicamente.
    std::cout << str1 << " tamaño: " << str1.size() << '\n';

    std::string str2 = "Texto\n con\talgunos \t  espacios en blanco\n\n";
    str2.erase(std::remove_if(str2.begin(),
        str2.end(),
        [](unsigned char x) { return std::isspace(x); }),
        str2.end());
    std::cout << str2 << '\n';
    return 0;
}