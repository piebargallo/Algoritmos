// Algorithm name: remove_copy_if()

#include <iostream>
#include <vector>
using std::vector;

template<class InputIt, class OutputIt, class UnaryPredicate>
OutputIt remove_copy_if(InputIt first, InputIt last, OutputIt d_first, UnaryPredicate p)
{
    for (; first != last; ++first)
        if (!p(*first))
            *d_first++ = *first;
    return d_first;
}

// Predicate function to check if a number is even
bool isEven(int n) {
    // Nota bene: la condición es n % 2 == 0 para even, pero la 
    // implementación del algoritmo contiene una negación del 
    // predicado, entonces el porque de negar la igualdad en la
    // condición para even.
    return (n % 2 != 0);
}

int main() {
    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> result;

    // Using remove_copy_if to copy odd numbers to the result vector
    remove_copy_if(numbers.begin(), numbers.end(), std::back_inserter(result), isEven);

    // Print the result vector
    for (int n : result) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}
