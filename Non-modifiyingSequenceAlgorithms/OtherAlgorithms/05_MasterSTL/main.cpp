// The find_if_not()

#include <iostream>
#include <vector>
using namespace std;

template<class InputIt, class UnaryPredicate>
constexpr InputIt find_if_not(InputIt first, InputIt last, UnaryPredicate q)
{
	for (; first != last; ++first) {
		if (!q(*first)) {
			return first;
		}
	}
	return last;
}

int main()
{
	// The list of elements to be searched.
	vector myVector{ 5, 6, 9, 8, 8, 3 };
	auto beginIter{ cbegin(myVector) };
	auto endIter{ cend(myVector) };

	// Find the first element that does not satisfy the given lambda expression.
	auto it{ find_if_not(beginIter, endIter, [](int i) { return i < 8; }) };
	if (it != endIter) {
		cout << "First element not < 8 is " << *it << endl;
	}
	return 0;
}
