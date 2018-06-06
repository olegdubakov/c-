#include <iostream>
#include <string>
#include <vector>
#include "Formatter.h"
#include "ExceptionInConstructor.h"
#include "ExceptionInDestructor.h"
#include <thread>
#include <chrono>  

using namespace std;
/*
Написать проект, в котором есть иерархия исключений унаследованных от std::exception или от его потомков std::logic_error, std::runtime_error.
Написать в проекте приложение, в котором будет реализовано следующее :
1.	Генерация одного из созданного класса исключений.
2.	Вложенный перехват исключений – try - catch в try - catche.
3.	Перехват исключений по цепочке – try { … }
catch (type1) { … }
catch (type2) { … }
catch (…) { … }.
4.	Генерация исключения, которое не обрабатывается.
5.	Регенерация пойманного исключения в обработчике.
6.	Использовать один раз std::nothrow.
7.	Использовать noexcept с методом класса один раз правильно, другой раз – нет.
8.	Создать класс, который генерирует исключение в своём конструкторе и десктрукторе.
    После вызова такого конструктора и деструктора – проверить, что будет с объектом и памятью.
	Будет ли он существовать и выделиться / очиститься ли после него память.
*/

void main()
{
	vector<int> indexes = { 1, 3, 8 };
	vector<int> values = { 1, 2, 3, 5, 6, 7, 8 };

	Formatter::FormateString(string("string for result"), indexes, values);

	cout << endl;

	values.clear();
	values.push_back(1);
	values.push_back(2);
	values.push_back(3);

	Formatter::FormateString(string("source"), indexes, values);

	cout << endl;

	values.clear();
	indexes.clear();
	Formatter::FormateString(string(""), indexes, values);

	cout << endl;

	Formatter::FormateString(string("source"), indexes, values);

	cout << endl;
	/*
	ExceptionInConstructor* exceptionInConstructor;

	try
	{
		exceptionInConstructor = new ExceptionInConstructor();
	}
	catch (...)
	{
		cout << "some error" << endl;
	}

	std::this_thread::sleep_for(chrono::seconds(2));

	cout << endl;

	*/

	ExceptionInDestructor* exceptionInDestructor;

	try
	{
		exceptionInDestructor = new ExceptionInDestructor();
	}
	catch (...)
	{
		cout << "some error" << endl;
	}

	std::this_thread::sleep_for(chrono::seconds(2));

	cout << endl;
}