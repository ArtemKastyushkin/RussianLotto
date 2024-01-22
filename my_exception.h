#if !defined MY_EXCEPTION_H
#define MY_EXCEPTION_H

#include <iostream>

enum ExceptionType { NullPtr, InvalidValue, Overflow, OutOfRange };

class MyException : public std::exception
{
private:
	ExceptionType _exceptionType;
public:
	MyException(char const* msg, ExceptionType exceptionType);

	ExceptionType GetExceptionType();
};

#endif#