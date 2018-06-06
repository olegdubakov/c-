#include "MyArrayException.h"

MyArrayException::MyArrayException(string error)
{
	this->error = error;
}

const char* MyArrayException::what()
{
	return BuildErrorMessage("MyArrayException: %s");
}

const char* MyArrayException::BuildErrorMessage(string exeptionTemplate) noexcept
{
	int bufferLenght = error.length() + exeptionTemplate.length() + 1;
	char* buffer = new (std::nothrow) char[bufferLenght];

	if (buffer)
	{
		sprintf_s(buffer, bufferLenght, exeptionTemplate.c_str(), this->error.c_str());
	}

	return buffer;
}