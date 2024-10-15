/* Algorithm name: move()

   Algorithm synopsis: moves elements from one sequence to another using
   efficient move semantics
*/

#include <chrono>
#include <iostream>
#include <list>
#include <thread>
#include <vector>

template<class InputIt, class OutputIt>
OutputIt move(InputIt first, InputIt last, OutputIt d_first)
{
    for (; first != last; ++d_first, ++first)
        *d_first = std::move(*first);

    return d_first;
}

void f(int n)
{
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "El hilo " << n << " finalizó" << std::endl;
}

int main()
{
    setlocale(LC_ALL, "es-Es.utf8");
    std::vector<std::jthread> v;
    v.emplace_back(f, 1);
    v.emplace_back(f, 2);
    v.emplace_back(f, 3);
    std::list<std::jthread> l;

    // copy() no compilaría, ya que std::jthread no es copiable
    std::move(v.begin(), v.end(), std::back_inserter(l));
    return 0;
}