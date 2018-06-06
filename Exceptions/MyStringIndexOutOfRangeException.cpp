#include "MyStringIndexOutOfRangeException.h"

const char* MyStringIndexOutOfRangeException::what()
{
	char* buffer = new (nothrow) char[200];
	sprintf_s(buffer, 200, "MyStringIndexOutOfRangeException: string '%s' is less than one of the indexes", this->error.c_str());

	return buffer;
}
