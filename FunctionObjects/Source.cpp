#include <iostream>
#include <string>
#include <algorithm> 
#include <cstdlib> 
#include <vector>
#include <functional>

using namespace std;

class Rand
{
	int _maxValue;
public:
	Rand(int maxValue)
	{
		_maxValue = maxValue;
	}

	Rand()
	{
		_maxValue = 99;
	}

	int operator()() const
	{
		return rand() % _maxValue + 1;
	}

	int operator()(int maxValue) const
	{
		return rand() % maxValue + 1;
	}

	int operator()(int minValue, int maxValue) const
	{
		if (minValue >= maxValue)
		{
			minValue = 0;
			maxValue = _maxValue;
		}

		return rand() % maxValue + minValue;
	}
};

class PrintVector
{
public:
	void operator() (vector<int>& vector) const
	{
		for_each(vector.begin(), vector.end(), [](int value) {
			cout << value << " ";
		});

		cout << endl;
	}
};

void fill_vector(vector<int>& vector, int count, function<int()> generator)
{
	vector.clear();
	vector.resize(count);

	generate(vector.begin(), vector.end(), generator);
}

void main()
{
	vector<int> values;

	Rand getRandom;
	Rand getRandomMaxValue(1000);
	const PrintVector printVector;

	fill_vector(values, 12, getRandom);
	printVector(values);
	values.clear();


	fill_vector(values, 12, getRandomMaxValue);
	printVector(values);
	values.clear();

	fill_vector(values, 12, bind(getRandom, 50));
	printVector(values);
	values.clear();

	fill_vector(values, 12, bind(getRandom, -100, -50));
	printVector(values);
	values.clear();
}