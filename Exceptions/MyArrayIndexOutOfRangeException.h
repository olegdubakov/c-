#pragma once
#include "MyArrayException.h"
#include <iostream>
#include <string>

using namespace std;

class MyArrayIndexOutOfRangeException : public MyArrayException
{
public:
	MyArrayIndexOutOfRangeException(string error) : MyArrayException(error) {};
	const char* what();
};
