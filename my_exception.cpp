#include "my_exception.h"

MyException::MyException(char const* msg, ExceptionType exceptionType) : exception(msg), _exceptionType(exceptionType) { }

ExceptionType MyException::GetExceptionType() { return _exceptionType; }