// The accumulate() algorithm

#include <cmath>
#include <numeric>
#include <vector>
#include <iostream>
#include <span>
#include <functional>

using namespace std;

double arithmeticMean(span<const int> values)
{
	double sum{ accumulate(cbegin(values), cend(values), 0.0) };
	return sum / values.size();
}

int main()
{
	vector<int> myVector;

	while (true) {
		cout << "Enter a test score to add (0 to stop): ";
		int score;
		cin >> score;
		if (score == 0) {
			break;
		}
		myVector.push_back(score);
	}

	cout << "The arithmetic mean is " << arithmeticMean(myVector) << endl;
}
