#pragma once

//! Exception Class
/*!
* Handles exceptions thrown for the NNeighbor class
*
* This class implements:
* @see getFault()
*/

#include <iostream>
#include <string>

class Exception
{
	std::string message;

public:
	Exception(const std::string& fault);

	std::string getFault();

};

