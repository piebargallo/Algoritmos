#include <iostream>
#include <random>
#include <string>
#include <iterator>
#include <algorithm>

int main()
{
    std::string in = "hgfedcba", out;
    std::sample(in.begin(), in.end(), std::back_inserter(out),
        5, std::mt19937{ std::random_device{}() });
    std::cout << "cinco letras al azar obtenidas de " << in << " : " << out << '\n';
}