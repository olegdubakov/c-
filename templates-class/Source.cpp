#include <iostream>
#include <string>
#include <list>

using namespace std;

class ExampleClassA
{
private:
	int value;
public:
	ExampleClassA(int value)
	{
		this->value = value;
	}

	friend ostream& operator<<(ostream& os, const ExampleClassA& exampleClassA)
	{
		os << "[ExampleClassA: " << exampleClassA.value << "]";
		return os;
	}
};


class ExampleClassB
{
private:
	string value;
public:
	ExampleClassB(string value)
	{
		this->value = value;
	}

	friend ostream& operator<<(ostream& os, const ExampleClassB& exampleClassB)
	{
		os << "[ExampleClassB: " << exampleClassB.value << "]";
		return os;
	}
};

template <typename T>
class TemplateClass
{
private:
	list<T> values;
public:
	void AddValue(T value)
	{
		values.push_back(value);
	}
	void PrintAllValues()
	{
		for (list<T>::iterator iterator = values.begin(); iterator != values.end(); iterator++)
		{
			cout << *iterator << " ";
		}
		cout << endl;
	}
};

void main()
{
	TemplateClass<int> intValues;
	intValues.AddValue(3);
	intValues.AddValue(55);
	intValues.AddValue(77);
	intValues.AddValue(5);
	intValues.PrintAllValues();

	TemplateClass<string> stringValue;
	stringValue.AddValue("Oleg");
	stringValue.AddValue("likes");
	stringValue.AddValue("C++");
	stringValue.AddValue("and C#");
	stringValue.PrintAllValues();
	
	TemplateClass<ExampleClassA> ExampleClassAValue;
	ExampleClassAValue.AddValue(ExampleClassA(1));
	ExampleClassAValue.AddValue(ExampleClassA(2));
	ExampleClassAValue.AddValue(ExampleClassA(3));
	ExampleClassAValue.AddValue(ExampleClassA(4));
	ExampleClassAValue.PrintAllValues();

	TemplateClass<ExampleClassB> ExampleClassBValue;
	ExampleClassBValue.AddValue(ExampleClassB("A"));
	ExampleClassBValue.AddValue(ExampleClassB("B"));
	ExampleClassBValue.AddValue(ExampleClassB("C"));
	ExampleClassBValue.AddValue(ExampleClassB("D"));
	ExampleClassBValue.PrintAllValues();
}