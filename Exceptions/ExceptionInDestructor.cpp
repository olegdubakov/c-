#include "ExceptionInDestructor.h"
#include <iostream>
#include <thread>
#include <chrono>  

using namespace std;

ExceptionInDestructor::ExceptionInDestructor()
{
	this->buf = new char[1024000];

	std::this_thread::sleep_for(chrono::seconds(2));
}


ExceptionInDestructor::~ExceptionInDestructor()
{
	throw 0;

	delete[] this->buf;

}