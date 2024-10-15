// Algorithm name: move_backward()

#include <iostream>
#include <iterator>
#include <string>
#include <string_view>
#include <vector>

template<class BidirIt1, class BidirIt2>
BidirIt2 move_backward(BidirIt1 first, BidirIt1 last,
    BidirIt2 d_last)
{
    while (first != last)
        *(--d_last) = std::move(*(--last));

    return d_last;
}

using container = std::vector<std::string>;

void print(std::string_view comment, const container& src, const container& dst = {})
{
    auto prn = [](std::string_view name, const container& cont)
        {
            std::cout << name;
            for (const auto& s : cont) { std::cout << (s.empty() ? "∙" : s.data()) << ' '; }
            std::cout << '\n';
        };
    std::cout << comment << '\n';
    prn("src: ", src);
    if (dst.empty()) return;
    prn("dst: ", dst);
}

int main()
{
    setlocale(LC_ALL, "es-Es.utf8");
    container src{ "foo", "bar", "baz" };
    container dst{ "qux", "quux", "quuz", "corge" };
    print("Caso no superpuesto; antes de move_backward:", src, dst);
    std::move_backward(src.begin(), src.end(), dst.end());
    print("Después:", src, dst);

    src = { "snap", "crackle", "pop", "lock", "drop" };
    print("Caso superpuesto; antes de move_backward:", src);
    std::move_backward(src.begin(), std::next(src.begin(), 3), src.end());
    print("Después:", src);
}