#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class MyArrayException : public exception
{
protected:
	string error;
	const char* BuildErrorMessage(string exeptionTemplate) noexcept;

public:
	MyArrayException(string error);
	const char* what();
};
