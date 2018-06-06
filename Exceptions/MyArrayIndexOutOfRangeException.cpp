#include "MyArrayIndexOutOfRangeException.h"

const char* MyArrayIndexOutOfRangeException::what()
{
	char* buffer = new (nothrow) char[200];
	sprintf_s(buffer, 200, "MyArrayIndexOutOfRangeException: collections have different count of element (differents - %s)", this->error.c_str());

	return buffer;
}
