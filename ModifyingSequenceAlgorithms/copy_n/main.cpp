#include <algorithm>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template<class InputIt, class Size, class OutputIt>
constexpr OutputIt copy_n(InputIt first, Size count, OutputIt result)
{
    if (count > 0)
    {
        *result = *first;
        ++result;
        for (Size i = 1; i != count; ++i, ++result)
            *result = *++first;
    }

    return result;
}

int main()
{
    string in{ "1234567890" };
    string out;

    std::copy_n(in.begin(), 4, std::back_inserter(out));
    cout << out << endl;

    return 0;
}