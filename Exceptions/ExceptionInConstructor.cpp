#include "ExceptionInConstructor.h"
#include <iostream>
#include <thread>
#include <chrono>  

using namespace std;

ExceptionInConstructor::ExceptionInConstructor()
{
	this->buf = new char[1024000];

	std::this_thread::sleep_for(chrono::seconds(2));

	throw 0;
}