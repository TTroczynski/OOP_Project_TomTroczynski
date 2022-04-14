#include "Exception.h"

Exception::Exception(const std::string& fault) : message(fault) {}


/*! \brief Retrieves the exception message
*
* returns this Exception message so the user understands the mode of failure
*
*/

std::string Exception::getFault()
{
	return message;
}


