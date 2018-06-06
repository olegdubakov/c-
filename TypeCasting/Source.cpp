#include <iostream>
#include <string>
#include <list>

using namespace std;


// explicit
void TestExplicit()
{
	char ea = 'a';
	double eb = 6.6;
	int ec = (int)ea + (int)eb;

	cout << "explicit casting result: " << ec << endl;
}

// implicit
void TestImplicit()
{
	double ia = 1.2;
	short ib = 3;
	int ic = ia + ib;

	cout << "implicit casting result: " << ic << endl;
}

// dynamic_cast
class DynamicCastA
{ 
public:
	virtual void test()
	{
		cout << "test from DynamicCastA" << endl;
	}
};

class DynamicCastB : public DynamicCastA
{
public:
	virtual void test()
	{
		cout << "test from DynamicCastB" << endl;
	}
};

void TestDynamicCast()
{
	DynamicCastA* dynamicCastA_1 = new DynamicCastB; 
	dynamicCastA_1->test();

	DynamicCastA* dynamicCastA_2 = new DynamicCastA;
	dynamicCastA_2->test();

	DynamicCastA* dynamicCastB_1 = dynamic_cast<DynamicCastA*>(dynamicCastA_1);
	dynamicCastB_1->test();

	DynamicCastA* dynamicCastB_2 = dynamic_cast<DynamicCastA*>(dynamicCastA_1);
	dynamicCastB_2->test();
}

// static_cast (Converts between types using a combination of implicit and user-defined conversions. )
class StaticCastA
{
public:
	int m = 0;

	virtual void test()
	{
		cout << "test from StaticCastA" << endl;
	}
};

class StaticCastB : public StaticCastA
{
public:
	virtual void test()
	{
		cout << "test from StaticCastB" << endl;
	}
};

enum staticCastEnum 
{
	ONE = 1, 
	TWO, 
	THREE
};

void TestStaticCast()
{
	float sc_float = 3.333;
	int sc_int_1 = 0;
	sc_int_1 = static_cast<int>(sc_float);
	cout << "result of static_cast<int>(float): " << sc_int_1 << endl;

	int sc_int_2 = 2;
	staticCastEnum sc_num = static_cast<staticCastEnum>(sc_int_2);

	cout << "result of static_cast<enum>(int): ";

	switch (sc_num)
	{
		case ONE:
			cout << "ONE" << endl; 
			break;
		case TWO: 
			cout << "TWO" << endl; 
			break;
		case THREE: 
			cout << "THREE" << endl; 
			break;
	}
}

// reinterpret_cast
void TestReinterpretCast()
{
	int *first_int = new int(51);
	void *ptr_to_int = reinterpret_cast<void*>(first_int);
	int *first_int_again = reinterpret_cast<int*>(ptr_to_int);
	std::cout << "result of reinterpret_cast: " << *first_int_again << endl;
}
// const_cast
void TestConstCast()
{
	int i = 33;
	const int& ci = i;
	const_cast<int&>(ci) = 4;
	std::cout << "result of const_cast: " << i << endl;
}


void main()
{
	TestExplicit();

	TestImplicit();

	TestDynamicCast();

	TestStaticCast();

	TestReinterpretCast();

	TestConstCast();
}