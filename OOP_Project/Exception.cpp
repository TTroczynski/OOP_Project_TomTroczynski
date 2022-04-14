#include "Exception.h"

Exception::Exception(const std::string& fault) : message(fault) {}

std::string Exception::getFault()
{
	return message;
}


