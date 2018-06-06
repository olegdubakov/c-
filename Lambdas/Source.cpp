#include <iostream>
#include <string>
#include <algorithm> 
#include <cstdlib> 
#include <vector>
#include <functional>

using namespace std;

void fill_vector(vector<int>& vector, int count, function<int()> generator)
{
	vector.clear();
	vector.resize(count);

	generate(vector.begin(), vector.end(), generator);
}

void print_vector(vector<int>& vector)
{
	for_each(vector.begin(), vector.end(), [](int value) {
		cout << value << " ";
	});

	cout << endl;
}

int getMaxValue(vector<int>& vector)
{
	int max = 0;

	std::for_each(vector.begin(), vector.end(), [&max](int value)
	{
		if (value > max)
		{
			max = value;
		}
	});

	return max;
}

void sortVector(vector<int>& vector, function<bool(int, int)> sorter)
{
	sort(vector.begin(), vector.end(), sorter);
}

int findInVector(vector<int>& vector, function<bool(int)> find)
{
	std::vector<int>::iterator result = find_if(vector.begin(), vector.end(), find);

	if (result != vector.end() || find(*result))
	{
		return *result;
	}

	return 0;
}

void main()
{
	// Example 1: simple lambda  
	int intValue = [] () -> int { return 1; }();
	cout << intValue << endl;

	// Example 2: fill vector
	vector<int> values;

	fill_vector(values, 12, []() -> int { return rand() % 99 + 1; });
	print_vector(values);

	// Example 3: get max value
	int max = getMaxValue(values);
	cout << max << endl;

	// Example 3: vector sort
	sortVector(values, [](int left, int right) -> bool {
		return left < right;
	});

	print_vector(values);

	// Example 4: find first even number
	
	int firstEvenNumber = findInVector(values, [](int value) -> bool {
		return (value % 2 == 0);
	});

	cout << firstEvenNumber << endl;
}