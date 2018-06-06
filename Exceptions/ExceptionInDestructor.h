#pragma once

class ExceptionInDestructor
{
public:
	ExceptionInDestructor();
	~ExceptionInDestructor();

private:
	char* buf;
};
