#include <iostream>
#include <string>

using namespace std;

template<typename T>
int Compare(
	T firsValue, 
	T secondValue)
{
	int result = 0;

	if (firsValue > secondValue)
	{
		result = 1;
	}
	else if (firsValue < secondValue)
	{
		result = -1;
	}

	return result;
};

template<typename T>
void PrintResult(
	T firsValue, 
	T secondValue)
{
	string comparer = " == ";

	if (Compare(firsValue, secondValue) == 1)
	{
		comparer = " > ";
	}
	else if (Compare(firsValue, secondValue) == -1)
	{
		comparer = " < ";
	}

	cout << firsValue << comparer << secondValue << endl;
};

void main()
{
	PrintResult(1, 2);
	PrintResult(22, 11);
	PrintResult("test", "test3");
	PrintResult(1.55, 1.54);
	PrintResult("string", "string");
}