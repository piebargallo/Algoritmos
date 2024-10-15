// Algorithm name: remove_copy

#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>

template<class InputIt, class OutputIt, class T>
OutputIt remove_copy(InputIt first, InputIt last, OutputIt d_first, const T& value)
{
    for (; first != last; ++first)
        if (!(*first == value))
            *d_first++ = *first;
    return d_first;
}

int main()
{
    setlocale(LC_ALL, "es-Es.utf8");
    std::string str = "#Optimización #del #Valor #de #Retorno";
    std::cout << "before: " << std::quoted(str) << '\n';

    std::cout << "after:  \"";
    remove_copy(str.begin(), str.end(),
        std::ostream_iterator<char>(std::cout), '#');
    std::cout << "\"\n";
    return 0;
}