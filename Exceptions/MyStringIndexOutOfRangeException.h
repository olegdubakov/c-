#pragma once
#include "MyArrayException.h"
#include <iostream>
#include <string>

using namespace std;

class MyStringIndexOutOfRangeException : public MyArrayException
{
public:
	MyStringIndexOutOfRangeException(string error) : MyArrayException(error) {};
	const char* what();
};
